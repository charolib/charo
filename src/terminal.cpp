#include <charo/render/screen.hpp>
#include <charo/terminal.hpp>
#include <charo/render/escape.hpp>
#include <charo/event/events.hpp>

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct charo::Terminal::impl {
    Screen screen;
    EventsSystem events;
    struct termios orig_termios;
};

charo::Terminal::Terminal() : pimpl(new impl) {
    tcgetattr(STDIN_FILENO, &pimpl->orig_termios);
    struct termios new_termios = pimpl->orig_termios;
    new_termios.c_lflag &= ~ICANON; // disable canonical input
    new_termios.c_lflag &= ~ECHO;   // disable echo by the terminal
    new_termios.c_lflag &= ~ISIG;   // disable keyboard signals (^C, ^\, ^Z)
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    std::setvbuf(stdin, NULL, _IONBF, 0);

    struct winsize term_size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);
    pimpl->screen.resize(Size{term_size.ws_xpixel, term_size.ws_ypixel});

    auto& events = pimpl->events;
    events.bind_event("enter", KeySet({charo::KEYS::LOWERCASE_A, charo::KEYS::LOWERCASE_B}, true));
    events.bind_event("exit", KeySet{charo::KEYS::LOWERCASE_Q, charo::KEYS::UPPERCASE_Q, charo::KEYS::ESC});
}

charo::Terminal::~Terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &pimpl->orig_termios);
}

auto charo::Terminal::read_event(std::string_view name) const -> bool {
    return pimpl->events.read_event(name);
}

void charo::Terminal::refresh() {
    if (read_event("exit")) {
        exit(1);
    }
    if (read_event("enter"))
        exit(1);
    draw_screen_diff(pimpl->screen.screen_diff());
    pimpl->screen.next_frame();
    pimpl->events.process();
}

auto charo::Terminal::size() const -> Size {
    return pimpl->screen.size();
}

void charo::Terminal::move_cursor(Pos pos) {
    escape::write(escape::get_escape(pos));
    escape::flush();
}