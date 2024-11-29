#pragma once
#include <cstdint>
#include <string_view>

namespace charo {

struct Vec2 {
public:
    using data_t = uint16_t;

    data_t x{0};
    data_t y{0};

public:
    constexpr Vec2() = default;
    constexpr Vec2(data_t x_cord, data_t y_cord) : x{x_cord}, y{y_cord} {}

    [[nodiscard]] constexpr auto has_value() const -> bool {
        return x != 0 && y != 0;
    }
    [[nodiscard]] constexpr auto count() const -> data_t {
        return x*y;
    }

    constexpr auto operator<=>(const Vec2& other) const = default;

    constexpr auto operator+=(data_t const& data) -> Vec2& {
        x += data;
        y += data;
        return *this;
    }
    constexpr auto operator-=(data_t const& data) -> Vec2& {
        x -= data;
        y -= data;
        return *this;
    }

    constexpr auto operator+=(Vec2 const& other) -> Vec2& {
        x += other.x;
        y += other.y;
        return *this;
    }
    constexpr auto operator-=(Vec2 const& other) -> Vec2&{
        x -= other.x;
        y -= other.y;
        return *this;
    }

    friend constexpr bool operator==(Vec2 const& lhs, Vec2 const& rhs) {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }
    friend constexpr bool operator!=(Vec2 const& lhs, Vec2 const& rhs) {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }

    friend constexpr auto operator+(Vec2 const& lhs, Vec2 const& rhs) -> Vec2 {
        return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend constexpr auto operator-(Vec2 const& lhs, Vec2 const& rhs) -> Vec2 {
        return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend constexpr auto operator/(Vec2 const& size, data_t data) -> Vec2 {
        return Vec2(size.x / data, size.y / data);
    }
};

using Size = Vec2;
using Pos = Vec2;

[[nodiscard]] constexpr auto calc_size(std::string_view str) -> Size {
    return Size{static_cast<Size::data_t>(str.length()), 1};
}

[[nodiscard]] constexpr auto calc_size(std::u32string_view str) -> Size {
    Size out{0, 1};
    for (char32_t const ch : str) {
        out.x++;
        if (ch > 0xFFFF) {
            out.x++;
        }
    }

    return out;
}

[[nodiscard]] constexpr auto calc_width(std::string_view str) -> Size::data_t {
    return str.length();
}
[[nodiscard]] constexpr auto calc_width(std::u32string_view str) -> Size::data_t {
    Size::data_t out = 0;
    for (char32_t const ch : str) {
        out++;
        if (ch > 0xFFFF) {
            out++;
        }
    }
    return out;
}

[[nodiscard]] constexpr auto calc_height([[maybe_unused]] std::string_view str) -> Size::data_t {
    return 1;
}
[[nodiscard]] constexpr auto calc_height([[maybe_unused]] std::u32string_view str) -> Size::data_t {
    return 1;
}

[[nodiscard]] constexpr auto next_pos(Pos const& pos, Size const& size) -> Pos {
    return (pos.x + 1) < size.x ? Pos{static_cast<Pos::data_t>(pos.x + 1), pos.y} : Pos{0, static_cast<Pos::data_t>(pos.y + 1)};
}

[[nodiscard]] constexpr auto calc_center(Size element, Size rect) -> Pos {
    Pos out(0, 0);
    if (rect.x > element.x)
        out.x = (rect.x - element.x) / 2;
    if (rect.y > element.y)
        out.y = (rect.y - element.y) / 2;
    return out;
}

}