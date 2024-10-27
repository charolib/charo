#pragma once

#include "key.hpp"
#include <map>
#include <string>
#include <vector>

namespace charo {

struct KeySet {
public:
    std::vector<KEYS> keys;
    const bool combo;

public:
    KeySet(std::initializer_list<KEYS> init, bool is_combo = false) : keys(init), combo(is_combo) {}
};

class EventsSystem {
public:
    using Eventmap = std::map<std::string, KeySet>;

private:
    Eventmap eventmap;
    KeyHandler keyhandler;

public:
    void process();

    void bind_event(std::string_view name, KeySet keyset);
    void rebind_event(std::string_view name, KeySet new_keyset);
    void unbind_event(std::string_view name);

    [[nodiscard]] auto read_event(std::string_view name) const -> bool;
};

}