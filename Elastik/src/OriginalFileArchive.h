#pragma once
#include <stdint.h>

enum ElastikArchiveStatus {ElastikArchiveOk=0,ElastikArchiveUnsupported=1,
    ElastikArchiveCorrupted=2,ElastikArchiveCannotRead=3,ElastikArchiveAssertion=4};
struct ElastikOriginalArchiveStream {
    void* context;
    void (*seek)(void*,int byte_position);
    bool (*read)(void*,unsigned char* destination,int* byte_count);
    int (*position)(void*);
    void (*retain)(void*);
    bool (*can_clone)(void*);
    void* (*path)(void*);
    ElastikOriginalArchiveStream* (*open_path)(void*,void* path);
    int (*end)(void*); // GNFile base fallback, including its seek side effect.
};
// Native layout, explicitly different from the original 576-byte i386 entry.
struct ElastikOriginalArchiveEntry {
    uint32_t record_bytes,flags;
    uint64_t length_bits,storage;
    uint32_t field6,field7,parent;
    uint16_t name_units[256];
    uint64_t timestamp,record_offset,data_offset;
    void* name;
};
struct ElastikOriginalArchive {
    uint32_t header_bytes,version,directory_layout,entry_count;
    ElastikOriginalArchiveEntry* entries;
    uint64_t file_bytes;
    bool read_only,force_shared;
    ElastikOriginalArchiveStream* stream;
    void* context;
    ElastikOriginalArchiveEntry* (*allocate_entries)(void*,uint32_t count);
    void* (*create_name)(void*,const uint16_t*,int units);
    void (*lock)(void*);
    void (*unlock)(void*);
};
// Original 0xe0a4c (1815 bytes), internal register ABI adapted to a native
// typed API. Successful allocation and names terminated within 256 UTF16
// units required. Counts/allocation products must fit the original 32-bit
// allocator. No additional format validation or old-array release is added.
extern "C" ElastikArchiveStatus elastik_original_archive_parse(ElastikOriginalArchive*) noexcept;

struct ElastikOriginalArchivePath {
    ElastikOriginalArchive* archive;
    uint32_t index; // Original directory numbers are one-based.
    void* unresolved;
    void* context;
    void (*resolve)(void*,ElastikOriginalArchivePath*);
};
// Original 0xe05a2 (154) and 0xe09c0 (139). Path lookup and GN mutex/object
// primitives are bindings. Resolved nonzero indices must be valid. Original
// files have positive signed 64-bit lengths; directories have negative ones.
extern "C" bool elastik_original_archive_is_file(ElastikOriginalArchivePath*) noexcept;
extern "C" uint32_t elastik_original_archive_file_size(ElastikOriginalArchivePath*) noexcept;

struct ElastikOriginalArchiveMember {
    ElastikOriginalArchivePath* path;
    ElastikOriginalArchiveStream* backing;
    ElastikOriginalArchiveStream* base; // GNFile memory/OS fallback.
    uint64_t position;
    bool shared;
};
// Original 0xe3e38 (443), 0xe4172 (663), 0xe440a (336), 0xe455a (362).
// Callbacks do not throw; returned status models the original GN assertion.
// Source reads use signed 32-bit counts; negative results are preserved in
// the logical-position update before the original result is clamped to zero.
// Valid indexed paths, accessible destinations and nonthrowing I/O required.
extern "C" ElastikArchiveStatus elastik_original_archive_bind_member(
    ElastikOriginalArchiveMember*,ElastikOriginalArchiveStream*) noexcept;
extern "C" bool elastik_original_archive_read_member(ElastikOriginalArchiveMember*,
    unsigned char*,int* count,ElastikArchiveStatus*) noexcept;
extern "C" ElastikArchiveStatus elastik_original_archive_seek_member(
    ElastikOriginalArchiveMember*,int offset) noexcept;
extern "C" int elastik_original_archive_end_member(
    ElastikOriginalArchiveMember*,ElastikArchiveStatus*) noexcept;

struct ElastikOriginalArchiveData {
    void* context;
    void* (*allocate)(void*,int bytes);
    void (*lock)(void*,void*);
    unsigned char* (*bytes)(void*,void*);
    void (*unlock)(void*,void*);
    // Optional original GNFileArchiveDelegate +4. It must keep the actual
    // authorization/codec behavior; no licensed-bank decode is supplied here.
    void* (*decode)(void*,void* data,void* name,uint32_t field7,uint32_t field6);
};
// Original 0xe063c (577). Requires a positive logical length with a valid
// low-word allocation request; preserves 64-bit length/read-count comparison.
// GN data allocation/locking and the optional bank delegate are bindings.
extern "C" void* elastik_original_archive_read_data(ElastikOriginalArchive*,
    uint32_t index,const ElastikOriginalArchiveData*,ElastikArchiveStatus*) noexcept;
