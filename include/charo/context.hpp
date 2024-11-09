#pragma once

#include "render/common_types.hpp"
#include <functional>
#include <vector>

namespace charo {

struct CharoContext {
public:
    using hash_t = size_t;

public:
    Pos cursor_pos;

    float delta_time = 0.f;

    size_t last_item_id = 0;
    Size last_item_size;

    hash_t focused_item = 0;
    size_t focused_item_id = 0;

    std::vector<hash_t> widgets;

    std::vector<std::function<void()>> deferred_callbacks;
public:
    void clear() {
        last_item_id = 0;
        last_item_size = Size{0, 0};
        cursor_pos = Pos{0, 0};
        widgets.clear();
        deferred_callbacks.clear();
    };
};

}