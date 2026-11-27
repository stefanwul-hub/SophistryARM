#pragma once
#include "../src/OriginalSampleFile.h"
#include "../src/OriginalBufferedPcm.h"
#include "../src/OriginalVoiceChunk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Events { int trace_count, diagnostic_count, invalid, lock_depth; int trace[8192][5], diagnostics[8192][5]; };
static void row(Events* e, bool diagnostic, int kind, int a, int b, int c, int d) {
    int& count = diagnostic ? e->diagnostic_count : e->trace_count;
    if (count == 8192) { e->invalid = 1; return; }
    int* p = diagnostic ? e->diagnostics[count++] : e->trace[count++];
    p[0] = kind; p[1] = a; p[2] = b; p[3] = c; p[4] = d;
}
static void diagnostic(void* opaque, int kind, int a, int b, int c, int d) { row(static_cast<Events*>(opaque), true, kind, a, b, c, d); }
static void lock(void* opaque) { auto* e = static_cast<Events*>(opaque); if (e->lock_depth++) e->invalid = 1; row(e, false, 2, 0, 0, 0, 0); }
static void unlock(void* opaque) { auto* e = static_cast<Events*>(opaque); if (--e->lock_depth) e->invalid = 1; row(e, false, 3, 0, 0, 0, 0); }
struct Reader {
    Events* events; int index, channels, frames, format, data_offset, fail, max_read, read_ok, size, position;
    unsigned char* bytes;
    ElastikOriginalReadBuffer buffer;
    void* observer_context = nullptr;
    void (*observe_read)(void*, int reader, int first, int count) = nullptr;
};
static int frames(void* opaque) {
    auto* r = static_cast<Reader*>(opaque); row(r->events, false, 1, r->index, r->frames, 0, 0); return r->frames;
}
static void seek(void* opaque, int position) {
    auto* r = static_cast<Reader*>(opaque); r->position = position;
    row(r->events, false, 5, r->index, position, 0, 0);
}
static bool read(void* opaque, unsigned char* destination, int* count) {
    auto* r = static_cast<Reader*>(opaque); const int wanted = *count;
    if (r->position < 0 || r->position > r->size || wanted < 0) { r->events->invalid = 1; return false; }
    int actual = wanted < r->size - r->position ? wanted : r->size - r->position;
    if (r->max_read >= 0 && r->max_read < actual) actual = r->max_read;
    memcpy(destination, r->bytes + r->position, actual); r->position += actual; *count = actual;
    row(r->events, false, 6, r->index, wanted, actual, r->read_ok); return r->read_ok != 0;
}
static void read_failed(void* opaque, int wanted, int position, int actual) {
    row(static_cast<Reader*>(opaque)->events, true, 4, wanted, position, actual, 0);
}
static void format_failed(void* opaque, int code) { row(static_cast<Reader*>(opaque)->events, true, 4 + code, 0, 0, 0, 0); }
static bool read_range(void* opaque, float* const* outputs, int first, int count) {
    auto* r = static_cast<Reader*>(opaque); int mask = 0;
    for (int i = 0; i < r->channels; ++i) if (outputs[i]) mask |= 1 << i;
    row(r->events, false, 4, r->index, first, count, mask);
    if (r->observe_read) r->observe_read(r->observer_context, r->index, first, count);
    if (r->fail) return false;
    ElastikOriginalByteIO io{r, seek, read};
    ElastikOriginalReaderDiagnostics diagnostics{r, read_failed, format_failed};
    elastik_original_read_buffered_pcm(&r->buffer, outputs, first, count, r->format, r->channels, r->data_offset, &io, &diagnostics);
    return true;
}
static bool input(void* bytes, unsigned size) { return fread(bytes, 1, size, stdin) == size; }
static bool output(const void* bytes, unsigned size) { return fwrite(bytes, 1, size, stdout) == size; }
