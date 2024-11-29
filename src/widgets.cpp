#include <charo/widgets.hpp>
#include <iostream>
#include "charo/terminal.hpp"

charo::WidgetBuilder::WidgetBuilder() {

    // Set Default callback for widgets processing that may be overwritten
    auto& context = get_current_context();
    auto const current_item_id = context.last_item_id;

    on_event_deferred("up", [&context, current_item_id] {
        if (current_item_id)
            context.focused_item = context.widgets[--context.focused_item_id];
    });

    on_event_deferred("down", [&context, current_item_id] {
        if ((current_item_id + 1) < context.widgets.size())
            context.focused_item = context.widgets[++context.focused_item_id];
    }); 
}

void charo::WidgetBuilder::name(std::string_view new_name) { name_ = std::hash<std::string_view>{}(new_name); }
void charo::WidgetBuilder::name(std::u32string_view new_name) { name_ = std::hash<std::u32string_view>{}(new_name); }

void charo::WidgetBuilder::size(Size new_size) { 
    Context const& context = get_current_context();

    Pos const& widget_pos = context.cursor_pos;
    Pos widget_max_pos = widget_pos + new_size;
    Pos const& window_max_pos = get_current_screen().size();

    if (widget_pos.x > window_max_pos.x || widget_pos.y > window_max_pos.y) {
        on_screen_ = false;
    } else {
        if (widget_max_pos.x > window_max_pos.x) 
            new_size.x = window_max_pos.x - widget_pos.x;
        if (widget_max_pos.y > window_max_pos.y)
            new_size.y = window_max_pos.y - widget_pos.y;
    }
    
    if (context.layout->size().has_value() && on_screen_) {
        widget_max_pos = widget_pos + new_size;
        Pos const layout_max_pos = context.last_layout_pos + context.layout->size();
        if (widget_pos.x > layout_max_pos.x || widget_pos.y > layout_max_pos.y) {
            on_screen_ = false;
        } else {
            if (widget_max_pos.x > layout_max_pos.x)
                new_size.x = layout_max_pos.x - widget_pos.x;
            if (widget_max_pos.y > layout_max_pos.y)
                new_size.y = layout_max_pos.y - widget_pos.y;
        }
    }
    size_ = new_size; 
}

void charo::WidgetBuilder::on_event(std::string_view event_name, std::function<void()> func) {
    callbacks_.emplace(event_name, func);
}

void charo::WidgetBuilder::on_event_deferred(std::string_view event_name, callback_t func) {
    deferreds_.emplace(event_name, func);
}

charo::Widget::Widget(WidgetBuilder& wb) {
    if ((wb.name_ == 0) || !wb.size_.has_value())
        throw std::logic_error("WidgetBuilder is not correctly built");

    auto const& name = wb.name_;
    auto& context = get_current_context();
    size_ = wb.size_ - Size{0, 1};
    pos_ = context.cursor_pos;
    on_screen_ = wb.on_screen_;
    
    if (!on_screen_)
        return;

    context.widgets.emplace_back(name);

    if (context.focused_item == 0)       
        context.focused_item = name;

    if (context.focused_item == name) {
        is_focused_ = true;
        context.focused_item_id = context.last_item_id;

        for (auto const& [event, callback] : wb.callbacks_) {
            if (read_event(event)) {
                callback();
            }
        }

        for (auto const& [event, deferred] : wb.deferreds_) {
            if (read_event(event)) {
                context.deferred_callbacks.emplace_back(deferred);
            }
        }
    }
}

charo::Widget::~Widget() {
    Context& context = get_current_context();
    context.last_item_id++;
    context.last_item_size = size_;
    context.max_layout_item_size = std::max(size_ + Size{0, 1}, context.max_layout_item_size);

    Style const& style = get_current_style();
    Layout const* layout = context.layout;
    if (layout->align() == Layout::Alignement::Vertical)
        context.cursor_pos.y += (size_.y + style.item_spacing.y + 1);
    else
        context.cursor_pos.x += (size_.x + style.item_spacing.x + 1);
}

auto charo::Widget::is_focused() const -> bool {
    return is_focused_;
}

void charo::Widget::draw(Pos pos, char data, GlyphStyle style) {
    if (!on_screen_)
        return;

    auto& screen = get_current_screen();
    Pos const abs_pos = pos_ + pos;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    if (abs_pos.x < pos.x + size_.x && screen.in_bounds(abs_pos)) {
        screen.draw(abs_pos, data, style);
    }
}

void charo::Widget::draw(Pos pos, char32_t data, GlyphStyle style) {
    if (!on_screen_)
        return;
    
    auto& screen = get_current_screen();
    Pos const abs_pos = pos_ + pos;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    if (abs_pos.x < pos.x + size_.x && screen.in_bounds(abs_pos)) {
        screen.draw(abs_pos, data, style);
    }
}


void charo::Widget::draw(Pos pos, std::string_view data, GlyphStyle style) {
    if (!on_screen_)
        return;
    
    auto& screen = get_current_screen();

    Size::data_t str_length = data.length();
    Pos const abs_pos = pos_ + pos;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    screen.draw(abs_pos, data.substr(0, std::min(str_length + 0, size_.x - pos.x)), style);
}

void charo::Widget::draw(Pos pos, std::u32string_view data, GlyphStyle style) {
    if (!on_screen_)
        return;
    
    auto& screen = get_current_screen();

    Size::data_t str_length = data.length();
    Pos const abs_pos = pos_ + pos;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    screen.draw(abs_pos, data.substr(0, std::min(str_length + 0, size_.x - pos.x)), style);
}

void charo::begin_group(Size const& size, Layout::Alignement align) {
    auto& context = get_current_context();
    
    context.previous_layout = context.layout;
    context.layout = new Layout(size, align);
    context.last_layout_pos = context.cursor_pos;
    context.layout_depth++;
    context.max_layout_item_size = Size{0, 0};
}

void charo::end_group() {
    Context& context = get_current_context();
    if (!context.layout_depth)
        throw std::logic_error("Missing begin_group");

    Size const& layout_size = context.layout->size();
    Style& style = get_current_style();

    Size real_layout_size;
    real_layout_size.x = (layout_size.has_value() ? layout_size.x : (context.layout->vertical() ? context.max_layout_item_size.x : context.cursor_pos.x - context.last_layout_pos.x - 1 - style.item_spacing.x));
    real_layout_size.y = (layout_size.has_value() ? layout_size.y : (context.layout->horizontal() ? context.max_layout_item_size.y : context.cursor_pos.y - context.last_layout_pos.y - style.item_spacing.y));
    if (context.previous_layout->vertical()) {
        context.cursor_pos = context.last_layout_pos + Size(0, style.item_spacing.y + real_layout_size.y);
    }
    else {
        context.cursor_pos = context.last_layout_pos + Size(style.item_spacing.x + real_layout_size.x, 0);
    }

    auto& screen = get_current_screen();
    Size const& screen_size = screen.size();
    if (context.last_layout_pos < screen_size) {
        Pos const max_layout_pos = context.last_layout_pos + real_layout_size;
        if (max_layout_pos.x > screen_size.x) {
            real_layout_size.x = screen_size.x - context.last_layout_pos.x;
        }
        if (max_layout_pos.y > screen_size.y) {
            real_layout_size.y = screen_size.y - context.last_layout_pos.y;
        }
        screen.bg_rect(context.last_layout_pos, real_layout_size, style.colors[COLORS::GROUP_BG]);
    }
    


    // if (!style.is_empty()) {
    //     // auto& screen = get_current_screen();
    //     // screen.draw(context.last_layout_pos, ' ', style);
    //     // Draw background rect
    // }

    delete context.layout;
    context.layout = context.previous_layout;
    context.layout_depth--;
}