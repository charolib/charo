#pragma once
#include <charo/glyphstyle.hpp>
#include <charo/common_types.hpp>
#include <map>

namespace charo {

enum class COLORS {
    GROUP_BG
};

struct Style {
    Size item_inner_padding{1, 1};
    Size item_spacing{1, 1};

    std::map<COLORS, ColorRGB> colors;
};

inline void default_colortheme(Style& style) {
    auto& colors = style.colors;

    colors[COLORS::GROUP_BG] = {125, 155, 55};
}
}