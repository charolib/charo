#include "charo/render/converter.hpp"
#include <charo/render/widgets.hpp>
#include <charo/terminal.hpp>
#include <format>

void charo::text_styled(std::string_view str, Style const& style) {
    WidgetBuilder builder;
    builder.name(str);
    builder.size(calc_str_size(str));

    Widget text_styled(builder);
    text_styled.draw(Pos{0, 0}, str, style);
}

void charo::text_styled(std::u32string_view str, Style const& style) {
    WidgetBuilder builder;
    builder.name(to_utf8(str));
    builder.size(calc_str_size(str));

    Widget text_styled(builder);
    text_styled.draw(Pos{0, 0}, str, style);
}

template<typename... Args>
void charo::text_styled(std::string_view fmt_str, Style const& style, Args&&... args) {
    std::string str = std::format(fmt_str, args...);

    WidgetBuilder builder;
    builder.name(str);
    builder.size(calc_str_size(str));

    Widget text_styled(builder);
    text_styled.draw(Pos{0, 0}, str, style);
}

template<typename... Args>
void charo::text_styled(std::u32string_view fmt_str, Style const& style, Args&&... args) {
    std::u32string str = std::format(fmt_str, args...);

    WidgetBuilder builder;
    builder.name(to_utf8(str));
    builder.size(calc_str_size(str));

    Widget text_styled(builder);
    text_styled.draw(Pos{0, 0}, str, style);
}
