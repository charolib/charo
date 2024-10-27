#pragma once

#include "base/common_types.hpp"
#include "style/effect.hpp"
#include "style/color.hpp"

#include <string>

namespace charo {
namespace escape {

auto get_escape(Pos pos) -> std::string;    
auto get_escape(Effects effects) -> std::string;
auto get_escape(FGColor<ColorRGB> color) -> std::string;
auto get_escape(BGColor<ColorRGB> color) -> std::string;

void write(char ch);
void write(std::string_view str);
void write(char32_t);
void write(std::u32string_view str);

void flush();
}
}