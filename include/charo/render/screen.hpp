#pragma once

#include "base/glyphspace.hpp"

#include <utility>
#include <vector>

namespace charo {


class Screen {
public:
    using ScreenDiffUnit = std::pair<Pos, Glyph>;
    using ScreenDiff = std::vector<ScreenDiffUnit>;

private:
    GlyphSpace current;
    GlyphSpace next;

public:
    Screen();
    explicit Screen(Size size);

    void resize(Size size);
    void next_frame() noexcept;

    [[nodiscard]] auto size() const -> Size;
    [[nodiscard]] auto screen_diff() const -> ScreenDiff;
    
};

void draw_screen_diff(Screen::ScreenDiff const& screen_diff);

}