#include "../src/OriginalVoiceChunk.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct Source { float* samples; int frames; int channels; bool invalid; };
static bool read_samples(void* opaque, float* destination, int channel, int start, int count, double a, double b) {
    auto* source = static_cast<Source*>(opaque);
    if (a != 100.0 || b != 100.0 || channel < 0 || channel >= source->channels || start < 0 || count < 0 || start + count > source->frames) {
        source->invalid = true; return false;
    }
    memcpy(destination, source->samples + channel * source->frames + start, static_cast<size_t>(count) * 4);
    return true;
}

int main() {
    int h[13]; float ramps[12];
    if (fread(h, sizeof(h), 1, stdin) != 1 || fread(ramps, sizeof(ramps), 1, stdin) != 1) return 2;
    if (h[0] < 1 || h[0] > 65536 || h[1] < 1 || h[1] > 2 || h[2] < 16 || h[2] > 65552 || h[4] < 0 || h[4] > h[2] - 16 || h[5] < 0 || h[5] >= h[1]) return 2;
    auto* samples = static_cast<float*>(malloc(static_cast<size_t>(h[0]) * h[1] * 4));
    auto* storage = static_cast<float*>(malloc(static_cast<size_t>(h[2]) * 4));
    if (!samples || !storage) return 3;
    if (fread(samples, 4, h[0] * h[1], stdin) != static_cast<size_t>(h[0] * h[1]) || fread(storage, 4, h[2], stdin) != static_cast<size_t>(h[2])) return 2;
    ElastikOriginalVoiceChunkState state{h[0], h[7], h[8], h[10], h[11], h[12], h[9], {}, {}};
    memcpy(state.fade_in, ramps, 24); memcpy(state.fade_out, ramps + 6, 24);
    Source source{samples, h[0], h[1], false};
    int next = 0x12345678; ElastikOriginalReadRange range{-1, -1};
    const int result = elastik_original_read_voice_chunk(&state, storage + 8, h[5], h[3], h[4], h[6] ? &next : nullptr, &range, read_samples, &source);
    if (source.invalid) return 5;
    int answer[5]{result, next, range.start, range.count, state.last_direction};
    if (fwrite(answer, sizeof(answer), 1, stdout) != 1 || fwrite(state.fade_in, 24, 1, stdout) != 1 || fwrite(state.fade_out, 24, 1, stdout) != 1 || fwrite(storage, 4, h[2], stdout) != static_cast<size_t>(h[2])) return 4;
    free(samples); free(storage); return 0;
}
