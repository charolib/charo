#pragma once

#include <cstdint>
#include <string_view>

namespace charo {

struct Pos;

struct Size {
public:
    using data_t = uint16_t;

    data_t w{0};
    data_t h{0};

public:
    constexpr Size() = default;
    constexpr Size(data_t width, data_t height) : w{width}, h{height} {}

    [[nodiscard]] constexpr auto has_value() -> bool {
        return w != 0 && h != 0;
    }
    [[nodiscard]] constexpr auto count() const -> data_t {
        return w*h;
    }

    constexpr operator Pos () const;

    constexpr auto operator<=>(const Size& other) const = default;

    constexpr auto operator+=(data_t const& data) -> Size& {
        w += data;
        h += data;
        return *this;
    }
    constexpr auto operator-=(data_t const& data) -> Size& {
        w -= data;
        h -= data;
        return *this;
    }

    constexpr auto operator+=(Pos const& pos) -> Size&;
    constexpr auto operator-=(Pos const& pos) -> Size&;

    friend constexpr bool operator==(Size const& lhs, Size const& rhs) {
        return (lhs.w == rhs.w) && (lhs.h == rhs.h);
    }
    friend constexpr bool operator!=(Size const& lhs, Size const& rhs) {
        return (lhs.w != rhs.w) || (lhs.h != rhs.h);
    }

    friend constexpr auto operator+(Size const& lhs, Size const& rhs) -> Size {
        return Size(lhs.w + rhs.w, lhs.h + rhs.h);
    }
    friend constexpr auto operator-(Size const& lhs, Size const& rhs) -> Size {
        return Size(lhs.w - rhs.w, lhs.h - rhs.h);
    }

    friend constexpr auto operator/(Size const& size, data_t data) -> Size {
        return Size(size.w / data, size.h / data);
    }
};

[[nodiscard]] constexpr auto calc_str_size(std::string_view str) -> Size {
    return Size{static_cast<Size::data_t>(str.length()), 1};
}

[[nodiscard]] constexpr auto calc_str_size(std::u32string_view str) -> Size {
    Size out{0, 1};
    for (char32_t const ch : str) {
        out.w++;
        if (ch > 0xFFFF) {
            out.w++;
        }
    }

    return out;
}

struct Pos {
public:
    using data_t = uint16_t;

    data_t x{0};
    data_t y{0};

public:
    constexpr Pos() = default;
    constexpr Pos(data_t horizontal, data_t vertical) : x{horizontal}, y{vertical} {}

    constexpr operator Size () const {
        return Size(x, y);
    }

    constexpr auto operator<=>(const Pos& other) const = default;

    constexpr auto operator+=(data_t const& data) -> Pos& {
        x += data;
        y += data;
        return *this;
    }
    constexpr auto operator-=(data_t const& data) -> Pos& {
        x -= data;
        y -= data;
        return *this;
    }

    constexpr auto operator+=(Size const& size) -> Pos& {
        x += size.w;
        y += size.h;
        return *this;
    }
    constexpr auto operator-=(Size const& size) -> Pos& {
        x -= size.w;
        y -= size.h;
        return *this;
    }

    friend constexpr auto operator+(Pos const& lhs, Pos const& rhs) -> Pos {
        return Pos(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend constexpr auto operator-(Pos const& lhs, Pos const& rhs) -> Pos {
        return Pos(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend constexpr auto operator+(Pos const& pos, Size const& size) -> Pos {
        return Pos(pos.x + size.w, pos.y + size.h);
    }
    friend constexpr auto operator-(Pos const& pos, Size const& size) -> Pos {
        return Pos(pos.x - size.w, pos.y - size.h);
    }
};

constexpr Size::operator Pos () const {
    return Pos(w, h);
}

constexpr auto Size::operator+=(Pos const& pos) -> Size& {
    w += pos.x;
    h += pos.y;
    return *this;
}
constexpr auto Size::operator-=(Pos const& pos) -> Size& {
    w -= pos.x;
    h -= pos.y;
    return *this;
}

[[nodiscard]] constexpr auto next_pos(Pos const& pos, Size const& size) -> Pos {
    return (pos.x + 1) < size.w ? Pos{static_cast<Pos::data_t>(pos.x + 1), pos.y} : Pos{0, static_cast<Pos::data_t>(pos.y + 1)};
}

}