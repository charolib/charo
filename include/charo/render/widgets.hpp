#pragma once
#include "charo/render/style.hpp"
#include "common_types.hpp"
#include <functional>
#include <unordered_map>

namespace charo {

class WidgetBuilder {
public:
    using callback_t = std::function<void()>;
    using callbacks_t = std::unordered_map<std::string_view, callback_t>;

private:
    std::string_view name_;
    Size size_;
    callbacks_t callbacks_;
    callbacks_t deferreds_;

public:
    WidgetBuilder();

    void name(std::string_view new_name);
    void size(Size new_size);

    void on_event(std::string_view event_name, callback_t func);
    void on_event_deferred(std::string_view event_name, callback_t func);

    [[nodiscard]] auto get_name() const -> std::string_view;
    [[nodiscard]] auto get_size() const -> Size;
    [[nodiscard]] auto get_callbacks() const -> callbacks_t;
    [[nodiscard]] auto get_deferreds() const -> callbacks_t;
};

class Widget {
public:
    using hash_t = size_t;

private:
    hash_t name_;
    Size size_;
    Pos pos_;

    bool is_focused_ = false;

public:
    Widget(WidgetBuilder& wb);
    ~Widget();

    [[nodiscard]] auto get_name() const -> hash_t;
    [[nodiscard]] auto is_focused() const -> bool;

    void draw(Pos relative_pos, char data, Style style = {});
    void draw(Pos relative_pos, char32_t data, Style style = {});
    void draw(Pos relative_pos, std::string_view data, Style style = {});
    void draw(Pos relative_pos, std::u32string_view data, Style style = {});
};

void text(std::string_view str);
void text(std::u32string_view str);
template<typename... Args>
void text(std::string_view fmt_str, Args&&... args);
template<typename... Args>
void text(std::u32string_view fmt_str, Args&&... args);

void text_styled(std::string_view str, Style const& style);
void text_styled(std::u32string_view str, Style const& style);
template<typename... Args>
void text_styled(std::string_view fmt_str, Style const& style, Args&&... args);
template<typename... Args>
void text_styled(std::u32string_view fmt_str, Style const& style, Args&&... args);

bool button(std::string_view text, Size size = {0, 0});

void checkbox(std::string_view text, bool& value);

void slider(std::string_view name, float& value, float min, float max);
// СОЗДАЙ ОБЁРТКУ КОТОРАЯ ПРИНИМАЕТ И STRING И U32STRING

// input radio combo slider listbox groups layouts setpos arrangments

}