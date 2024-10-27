#include <charo/render/escape.hpp>
#include <charo/render/base/converter.hpp>

auto charo::escape::get_escape(charo::Pos pos) -> std::string {
    std::string out = "\033[" + std::to_string(pos.y + 1) + ';' + std::to_string(pos.x + 1) + 'H';
    return out;
}

auto charo::escape::get_escape(Effects flags) -> std::string {
    // Create new and off previous styles
    std::string out{"\033[22;23;24;25;27;28;29;"};
    
    if (!(flags & EffectFlags::NONE)) {
        if (flags & EffectFlags::STANDOUT)
            out.append("1;7;");
        if (flags & EffectFlags::BOLD)
            out.append("1;");
        if (flags & EffectFlags::DIM)
            out.append("2;");
        if (flags & EffectFlags::ITALIC)
            out.append("3;");
        if (flags & EffectFlags::UNDERLINE)
            out.append("4;");
        if (flags & EffectFlags::BLINK)
            out.append("5;");
        if (flags & EffectFlags::INVERSE)
            out.append("7;");
        if (flags & EffectFlags::HIDDEN)
            out.append("8;");
        if (flags & EffectFlags::CROSSED_OUT)
            out.append("9;");
        if (flags & EffectFlags::DOUBLE_UNDERLINE)
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