#pragma once
#include <charo/common_types.hpp>

namespace charo {
    
class Layout {
public:
    enum class Alignement {
        Vertical,
        Horizontal
    };

private:
    Size size_ = {};
    Alignement align_ = Alignement::Horizontal;

public:
    Layout() = default;
    Layout(Size const& size) : size_{size} {};
    Layout(Size const& size, Alignement align) : size_{size}, align_{align} {};

    void resize(Size const& new_size) {
        size_ = new_size;
    }
    [[nodiscard]] auto size() const -> Size {
        return size_;
    }


    void set_align(Alignement new_align) {
        align_ = new_align;
    }
    [[nodiscard]] auto align() const -> Alignement {
        return align_;
    }
    [[nodiscard]] auto vertical() const -> bool {
        return align_ == Alignement::Vertical;
    }
    [[nodiscard]] auto horizontal() const -> bool {
        return align_ == Alignement::Horizontal;
    }
};

}