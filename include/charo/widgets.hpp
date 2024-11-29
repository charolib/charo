#pragma once
#include <charo/glyphstyle.hpp>
#include <charo/common_types.hpp>
#include <charo/internal/layout.hpp>
#include <functional>
#include <unordered_map>

namespace charo {

class Widget;

class WidgetBuilder {
public:
    using callback_t = std::function<void()>;
    using callbacks_t = std::unordered_map<std::string_view, callback_t>;
    using hash_t = size_t;

private:
    hash_t name_;
    Size size_;
    callbacks_t callbacks_;
    callbacks_t deferreds_;

    bool on_screen_ = true;

public:
    WidgetBuilder();

    void name(std::string_view new_name);
    void name(std::u32string_view new_name);
    void size(Size new_size);

    void on_event(std::string_view event_name, callback_t func);
    void on_event_deferred(std::string_view event_name, callback_t func);

    friend Widget;
};

class Widget {
public:
    // using hash_t = size_t;

private:
    // hash_t name_;
    Size size_;
    Pos pos_;

    bool is_focused_ = false;
    bool on_screen_ = true;

public:
    Widget(WidgetBuilder& wb);
    ~Widget();

    // [[nodiscard]] auto get_name() const -> hash_t;
    [[nodiscard]] auto is_focused() const -> bool;

    void draw(Pos relative_pos, char data, GlyphStyle style = {});
    void draw(Pos relative_pos, char32_t data, GlyphStyle style = {});
    void draw(Pos relative_pos, std::string_view data, GlyphStyle style = {});
    void draw(Pos relative_pos, std::u32string_view data, GlyphStyle style = {});
};

void text(std::string_view str);
void text(std::u32string_view str);
template<typename... Args>
void text(std::string_view fmt_str, Args&&... args);
template<typename... Args>
void text(std::u32string_view fmt_str, Args&&... args);

void text_styled(std::string_view str, GlyphStyle const& style);
void text_styled(std::u32string_view str, GlyphStyle const& style);
template<typename... Args>
void text_styled(std::string_view fmt_str, GlyphStyle const& style, Args&&... args);
template<typename... Args>
void text_styled(std::u32string_view fmt_str, GlyphStyle const& style, Args&&... args);

bool button(std::string_view label, Size size = {0, 0});

void checkbox(std::string_view label, bool& value);

void slider(std::string_view label, float& value, float min, float max);

void begin_group(Size const& size = Size(0, 0), Layout::Alignement align = Layout::Alignement::Vertical);
void end_group();

// input radio combo slider listbox groups layouts setpos arrangments

}