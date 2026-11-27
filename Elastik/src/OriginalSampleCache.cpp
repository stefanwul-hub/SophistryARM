#include "OriginalSampleCache.h"

static int add_i32(int a, int b) noexcept {
    const unsigned value = static_cast<unsigned>(a) + static_cast<unsigned>(b);
    int result; __builtin_memcpy(&result, &value, 4); return result;
}
static void diagnostic(const ElastikOriginalSampleCache* cache, int kind, int a, int b, int c, int d) noexcept {
    if (cache->diagnostics.emit) cache->diagnostics.emit(cache->diagnostics.context, kind, a, b, c, d);
}

extern "C" int elastik_original_cache_slot(const ElastikOriginalSampleCache* cache, int block) noexcept {
    const int mapped = cache->block_to_slot[block];
    if (mapped == -1 || cache->blocks[mapped].block == block) return mapped;
    for (int slot = 0; slot < cache->slot_count; ++slot) {
        if (cache->blocks[slot].block == block) {
            diagnostic(cache, 1, slot, block, block, mapped);
            return slot;
        }
    }
    return -1;
}

extern "C" int elastik_original_cache_reusable_slot(const ElastikOriginalSampleCache* cache) noexcept {
    for (int slot = 0; slot < cache->slot_count; ++slot) {
        const int block = cache->blocks[slot].block;
        if (block == -1) return slot;
        bool protected_block = false;
        for (int i = 0; i < cache->client_count; ++i) {
            const auto& client = cache->clients[i];
            if (client.active && client.first_block != -1 &&
                block >= client.first_block && block <= client.last_block) {
                protected_block = true;
                break;
            }
        }
        if (!protected_block) return slot;
    }
    return -1;
}

extern "C" bool elastik_original_cache_read(
    ElastikOriginalSampleCache* cache, float* destination, int channel, int first, int count) noexcept {
    if (first >= cache->frames) return false;
    const int end = add_i32(first, count);
    int remaining = end <= cache->frames ? count : cache->frames - first;
    if (remaining < 0) return false;
    while (remaining > 0) {
        const int block = first / cache->chunk_frames;
        const int within = first - block * cache->chunk_frames;
        const int available = cache->chunk_frames - within;
        const int take = remaining < available ? remaining : available;
        const int slot = elastik_original_cache_slot(cache, block);
        if (slot == -1) {
            cache->underrun = 1;
            // The original never advances its client pointer in this loop.
            // Keep its repeated diagnostic for client zero, including count.
            for (int i = 0; i < cache->client_count; ++i) {
                const auto& client = cache->clients[0];
                if (client.active && client.first_block != -1)
                    diagnostic(cache, 2, first, remaining,
                               client.first_block * cache->chunk_frames,
                               client.last_block * cache->chunk_frames);
            }
            return false;
        }
        const float* source = cache->blocks[slot].samples + channel * cache->chunk_frames + within;
        __builtin_memcpy(destination, source, static_cast<unsigned>(take) * 4u);
        remaining -= take;
        first += take;
        destination += take;
    }
    return true;
}

extern "C" bool elastik_original_cache_request(
    const ElastikOriginalSampleCache* cache, ElastikOriginalCacheClient* client, int first, int count) noexcept {
    if (first >= cache->frames) return false;
    const int end = add_i32(first, count);
    client->first_block = first / cache->chunk_frames;
    client->last_block = (end <= cache->frames ? end : cache->frames) / cache->chunk_frames;
    return true;
}

extern "C" void elastik_original_cache_invalidate(ElastikOriginalCacheClient* client) noexcept {
    client->first_block = -1;
    client->last_block = -1;
}
