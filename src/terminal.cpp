#include <charo/terminal.hpp>
#include <charo/internal/screen.hpp>
#include <charo/internal/escape.hpp>
#include <charo/internal/event/events.hpp>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct charo::Terminal::impl {
    EventsSystem events;
    struct termios orig_termios;
};

charo::Terminal::Terminal() : pimpl_{new impl} {
    auto constexpr stdout_buf_size = 4'096;
    if (std::setlocale(LC_ALL, "en_US.UTF-8") == nullptr)
        throw std::runtime_error{"Terminal(): setlocale() failed"};
    std::setvbuf(stdout, nullptr, _IOFBF, stdout_buf_size);

    tcgetattr(STDIN_FILENO, &pimpl_->orig_termios);
    struct termios new_termios = pimpl_->orig_termios;
    new_termios.c_lflag &= ~ICANON; // disable canonical input
    new_termios.c_cc[VMIN] = 1;

    new_termios.c_lflag &= ~ECHO;   // disable echo by the terminal
    new_termios.c_lflag &= ~ISIG;   // disable keyboard signals (^C, ^\, ^Z)
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    std::setvbuf(stdin, NULL, _IONBF, 0);

    struct winsize term_size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);
    screen_.resize(Size{term_size.ws_col, term_size.ws_row});

    escape::write("\033[" "?1049h");
    escape::write("\033[" "?25l");

    auto& events = pimpl_->events;
    events.bind_event("enter", KeySet{charo::KEYS::LOWERCASE_L, charo::KEYS::UPPERCASE_L});
    events.bind_event("exit", KeySet{charo::KEYS::LOWERCASE_Q, charo::KEYS::UPPERCASE_Q, charo::KEYS::ESC});
    events.bind_event("up", KeySet{charo::KEYS::LOWERCASE_J, charo::KEYS::UPPERCASE_J});
    events.bind_event("down", KeySet{charo::KEYS::LOWERCASE_K, charo::KEYS::UPPERCASE_K});

    context_.layout = &screen_.layout();
    default_colortheme(style_);
}

charo::Terminal::~Terminal() {
    escape::write("\033[?7h");
    escape::write("\033[" "?1049l");
    escape::write("\033[" "?25h");
    escape::flush();
    tcsetattr(STDIN_FILENO, TCSANOW, &pimpl_->orig_termios);
}

auto charo::Terminal::read_event(std::string_view name) const -> bool {
    return pimpl_->events.read_event(name);
}

auto charo::read_event(std::string_view name) -> bool {
    return get_terminal().read_event(name);
}

bool charo::Terminal::refresh() {
    if (context_.layout_depth)
        throw std::logic_error("Missing end_group");

    if (read_event("exit")) {
        return false;
    }

    auto const& deferred_callbacks = context_.deferred_callbacks;
    for (auto const& callback : deferred_callbacks)
        callback();
    
    draw_screen_diff(screen_.screen_diff());

    context_.clear();

    screen_.next_frame();

    pimpl_->events.process();

    return true;
}

auto charo::Terminal::size() const -> Size {
    return screen_.size();
}
auto charo::Terminal::screen() -> Screen& {
    return screen_;
}
auto charo::Terminal::context() -> Context& {
    return context_;
}
auto charo::Terminal::style() -> Style& {
    return style_;
}

void charo::Terminal::move_cursor(Pos pos) {
    escape::write(escape::get_escape(pos));
    escape::flush();
}