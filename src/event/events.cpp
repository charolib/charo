#include <charo/event/events.hpp>
#include <iostream>

void charo::EventsSystem::process() {
    keyhandler.handle();
}

void charo::EventsSystem::bind_event(std::string_view name, KeySet keyset) {
    eventmap.emplace(name, keyset);
}

void charo::EventsSystem::rebind_event(std::string_view name, KeySet new_keyset) {
    unbind_event(name);
    bind_event(name, new_keyset);
}

void charo::EventsSystem::unbind_event(std::string_view name) {
    eventmap.erase(name.data());
}

[[nodiscard]] auto charo::EventsSystem::read_event(std::string_view name) const -> bool {
    KeySet const& event_keyset = eventmap.at(name.data());
    KEYS const pressed_key = keyhandler.get_pressed();

    if (event_keyset.combo) {
        auto const history = keyhandler.get_combo(event_keyset.keys.size());
        return event_keyset.keys == std::vector<KEYS>(history.rbegin(), history.rend());
    } else {
        for (KEYS const key : event_keyset.keys) {
            if (pressed_key == key)
                return true;
        }
    }


    return false;
}