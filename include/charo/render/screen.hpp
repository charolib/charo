#pragma once

#include "glyphspace.hpp"

#include <string_view>
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
    [[nodiscard]] auto in_bounds(Pos pos) const -> bool;

    void draw(Pos pos, Glyph const& glyph);
    void draw(Pos pos, char str, Style const& style = {});
    void draw(Pos pos, char32_t str, Style const& style = {});
    void draw(Pos pos, std::string_view str, Style const& style = {});
    void draw(Pos pos, std::u32string_view str, Style const& style = {});
    
};

void draw_screen_diff(Screen::ScreenDiff const& screen_diff);



}