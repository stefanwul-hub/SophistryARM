#pragma once

// Native fields used by the original cache routines, not an i386 object layout.
// Thread scheduling and synchronization are separate platform layers.
struct ElastikOriginalCacheBlock { int block; float* samples; };
struct ElastikOriginalCacheClient { unsigned char active; int first_block; int last_block; };
using ElastikOriginalSampleDiagnostic = void (*)(void*, int, int, int, int, int);
struct ElastikOriginalSampleDiagnostics {
    void* context;
    // 1=stale map lookup, 2=cache underrun, 3=closed file; four original args.
    ElastikOriginalSampleDiagnostic emit;
};
struct ElastikOriginalSampleCache {
    ElastikOriginalCacheBlock* blocks;
    int* block_to_slot;
    int slot_count;
    unsigned char underrun;
    ElastikOriginalCacheClient* clients;
    int client_count;
    int frames;
    int chunk_frames;
    ElastikOriginalSampleDiagnostics diagnostics;
};

// Original 0x218102 (130 bytes): an inconsistent nonnegative map entry can
// fall back to a slot scan. A missing (-1) entry does not scan or repair it.
extern "C" int elastik_original_cache_slot(const ElastikOriginalSampleCache*, int block) noexcept;
// Original 0x2181d6 (168 bytes): first empty slot or block outside every
// active client's inclusive request range. Does not change the cache.
extern "C" int elastik_original_cache_reusable_slot(const ElastikOriginalSampleCache*) noexcept;
// Original 0x21900c (337 bytes): may copy a prefix before returning false on
// an underrun. Valid domain: nonnegative first, valid channel and map indices,
// chunk_frames > 0, accessible buffers, no concurrent cache mutation.
extern "C" bool elastik_original_cache_read(
    ElastikOriginalSampleCache*, float* destination, int channel, int first, int count) noexcept;
// Original 0x218cf6 (82 bytes), unused original third argument omitted.
extern "C" bool elastik_original_cache_request(
    const ElastikOriginalSampleCache*, ElastikOriginalCacheClient*, int first, int count) noexcept;
// Original 0x218d48 (22 bytes), unused original cache argument omitted.
extern "C" void elastik_original_cache_invalidate(ElastikOriginalCacheClient*) noexcept;
