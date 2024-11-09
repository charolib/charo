#include <charo/render/screen.hpp>
#include <charo/render/converter.hpp>
#include <charo/render/escape.hpp>
#include <string>

charo::Screen::Screen() : current{Size{}}, next{Size{}} {}
charo::Screen::Screen(charo::Size size) : current{size}, next{size} {}

void charo::Screen::resize(charo::Size size) {
    current.resize(size);
    next.resize(size);
}

void charo::Screen::next_frame() noexcept {
    current = next;
    next.reset();
}

auto charo::Screen::size() const -> Size {
    return current.size();
}

auto charo::Screen::screen_diff() const -> ScreenDiff {
    ScreenDiff diff;
    Pos pos;

    for (Glyph const& glyph : next) { 
        if (glyph != current[pos]) {
            diff.emplace_back(pos, glyph);
        }
        pos = next_pos(pos, size());
    }

    return diff;
}

auto charo::Screen::in_bounds(Pos pos) const -> bool {
    return next.in_bounds(pos);
}

void charo::Screen::draw(Pos pos, Glyph const& glyph) {
    next[pos] = glyph;
}

void charo::Screen::draw(Pos pos, char const ch, Style const& style) {
    draw(pos, Glyph{ch, style});
}

void charo::Screen::draw(Pos pos, char32_t ch, Style const& style) {
    draw(pos, Glyph{ch, style});
}

void charo::Screen::draw(Pos pos, std::string_view str, Style const& style) {
    for (auto const ch : str) {
        if (!next.in_bounds(pos)) 
            break;

        draw(pos, Glyph{ch, style});
        pos.x++;
    }
}

void charo::Screen::draw(Pos pos, std::u32string_view str, Style const& style) {
    for (auto const ch : str) {
        if (!next.in_bounds(pos)) 
            break;

        draw(pos, Glyph{ch, style});
        pos.x++;

        if (ch > 0xFFFF) {
            draw(pos, Glyph{'\0', style});
            pos.x++;
        }
    }
}

void charo::draw_screen_diff(Screen::ScreenDiff const& screen_diff) {
    std::string out;
    constexpr auto approx_sdiffunit_str_size = 10;
    out.reserve(screen_diff.size() * approx_sdiffunit_str_size);

    for (auto const& [pos, glyph] : screen_diff) {
        out.append(escape::get_escape(pos));
        out.append(escape::get_escape(glyph.style.effects));
        if (!glyph.style.fg.is_default)
            out.append(escape::get_escape(glyph.style.fg));
        if (!glyph.style.bg.is_default)
            out.append(escape::get_escape(glyph.style.bg));
        out.append(to_utf8(glyph.data));
        out.append("\033[0m");
    }

    escape::write(out);
    escape::flush();
}
