#pragma once
#include "OriginalCacheLifecycle.h"
#include "OriginalWave.h"

// Native identities for the original GN reader/path objects. The sample
// callbacks belong to the reader; they need not use its GN object identity.
struct ElastikOriginalFileReader {
    ElastikOriginalSampleReader samples;
    void* identity;
};
enum ElastikOriginalFileStatus {
    ElastikFileOk=0, ElastikFileCannotRead=1, ElastikFileUnsupported=2,
    ElastikFileAssertion=3, ElastikFilePlatformError=4
};
struct ElastikOriginalFileOpenPlatform {
    void* context;
    // Format order: AIFF, WAVE, SND, SDII, matching the original constructors.
    ElastikOriginalFileReader* (*construct)(void*,int format);
    ElastikOriginalFileReader* (*initialize)(void*,ElastikOriginalFileReader*);
    ElastikOriginalFileReader* (*autorelease)(void*,ElastikOriginalFileReader*);
    ElastikOriginalFileStatus (*open)(void*,ElastikOriginalFileReader*,void* path);
    void (*object_operation)(void*,int operation,void* identity); // 1 retain, 2 release
    unsigned (*channels)(void*,ElastikOriginalFileReader*);
    double (*sample_rate)(void*,ElastikOriginalFileReader*);
    unsigned (*sample_format)(void*,ElastikOriginalFileReader*);
    int (*file_kind)(void*,ElastikOriginalFileReader*);
    void (*export_metadata)(void*,ElastikOriginalFileReader*,void* destination);
    void* (*find_mono_partner)(void*,void* path,int* side);
    bool (*path_exists)(void*,void* path);
};
struct ElastikOriginalFileOpenState {
    ElastikOriginalSampleFile* file;
    ElastikOriginalFileReader* primary;
    ElastikOriginalFileReader* paired[2];
    const ElastikOriginalSampleReader* channel_readers[2];
    void* path;
    void* paired_paths[2];
    void* metadata;
    int file_kind;
};

// Original 0x219202 (464 bytes). The GN constructor/init/autorelease and
// exception runtime are explicit boundaries. Only FormatNotSupported (and
// subclasses, classified by the binding) retries. Other exceptions propagate.
// Successful allocations and nonthrowing getters/reference callbacks required.
extern "C" ElastikOriginalFileStatus elastik_original_create_file_reader(
    const ElastikOriginalFileOpenPlatform*,void* path,ElastikOriginalFileReader** result) noexcept;
// Original 0x1adbb6 (840 bytes). No rollback on a later failed open. The
// partner-filename heuristic is an explicit binding, not a port of 0x1ac468.
// Primary and paired reader ownership/order and exact comparisons are retained.
extern "C" ElastikOriginalFileStatus elastik_original_open_sample_file(
    ElastikOriginalFileOpenState*,const ElastikOriginalFileOpenPlatform*,void* path) noexcept;

// Original 0x1ac9dc (105 bytes). The platform constructs/initializes the GN
// sound-cache object; configuration and timer start execute translated code.
// Existing file.cache returns immediately, including when owner is null.
extern "C" void elastik_original_ensure_file_cache(
    ElastikOriginalSampleFile*,ElastikOriginalCacheLifecycle** owner,
    void* context,ElastikOriginalCacheLifecycle* (*construct)(void*),
    ElastikOriginalCacheScratch*) noexcept;

struct ElastikOriginalMetadataBinding {
    void* context;
    void* (*source)(void*);
    bool (*contains)(void*,void* dictionary,const char* key);
    void* (*get)(void*,void* dictionary,const char* key);
    void (*set)(void*,void* dictionary,const char* key,void* value);
    void* (*integer)(void*,int value);
};
// Original 0x219a4c (263 bytes). Copies the two object references, rather
// than cloning them. GN's lazily constructed constant key array is a binding.
extern "C" void elastik_original_export_file_metadata(
    const ElastikOriginalMetadataBinding*,void* destination) noexcept;
// Original 0x249f1e (126 bytes). Preserve the legacy Melodyne sample-count
// adjustment, including its byte-offset division. Nonzero valid denominator
// required when sample_bytes is nonzero; no additional validation is inserted.
extern "C" void elastik_original_export_wave_metadata(
    const ElastikOriginalWave*,const ElastikOriginalMetadataBinding*,void* destination) noexcept;
