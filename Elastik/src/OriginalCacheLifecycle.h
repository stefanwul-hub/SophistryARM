#pragma once
#include "OriginalCacheRefill.h"
#include "OriginalSampleFormat.h"

enum ElastikOriginalCacheAllocation {
    ElastikCacheSlots = 1, ElastikCacheMap = 2, ElastikCacheClients = 3,
    ElastikCacheSamples = 4, ElastikCacheScratch = 5
};
// Allocations of pointer-containing structures use logical element counts.
// Samples/scratch use byte counts. The platform chooses native element sizes.
struct ElastikOriginalCachePlatform {
    void* context;
    void* (*allocate)(void*, int kind, int count);
    void (*release)(void*, int kind, void*);
    void (*object_operation)(void*, int operation, void*); // 1 retain, 2 release
    void (*warning)(void*, int code); // 1 client capacity, 2 block capacity
    void* (*create_timer)(void*, void (*callback)(void*), void* data, double seconds, bool repeat);
    void (*cancel_timer)(void*, void* timer);
};
struct ElastikOriginalCacheLifecycle {
    ElastikOriginalSampleCache* cache;
    ElastikOriginalCacheRefill* refill;
    const ElastikOriginalCachePlatform* platform;
    int maximum_clients;
    void* delegate;
    void* timer;
    void (*process)(void*);
    void* process_context;
};
struct ElastikOriginalCacheScratch { void* data; int bytes; };

// Original 0x217cd2 (128 bytes), excluding GN base-object construction and
// vtable assignment. Only original initialized fields are changed.
extern "C" void elastik_original_cache_initialize(ElastikOriginalCacheLifecycle*) noexcept;
// Original 0x217db8 (291 bytes). Valid positive block size, representable
// positive capacity and successful allocations are required. Not a resize:
// original storage pointers are replaced without releasing previous arrays.
extern "C" void elastik_original_cache_allocate(
    ElastikOriginalCacheLifecycle*, int cache_bytes, int maximum_clients) noexcept;
// Original 0x218b82 (359 bytes), platform representation of shared scratch.
// Requires positive valid channel count, representable allocation sizes and
// successful allocations. Original GN assertions/allocator failures are bindings.
extern "C" void elastik_original_sound_cache_configure(
    ElastikOriginalCacheLifecycle*, const ElastikOriginalSampleFile*, ElastikOriginalCacheScratch*) noexcept;
// Original 0x2182e0 (242 bytes). Reuses inactive records before extending the
// high-water client count; physical client storage must fit the result.
extern "C" ElastikOriginalCacheClient* elastik_original_cache_acquire_client(ElastikOriginalCacheLifecycle*) noexcept;
// Original 0x2183d2 (25 bytes), unused cache argument omitted.
extern "C" void elastik_original_cache_release_client(ElastikOriginalCacheClient*) noexcept;
// Original 0x217fe2 (90 bytes) and 0x21803c (49 bytes).
extern "C" void elastik_original_cache_start(ElastikOriginalCacheLifecycle*) noexcept;
extern "C" void elastik_original_cache_stop(ElastikOriginalCacheLifecycle*) noexcept;
// Original 0x217edc (151 bytes). One-shot cleanup: original array pointers
// and counts remain dangling/unchanged afterward, so do not reuse the object.
extern "C" void elastik_original_cache_dispose(ElastikOriginalCacheLifecycle*) noexcept;
