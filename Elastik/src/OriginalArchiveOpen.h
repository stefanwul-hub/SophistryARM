#pragma once
#include "OriginalFileArchive.h"

// Preserve the distinct GNFileArchiveCannotOpenArchiveException.
constexpr int ElastikArchiveCannotOpen=5;
struct ElastikOriginalArchiveContainer {
    ElastikOriginalArchive* core;
    ElastikOriginalArchiveStream* file;
    void* owner;
};
struct ElastikOriginalArchiveOpenPlatform {
    void* context;
    ElastikOriginalArchiveStream* (*read_file)(void*,void* source_path);
    int (*file_size)(void*,void* source_path);
    ElastikOriginalArchivePath* (*construct_path)(void*);
    int (*string_length)(void*,void* string);
    uint16_t (*character)(void*,void* string,int index);
    void* (*retain_string)(void*,void* string);
    void (*retain_owner)(void*,void* owner);
};
// Original 0xe13de (217). Valid initialized core/platform required. This
// read-only open path is distinct from the older read/write/create path.
// It sets readonly before opening, retains a returned reader, sign-extends
// the file size and tail-calls the translated directory parser. No rollback.
extern "C" int elastik_original_archive_open_read(
    ElastikOriginalArchiveContainer*,void* source_path,
    const ElastikOriginalArchiveOpenPlatform*) noexcept;
// Original 0xe168c (433). A successfully constructed native path starts with
// archive=null, index=0 and unresolved=null; runtime context/resolve are set.
// GN construction/lifetime/strings are bindings; underlying resolve is the
// real translated lookup. Invalid paths preserve allocation side effects.
extern "C" ElastikOriginalArchivePath* elastik_original_archive_path_for_core(
    ElastikOriginalArchive*,void* owner,void* absolute_path,
    const ElastikOriginalArchiveOpenPlatform*,ElastikArchiveStatus*) noexcept;
// Original 0xe1a68, instruction-verified 18 bytes including the tail jump.
extern "C" ElastikOriginalArchivePath* elastik_original_archive_path_for_container(
    ElastikOriginalArchiveContainer*,void* absolute_path,
    const ElastikOriginalArchiveOpenPlatform*,ElastikArchiveStatus*) noexcept;
