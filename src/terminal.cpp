#include <charo/render/screen.hpp>
#include <charo/terminal.hpp>
#include <charo/render/escape.hpp>
#include <charo/event/events.hpp>

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct charo::Terminal::impl {
    EventsSystem events;
    struct termios orig_termios;
};

charo::Terminal::Terminal() : pimpl(new impl) {
    tcgetattr(STDIN_FILENO, &pimpl->orig_termios);
    struct termios new_termios = pimpl->orig_termios;
    new_termios.c_lflag &= ~ICANON; // disable canonical input
    new_termios.c_cc[VMIN] = 1;

    new_termios.c_lflag &= ~ECHO;   // disable echo by the terminal
    new_termios.c_lflag &= ~ISIG;   // disable keyboard signals (^C, ^\, ^Z)
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    std::setvbuf(stdin, NULL, _IONBF, 0);

    struct winsize term_size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);
    screen.resize(Size{term_size.ws_col, term_size.ws_row});

    escape::write("\033[" "?1049h");
    escape::write("\033[" "?25l");

    auto& events = pimpl->events;
    events.bind_event("enter", KeySet{charo::KEYS::LOWERCASE_L, charo::KEYS::UPPERCASE_L});
    events.bind_event("exit", KeySet{charo::KEYS::LOWERCASE_Q, charo::KEYS::UPPERCASE_Q, charo::KEYS::ESC});
    events.bind_event("up", KeySet{charo::KEYS::LOWERCASE_J, charo::KEYS::UPPERCASE_J});
    events.bind_event("down", KeySet{charo::KEYS::LOWERCASE_K, charo::KEYS::UPPERCASE_K});
}

charo::Terminal::~Terminal() {
    escape::write("\033[?7h");
    escape::write("\033[" "?1049l");
    escape::write("\033[" "?25h");
    escape::flush();
    tcsetattr(STDIN_FILENO, TCSANOW, &pimpl->orig_termios);
}

auto charo::Terminal::read_event(std::string_view name) const -> bool {
    return pimpl->events.read_event(name);
}

auto charo::read_event(std::string_view name) -> bool {
    return get_terminal().read_event(name);
}

void charo::Terminal::refresh() {


    if (read_event("exit")) {
        exit(1);
    }

    auto const& deferred_callbacks = context.deferred_callbacks;
    for (auto const& callback : deferred_callbacks)
        callback();
    
    draw_screen_diff(screen.screen_diff());

    context.clear();

    screen.next_frame();

    pimpl->events.process();
}

auto charo::Terminal::size() const -> Size {
    return screen.size();
}

auto charo::Terminal::current_screen() -> Screen& {
    return screen;
}
auto charo::Terminal::current_context() -> CharoContext& {
    return context;
}

void charo::Terminal::move_cursor(Pos pos) {
    escape::write(escape::get_escape(pos));
    escape::flush();
}