#pragma once
#include <charo/render/base/common_types.hpp>

#include <memory>

namespace charo {

class Terminal {
private:
    // enum class COLOR_MODES {
    //     COLOR16,
    //     COLORRGB
    // };
    // COLOR_MODES colormode = COLOR_MODES::COLORRGB;
    struct impl;
    std::unique_ptr<impl> pimpl;

public:
    Terminal();
    ~Terminal();

    [[nodiscard]] auto read_event(std::string_view name) const -> bool;

    void refresh();

    [[nodiscard]] auto size() const -> Size;

    void move_cursor(Pos pos);
};

}