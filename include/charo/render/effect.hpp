#pragma once

#include <cstdint>
namespace charo {

using Effects = uint16_t;

enum Flags : uint16_t {
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
}