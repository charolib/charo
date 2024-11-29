#pragma once
#include <charo/internal/layout.hpp>
#include <charo/common_types.hpp>
#include <functional>
#include <vector>

namespace charo {

struct Context {
public:
    using hash_t = size_t;

public:
    std::vector<hash_t> widgets;
    std::vector<std::function<void()>> deferred_callbacks;

    Layout* layout = nullptr;
    Layout* previous_layout = nullptr;
    size_t layout_depth = 0;
    Size max_layout_item_size;

    Pos cursor_pos;
    Pos last_layout_pos;
    Size last_item_size;
    size_t last_item_id = 0;
    size_t focused_item_id = 0;
    hash_t focused_item = 0;
    float delta_time = 0.f;

public:
    void clear() {
        previous_layout = nullptr;
        last_layout_pos = Pos{0, 0};
        last_item_id = 0;
        last_item_size = Size{0, 0};
        cursor_pos = Pos{0, 0};
        widgets.clear();
        deferred_callbacks.clear();
    };
};

}