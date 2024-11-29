#pragma once
#include <charo/internal/glyphspace.hpp>
#include <charo/internal/layout.hpp>
#include <string_view>
#include <utility>
#include <vector>

namespace charo {

class Screen {
public:
    using ScreenDiffUnit = std::pair<Pos, Glyph>;
    using ScreenDiff = std::vector<ScreenDiffUnit>;

private:
    GlyphSpace current_;
    GlyphSpace next_;
    Layout layout_;

public:
    Screen() = default;
    explicit Screen(Size size);

    void resize(Size size);
    void next_frame() noexcept;

    void redraw();

    [[nodiscard]] auto size() const -> Size;
    [[nodiscard]] auto layout() -> Layout&;
    [[nodiscard]] auto screen_diff() const -> ScreenDiff;
    [[nodiscard]] auto in_bounds(Pos pos) const -> bool;

    void draw(Pos pos, Glyph const& glyph);
    void draw(Pos pos, char str, GlyphStyle const& style = {});
    void draw(Pos pos, char32_t str, GlyphStyle const& style = {});
    void draw(Pos pos, std::string_view str, GlyphStyle const& style = {});
    void draw(Pos pos, std::u32string_view str, GlyphStyle const& style = {});

    void bg_rect(Pos pos, Size size, ColorRGB color);
    // rect, rounded_rect, circle, triangle, line, border
    
};

void draw_screen_diff(Screen::ScreenDiff const& screen_diff);

}