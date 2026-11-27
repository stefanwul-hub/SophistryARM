#include "SampleProbeIO.h"

static int run(const int* h) {
    if (h[0] < 0 || h[0] > 1000000 || h[1] < 1 || h[1] > 64 || h[2] < 1 || h[2] > 4 || h[3] < 1 || h[3] > 128 ||
        h[4] < 1 || h[4] > 256 || h[5] < 1 || h[5] > 8 || h[7] < 16 || h[7] > 4096) return 2;
    auto* ids = static_cast<int*>(malloc(h[3] * 4));
    auto* map = static_cast<int*>(malloc(h[4] * 4));
    auto* client_data = static_cast<int*>(malloc(h[5] * 12));
    auto* clients = static_cast<ElastikOriginalCacheClient*>(malloc(h[5] * sizeof(ElastikOriginalCacheClient)));
    const unsigned pool_words = h[3] * h[1] * h[2];
    auto* pool = static_cast<float*>(malloc(pool_words * 4));
    // Entry 5 appends multichannel coverage using the same fixture protocol.
    // Its output storage is read after the file header reveals the channels.
    float* store = nullptr;
    auto* blocks = static_cast<ElastikOriginalCacheBlock*>(malloc(h[3] * sizeof(ElastikOriginalCacheBlock)));
    auto* events = static_cast<Events*>(calloc(1, sizeof(Events)));
    if (!ids || !map || !client_data || !clients || !pool || !blocks || !events) return 3;
    if (!input(ids, h[3] * 4) || !input(map, h[4] * 4) || !input(client_data, h[5] * 12) || !input(pool, pool_words * 4)) return 2;
    // The legacy protocol places storage before the file header. Entry 5
    // therefore uses h[6] to specify its storage channel count (old cases 0).
    const int storage_channels = h[6] ? h[6] : 1;
    if (storage_channels < 1 || storage_channels > 4) return 2;
    const unsigned storage_words = h[7] * storage_channels;
    store = static_cast<float*>(malloc(storage_words * 4)); if (!store) return 3;
    if (!input(store, storage_words * 4)) return 2;
    int f[17], v[10]; double window[3]; float ramps[12];
    if (!input(f, sizeof(f)) || !input(window, sizeof(window)) || !input(v, sizeof(v)) || !input(ramps, sizeof(ramps))) return 2;
    const int channels = f[1] & 0x100 ? f[1] & 255 : f[1];
    if (channels < 0 || channels > 4 || f[2] < 0 || f[2] > 5 || f[9] < 1 || f[9] > 4096 || f[12] < 0 || f[12] > h[7] - 16 || f[13] < 0 ||
        (f[2] == 4 && (f[13] > 1 || channels < 2))) return 2;
    const int readers = f[7] == 1 ? channels + 1 : 1;
    Reader contexts[5]{}; ElastikOriginalSampleReader api[5]{}; const ElastikOriginalSampleReader* per_channel[4]{};
    for (int i = 0; i < readers; ++i) {
        int bytes; if (!input(&bytes, 4) || bytes < 0 || bytes > 4194304) return 2;
        auto* raw = static_cast<unsigned char*>(malloc(bytes ? bytes : 1));
        auto* buffer = static_cast<unsigned char*>(malloc(f[9])); if (!raw || !buffer) return 3;
        if (!input(raw, bytes) || !input(buffer, f[9])) return 2;
        contexts[i] = {events, i, i ? 1 : channels, f[5], f[0], f[10], f[8] == 1 || f[8] == i + 2, f[14], f[15], bytes, 0, raw, {buffer, f[9]}};
        api[i] = {contexts + i, frames, read_range}; if (i) per_channel[i - 1] = api + i;
    }
    for (int i = 0; i < h[3]; ++i) blocks[i] = {ids[i], pool + i * h[1] * h[2]};
    for (int i = 0; i < h[5]; ++i) clients[i] = {static_cast<unsigned char>(client_data[i * 3]), client_data[i * 3 + 1], client_data[i * 3 + 2]};
    ElastikOriginalSampleCache cache{blocks, map, h[3], static_cast<unsigned char>(h[8]), clients, h[5], h[0], h[1], {events, diagnostic}};
    ElastikOriginalSampleFile file{f[16] ? &cache : nullptr, static_cast<unsigned>(f[1]), window[2], f[4], f[7], f[6] ? nullptr : api, per_channel, events, lock, unlock, {events, diagnostic}};
    ElastikOriginalSampleHandle handle{&file, clients, f[3] != 0};
    ElastikOriginalVoiceChunkState voice{f[5], v[0], v[1], v[2], v[3], v[4], v[5], {}, {}};
    memcpy(voice.fade_in, ramps, 24); memcpy(voice.fade_out, ramps + 6, 24);
    int next = v[7]; ElastikOriginalReadRange range{v[8], v[9]}; int result;
    if (f[2] == 0) result = elastik_original_read_file_channel(&file, store + 8, f[13], f[11], f[12], f[3] != 0);
    else if (f[2] == 1) { elastik_original_prepare_file_range(&file, clients, f[11], f[12], window[0], window[1]); result = 0; }
    else if (f[2] == 2) result = elastik_original_read_file_and_prepare(&file, clients, store + 8, f[13], f[11], f[12], window[0], window[1], f[3] != 0);
    else if (f[2] == 3) result = elastik_original_sample_provider(&handle, store + 8, f[13], f[11], f[12], window[0], window[1]);
    else if (f[2] == 4) result = elastik_original_read_voice_chunk(&voice, store + 8, f[13], f[11], f[12], v[6] ? &next : nullptr, &range, elastik_original_sample_provider, &handle);
    else {
        float* outputs[4]{};
        for (int c = 0; c < channels; ++c) if (f[13] & (1 << c)) outputs[c] = store + c * h[7] + 8;
        result = elastik_original_read_file_channels(&file, outputs, f[11], f[12]);
    }
    if (events->invalid || events->lock_depth) return 5;
    for (int i = 0; i < h[5]; ++i) { client_data[i * 3] = clients[i].active; client_data[i * 3 + 1] = clients[i].first_block; client_data[i * 3 + 2] = clients[i].last_block; }
    const int header[]{result, cache.underrun, events->diagnostic_count, events->trace_count, next, range.start, range.count, voice.last_direction};
    bool ok = output(header, sizeof(header)) && output(client_data, h[5] * 12) && output(map, h[4] * 4) && output(ids, h[3] * 4) && output(pool, pool_words * 4) &&
        output(voice.fade_in, 24) && output(voice.fade_out, 24) && output(events->trace, events->trace_count * 20) && output(events->diagnostics, events->diagnostic_count * 20);
    for (int i = 0; i < readers; ++i) { if (!output(contexts[i].buffer.bytes, f[9])) ok = false; free(contexts[i].buffer.bytes); free(contexts[i].bytes); }
    if (!output(store, storage_words * 4)) ok = false;
    free(events); free(blocks); free(store); free(pool); free(clients); free(client_data); free(map); free(ids);
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
