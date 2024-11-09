#pragma once

#include "color.hpp"
#include "effect.hpp"

namespace charo {

struct Style {
    FGColor<ColorRGB> fg = {};
    BGColor<ColorRGB> bg = {};
    Effects effects = FLAG_NONE;

    [[nodiscard]] constexpr auto is_empty() -> bool {
        return fg.is_default && bg.is_default && effects == FLAG_NONE;
    }

    friend constexpr bool operator==(Style const& lhs, Style const& rhs) {
        return (lhs.fg == rhs.fg) && (lhs.bg == rhs.bg) && (lhs.effects == rhs.effects);
    }

    friend constexpr bool operator!=(Style const& lhs, Style const& rhs) {
        return (lhs.fg != rhs.fg) || (lhs.bg != rhs.bg) || (lhs.effects != rhs.effects);
    }
};

}