#pragma once
#include "OriginalWave.h"

// Original 0x24c638 (1575 bytes) and 0x249b18 (1000 bytes). Decode a full
// encoded block but write only [first,end) into destination_base+(frame-first).
// State, input blocks, output pointers and scratch must fit the original
// metadata. MS supports mono/stereo and valid coefficient indices; DVI needs
// 1..8 channels, complete four-byte channel groups and sufficient scratch.
// Input is little-endian. DVI mutates its scratch, not the encoded input.
extern "C" void elastik_original_decode_ms_adpcm(
    const ElastikOriginalWave*, const unsigned char* block, int first, int end,
    float* const* outputs, int destination_base) noexcept;
extern "C" void elastik_original_decode_dvi_adpcm(
    ElastikOriginalWave*, const unsigned char* block, int first, int end,
    float* const* outputs, int destination_base, const ElastikOriginalWaveIO* diagnostics = nullptr) noexcept;

struct ElastikOriginalWaveReadPlatform {
    void* context;
    unsigned char* (*allocate)(void*, int bytes);
    void (*release)(void*, unsigned char*);
};
// Original 0x24cc60 (533 bytes), including PCM dispatch. On compressed read
// failure, returns the original CannotRead exception without the normal-path
// buffer release (GN exception/lifetime cleanup is a separate binding).
// Valid nonnegative first/count, nonzero block frames and allocation required.
extern "C" ElastikWaveStatus elastik_original_read_wave(
    ElastikOriginalWave*, ElastikOriginalReadBuffer*, float* const* outputs,
    int first, int count, const ElastikOriginalByteIO*,
    const ElastikOriginalWaveReadPlatform*, const ElastikOriginalReaderDiagnostics* = nullptr,
    const ElastikOriginalWaveIO* codec_diagnostics = nullptr) noexcept;
