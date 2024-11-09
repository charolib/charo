#include <charo/render/widgets.hpp>

void charo::checkbox(std::string_view text, bool& value) {
    WidgetBuilder builder;
    builder.name(text);
    builder.size(calc_str_size(text));
    builder.on_event("enter", [&value] { value = !value; });

    Widget checkbox(builder);

    constexpr auto default_checkmark = U"☐";
    constexpr auto actived_checkmark = U"🗹";
    auto const current_checkmark = value ? actived_checkmark : default_checkmark;

    checkbox.draw(Pos{0, 0}, current_checkmark);
    checkbox.draw(Pos(calc_str_size(actived_checkmark).w, 0), text);
}