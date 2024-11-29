#include <charo/widgets.hpp>

void charo::slider(std::string_view name, float& value, float min, float max) {
    WidgetBuilder builder;

    // before doing this
    // Do layouts
    // Do arrangments

    Size widget_size;
    // widget_size.w = get_available_space().w;
    widget_size.y = calc_size(name).y;

    
    // builder.name(name);
    // builder.size(calc_size(text));
    // builder.on_event("enter", [&value] { value = !value; });

    // Widget checkbox(builder);

    // constexpr auto default_checkmark = U"☐";
    // constexpr auto actived_checkmark = U"🗹";
    // auto const current_checkmark = value ? actived_checkmark : default_checkmark;

    // checkbox.draw(Pos{0, 0}, current_checkmark);
    // checkbox.draw(Pos(calc_size(actived_checkmark).w, 0), text);
}