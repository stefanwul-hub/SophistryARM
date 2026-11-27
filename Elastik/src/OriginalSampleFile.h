#pragma once
#include "OriginalSampleCache.h"

struct ElastikOriginalSampleReader {
    void* context;
    int (*frame_count)(void*);
    // Original read method is void with GN exceptions. The platform boundary
    // returns false for that exception, true for normal completion.
    bool (*read)(void*, float* const*, int first, int count);
};
struct ElastikOriginalSampleFile {
    ElastikOriginalSampleCache* cache;
    unsigned channel_format;
    double sample_rate; // Original reader rate, frames/second, at file +0x18.
    int known_frames; // Original zero means query the reader each time.
    int separate_channel_readers; // Only value 1 selects the channel readers.
    const ElastikOriginalSampleReader* reader;
    const ElastikOriginalSampleReader* const* channel_readers;
    void* lock_context;
    void (*lock)(void*);
    void (*unlock)(void*);
    ElastikOriginalSampleDiagnostics diagnostics;
    unsigned sample_format = 0x44; // Original encoded format at file +0x20.
};

// Original 0x1af4e2 (794 bytes). File, cache and buffers must have valid
// metadata; requested count >= 0, channel >= 0, channel count <= 255.
// Direct reads require the shared lock callbacks. GN exception machinery,
// lazy shared-mutex creation and native framework objects are host bindings.
extern "C" bool elastik_original_read_file_channel(
    const ElastikOriginalSampleFile*, float* destination, int channel,
    int first, int count, bool direct) noexcept;
// Original 0x1afed2 (695 bytes), direct multichannel read with clipping and
// the shared lock. Separate-reader mode is the original paired mono path:
// it always invokes its two readers, including for a null output pointer.
// Loaded reader(s), valid output array and lock callbacks are required when
// the clipped range reaches a read operation. No closed-file guard is added.
extern "C" bool elastik_original_read_file_channels(
    const ElastikOriginalSampleFile*, float* const* outputs, int first, int count) noexcept;
// Original 0x1aecf0 (324 bytes), with client-pointer getter adapted.
extern "C" void elastik_original_prepare_file_range(
    const ElastikOriginalSampleFile*, ElastikOriginalCacheClient*, int first, int count,
    double before, double after) noexcept;
// Original 0x1afb00 (159 bytes), original global mode made explicit.
extern "C" bool elastik_original_read_file_and_prepare(
    const ElastikOriginalSampleFile*, ElastikOriginalCacheClient*, float* destination,
    int channel, int first, int count, double before, double after, bool direct) noexcept;

struct ElastikOriginalSampleHandle {
    const ElastikOriginalSampleFile* file;
    ElastikOriginalCacheClient* client;
    bool direct;
};
// Original 0x1f0c92: provider compatible with OriginalVoiceChunk.h callback.
extern "C" bool elastik_original_sample_provider(
    void* handle, float* destination, int channel, int first, int count,
    double before, double after) noexcept;
