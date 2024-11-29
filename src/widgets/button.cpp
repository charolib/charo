#include <charo/widgets.hpp>

bool charo::button(std::string_view label, Size size) {
    bool pressed = false;
    Size const label_size = calc_size(label);

    WidgetBuilder builder;
    builder.name(label);
    builder.size(size.has_value() ? size : label_size);
    builder.on_event("enter", [&pressed] { pressed = true; });

    constexpr GlyphStyle default_style{.bg = {55, 55, 55}};
    constexpr GlyphStyle pressed_style{.bg = {75, 75, 155}, .effects = FLAG_BOLD};

    Pos const text_centered_pos = calc_center(label_size, size);

    Widget button(builder);
    button.draw(text_centered_pos, label, pressed ? pressed_style : default_style);

    return pressed;
}