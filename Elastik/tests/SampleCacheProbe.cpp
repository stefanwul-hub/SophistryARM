#include "../src/OriginalSampleCache.h"
#include <stdio.h>
#include <stdlib.h>

struct Diagnostics { int count; int invalid; int rows[8192][5]; };
static void emit(void* opaque, int kind, int a, int b, int c, int d) {
    auto* value = static_cast<Diagnostics*>(opaque);
    if (value->count == 8192) { value->invalid = 1; return; }
    int* row = value->rows[value->count++]; row[0] = kind; row[1] = a; row[2] = b; row[3] = c; row[4] = d;
}
static bool input(void* buffer, unsigned bytes) { return fread(buffer, 1, bytes, stdin) == bytes; }
static bool output(const void* buffer, unsigned bytes) { return fwrite(buffer, 1, bytes, stdout) == bytes; }
static int run(const int* h) {
    // frames, chunk, channels, slots, map count, clients, ops, output words, underrun
    if (h[0] < 0 || h[0] > 8192 || h[1] < 1 || h[1] > 64 || h[2] < 1 || h[2] > 4 ||
        h[3] < 0 || h[3] > 128 || h[4] < 1 || h[4] > 256 || h[5] < 0 || h[5] > 8 ||
        h[6] < 0 || h[6] > 512 || h[7] < 16 || h[7] > 65536) return 2;
    const int allocated = h[3] ? h[3] : 1;
    const unsigned pool_words = allocated * h[1] * h[2];
    auto* ids = static_cast<int*>(malloc(allocated * 4));
    auto* map = static_cast<int*>(malloc(h[4] * 4));
    auto* client_data = static_cast<int*>(malloc((h[5] ? h[5] : 1) * 12));
    auto* clients = static_cast<ElastikOriginalCacheClient*>(malloc((h[5] ? h[5] : 1) * sizeof(ElastikOriginalCacheClient)));
    auto* pool = static_cast<float*>(malloc(pool_words * 4));
    auto* store = static_cast<float*>(malloc(h[7] * 4));
    auto* operations = static_cast<int*>(malloc((h[6] ? h[6] : 1) * 24));
    auto* results = static_cast<int*>(malloc((h[6] ? h[6] : 1) * 4));
    auto* blocks = static_cast<ElastikOriginalCacheBlock*>(malloc(allocated * sizeof(ElastikOriginalCacheBlock)));
    auto* diagnostic = static_cast<Diagnostics*>(calloc(1, sizeof(Diagnostics)));
    if (!ids || !map || !client_data || !clients || !pool || !store || !operations || !results || !blocks || !diagnostic) return 3;
    if (!input(ids, allocated * 4) || !input(map, h[4] * 4) || !input(client_data, h[5] * 12) ||
        !input(pool, pool_words * 4) || !input(store, h[7] * 4) || !input(operations, h[6] * 24)) return 2;
    for (int i = 0; i < allocated; ++i) blocks[i] = {ids[i], pool + i * h[1] * h[2]};
    for (int i = 0; i < h[5]; ++i) clients[i] = {static_cast<unsigned char>(client_data[i * 3]), client_data[i * 3 + 1], client_data[i * 3 + 2]};
    ElastikOriginalSampleCache cache{blocks, map, h[3], static_cast<unsigned char>(h[8]), clients, h[5], h[0], h[1], {diagnostic, emit}};
    for (int i = 0; i < h[6]; ++i) {
        const int* op = operations + i * 6;
        if (op[0] == 1) {
            if (op[1] < 0 || op[1] >= h[4]) return 2;
            results[i] = elastik_original_cache_slot(&cache, op[1]);
        } else if (op[0] == 2) {
            if (op[1] < 0 || op[1] >= h[2] || op[2] < 0 || op[3] < 0 || op[4] < 0 || op[4] + op[3] > h[7]) return 2;
            results[i] = elastik_original_cache_read(&cache, store + op[4], op[1], op[2], op[3]);
        } else if (op[0] == 3) {
            if (op[1] < 0 || op[1] >= h[5]) return 2;
            results[i] = elastik_original_cache_request(&cache, clients + op[1], op[2], op[3]);
        } else if (op[0] == 4) {
            if (op[1] < 0 || op[1] >= h[5]) return 2;
            elastik_original_cache_invalidate(clients + op[1]); results[i] = 0;
        } else if (op[0] == 5) {
            results[i] = elastik_original_cache_reusable_slot(&cache);
        } else return 2;
    }
    if (diagnostic->invalid) return 5;
    for (int i = 0; i < h[5]; ++i) {
        client_data[i * 3] = clients[i].active; client_data[i * 3 + 1] = clients[i].first_block; client_data[i * 3 + 2] = clients[i].last_block;
    }
    const int header[]{h[6], cache.underrun, diagnostic->count, h[5], h[7]};
    const bool ok = output(header, sizeof(header)) && output(results, h[6] * 4) &&
        output(client_data, h[5] * 12) && output(map, h[4] * 4) && output(ids, allocated * 4) &&
        output(pool, pool_words * 4) && output(diagnostic->rows, diagnostic->count * 20) && output(store, h[7] * 4);
    free(diagnostic); free(blocks); free(results); free(operations); free(store); free(pool); free(clients); free(client_data); free(map); free(ids);
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
