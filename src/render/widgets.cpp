#include "charo/terminal.hpp"
#include <charo/render/widgets.hpp>

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

void charo::WidgetBuilder::name(std::string_view new_name) { name_ = new_name; }
void charo::WidgetBuilder::size(Size new_size) { 
    auto const& widget_pos = get_current_context().cursor_pos;
    auto const widget_max_pos = widget_pos + new_size;
    Pos const& window_max_pos = get_current_screen().size();

    if (widget_max_pos.x > window_max_pos.x)
        new_size.w -= (widget_max_pos.x - window_max_pos.x);
    if (widget_max_pos.y > window_max_pos.x)
        new_size.h -= (widget_max_pos.y - window_max_pos.y);

    size_ = new_size; 
}

void charo::WidgetBuilder::on_event(std::string_view event_name, std::function<void()> func) {
    callbacks_.emplace(event_name, func);
}

void charo::WidgetBuilder::on_event_deferred(std::string_view event_name, callback_t func) {
    deferreds_.emplace(event_name, func);
}

auto charo::WidgetBuilder::get_name() const -> std::string_view { return name_; }
auto charo::WidgetBuilder::get_size() const -> Size { return size_; }
auto charo::WidgetBuilder::get_callbacks() const -> callbacks_t { return callbacks_; }
auto charo::WidgetBuilder::get_deferreds() const -> callbacks_t { return deferreds_; }

charo::Widget::Widget(WidgetBuilder& wb) {
    if (wb.get_name().empty() || wb.get_size() == Size{0, 0})
        throw std::logic_error("WidgetBuilder is not correctly built");


    auto& context = get_current_context();

    name_ = std::hash<std::string_view>{}(wb.get_name());
    size_ = wb.get_size() - Size{1, 1};
    pos_ = context.cursor_pos;

    context.widgets.emplace_back(name_);

    if (context.focused_item == 0)       
        context.focused_item = name_;

    if (context.focused_item == name_) {
        is_focused_ = true;
        context.focused_item_id = context.last_item_id;

        for (auto const& [event, callback] : wb.get_callbacks()) {
            if (read_event(event)) {
                callback();
            }
        }

        for (auto const& [event, deferred] : wb.get_deferreds()) {
            if (read_event(event)) {
                context.deferred_callbacks.emplace_back(deferred);
            }
        }
    }
}

charo::Widget::~Widget() {
    auto& context = get_current_context();
    context.last_item_id++;
    context.last_item_size = size_;

    context.cursor_pos.y += (size_.h + 1);
}

auto charo::Widget::get_name() const -> hash_t {
    return name_;
}

auto charo::Widget::is_focused() const -> bool {
    return is_focused_;
}

void charo::Widget::draw(Pos pos, char data, Style style) {
    auto& screen = get_current_screen();
    Pos const abs_pos = pos_ + pos;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    if (abs_pos.x < pos.x + size_.w &&  screen.in_bounds(abs_pos)) {
        screen.draw(abs_pos, data, style);
    }
}

void charo::Widget::draw(Pos pos, char32_t data, Style style) {
    auto& screen = get_current_screen();
    Pos const abs_pos = pos_ + pos;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    if (abs_pos.x < pos.x + size_.w &&  screen.in_bounds(abs_pos)) {
        screen.draw(abs_pos, data, style);
    }
}

void charo::Widget::draw(Pos pos, std::string_view data, Style style) {
    auto& screen = get_current_screen();
    auto const max_x = pos.x + size_.w;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    for (auto const ch : data) {
        Pos const abs_pos = pos_ + pos;
        if (pos.x > max_x || !screen.in_bounds(abs_pos)) 
            break;

        screen.draw(abs_pos, ch, style);
        pos.x++;
    }
}

void charo::Widget::draw(Pos pos, std::u32string_view data, Style style) {
    auto& screen = get_current_screen();
    auto const max_x = pos.x + size_.w;

    if (is_focused_)
        style.effects |= FLAG_UNDERLINE;

    for (auto const ch : data) {
        Pos const abs_pos = pos_ + pos;
        if (pos.x > max_x || !screen.in_bounds(abs_pos))
            break;

        screen.draw(abs_pos, ch, style);
        pos.x++;

        if (ch > 0xFFFF) {
            screen.draw(pos_ + pos, '\0', style);
            pos.x++;
        }
    }
}
