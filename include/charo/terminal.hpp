#pragma once
#include "charo/context.hpp"
#include "charo/render/screen.hpp"
#include <charo/render/common_types.hpp>

#include <memory>

namespace charo {

class Terminal {
private:
    // enum class COLOR_MODES {
    //     COLOR16,
    //     COLORRGB
    // };
    // COLOR_MODES colormode = COLOR_MODES::COLORRGB;
    Screen screen;
    CharoContext context;

    struct impl;
    std::unique_ptr<impl> pimpl;

public:
    [[nodiscard]] static auto instance() -> Terminal& {
        static Terminal term;
        return term;
    }

    Terminal();
    ~Terminal();

    [[nodiscard]] auto read_event(std::string_view name) const -> bool;

    void refresh();

    [[nodiscard]] auto size() const -> Size;
    [[nodiscard]] auto current_screen() -> Screen&;
    [[nodiscard]] auto current_context() -> CharoContext&;

    void move_cursor(Pos pos);
};

[[nodiscard, maybe_unused]] static auto get_terminal() -> Terminal& {
    return Terminal::instance();
}

[[nodiscard, maybe_unused]] static auto get_current_screen() -> Screen& {
    return get_terminal().current_screen();
}

[[nodiscard, maybe_unused]] static auto get_current_context() -> CharoContext& {
    return get_terminal().current_context();
}

auto read_event(std::string_view name) -> bool;

}