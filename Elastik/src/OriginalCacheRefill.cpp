#include "OriginalCacheRefill.h"

static_assert(sizeof(int) == 4 && sizeof(float) == 4, "Original scalar sizes");
static int mul_i32(int a, int b) noexcept {
    const unsigned value = static_cast<unsigned>(a) * static_cast<unsigned>(b);
    int result; __builtin_memcpy(&result, &value, 4); return result;
}

extern "C" int elastik_original_cache_add_slot(ElastikOriginalCacheRefill* refill) noexcept {
    auto* cache = refill->cache;
    if (cache->slot_count >= refill->slot_capacity && refill->capacity_warning)
        refill->capacity_warning(refill->platform_context);
    const int target = cache->slot_count;
    float* storage = refill->allocate_block(refill->platform_context, refill->block_bytes);
    cache->blocks[target].samples = storage;
    const int previous = cache->slot_count;
    cache->slot_count = previous + 1;
    return previous;
}

extern "C" void elastik_original_cache_refill(ElastikOriginalCacheRefill* refill) noexcept {
    auto* cache = refill->cache;
    if (cache->underrun) cache->underrun = 0;
    if (refill->profiling) {
        const double previous = refill->elapsed_seconds;
        const double now = refill->clock_seconds(refill->platform_context);
        refill->elapsed_seconds = previous - now;
    }
    refill->processing = 1;
    for (int client_index = 0; client_index < cache->client_count; ++client_index) {
        const auto& client = cache->clients[client_index];
        if (!client.active || client.first_block == -1) continue;
        const int last = client.last_block;
        for (int block = client.first_block; block <= last; ++block) {
            if (elastik_original_cache_slot(cache, block) != -1) continue;
            int slot = elastik_original_cache_reusable_slot(cache);
            if (slot == -1) slot = elastik_original_cache_add_slot(refill);
            const int old_block = cache->blocks[slot].block;
            if (old_block != -1) cache->block_to_slot[old_block] = -1;
            cache->blocks[slot].block = -1;
            float* outputs[255];
            for (int channel = 0; channel < refill->channels; ++channel)
                outputs[channel] = cache->blocks[slot].samples + channel * cache->chunk_frames;
            // Original pass ignores the read's bool, even after a caught
            // reader exception. Preserve its publication order and data.
            (void)elastik_original_read_file_channels(refill->file, outputs,
                mul_i32(block, cache->chunk_frames), cache->chunk_frames);
            cache->blocks[slot].block = block;
            cache->block_to_slot[block] = slot;
        }
    }
    refill->processing = 0;
    if (refill->profiling) {
        const double previous = refill->elapsed_seconds;
        const double now = refill->clock_seconds(refill->platform_context);
        refill->elapsed_seconds = previous + now;
    }
}
