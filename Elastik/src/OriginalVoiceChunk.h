#pragma once

// Native representation of the fields used by the original chunk reader.
// The original 32-bit object pointers remain outside this portable DSP API.
struct ElastikOriginalRamp {
    float target;
    float current;
    float step;
};

struct ElastikOriginalVoiceChunkState {
    int sample_frames;
    int loop_start;
    int loop_stop;
    int direction;
    int looping;
    int released;
    int last_direction;
    ElastikOriginalRamp fade_in[2];
    ElastikOriginalRamp fade_out[2];
};

struct ElastikOriginalReadRange { int start; int count; };
using ElastikOriginalReadSamples = bool (*)(void*, float*, int, int, int, double, double);

// Original 0x15197c, complete 262-byte cursor method.
extern "C" int elastik_original_next_sample(
    const ElastikOriginalVoiceChunkState*, int start, int count, int direction) noexcept;

// Original 0x152664, complete 2064-byte chunk processing method.
// Valid caller contract: non-null state/range/provider, channel 0 or 1,
// loaded sample data, valid loop endpoints and enough destination space.
// The provider adapts the original sample-file API; its file decoder is not
// implemented by this method. Diagnostic printing is outside this DSP API.
extern "C" int elastik_original_read_voice_chunk(
    ElastikOriginalVoiceChunkState*, float* destination, int channel,
    int position, int requested_frames, int* next_sample,
    ElastikOriginalReadRange*, ElastikOriginalReadSamples, void*) noexcept;
