#pragma once

#include "OriginalSoundbank.h"

namespace elastik_soundbank_detail {

struct ArchiveReader {
    const void* context;
    int (*open)(const void*, void* archive, void* source);
    void (*read_metadata)(const void*, ElastikOriginalSoundbank*, const ElastikOriginalSoundbankPlatform*, void* source);
};

void* load(ElastikOriginalSoundbank*, const ElastikOriginalSoundbankPlatform*, const ArchiveReader&);
void path_diagnostic(const ElastikOriginalSoundbankPlatform*, int code, void* source) noexcept;
void apply_metadata(ElastikOriginalSoundbank*, const ElastikOriginalSoundbankPlatform*, void* dictionary) noexcept;

} // namespace elastik_soundbank_detail
