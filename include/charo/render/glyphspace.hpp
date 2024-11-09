#pragma once
#include "common_types.hpp"
#include "glyph.hpp"

#include <vector>

namespace charo {
class GlyphSpace {
private:
    using data_t = std::vector<Glyph>;
    using iterator = data_t::iterator;
    using const_iterator = data_t::const_iterator;

    data_t data_;
    Size size_;

public:
    explicit GlyphSpace(Size size);

    void resize(Size new_size);
    void reset();
    void clear();

    void swap(GlyphSpace& with) noexcept;

    [[nodiscard]] auto size() const -> Size;
    [[nodiscard]] auto width() const -> Size::data_t;
    [[nodiscard]] auto height() const -> Size::data_t;
    [[nodiscard]] auto in_bounds(Pos pos) const -> bool;

    [[nodiscard]] auto operator[](Pos pos) -> Glyph&;
    [[nodiscard]] auto operator[](Pos pos) const -> Glyph;

    [[nodiscard]] auto begin() -> iterator;
    [[nodiscard]] auto end() -> iterator;

    [[nodiscard]] auto begin() const -> const_iterator;
    [[nodiscard]] auto end() const -> const_iterator;
};

}