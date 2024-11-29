#include <charo/widgets.hpp>
#include <charo/terminal.hpp>

void charo::checkbox(std::string_view label, bool& value) {
    constexpr auto default_checkmark(U"☐");
    constexpr auto actived_checkmark(U"☑");
    auto const current_checkmark = value ? actived_checkmark : default_checkmark;
    
    Style const& style = get_current_style();

    Size const label_size = calc_size(label);
    auto const checkmark_width = calc_width(current_checkmark);
    Size const full_size = Size(checkmark_width + style.item_inner_padding.x, 0) + label_size;

    WidgetBuilder builder;
    builder.name(label);
    builder.size(full_size);
    builder.on_event("enter", [&value] { value = !value; });

    Widget checkbox(builder);

    checkbox.draw(Pos{0, 0}, current_checkmark);
    checkbox.draw(Pos(checkmark_width + style.item_inner_padding.x, 0), label);
}