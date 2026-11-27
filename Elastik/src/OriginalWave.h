#pragma once
#include "OriginalBufferedPcm.h"

// Native representation, not a copy of the i386 object. Metadata objects are
// opaque GN bindings with caller-managed lifetime through the parse operation.
enum ElastikWaveObjectKind { ElastikWaveDictionary=1, ElastikWaveArray=2,
    ElastikWaveInteger=3, ElastikWaveLongInteger=4, ElastikWaveString=5, ElastikWaveData=6 };
enum ElastikWaveStatus { ElastikWaveOk=0, ElastikWaveCannotRead=1, ElastikWaveUnsupported=2, ElastikWaveAssertion=3 };
struct ElastikOriginalWaveObjects {
    void* context;
    void* (*create)(void*,int kind,const void* bytes,int length);
    void (*set)(void*,void* dictionary,const char* key,void* value);
    void* (*get)(void*,void* dictionary,const char* key);
    void (*append)(void*,void* array,void* value);
    int (*count)(void*,void* object);
    unsigned char* (*bytes)(void*,void* data);
    void (*resize)(void*,void* data,int length);
    // Original GNFile::readData and delegated inst/acid chunk factories.
    void* (*read_data)(void*,int length);
    void* (*decode_chunk)(void*,bool acid,void* data);
    const char* (*chunk_name)(void*,void* chunk);
    void* (*allocate_dvi)(void*,int bytes);
};
struct ElastikOriginalWaveIO {
    ElastikOriginalByteIO bytes;
    bool (*open)(void*);
    void (*retain)(void*);
    int (*position)(void*);
    int (*length)(void*);
    // Original GNFile +0x14. i386 and little-endian ARM64 normally use zero.
    bool swap_integers;
    void (*diagnostic)(void*,int code,int a,int b); // 1=format, 2=damaged data, 3=playlist, 4=wavelist
};
struct ElastikOriginalWave {
    short block_align,channels,bits,format;
    int sample_bytes,sample_rate,frames,average_bytes,data_offset;
    short ms_samples_per_block,ms_block_bytes,ms_coefficient_count;
    short dvi_values_per_block,dvi_block_bytes;
    void* dvi_samples;
    int coefficients[256][2];
    bool stream_open;
    void* metadata;
};
struct ElastikOriginalWaveChunk { unsigned char id[5]; int bytes; };

// Original 0x24bfce (522 bytes). Successful header reads must supply their
// requested bytes; out->id[4] must already be NUL. Position arithmetic follows
// original 32-bit wrap behavior. Metadata string bytes use original encoding 4.
extern "C" bool elastik_original_wave_chunk(const ElastikOriginalWaveIO*,int end,
    ElastikOriginalWaveChunk*,const unsigned char* known_ids,int known_count,const char* oversize_id) noexcept;
// Original 0x249976 (129 bytes), 0x2499f8 (44), 0x249a3c (11).
extern "C" unsigned elastik_original_wave_sample_format(const ElastikOriginalWave*) noexcept;
extern "C" unsigned elastik_original_wave_channel_format(const ElastikOriginalWave*) noexcept;
extern "C" int elastik_original_wave_frames(const ElastikOriginalWave*) noexcept;
// Original 0x24ce76 (11316 bytes), with GN objects, exceptions, inst/acid
// subdecoders and byte I/O as explicit platform bindings. Requires valid object
// callbacks, successful allocations, bounded counts and nonzero PCM widths /
// compressed denominators whenever a data chunk reaches frame calculation.
// Error return represents the original GN exception and preserves prior writes.
extern "C" ElastikWaveStatus elastik_original_wave_open(ElastikOriginalWave*,
    const ElastikOriginalWaveIO*,const ElastikOriginalWaveObjects*) noexcept;
