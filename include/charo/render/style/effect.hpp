#pragma once

#include <cstdint>
namespace charo {

using Effects = uint16_t;

namespace EffectFlags {
enum Flags : uint16_t {
    NONE                = 0,
    STANDOUT            = 1 << 0,
    BOLD                = 1 << 1,
    ITALIC              = 1 << 2,
    DIM                 = 1 << 3,
    UNDERLINE           = 1 << 4,
    BLINK               = 1 << 5,
    INVERSE             = 1 << 6,
    HIDDEN              = 1 << 7,
    CROSSED_OUT         = 1 << 8,
    DOUBLE_UNDERLINE    = 1 << 9
};
}
}