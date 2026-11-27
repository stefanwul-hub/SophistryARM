#include "OriginalCacheLifecycle.h"

static int bits_i32(unsigned value) noexcept { int n; __builtin_memcpy(&n, &value, 4); return n; }
static int mul_i32(int a, int b) noexcept { return bits_i32(static_cast<unsigned>(a) * static_cast<unsigned>(b)); }

extern "C" void elastik_original_cache_initialize(ElastikOriginalCacheLifecycle* state) noexcept {
    state->delegate = nullptr;
    state->timer = nullptr;
    state->refill->block_bytes = 0x4000; // Original getter 0x1804c8.
    state->cache->slot_count = 0;
    state->cache->underrun = 0;
    state->refill->profiling = 0;
    state->refill->elapsed_seconds = 0.0;
    state->refill->processing = 0;
    state->refill->slot_capacity = 0;
    state->maximum_clients = 0;
}

extern "C" void elastik_original_cache_allocate(
    ElastikOriginalCacheLifecycle* state, int cache_bytes, int maximum_clients) noexcept {
    auto* cache = state->cache; const auto* platform = state->platform;
    int capacity = cache_bytes ? cache_bytes / state->refill->block_bytes
        : (0x40000000 / state->refill->block_bytes) * 2;
    capacity += 2;
    state->refill->slot_capacity = capacity;
    state->maximum_clients = maximum_clients ? maximum_clients : 0x5000;
    cache->blocks = static_cast<ElastikOriginalCacheBlock*>(platform->allocate(platform->context, ElastikCacheSlots, capacity));
    cache->block_to_slot = static_cast<int*>(platform->allocate(platform->context, ElastikCacheMap, capacity));
    for (int i = 0; i < capacity; ++i) { cache->blocks[i].block = -1; cache->block_to_slot[i] = -1; }
    for (int i = 0; i < cache->slot_count; ++i)
        cache->blocks[i].samples = static_cast<float*>(platform->allocate(platform->context, ElastikCacheSamples, state->refill->block_bytes));
    cache->clients = static_cast<ElastikOriginalCacheClient*>(platform->allocate(platform->context, ElastikCacheClients, state->maximum_clients));
    cache->client_count = 0;
    for (int i = 0; i < state->maximum_clients; ++i) {
        cache->clients[i].active = 0; cache->clients[i].first_block = -1; cache->clients[i].last_block = -1;
    }
}

extern "C" void elastik_original_sound_cache_configure(
    ElastikOriginalCacheLifecycle* state, const ElastikOriginalSampleFile* file, ElastikOriginalCacheScratch* scratch) noexcept {
    state->refill->file = file;
    const int channels = file->channel_format & 0x100u ? file->channel_format & 255u : file->channel_format;
    state->refill->channels = channels;
    state->cache->chunk_frames = 0x4000;
    state->refill->block_bytes = mul_i32(channels, 0x10000);
    state->cache->frames = file->known_frames ? file->known_frames : (file->reader ? file->reader->frame_count(file->reader->context) : 0);
    elastik_original_cache_allocate(state, mul_i32(mul_i32(state->cache->frames, channels), 4), 0);
    const int wanted = mul_i32(mul_i32(state->cache->chunk_frames, elastik_original_sample_bytes(file->sample_format)), channels);
    if (wanted != scratch->bytes && scratch->bytes <= wanted) {
        if (scratch->data) state->platform->release(state->platform->context, ElastikCacheScratch, scratch->data);
        scratch->bytes = wanted;
        scratch->data = state->platform->allocate(state->platform->context, ElastikCacheScratch, wanted);
    }
}

extern "C" ElastikOriginalCacheClient* elastik_original_cache_acquire_client(ElastikOriginalCacheLifecycle* state) noexcept {
    auto* cache = state->cache;
    for (int i = 0; i < cache->client_count; ++i) {
        if (!cache->clients[i].active) {
            cache->clients[i].first_block = -1; cache->clients[i].last_block = -1; cache->clients[i].active = 1;
            return cache->clients + i;
        }
    }
    const int index = cache->client_count;
    if (index >= state->maximum_clients && state->platform->warning) state->platform->warning(state->platform->context, 1);
    cache->clients[index].first_block = -1; cache->clients[index].last_block = -1; cache->clients[index].active = 1;
    ++cache->client_count;
    return cache->clients + index;
}

extern "C" void elastik_original_cache_release_client(ElastikOriginalCacheClient* client) noexcept {
    client->active = 0; client->first_block = -1; client->last_block = -1;
}

extern "C" void elastik_original_cache_start(ElastikOriginalCacheLifecycle* state) noexcept {
    if (state->timer) return;
    state->timer = state->platform->create_timer(state->platform->context, state->process, state->process_context, 0.2, true);
    state->platform->object_operation(state->platform->context, 1, state->timer);
}

extern "C" void elastik_original_cache_stop(ElastikOriginalCacheLifecycle* state) noexcept {
    if (!state->timer) return;
    state->platform->cancel_timer(state->platform->context, state->timer);
    state->platform->object_operation(state->platform->context, 2, state->timer);
    state->timer = nullptr;
}

extern "C" void elastik_original_cache_dispose(ElastikOriginalCacheLifecycle* state) noexcept {
    const auto* platform = state->platform; auto* cache = state->cache;
    if (state->timer) {
        platform->cancel_timer(platform->context, state->timer);
        if (state->timer) platform->object_operation(platform->context, 2, state->timer);
    }
    state->timer = nullptr;
    if (state->delegate) platform->object_operation(platform->context, 2, state->delegate);
    state->delegate = nullptr;
    for (int i = 0; i < cache->slot_count; ++i) platform->release(platform->context, ElastikCacheSamples, cache->blocks[i].samples);
    platform->release(platform->context, ElastikCacheSlots, cache->blocks);
    platform->release(platform->context, ElastikCacheMap, cache->block_to_slot);
    platform->release(platform->context, ElastikCacheClients, cache->clients);
}
