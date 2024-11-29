#pragma once
#include <charo/common_types.hpp>
#include <charo/internal/screen.hpp>
#include <charo/internal/context.hpp>
#include <charo/internal/style.hpp>
#include <memory>

namespace charo {

class Terminal {
private:
    // enum class COLOR_MODES {
    //     COLOR16,
    //     COLORRGB
    // };
    // COLOR_MODES colormode = COLOR_MODES::COLORRGB;
    Screen screen_;
    Context context_;
    Style style_;

    struct impl;
    std::unique_ptr<impl> pimpl_;
    //  EventsSystem events;
    //  struct termios orig_termios;

public:
    [[nodiscard]] static auto instance() -> Terminal& {
        static Terminal term;
        return term;
    }

    Terminal();
    ~Terminal();

    [[nodiscard]] auto read_event(std::string_view name) const -> bool;

    bool refresh();

    [[nodiscard]] auto size() const -> Size;
    [[nodiscard]] auto screen() -> Screen&;
    [[nodiscard]] auto layout() -> Layout;
    [[nodiscard]] auto context() -> Context&;
    [[nodiscard]] auto style() -> Style&;

    void move_cursor(Pos pos);
};

[[nodiscard, maybe_unused]] static auto get_terminal() -> Terminal& {
    return Terminal::instance();
}
[[nodiscard, maybe_unused]] static auto get_current_screen() -> Screen& {
    return get_terminal().screen();
}
[[nodiscard, maybe_unused]] static auto get_current_context() -> Context& {
    return get_terminal().context();
}
[[nodiscard, maybe_unused]] static auto get_current_style() -> Style& {
    return get_terminal().style();
}

auto read_event(std::string_view name) -> bool;

}