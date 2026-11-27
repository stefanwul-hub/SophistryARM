#include "OriginalArchivePropertyList.h"

#include <limits>

ElastikArchivePropertyList elastik_original_archive_plist(
    ElastikOriginalArchivePath* path, const ElastikOriginalArchiveFactory* factory) {
    if (!path || !elastik_original_archive_is_file(path)) return {ElastikArchiveOk, std::nullopt};

    const uint64_t length = path->archive->entries[path->index - 1].length_bits;
    if (length > static_cast<uint64_t>(std::numeric_limits<int>::max())) {
        return {ElastikArchiveCannotRead, std::nullopt};
    }

    ElastikArchiveStatus status;
    auto* file = elastik_original_archive_open_file(path, factory, &status);
    if (status != ElastikArchiveOk) return {status, std::nullopt};
    if (!file) return {ElastikArchiveCannotRead, std::nullopt};

    std::string bytes(static_cast<size_t>(length), '\0');
    int count = static_cast<int>(length);
    const bool ok = elastik_original_archive_read_member(
        &file->member, reinterpret_cast<unsigned char*>(bytes.data()), &count, &status);
    if (status != ElastikArchiveOk) return {status, std::nullopt};
    if (!ok || count != static_cast<int>(length)) return {ElastikArchiveCannotRead, std::nullopt};
    return {ElastikArchiveOk, elastik_original_plist(bytes, true)};
}
