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


using Flags = uint16_t;
enum FlagsEnum : uint16_t {
    FLAG_NONE                = 0,
    FLAG_STANDOUT            = 1 << 0,
    FLAG_BOLD                = 1 << 1,
    FLAG_ITALIC              = 1 << 2,
    FLAG_DIM                 = 1 << 3,
    FLAG_UNDERLINE           = 1 << 4,
    FLAG_BLINK               = 1 << 5,
    FLAG_INVERSE             = 1 << 6,
    FLAG_HIDDEN              = 1 << 7,
    FLAG_CROSSED_OUT         = 1 << 8,
    FLAG_DOUBLE_UNDERLINE    = 1 << 9
};


struct GlyphStyle {
    FGColor<ColorRGB> fg = {};
    BGColor<ColorRGB> bg = {};
    Flags effects = FLAG_NONE;

    [[nodiscard]] constexpr auto is_empty() const -> bool {
        return fg.is_default && bg.is_default && effects == FLAG_NONE;
    }

    friend constexpr bool operator==(GlyphStyle const& lhs, GlyphStyle const& rhs) {
        return (lhs.fg == rhs.fg) && (lhs.bg == rhs.bg) && (lhs.effects == rhs.effects);
    }

    friend constexpr bool operator!=(GlyphStyle const& lhs, GlyphStyle const& rhs) {
        return (lhs.fg != rhs.fg) || (lhs.bg != rhs.bg) || (lhs.effects != rhs.effects);
    }
};

}