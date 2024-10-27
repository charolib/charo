#pragma once

#include "../style/style.hpp"

namespace charo {

struct Glyph {
public:
    using data_t = char32_t;

    data_t data = U'\0';
    Style style;

public:
    Glyph() = default;
    explicit Glyph(data_t symbol) : data{symbol} {}
    explicit Glyph(char symbol) : data{static_cast<data_t>(symbol)} {}

    friend bool operator==(Glyph const& lhs, Glyph const& rhs) {
        return (lhs.data == rhs.data) && (lhs.style == rhs.style);
    }

    friend bool operator!=(Glyph const& lhs, Glyph const& rhs) {
        return (lhs.data != rhs.data) && (lhs.style != rhs.style);
    }
};

}