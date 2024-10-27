#pragma once

#include "color.hpp"
#include "effect.hpp"

namespace charo {

struct Style {
    FGColor<ColorRGB> fg;
    BGColor<ColorRGB> bg;
    Effects effects = EffectFlags::NONE;

    friend bool operator==(Style const& lhs, Style const& rhs) {
        return (lhs.fg == rhs.fg) && (lhs.bg == rhs.bg) && (lhs.effects == rhs.effects);
    }

    friend bool operator!=(Style const& lhs, Style const& rhs) {
        return (lhs.fg != rhs.fg) && (lhs.bg != rhs.bg) && (lhs.effects != rhs.effects);
    }
};

}