#include "charo/render/converter.hpp"
#include <charo/render/widgets.hpp>
#include <charo/terminal.hpp>
#include <format>

void charo::text(std::string_view str) {
    WidgetBuilder builder;
    builder.name(str);
    builder.size(calc_str_size(str));

    Widget text(builder);
    text.draw(Pos{0, 0}, str);
}

void charo::text(std::u32string_view str) {
    WidgetBuilder builder;
    builder.name(to_utf8(str));
    builder.size(calc_str_size(str));

    Widget text(builder);
    text.draw(Pos{0, 0}, str);
}

template<typename... Args>
void charo::text(std::string_view fmt_str, Args&&... args) {
    std::string str = std::format(fmt_str, args...);

    WidgetBuilder builder;
    builder.name(str);
    builder.size(calc_str_size(str));

    Widget text(builder);
    text.draw(Pos{0, 0}, str);
}

template<typename... Args>
void charo::text(std::u32string_view fmt_str, Args&&... args) {
    std::u32string str = std::format(fmt_str, args...);

    WidgetBuilder builder;
    builder.name(to_utf8(str));
    builder.size(calc_str_size(str));

    Widget text(builder);
    text.draw(Pos{0, 0}, str);
}
