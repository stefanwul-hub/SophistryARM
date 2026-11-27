#include "OriginalWaveChunks.h"

static int signed_byte(unsigned char v) noexcept { return int(v) - ((v & 128) ? 256 : 0); }
static short short_le(const unsigned char* p) noexcept {
    unsigned short bits = static_cast<unsigned short>(unsigned(p[0]) | unsigned(p[1]) << 8);
    short value; __builtin_memcpy(&value, &bits, 2); return value;
}
static unsigned word_le(const unsigned char* p) noexcept {
    return unsigned(p[0]) | unsigned(p[1]) << 8 | unsigned(p[2]) << 16 | unsigned(p[3]) << 24;
}
extern "C" ElastikWaveStatus elastik_original_read_instrument_chunk(
    ElastikOriginalInstrumentChunk* state, const unsigned char* data, int bytes) noexcept {
    if (!data) return ElastikWaveCannotRead;
    if (bytes < 7) return ElastikWaveUnsupported;
    state->base_note = signed_byte(data[0]);
    state->detune = signed_byte(data[1]);
    state->gain = signed_byte(data[2]);
    state->low_note = signed_byte(data[3]);
    state->high_note = signed_byte(data[4]);
    state->low_velocity = signed_byte(data[5]);
    state->high_velocity = signed_byte(data[6]);
    return ElastikWaveOk;
}
extern "C" ElastikWaveStatus elastik_original_read_acid_chunk(
    ElastikOriginalAcidChunk* state, const unsigned char* data, int bytes) noexcept {
    if (!data) return ElastikWaveCannotRead;
    if (bytes != 24) return ElastikWaveUnsupported;
    const unsigned flags = word_le(data);
    const int root = short_le(data + 4);
    const unsigned beat_bits = word_le(data + 12);
    __builtin_memcpy(&state->beats, &beat_bits, 4);
    state->numerator = short_le(data + 18);
    state->denominator = short_le(data + 16);
    state->root_mode = (flags & 2) && root ? 3 : 0;
    if (!(flags & 1)) state->looping = 1;
    else state->beats = 0; // Original leaves the previous looping byte intact.
    state->root_offset = state->root_mode && root ? root - 48 : 0;
    // The original reads offset 8 and offset 20 floats but does not retain
    // either, including the nominal ACID tempo. No new tempo inference here.
    return ElastikWaveOk;
}
extern "C" int elastik_original_write_instrument_chunk(
    const ElastikOriginalInstrumentChunk* state, unsigned flags, unsigned char* output) noexcept {
    output[0] = static_cast<unsigned char>(state->base_note);
    output[1] = static_cast<unsigned char>(state->detune);
    output[2] = static_cast<unsigned char>(state->gain);
    output[3] = static_cast<unsigned char>(state->low_note);
    output[4] = static_cast<unsigned char>(state->high_note);
    output[5] = static_cast<unsigned char>(state->low_velocity);
    output[6] = static_cast<unsigned char>(state->high_velocity);
    if (flags & 1) return 7;
    output[7] = 0;
    return 8;
}
