#pragma once

#include <string>

namespace charo {
    auto to_utf8(char32_t ch) -> std::string;
    auto to_utf8(std::u32string_view str) -> std::string;

    auto to_utf32(char ch) -> char32_t;
    auto to_utf32(std::string_view str) -> std::u32string;
}