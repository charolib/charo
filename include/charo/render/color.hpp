#pragma once

#include <cstdint>

namespace charo {

struct ColorRGB {
public:
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

public:
    constexpr friend bool operator==(ColorRGB const& lhs, ColorRGB const& rhs) {
        return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b);
    }

    constexpr friend bool operator!=(ColorRGB const& lhs, ColorRGB const& rhs) {
        return (lhs.r != rhs.r) && (lhs.g != rhs.g) && (lhs.b != rhs.b);
    }
};

template <typename ColorType>
struct FGColor : public ColorType {
    constexpr FGColor() = default;
    constexpr FGColor(ColorType col) : ColorType{col} {
        is_default = false;
    }
    bool is_default = true;
};

template <typename ColorType>
struct BGColor : public ColorType {
    constexpr BGColor() = default;
    constexpr BGColor(ColorType col) : ColorType{col} {
        is_default = false;
    }
    bool is_default = true;
};

template <>
struct FGColor<ColorRGB> : public ColorRGB {
    constexpr FGColor() = default;
    constexpr FGColor(ColorRGB col) : ColorRGB{col} {
        is_default = false;
    }
    constexpr FGColor(uint8_t r, uint8_t g, uint8_t b) : ColorRGB(r, g, b) {
        is_default = false;
    }

    bool is_default = true;
};

template <>
struct BGColor<ColorRGB> : public ColorRGB {
    constexpr BGColor() = default;
    constexpr BGColor(ColorRGB col) : ColorRGB{col} {
        is_default = false;
    }
    constexpr BGColor(uint8_t r, uint8_t g, uint8_t b) : ColorRGB(r, g, b) {
        is_default = false;
    }

    bool is_default = true;
};
}