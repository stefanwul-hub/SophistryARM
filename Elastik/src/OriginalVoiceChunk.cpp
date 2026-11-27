#include "OriginalVoiceChunk.h"

static_assert(sizeof(int) == 4 && sizeof(float) == 4, "Original word sizes");

extern "C" int elastik_original_next_sample(
    const ElastikOriginalVoiceChunkState* s, int start, int count, int direction) noexcept {
    // Direct transcription of 0x15197c; normal and wrapped loop endpoints.
    if (direction != 0) {
        const int previous = start - 1;
        if (s->loop_stop <= s->loop_start) {
            if (s->loop_start <= s->loop_stop) return previous;
            if (start < s->loop_start) {
                if (s->loop_stop < start) return previous;
                if (previous >= 0) return previous;
                return s->sample_frames - 1;
            }
        }
        if (s->loop_start <= previous) return previous;
        return s->loop_stop;
    }
    const int after = count + start;
    if (s->loop_stop <= s->loop_start) {
        if (s->loop_start <= s->loop_stop) return after;
        if (s->loop_stop < start) {
            if (start < s->loop_start) return after;
            const int excess = after - (s->sample_frames - 1);
            if (excess < 1) return after;
            return excess - 1;
        }
    }
    if (after - s->loop_stop < 1) return after;
    return s->loop_start - 1 + (after - s->loop_stop);
}

static void advance_original_ramp(ElastikOriginalRamp& r) noexcept {
    const float step = r.step;
    const float next = step + r.current;
    r.current = next;
    if ((step > 0.0f && next >= r.target) || (step < 0.0f && next <= r.target)) {
        r.current = r.target;
        r.step = 0.0f;
    }
}

extern "C" int elastik_original_read_voice_chunk(
    ElastikOriginalVoiceChunkState* s, float* output, int channel,
    int position, int requested_frames, int* next_sample,
    ElastikOriginalReadRange* range, ElastikOriginalReadSamples read, void* context) noexcept {
    const int first = s->loop_start;
    const int last = s->loop_stop;
    const int direction = s->direction;
    if (direction != s->last_direction) s->last_direction = direction;
    const int fade_boundary = direction == 0
        ? (last < 101 ? s->sample_frames - (100 - last) : last - 100)
        : (first < 101 ? s->sample_frames - (100 - first) : first - 100);
    int start = position;
    int count = requested_frames;
    if (direction > 0) {
        if (first < last || (last < first && last < position && first <= position)) {
            start = position - count + 1;
            if (start < first) {
                count = position - first + 1;
                start = first;
            }
        } else if (last < first && position <= last) {
            start = position - count + 1;
            if (start < 0) {
                count = position + 1;
                start = 0;
            }
        }
    }
    range->start = start;
    range->count = count;
    if (first < last || (last < first && start <= last)) {
        if (last + 1 < start + count) range->count = last - start + 1;
    } else if (last < first && first <= start && s->sample_frames < start + count) {
        range->count = s->sample_frames - start;
    }
    // Original provider call 0x1f0c92, both cache-range arguments exactly 100.
    // Original code only logs a failed provider result and continues.
    (void)read(context, output, channel, range->start, range->count, 100.0, 100.0);
    if (next_sample) *next_sample = elastik_original_next_sample(s, range->start, range->count, direction);

    if (direction != 0) {
        const int half = range->count / 2;
        if (half > 0) {
            // Preserve original 0x152865/0x152868: compare <= half after
            // the swap. Even-length chunks perform one extra middle swap.
            int backward = range->count;
            for (int index = 1;; ++index) {
                const float value = output[index - 1];
                output[index - 1] = output[backward - 1];
                output[backward - 1] = value;
                --backward;
                if (half < index) break;
            }
        }
    }

    auto& in = s->fade_in[channel];
    if (in.step != 0.0f) {
        for (int index = 0; index < range->count; ++index) {
            advance_original_ramp(in);
            output[index] = output[index] * in.current;
            if (in.step == 0.0f) break;
        }
    }

    auto& out = s->fade_out[channel];
    const bool boundary_in_range = range->start <= fade_boundary && fade_boundary < range->start + range->count;
    int offset = 0;
    if (!s->looping && boundary_in_range && out.step == 0.0f) {
        offset = fade_boundary - range->start;
        out.target = 0.0f; out.current = 1.0f; out.step = -0.01f;
    }
    if (!s->looping || (last == s->sample_frames - 1 && first == 0)) {
        if (out.step == 0.0f) return range->count;
    } else if (out.step == 0.0f) {
        if (!boundary_in_range) return range->count;
        offset = fade_boundary - range->start;
        out.target = 0.0f; out.current = 1.0f; out.step = -0.01f;
    }
    for (int index = offset; index < range->count; ++index) {
        if (out.step != 0.0f) advance_original_ramp(out);
        output[index] = output[index] * out.current;
        if (out.step == 0.0f && !s->released) break;
    }
    return range->count;
}
