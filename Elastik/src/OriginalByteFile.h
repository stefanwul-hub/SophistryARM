#pragma once
#include "OriginalFileArchive.h"

struct ElastikOriginalByteFile {
    void* data;
    int16_t fork;
    int position,length;
};
struct ElastikOriginalByteFilePlatform {
    void* context;
    void (*object_operation)(void*,int operation,void* data); // 1 retain, 2 release
    ElastikArchiveStatus (*lock_data)(void*,void* data);
    int (*data_length)(void*,void* data);
    const unsigned char* (*data_bytes)(void*,void* data);
    int16_t (*read_fork)(void*,int16_t fork,int requested,unsigned char*,int* actual);
    int16_t (*get_fork_position)(void*,int16_t fork,uint64_t* position);
    int16_t (*set_fork_position)(void*,int16_t fork,int origin,int offset);
};
// Original 0x17f8a0 (119 bytes): retain/release, lock, reset position and cache
// length, including when the same data object is rebound. A failed lock models
// the original GN exception and leaves the earlier object writes intact.
extern "C" ElastikArchiveStatus elastik_original_byte_file_bind_data(
    ElastikOriginalByteFile*,void* data,const ElastikOriginalByteFilePlatform*) noexcept;
// Original 0x17f918 (591). Readable source/destination storage and valid
// nonthrowing callbacks required. Memory short reads can return true; fork
// errors can copy bytes but reset the caller's count to zero. Signed 32-bit
// arithmetic follows i386 wrapping. Invalid pointer/count assertions are status.
extern "C" bool elastik_original_byte_file_read(ElastikOriginalByteFile*,
    unsigned char*,int* count,const ElastikOriginalByteFilePlatform*,ElastikArchiveStatus*) noexcept;
// Original 0x180a68 (236), 0x180c72 (329), 0x180b54 (285). FS fork imports
// are platform bindings; the original low-word results and error behavior
// are preserved. Successful memory mode uses cached length and position.
extern "C" int elastik_original_byte_file_position(const ElastikOriginalByteFile*,
    const ElastikOriginalByteFilePlatform*,ElastikArchiveStatus*) noexcept;
extern "C" ElastikArchiveStatus elastik_original_byte_file_seek(ElastikOriginalByteFile*,
    int offset,const ElastikOriginalByteFilePlatform*) noexcept;
extern "C" int elastik_original_byte_file_end(ElastikOriginalByteFile*,
    const ElastikOriginalByteFilePlatform*,ElastikArchiveStatus*) noexcept;
