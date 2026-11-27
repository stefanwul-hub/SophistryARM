#include "SampleProbeIO.h"
#include "../src/OriginalCacheRefill.h"

struct RefillContext {
    Events* events;
    ElastikOriginalCacheRefill* refill;
    float* pool;
    int physical_slots, block_words, clock_calls, allocations;
    double clock_base, clock_step;
};
static float* allocate_block(void* opaque, int bytes) {
    auto* c = static_cast<RefillContext*>(opaque); auto* r = c->refill; const int slot = r->cache->slot_count;
    row(c->events, false, 11, bytes, slot, r->processing, r->cache->underrun);
    if (slot < 0 || slot >= c->physical_slots || bytes != c->block_words * 4) abort();
    ++c->allocations; return c->pool + slot * c->block_words;
}
static void capacity_warning(void* opaque) {
    auto* c = static_cast<RefillContext*>(opaque); auto* r = c->refill;
    row(c->events, false, 12, r->cache->slot_count, r->slot_capacity, r->processing, r->cache->underrun);
}
static double clock_seconds(void* opaque) {
    auto* c = static_cast<RefillContext*>(opaque); auto* r = c->refill;
    row(c->events, false, 10, c->clock_calls, r->processing, r->cache->underrun, r->cache->slot_count);
    const double now = c->clock_base + c->clock_calls * c->clock_step;
    ++c->clock_calls; return now;
}
static void observe_read(void* opaque, int reader, int first, int count) {
    (void)reader; (void)count;
    auto* c = static_cast<RefillContext*>(opaque); auto* r = c->refill; auto* cache = r->cache;
    const int block = first / cache->chunk_frames;
    row(c->events, false, 13, r->processing, cache->underrun, cache->slot_count, cache->block_to_slot[block]);
    for (int i = 0; i < cache->slot_count; ++i) {
        const int id = cache->blocks[i].block;
        row(c->events, false, 14, i, id, cache->blocks[i].samples != nullptr, id >= 0 ? cache->block_to_slot[id] : -1);
    }
}
static bool voice_provider(void* opaque, float* destination, int channel, int first, int count, double before, double after) {
    auto* handle = static_cast<ElastikOriginalSampleHandle*>(opaque);
    const bool ok = elastik_original_sample_provider(opaque, destination, channel, first, count, before, after);
    // VoiceChunk's diagnostics are an adapted framework boundary, outside
    // its portable DSP API. Preserve the original failed-provider message.
    if (!ok) handle->file->diagnostics.emit(handle->file->diagnostics.context, 7, 0, 0, 0, 0);
    return ok;
}
static int run(const int* h) {
    // h[3] is physical slot capacity; r[0] below is the active slot count.
    if (h[0] < 1 || h[0] > 1000000 || h[1] < 1 || h[1] > 2048 || h[2] < 1 || h[2] > 4 || h[3] < 1 || h[3] > 128 ||
        h[4] < 1 || h[4] > 256 || h[5] < 0 || h[5] > 8 || h[7] < 16 || h[7] > 4096 || h[3] * h[1] * h[2] > 131072) return 2;
    auto* ids = static_cast<int*>(malloc(h[3] * 4)); auto* map = static_cast<int*>(malloc(h[4] * 4));
    auto* client_data = static_cast<int*>(malloc((h[5] ? h[5] : 1) * 12));
    auto* clients = static_cast<ElastikOriginalCacheClient*>(malloc((h[5] ? h[5] : 1) * sizeof(ElastikOriginalCacheClient)));
    const unsigned pool_words = h[3] * h[1] * h[2];
    auto* pool = static_cast<float*>(malloc(pool_words * 4)); auto* store = static_cast<float*>(malloc(h[7] * 4));
    auto* blocks = static_cast<ElastikOriginalCacheBlock*>(malloc(h[3] * sizeof(ElastikOriginalCacheBlock)));
    auto* events = static_cast<Events*>(calloc(1, sizeof(Events)));
    if (!ids || !map || !client_data || !clients || !pool || !store || !blocks || !events) return 3;
    if (!input(ids, h[3] * 4) || !input(map, h[4] * 4) || !input(client_data, h[5] * 12) || !input(pool, pool_words * 4) || !input(store, h[7] * 4)) return 2;
    int f[17], v[10]; double window[3]; float ramps[12];
    if (!input(f, sizeof(f)) || !input(window, sizeof(window)) || !input(v, sizeof(v)) || !input(ramps, sizeof(ramps))) return 2;
    const int channels = f[1] & 0x100 ? f[1] & 255 : f[1];
    if (channels < 1 || channels > 4 || channels != h[2] || f[9] < 1 || f[9] > 4096 || (f[7] == 1 && channels != 2)) return 2;
    const int readers = f[7] == 1 ? channels + 1 : 1;
    Reader contexts[5]{}; ElastikOriginalSampleReader api[5]{}; const ElastikOriginalSampleReader* per_channel[4]{};
    for (int i = 0; i < readers; ++i) {
        int bytes; if (!input(&bytes, 4) || bytes < 0 || bytes > 4194304) return 2;
        auto* raw = static_cast<unsigned char*>(malloc(bytes ? bytes : 1)); auto* buffer = static_cast<unsigned char*>(malloc(f[9]));
        if (!raw || !buffer) return 3;
        if (!input(raw, bytes) || !input(buffer, f[9])) return 2;
        contexts[i] = {events, i, i ? 1 : channels, f[5], f[0], f[10], f[8] == 1 || f[8] == i + 2, f[14], f[15], bytes, 0, raw, {buffer, f[9]}};
        api[i] = {contexts + i, frames, read_range}; if (i) per_channel[i - 1] = api + i;
    }
    int r[7]; double times[3];
    if (!input(r, sizeof(r)) || !input(times, sizeof(times)) || r[0] < 0 || r[0] > h[3] || r[4] < 0 || r[4] > 256) return 2;
    auto* operations = static_cast<int*>(malloc((r[4] ? r[4] : 1) * 32)); auto* results = static_cast<int*>(malloc((r[4] ? r[4] : 1) * 4));
    if (!operations || !results) return 3;
    if (!input(operations, r[4] * 32)) return 2;
    for (int i = 0; i < h[3]; ++i) blocks[i] = {ids[i], i < r[0] ? pool + i * h[1] * h[2] : nullptr};
    for (int i = 0; i < h[5]; ++i) clients[i] = {static_cast<unsigned char>(client_data[i * 3]), client_data[i * 3 + 1], client_data[i * 3 + 2]};
    ElastikOriginalSampleCache cache{blocks, map, r[0], static_cast<unsigned char>(h[8]), clients, h[5], h[0], h[1], {events, diagnostic}};
    ElastikOriginalSampleFile file{&cache, static_cast<unsigned>(f[1]), window[2], f[4], f[7], api, per_channel, events, lock, unlock, {events, diagnostic}};
    RefillContext platform{events, nullptr, pool, h[3], h[1] * h[2], 0, 0, times[1], times[2]};
    ElastikOriginalCacheRefill refill{&cache, &file, h[1] * h[2] * 4, r[1], channels, static_cast<unsigned char>(r[2]), static_cast<unsigned char>(r[3]), times[0], &platform, allocate_block, capacity_warning, clock_seconds};
    platform.refill = &refill;
    for (int i = 0; i < readers; ++i) { contexts[i].observer_context = &platform; contexts[i].observe_read = observe_read; }
    ElastikOriginalSampleHandle handle{&file, clients, false};
    ElastikOriginalVoiceChunkState voice{f[5], v[0], v[1], v[2], v[3], v[4], v[5], {}, {}};
    memcpy(voice.fade_in, ramps, 24); memcpy(voice.fade_out, ramps + 6, 24);
    int next = v[7]; ElastikOriginalReadRange range{v[8], v[9]};
    for (int i = 0; i < r[4]; ++i) {
        const int* op = operations + i * 8; results[i] = 0;
        if (op[0] == 1) elastik_original_cache_refill(&refill);
        else if (op[0] == 2) results[i] = elastik_original_cache_request(&cache, clients + op[1], op[2], op[3]);
        else if (op[0] == 3) elastik_original_cache_invalidate(clients + op[1]);
        else if (op[0] == 4) clients[op[1]].active = static_cast<unsigned char>(op[2]);
        else if (op[0] == 5) results[i] = elastik_original_sample_provider(&handle, store + op[4], op[1], op[2], op[3], window[0], window[1]);
        else if (op[0] == 6) results[i] = elastik_original_read_voice_chunk(&voice, store + op[4], op[1], op[2], op[3], v[6] ? &next : nullptr, &range, voice_provider, &handle);
        else if (op[0] == 7) results[i] = elastik_original_cache_add_slot(&refill);
        else return 2;
    }
    if (events->invalid || events->lock_depth) return 5;
    for (int i = 0; i < h[5]; ++i) { client_data[i * 3] = clients[i].active; client_data[i * 3 + 1] = clients[i].first_block; client_data[i * 3 + 2] = clients[i].last_block; }
    const int header[]{r[4], cache.slot_count, cache.underrun, refill.processing, events->diagnostic_count, events->trace_count, platform.clock_calls, next, range.start, range.count, voice.last_direction, platform.allocations};
    bool ok = output(header, sizeof(header)) && output(&refill.elapsed_seconds, 8) && output(results, r[4] * 4) && output(client_data, h[5] * 12) && output(map, h[4] * 4);
    for (int i = 0; i < h[3]; ++i) { const int state[]{blocks[i].block, blocks[i].samples ? i : -1}; if (!output(state, sizeof(state))) ok = false; }
    ok = ok && output(pool, pool_words * 4) && output(voice.fade_in, 24) && output(voice.fade_out, 24) && output(events->trace, events->trace_count * 20) && output(events->diagnostics, events->diagnostic_count * 20);
    for (int i = 0; i < readers; ++i) { if (!output(contexts[i].buffer.bytes, f[9])) ok = false; free(contexts[i].buffer.bytes); free(contexts[i].bytes); }
    if (!output(store, h[7] * 4)) ok = false;
    free(results); free(operations); free(events); free(blocks); free(store); free(pool); free(clients); free(client_data); free(map); free(ids);
    return ok ? 0 : 4;
}
int main() {
    for (;;) {
        int h[9]; const auto bytes = fread(h, 1, sizeof(h), stdin);
        if (!bytes && feof(stdin)) return 0;
        if (bytes != sizeof(h)) return 2;
        const int result = run(h); if (result) return result;
        if (fflush(stdout)) return 4;
    }
}
