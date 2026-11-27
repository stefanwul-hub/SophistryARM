#include "OriginalTimer.h"

static void install(ElastikOriginalTimer* timer, double seconds) noexcept {
    const auto* p = timer->platform;
    timer->event_handle = p->install(p->context, timer, seconds, timer->repeating ? seconds : 0.0);
    p->register_cleanup(p->context, timer);
}

extern "C" void elastik_original_timer_start_callback(
    ElastikOriginalTimer* timer, void (*callback)(void*), void* data, double seconds, unsigned char repeat) noexcept {
    const auto* p = timer->platform;
    p->object_operation(p->context, 1, timer);
    timer->active = 1;
    timer->repeating = repeat;
    // The original clears the name without releasing it and leaves the old
    // handler untouched. Fresh timers normally start with both null.
    timer->action_name = nullptr;
    timer->callback = callback;
    timer->callback_context = data;
    install(timer, seconds);
}

extern "C" void elastik_original_timer_start_action(
    ElastikOriginalTimer* timer, void* name, void* handler, double seconds, unsigned char repeat) noexcept {
    const auto* p = timer->platform;
    p->object_operation(p->context, 1, timer);
    timer->active = 1;
    timer->repeating = repeat;
    if (name != timer->action_name) {
        if (timer->action_name) p->object_operation(p->context, 2, timer->action_name);
        timer->action_name = name;
        if (name) p->object_operation(p->context, 1, name);
    }
    timer->callback = nullptr;
    timer->callback_context = nullptr;
    if (handler != timer->action_handler) {
        if (timer->action_handler) p->object_operation(p->context, 2, timer->action_handler);
        timer->action_handler = handler;
        if (handler) p->object_operation(p->context, 1, handler);
    }
    install(timer, seconds);
}

extern "C" void elastik_original_timer_cancel(ElastikOriginalTimer* timer) noexcept {
    const auto* p = timer->platform;
    if (timer->active) p->object_operation(p->context, 3, timer);
    timer->active = 0;
    if (timer->event_handle) {
        p->remove(p->context, timer->event_handle);
        timer->event_handle = nullptr;
    }
    p->unregister_cleanup(p->context, timer);
}

extern "C" void elastik_original_timer_fire(ElastikOriginalTimer* timer) noexcept {
    if (!timer->active) return;
    const auto* p = timer->platform;
    void* pool = p->begin_pool(p->context, 10);
    if (!timer->repeating) elastik_original_timer_cancel(timer);
    if (timer->action_handler && timer->action_name) {
        void* action = p->make_action(p->context, timer->action_name);
        p->dispatch_action(p->context, timer->action_handler, action);
        p->object_operation(p->context, 2, action);
    }
    if (timer->callback) timer->callback(timer->callback_context);
    p->after_dispatch(p->context);
    p->end_pool(p->context, pool);
}

extern "C" void elastik_original_timer_event(ElastikOriginalTimer* timer, bool events_suspended) noexcept {
    if (events_suspended) return;
    elastik_original_timer_fire(timer);
}

extern "C" void elastik_original_timer_dispose(ElastikOriginalTimer* timer) noexcept {
    const auto* p = timer->platform;
    if (timer->event_handle) elastik_original_timer_cancel(timer);
    if (timer->action_name) p->object_operation(p->context, 2, timer->action_name);
    timer->action_name = nullptr;
    if (timer->action_handler) p->object_operation(p->context, 2, timer->action_handler);
    timer->action_handler = nullptr;
}
