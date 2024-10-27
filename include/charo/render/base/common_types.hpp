#pragma once

#include <cstdint>

namespace charo {

struct Size {
public:
    using data_t = uint16_t;

    data_t w{0};
    data_t h{0};

public:
    constexpr Size() = default;
    constexpr Size(data_t width, data_t height) : w{width}, h{height} {}

    [[nodiscard]] auto count() const -> data_t {
        return w*h;
    } 
};


struct Pos {
public:
    using data_t = uint16_t;

    data_t x{0};
    data_t y{0};

public:
    constexpr Pos() = default;
    constexpr Pos(data_t horizontal, data_t vertical) : x{horizontal}, y{vertical} {}
};

[[nodiscard]] constexpr auto next_pos(Pos const& pos, Size const& size) -> Pos {
    return (pos.x + 1) < size.w ? Pos{static_cast<Pos::data_t>(pos.x + 1), pos.y} : Pos{0, static_cast<Pos::data_t>(pos.y + 1)};
}
}