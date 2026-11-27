#pragma once
#include "OriginalSampleFormat.h"

struct ElastikOriginalReadBuffer { unsigned char* bytes; int capacity; };
struct ElastikOriginalByteIO {
    void* context;
    void (*seek)(void*, int byte_position);
    bool (*read)(void*, unsigned char* destination, int* byte_count);
};
struct ElastikOriginalReaderDiagnostics {
    void* context;
    void (*read_failed)(void*, int wanted_remaining_bytes, int byte_position, int bytes_read);
    ElastikOriginalFormatDiagnostic format;
};

// Direct translation of original 0x219820 (556 bytes). The caller supplies
// header-derived metadata and platform byte I/O. Buffer capacity must fit
// at least one frame for nonzero width/channels; destinations must fit frames.
// WAVE/AIFF container parsing, compressed codecs and asynchronous cache are
// separate layers, not implemented by this generic PCM reader.
extern "C" void elastik_original_read_buffered_pcm(
    ElastikOriginalReadBuffer*, float* const* channels, int first_frame, int frames,
    unsigned sample_format, unsigned channel_format, int data_byte_offset,
    const ElastikOriginalByteIO*, const ElastikOriginalReaderDiagnostics* = nullptr) noexcept;
