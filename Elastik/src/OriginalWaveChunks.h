#pragma once
#include "OriginalWave.h"

struct ElastikOriginalInstrumentChunk {
    int base_note, detune, low_note, high_note, low_velocity, high_velocity, gain;
};
struct ElastikOriginalAcidChunk {
    unsigned char looping;
    int numerator, denominator, beats, root_offset, root_mode;
};
// Original 0x28900e (347 bytes) and 0x288744 (433 bytes). The data-memory
// stream, GN allocation and exceptions are represented by a bounded byte span
// and the same status values used by the WAVE parser. Invalid length or null
// data leave state unchanged. Instrument bytes are explicitly SIGNED as i386
// char was signed; default ARM char signedness must not affect these fields.
extern "C" ElastikWaveStatus elastik_original_read_instrument_chunk(
    ElastikOriginalInstrumentChunk*, const unsigned char* data, int bytes) noexcept;
extern "C" ElastikWaveStatus elastik_original_read_acid_chunk(
    ElastikOriginalAcidChunk*, const unsigned char* data, int bytes) noexcept;
// Original 0x28916a (150 bytes), data allocation is a caller binding. Output
// must fit eight bytes. Only flags bit zero chooses seven vs padded eight.
extern "C" int elastik_original_write_instrument_chunk(
    const ElastikOriginalInstrumentChunk*, unsigned flags, unsigned char* output) noexcept;
