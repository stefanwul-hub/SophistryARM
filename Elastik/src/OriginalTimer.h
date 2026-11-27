#pragma once

struct ElastikOriginalTimer;
struct ElastikOriginalTimerPlatform {
    void* context;
    // 1 retain, 2 release, 3 autorelease. Self is the timer-state pointer;
    // other objects are opaque action names, handlers and action payloads.
    void (*object_operation)(void*, int operation, void* object);
    void* (*install)(void*, ElastikOriginalTimer*, double delay, double interval);
    void (*remove)(void*, void* event_handle);
    void (*register_cleanup)(void*, ElastikOriginalTimer*);
    void (*unregister_cleanup)(void*, ElastikOriginalTimer*);
    void* (*begin_pool)(void*, int initial_capacity);
    void (*end_pool)(void*, void* pool);
    void* (*make_action)(void*, void* action_name);
    void (*dispatch_action)(void*, void* handler, void* action);
    void (*after_dispatch)(void*);
};
struct ElastikOriginalTimer {
    void* event_handle;
    unsigned char active;
    unsigned char repeating;
    void* action_name;
    void* action_handler;
    void (*callback)(void*);
    void* callback_context;
    const ElastikOriginalTimerPlatform* platform;
};

// Original 0x6fdb4 (594 bytes). Valid timer, callback and successful non-null
// platform installation required. GN assertions/allocation failures are
// outside this API; retention, deferred releases and pools are host bindings.
extern "C" void elastik_original_timer_start_callback(
    ElastikOriginalTimer*, void (*callback)(void*), void* data, double seconds, unsigned char repeat) noexcept;
// Original 0x6faba (762 bytes), valid name and handler required.
extern "C" void elastik_original_timer_start_action(
    ElastikOriginalTimer*, void* name, void* handler, double seconds, unsigned char repeat) noexcept;
// Original 0x6f75c (173 bytes), including repeated cancellation behavior.
extern "C" void elastik_original_timer_cancel(ElastikOriginalTimer*) noexcept;
// Original 0x6f80a (354 bytes), normal callback/action dispatch. The platform
// must keep the object alive until its autorelease pool is drained.
extern "C" void elastik_original_timer_fire(ElastikOriginalTimer*) noexcept;
// Original 0x6fa3c (125 bytes), event callback's original global pause flag
// made explicit. The actual loop/token argument is unused by the original.
extern "C" void elastik_original_timer_event(ElastikOriginalTimer*, bool events_suspended) noexcept;
// Original 0x6f96c (82 bytes), cleanup of timer and retained action objects.
extern "C" void elastik_original_timer_dispose(ElastikOriginalTimer*) noexcept;
