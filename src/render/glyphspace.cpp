#include <charo/render/glyphspace.hpp>
#include <stdexcept>

charo::GlyphSpace::GlyphSpace(Size size) : data_(size.h), size_{size} {}

void charo::GlyphSpace::resize(Size new_size) {
    size_ = std::move(new_size);
    data_.resize(new_size.count());
    data_.shrink_to_fit();
}

void charo::GlyphSpace::reset() {
    std::fill(data_.begin(), data_.end(), Glyph{});
}

void charo::GlyphSpace::clear() {
    data_.clear();
    data_.shrink_to_fit();
}

auto charo::GlyphSpace::size() const -> Size {
    return size_;
}

auto charo::GlyphSpace::width() const -> Size::data_t {
    return size_.w;
}

auto charo::GlyphSpace::height() const -> Size::data_t {
    return size_.h;
}

auto charo::GlyphSpace::in_bounds(Pos pos) const -> bool {
    size_t const glyph_idx = pos.x + (pos.y * size_.w);
    return (glyph_idx <= data_.size());
}

auto charo::GlyphSpace::operator[](Pos pos) -> Glyph& {
    size_t const glyph_idx = pos.x + (pos.y * size_.w);
    if (glyph_idx > data_.size())
        throw std::out_of_range("Given glyph pos in GlyphSpace::operator() out of bounds");
    return data_[glyph_idx];
}

auto charo::GlyphSpace::operator[](Pos pos) const -> Glyph {
    size_t const glyph_idx = pos.x + (pos.y * size_.w);
    if (glyph_idx > data_.size())
        throw std::out_of_range("Given glyph pos in GlyphSpace::operator() out of bounds");
    return data_[glyph_idx];
}

auto charo::GlyphSpace::begin() -> iterator {
    return data_.begin();
}
auto charo::GlyphSpace::end() -> iterator {
    return data_.end();
}

auto charo::GlyphSpace::begin() const -> const_iterator {
    return data_.cbegin();
}
auto charo::GlyphSpace::end() const -> const_iterator {
    return data_.cend();
}