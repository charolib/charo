#include <charo/render/widgets.hpp>

bool charo::button(std::string_view text, Size size) {
    bool pressed = false;
    Size const text_size = calc_str_size(text);

    WidgetBuilder builder;
    builder.name(text);
    builder.size(size.has_value() ? size : text_size);
    builder.on_event("enter", [&pressed] { pressed = true; });

    constexpr Style default_style{.bg = {55, 55, 55}};
    constexpr Style pressed_style{.bg = {75, 75, 155}, .effects = FLAG_BOLD};

    Pos text_centered_pos{0, 0};
    if (size.w > text_size.w)
        text_centered_pos.x = (size.w - text_size.w) / 2;
    if (size.h > text_size.h)
        text_centered_pos.y = (size.h - text_size.h) / 2;

    Widget button(builder);
    button.draw(text_centered_pos, text, pressed ? pressed_style : default_style);

    return pressed;
}