#include "../src/OriginalBufferedPcm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Context {
    unsigned char* file; int size, position, max_read, read_ok;
    int read_diagnostics = 0, format_diagnostics = 0, format_flags = 0;
    int event_count = 0, invalid = 0;
    int events[4096][4];
};
static void event(Context* c, int kind, int a, int b, int d) {
    if (c->event_count == 4096) { c->invalid = 1; return; }
    auto* row = c->events[c->event_count++]; row[0] = kind; row[1] = a; row[2] = b; row[3] = d;
}
static void seek(void* opaque, int at) { auto* c = static_cast<Context*>(opaque); c->position = at; event(c, 1, at, 0, 0); }
static bool read(void* opaque, unsigned char* destination, int* bytes) {
    auto* c = static_cast<Context*>(opaque); const int wanted = *bytes;
    if (c->position < 0 || c->position > c->size || wanted < 0) { c->invalid = 1; return false; }
    int actual = wanted < c->size - c->position ? wanted : c->size - c->position;
    if (c->max_read >= 0 && c->max_read < actual) actual = c->max_read;
    memcpy(destination, c->file + c->position, actual); c->position += actual; *bytes = actual;
    event(c, 2, wanted, actual, c->read_ok); return c->read_ok != 0;
}
static void read_failed(void* opaque, int wanted, int at, int actual) {
    auto* c = static_cast<Context*>(opaque); ++c->read_diagnostics; event(c, 3, wanted, at, actual);
}
static void format_failed(void* opaque, int code) {
    auto* c = static_cast<Context*>(opaque); ++c->format_diagnostics; c->format_flags |= 1 << code; event(c, 4, code, 0, 0);
}
static int run(const int* h) {
    const unsigned channel_format = static_cast<unsigned>(h[2]);
    const unsigned channels = channel_format & 0x100u ? channel_format & 0xffu : channel_format;
    if (h[0] < 0 || h[0] > 4194304 || channels > 16 || h[4] < 0 || h[4] > 512 || h[6] < 1 || h[6] > 1048576 || h[8] < h[4] + 16 || h[8] > 65536) return 2;
    auto* c = static_cast<Context*>(calloc(1, sizeof(Context)));
    auto* file = static_cast<unsigned char*>(malloc(h[0] ? h[0] : 1));
    auto* buffer = static_cast<unsigned char*>(malloc(h[6]));
    const unsigned output_words = (channels ? channels : 1) * h[8];
    auto* storage = static_cast<float*>(malloc(static_cast<size_t>(output_words) * 4));
    if (!c || !file || !buffer || !storage) return 3;
    if (fread(file, 1, h[0], stdin) != static_cast<unsigned>(h[0]) || fread(buffer, 1, h[6], stdin) != static_cast<unsigned>(h[6]) || fread(storage, 4, output_words, stdin) != output_words) return 2;
    c->file = file; c->size = h[0]; c->max_read = h[9]; c->read_ok = h[10];
    float* output[16]{};
    for (unsigned i = 0; i < channels; ++i) if (static_cast<unsigned>(h[7]) & (1u << i)) output[i] = storage + i * h[8] + 8;
    ElastikOriginalReadBuffer work{buffer, h[6]}; ElastikOriginalByteIO io{c, seek, read};
    ElastikOriginalReaderDiagnostics diagnostics{c, read_failed, format_failed};
    elastik_original_read_buffered_pcm(&work, output, h[3], h[4], static_cast<unsigned>(h[1]), channel_format, h[5], &io, &diagnostics);
    if (c->invalid) return 5;
    const int result[5]{c->read_diagnostics, c->format_diagnostics, c->format_flags, c->event_count, c->invalid};
    if (fwrite(result, sizeof(result), 1, stdout) != 1 || fwrite(c->events, 16, c->event_count, stdout) != static_cast<unsigned>(c->event_count) || fwrite(buffer, 1, h[6], stdout) != static_cast<unsigned>(h[6]) || fwrite(storage, 4, output_words, stdout) != output_words) return 4;
    free(storage); free(buffer); free(file); free(c); return 0;
}
int main() {
    for (;;) {
        int h[11]; const auto bytes = fread(h, 1, sizeof(h), stdin);
        if (!bytes && feof(stdin)) return 0;
        if (bytes != sizeof(h)) return 2;
        const int result = run(h); if (result) return result;
        if (fflush(stdout)) return 4;
    }
}
