#include <charo/internal/screen.hpp>
#include <charo/internal/converter.hpp>
#include <charo/internal/escape.hpp>
#include <string>

charo::Screen::Screen(charo::Size size) : current_{size}, next_{size}, layout_{size} {}

void charo::Screen::resize(charo::Size size) {
    current_.resize(size);
    next_.resize(size);
    layout_.resize(size);
}

void charo::Screen::next_frame() noexcept {
    current_ = next_;
    next_.reset();
}

auto charo::Screen::size() const -> Size {
    return current_.size();
}
auto charo::Screen::layout() -> Layout& {
    return layout_;
}

auto charo::Screen::screen_diff() const -> ScreenDiff {
    ScreenDiff diff;
    Pos pos;

    for (Glyph const& glyph : next_) { 
        if (glyph != current_[pos]) {
            diff.emplace_back(pos, glyph);
        }
        pos = next_pos(pos, size());
    }

    return diff;
}

auto charo::Screen::in_bounds(Pos pos) const -> bool {
    return next_.in_bounds(pos);
}

void charo::Screen::draw(Pos pos, Glyph const& glyph) {
    auto& current_ch = next_[pos];

    current_ch.data = glyph.data;
    if (!(glyph.style.fg.is_default)) current_ch.style.fg = glyph.style.fg;
    if (!(glyph.style.bg.is_default)) current_ch.style.bg = glyph.style.bg;
    if (glyph.style.effects) current_ch.style.effects = glyph.style.effects;
}

void charo::Screen::draw(Pos pos, char const ch, GlyphStyle const& style) {
    draw(pos, Glyph{ch, style});
}

void charo::Screen::draw(Pos pos, char32_t ch, GlyphStyle const& style) {
    draw(pos, Glyph{ch, style});
}

void charo::Screen::draw(Pos pos, std::string_view str, GlyphStyle const& style) {
    for (auto const ch : str) {
        if (!next_.in_bounds(pos)) 
            break;

        draw(pos, Glyph{ch, style});
        pos.x++;
    }
}

void charo::Screen::draw(Pos pos, std::u32string_view str, GlyphStyle const& style) {
    for (auto const ch : str) {
        if (!next_.in_bounds(pos)) 
            break;

        if (ch > 0xFFFF) {
            draw(pos, Glyph{ch, style});
            pos.x++;
            draw(pos, Glyph{'\0', style});
            pos.x++;
        } else {
            draw(pos, Glyph{ch, style});
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

void charo::Screen::redraw() {
    std::string out;
    constexpr auto approx_sdiffunit_str_size = 10;
    out.reserve(next_.height() * next_.width() * approx_sdiffunit_str_size);

    Pos pos(0, 0);
    for (auto const& glyph : next_) {
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