#include <charo/internal/screen.hpp>

void charo::Screen::bg_rect(Pos pos, Size size, ColorRGB color) {
    for (Pos cursor{0, 0};; cursor = next_pos(cursor, size)) {
        Glyph& current_glyph = next_[pos + cursor];
        if (current_glyph.style.bg.is_default) {
            current_glyph.style.bg = color;
        }
        if (cursor + Pos{1, 1} == size)
            break;
    }
}