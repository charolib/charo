#include <charo/render/converter.hpp>
#include <locale>
#include <codecvt>

auto charo::to_utf8(char32_t ch) -> std::string {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.to_bytes(ch);
}

auto charo::to_utf8(std::u32string_view str) -> std::string {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.to_bytes(str.data());
}

auto charo::to_utf32(char ch) -> char32_t {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.from_bytes(ch)[0];
}

auto charo::to_utf32(std::string_view str) -> std::u32string {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.from_bytes(str.data());
}