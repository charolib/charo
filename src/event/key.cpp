#include <charo/event/key.hpp>
#include <iostream>
#include <sys/select.h>
#include <unistd.h>

void charo::KeyHandler::handle() {
    const auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - last_update) >= combo_timeout) {
        combo.clear();
    }

    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(STDIN_FILENO, &read_set);
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 500;

    current_key = KEYS::NUL;
    if (select(STDIN_FILENO + 1, &read_set, NULL, NULL, &timeout) > 0)
    {
        char input;
        read(STDIN_FILENO, &input, 1);
        current_key = static_cast<KEYS>(input);

        combo.push_front(current_key);

        last_update = std::chrono::steady_clock::now();
        if (combo.size() >= combo_size) {
            combo.pop_back();
        }
    }
}

auto charo::KeyHandler::get_pressed() const -> KEYS {
    return current_key;
}

auto charo::KeyHandler::get_combo(size_t count) const -> std::vector<KEYS> {
    auto const count_clamped = std::min(combo.size(), std::min(count, combo_size));
    return std::vector<KEYS>(combo.begin(), combo.begin() + count_clamped);
}