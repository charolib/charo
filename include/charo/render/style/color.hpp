#pragma once

#include <cstdint>

namespace charo {

struct Color16 {

};

struct ColorRGB {
public:
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

public:
    friend bool operator==(ColorRGB const& lhs, ColorRGB const& rhs) {
        return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b);
    }

    friend bool operator!=(ColorRGB const& lhs, ColorRGB const& rhs) {
        return (lhs.r != rhs.r) && (lhs.g != rhs.g) && (lhs.b != rhs.b);
    }
};

template <typename ColorType>
struct FGColor : public ColorType {};

template <typename ColorType>
struct BGColor : public ColorType {};
}