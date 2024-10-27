#include <charo/render/screen.hpp>
#include <charo/render/base/converter.hpp>
#include <charo/render/escape.hpp>

#include <string>

charo::Screen::Screen() : current{Size{}}, next{Size{}} {}
charo::Screen::Screen(charo::Size size) : current{size}, next{size} {}

void charo::Screen::resize(charo::Size size) {
    current.resize(size);
    next.resize(size);
}

void charo::Screen::next_frame() noexcept {
    current = std::move(next);
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

void charo::draw_screen_diff(Screen::ScreenDiff const& screen_diff) {
    std::string out;
    constexpr auto approx_sdiffunit_str_size = 10;
    out.reserve(screen_diff.size() * approx_sdiffunit_str_size);

    for (auto const& [pos, glyph] : screen_diff) {
        out.append(escape::get_escape(pos));
        out.append(escape::get_escape(glyph.style.effects));
        out.append(escape::get_escape(glyph.style.fg));
        out.append(escape::get_escape(glyph.style.bg));
        out.append(to_utf8(glyph.data));
    }

    escape::write(out);
}