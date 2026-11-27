#pragma once
#include "OriginalByteFile.h"

// GN string/array primitives retain their original semantics, including the
// legacy default encoding used by split("/"). They are runtime bindings.
struct ElastikOriginalArchiveStrings {
    void* context;
    int (*length)(void*,void* string);
    void* (*split_slashes)(void*,void* string);
    uint32_t (*count)(void*,void* array);
    void* (*at)(void*,void* array,uint32_t index);
    bool (*equal)(void*,void* entry_name,void* component);
    void (*release)(void*,void* string);
};
// Original 0xdf8d2 (321). Commit the one-based index and release the path
// only after complete success. On failure, even a previous nonzero index is
// retained. Names are tested in original directory order; zero lengths skip.
extern "C" void elastik_original_archive_resolve_path(ElastikOriginalArchivePath*,
    const ElastikOriginalArchiveStrings*) noexcept;

// Native composition of the original GNFileArchiveFile and its GNFile base.
struct ElastikOriginalArchiveOpenFile {
    ElastikOriginalArchiveMember member;
    ElastikOriginalByteFile base;
    bool writing;
};
struct ElastikOriginalArchiveFactory {
    void* context;
    ElastikOriginalArchiveOpenFile* (*construct)(void*);
    ElastikOriginalArchiveOpenFile* (*initialize)(void*,ElastikOriginalArchiveOpenFile*);
    ElastikOriginalArchiveOpenFile* (*autorelease)(void*,ElastikOriginalArchiveOpenFile*);
    ElastikOriginalArchivePath* (*retain_path)(void*,ElastikOriginalArchivePath*);
    const ElastikOriginalArchiveData* data;
    const ElastikOriginalByteFilePlatform* byte_file;
};
// Original 0xe3ff4 (381). GN construction, lifetime and primitives are explicit
// bindings. Uses stream binding for read-only archives and materialized data
// otherwise. Original exceptions leave the lock held; outer GN unwinding is
// a runtime responsibility, not an extra normal-path unlock inserted here.
extern "C" ElastikOriginalArchiveOpenFile* elastik_original_archive_open_file(
    ElastikOriginalArchivePath*,const ElastikOriginalArchiveFactory*,ElastikArchiveStatus*) noexcept;
// Original 0xdfab4, instruction-verified 24 bytes (including tail jump).
// Member must be non-null. Backing streams use logical low32 position;
// memory mode delegates to the real translated GNFile position method.
extern "C" int elastik_original_archive_open_file_position(
    const ElastikOriginalArchiveOpenFile*,const ElastikOriginalByteFilePlatform*,ElastikArchiveStatus*) noexcept;
