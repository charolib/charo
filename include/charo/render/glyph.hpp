#pragma once

#include "style.hpp"

namespace charo {

struct Glyph {
public:
    using data_t = char32_t;

    data_t data = U'\0';
    Style style;

public:
    constexpr Glyph() = default;
    explicit constexpr Glyph(data_t symbol) : data{symbol} {}
    explicit constexpr Glyph(char symbol) : data{static_cast<data_t>(symbol)} {}
    constexpr Glyph(data_t symbol, Style styles) : data{symbol}, style{styles} {}
    constexpr Glyph(char symbol, Style styles) : data{static_cast<data_t>(symbol)}, style{styles} {}

    constexpr friend bool operator==(Glyph const& lhs, Glyph const& rhs) {
        return (lhs.data == rhs.data) && (lhs.style == rhs.style);
    }

    constexpr friend bool operator!=(Glyph const& lhs, Glyph const& rhs) {
        return (lhs.data != rhs.data) || (lhs.style != rhs.style);
    }
};

}