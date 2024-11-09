#include <charo/render/escape.hpp>
#include <charo/render/converter.hpp>

auto charo::escape::get_escape(charo::Pos pos) -> std::string {
    std::string out = "\033[" + std::to_string(pos.y + 1) + ';' + std::to_string(pos.x + 1) + 'H';
    return out;
}

auto charo::escape::get_escape(Effects flags) -> std::string {
    std::string out{"\033[22;23;24;25;27;28;29;"};
    
    if (!(flags & FLAG_NONE)) {
        if (flags & FLAG_STANDOUT)
            out.append("1;7;");
        if (flags & FLAG_BOLD)
            out.append("1;");
        if (flags & FLAG_DIM)
            out.append("2;");
        if (flags & FLAG_ITALIC)
            out.append("3;");
        if (flags & FLAG_UNDERLINE)
            out.append("4;");
        if (flags & FLAG_BLINK)
            out.append("5;");
        if (flags & FLAG_INVERSE)
            out.append("7;");
        if (flags & FLAG_HIDDEN)
            out.append("8;");
        if (flags & FLAG_CROSSED_OUT)
            out.append("9;");
        if (flags & FLAG_DOUBLE_UNDERLINE)
            out.append("21;");
    }

    // Remove last semicolon
    out.pop_back();
    out.push_back('m');

    return out;
}

auto charo::escape::get_escape(FGColor<ColorRGB> color) -> std::string {
    std::string out = std::string("\033[38;2;" + 
                        std::to_string(color.r) + ";" + 
                        std::to_string(color.g) + ";" + 
                        std::to_string(color.b) + "m");
    return out;
}
auto charo::escape::get_escape(BGColor<ColorRGB> color) -> std::string {
    std::string out = std::string("\033[48;2;" + 
                        std::to_string(color.r) + ";" + 
                        std::to_string(color.g) + ";" + 
                        std::to_string(color.b) + "m");
    return out;
}

void charo::escape::set_cursor_pos(Pos pos) {
    std::string esc_pos = "\033[" + std::to_string(pos.y + 1) + ';' + std::to_string(pos.x + 1) + 'H';
    write(esc_pos);
}

void charo::escape::write(char ch) {
    std::putchar(ch);
}

void charo::escape::write(std::string_view str) {
    for (auto ch : str) {
        write(ch);
    }
}

void charo::escape::write(char32_t ch) {
    std::string u8str = to_utf8(ch);
    write(u8str);
}

void charo::escape::write(std::u32string_view str) {
    std::string u8str = to_utf8(str);
    write(u8str);
}

void charo::escape::flush() {
    std::fflush(::stdout);
}