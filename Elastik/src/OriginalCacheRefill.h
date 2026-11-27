#pragma once
#include "OriginalSampleFile.h"

// Native representation of additional fields used by the refill pass.
// Storage capacities and buffer sizes are established by the caller. The
// original allocation/lifetime manager and thread scheduler are not here.
struct ElastikOriginalCacheRefill {
    ElastikOriginalSampleCache* cache;
    const ElastikOriginalSampleFile* file;
    int block_bytes;
    int slot_capacity;
    int channels;
    unsigned char profiling;
    unsigned char processing;
    double elapsed_seconds;
    void* platform_context;
    float* (*allocate_block)(void*, int bytes);
    void (*capacity_warning)(void*);
    double (*clock_seconds)(void*);
};

// Original 0x21827e (79 bytes). Returns the original slot count before its
// increment, despite Ghidra's initial void type. Caller storage must fit the
// resulting slot and the allocator must return a valid non-null buffer.
extern "C" int elastik_original_cache_add_slot(ElastikOriginalCacheRefill*) noexcept;
// Original 0x218d5e (686 bytes), one complete refill pass over active requests.
// Valid, allocated map indices, channel buffers and readers are required.
// This function does not provide concurrent access or launch a worker thread.
extern "C" void elastik_original_cache_refill(ElastikOriginalCacheRefill*) noexcept;
