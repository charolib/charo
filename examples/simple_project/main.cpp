#include <charo/charo.hpp>
#include <thread>

int main() {
    auto& term = charo::get_terminal();

    auto previous_time = std::chrono::high_resolution_clock::now();

    constexpr int target_fps = 60;
    constexpr auto frame_duration = std::chrono::milliseconds(1000 / target_fps);

    while (1) {
        auto frame_start = std::chrono::high_resolution_clock::now();

        charo::text("text");
        charo::text("fsdakjhfsdklfhjdsjhfds;hjkfshj;dkghjkdsjkg;jdksfghkgkbwelgfglwjhefvgewjgflyjewfgewylfvwleyufvyuweuyvofvyuwevuyfwueyfuvywefuvyewfewfwsefwsfs");
        charo::text_styled(U"🍌ss", charo::Style{.fg = {255, 55, 55}, .effects = charo::FLAG_BOLD | charo::FLAG_BLINK});

        charo::button("button");
        charo::button("pressed_button");

        static bool checkbox = false;
        static bool a_checkbox = true;
        charo::checkbox("checkbox", checkbox);
        charo::checkbox("actived_checkbox", a_checkbox);

        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta_timez = current_time - previous_time;
        charo::get_current_context().delta_time = delta_timez.count();
        previous_time = current_time;

        term.refresh();

        auto frame_end = std::chrono::high_resolution_clock::now();
        auto work_duration = frame_end - frame_start;
        if (work_duration < frame_duration) {
            std::this_thread::sleep_for(frame_duration - work_duration);
        }
    }
    return 0;
}