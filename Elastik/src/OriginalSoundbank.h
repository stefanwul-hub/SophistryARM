#pragma once
#include "OriginalFileArchive.h"

// Native representation of ETSoundbank. Original i386 object fields begin at
// +0x0c; pointers are never truncated to that layout in the port.
struct ElastikOriginalSoundbank {
    void *title,*identifier,*serial,*response,*source_path,*root_path,*archive,*color;
    double mounted_at,grace_period;
};
enum ElastikSoundbankField {ElastikBankTitle=0,ElastikBankIdentifier=1,
    ElastikBankSerial=2,ElastikBankResponse=3,ElastikBankSource=4,
    ElastikBankRoot=5,ElastikBankArchive=6,ElastikBankColor=7};
struct ElastikOriginalSoundbankPlatform {
    void* context;
    void (*reference)(void*,int operation,void*); // 1 retain, 2 release
    bool (*is_mutable)(void*,void*);
    void* (*immutable_copy)(void*,void*);
    int (*string_length)(void*,void*);
    void* (*system_path)(void*,void* string);
    bool (*path_is_file)(void*,void* path);
    void* (*last_component)(void*,void* string);
    void* (*resource_path)(void*,void* component);
    void* (*path_posix)(void*,void* path);
    void* (*path_name)(void*,void* path);
    void* (*construct_archive)(void*);
    int (*open_archive)(void*,void* archive,void* path);
    void* (*archive_member)(void*,void* archive,const char* absolute_path);
    void* (*parse_plist)(void*,void* path);
    void* (*description)(void*,void* object);
    void* (*dictionary_get)(void*,void* dictionary,const char* key);
    float (*number_float)(void*,void* value); // Original GNString float getter for gracePeriode.
    void (*diagnostic)(void*,int code,void* name); // 1 missing, 2 invalid, 3 loaded
};
// Originals: identifier 0x1a9b78(86), source 0x1a9bda(77), root
// 0x1a9cb4(55), title 0x1a9cf8(55), color 0x1a9d3c(55), serial
// 0x1a9d80(55), response 0x1a9dc4(55). Source always invalidates archive.
extern "C" void elastik_original_bank_set(ElastikOriginalSoundbank*,
    ElastikSoundbankField,void*,const ElastikOriginalSoundbankPlatform*) noexcept;
// Original 0x1aa964(98). Fetch path string before releasing the old archive.
extern "C" void elastik_original_bank_set_file(ElastikOriginalSoundbank*,
    void* path,const ElastikOriginalSoundbankPlatform*) noexcept;
// Original 0x1a99d2(199). Preserve release order and the two numeric fields.
extern "C" void elastik_original_bank_clear(ElastikOriginalSoundbank*,
    const ElastikOriginalSoundbankPlatform*) noexcept;
// Original 0x1a9c28(127). Resource fallback follows a non-file system path; failed/null path
// construction returns null. Runtime callbacks are bindings.
extern "C" void* elastik_original_bank_source(ElastikOriginalSoundbank*,
    const ElastikOriginalSoundbankPlatform*) noexcept;
// Original 0x1aa9c6(1143). Non-null archive construction and valid GN objects
// required. Only the archive-open exception is caught here. Other callbacks
// must not throw. The actual plist parser, GN runtime and OS are bindings.
// No authorization predicate, response validation or protected-data decoder
// is replaced by this metadata loader.
extern "C" void* elastik_original_bank_archive(ElastikOriginalSoundbank*,
    const ElastikOriginalSoundbankPlatform*) noexcept;
