#include "OriginalSampleFile.h"

static int bits_i32(unsigned value) noexcept { int result; __builtin_memcpy(&result, &value, 4); return result; }
static int add_i32(int a, int b) noexcept { return bits_i32(static_cast<unsigned>(a) + static_cast<unsigned>(b)); }
static int sub_i32(int a, int b) noexcept { return bits_i32(static_cast<unsigned>(a) - static_cast<unsigned>(b)); }
static int cvtt_i32(double value) noexcept {
    if (!(value >= -2147483648.0 && value < 2147483648.0)) return bits_i32(0x80000000u);
    return static_cast<int>(value);
}
static int frame_count(const ElastikOriginalSampleFile* file) noexcept {
    if (file->known_frames) return file->known_frames;
    return file->reader ? file->reader->frame_count(file->reader->context) : 0;
}

extern "C" bool elastik_original_read_file_channel(
    const ElastikOriginalSampleFile* file, float* destination, int channel,
    int first, int count, bool direct) noexcept {
    if (!file->reader) {
        if (file->diagnostics.emit) file->diagnostics.emit(file->diagnostics.context, 3, 0, 0, 0, 0);
        return false;
    }
    const unsigned channels = file->channel_format & 0x100u ? file->channel_format & 0xffu : file->channel_format;
    const int frames = frame_count(file);
    if (!channels) return false;
    if (channel >= static_cast<int>(channels)) channel = static_cast<int>(channels) - 1;
    const int end = add_i32(first, count);
    if (first < 0 || frames < end) {
        __builtin_memset(destination, 0, static_cast<unsigned>(count) * 4u);
        if (first < 0) {
            if (end < 1) return true;
            first = 0;
            count = end;
        }
        if (frames < end) {
            if (frames <= first) return true;
            count = frames - first;
        }
    }
    if (!direct) {
        if (elastik_original_cache_read(file->cache, destination, channel, first, count)) return true;
        __builtin_memset(destination, 0, static_cast<unsigned>(count) * 4u);
        return false;
    }
    float* outputs[255]{};
    outputs[channel] = destination;
    file->lock(file->lock_context);
    bool ok;
    if (file->separate_channel_readers == 1) {
        const auto* reader = file->channel_readers[channel];
        ok = reader->read(reader->context, &destination, first, count);
    } else {
        ok = file->reader->read(file->reader->context, outputs, first, count);
    }
    file->unlock(file->lock_context);
    return ok;
}

extern "C" void elastik_original_prepare_file_range(
    const ElastikOriginalSampleFile* file, ElastikOriginalCacheClient* client,
    int first, int count, double before, double after) noexcept {
    int end = add_i32(first, count);
    if (before > 0.0) first = sub_i32(first, cvtt_i32(before * file->sample_rate));
    if (after > 0.0) end = add_i32(end, cvtt_i32(after * file->sample_rate));
    if (first < 0) first = 0;
    if (frame_count(file) <= end) {
        end = file->known_frames;
        if (!end) {
            if (!file->reader) end = -1;
            else end = sub_i32(file->reader->frame_count(file->reader->context), 1);
        } else {
            end = sub_i32(end, 1);
        }
    }
    if (end <= first || !file->cache) return;
    count = sub_i32(end, first);
    const int frames = frame_count(file);
    if (first < 0) {
        count = add_i32(count, first);
        if (count < 1) return;
        first = 0;
        if (count > frames) count = frames;
    } else if (add_i32(first, count) > frames) {
        if (frames <= first) return;
        count = frames - first;
    }
    (void)elastik_original_cache_request(file->cache, client, first, count);
}

extern "C" bool elastik_original_read_file_and_prepare(
    const ElastikOriginalSampleFile* file, ElastikOriginalCacheClient* client,
    float* destination, int channel, int first, int count,
    double before, double after, bool direct) noexcept {
    const bool result = elastik_original_read_file_channel(file, destination, channel, first, count, direct);
    if (!direct) elastik_original_prepare_file_range(file, client, first, count, before, after);
    return result;
}

extern "C" bool elastik_original_sample_provider(
    void* context, float* destination, int channel, int first, int count,
    double before, double after) noexcept {
    const auto* handle = static_cast<const ElastikOriginalSampleHandle*>(context);
    return elastik_original_read_file_and_prepare(handle->file, handle->client, destination,
        channel, first, count, before, after, handle->direct);
}
