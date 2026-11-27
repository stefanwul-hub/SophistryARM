#pragma once

#include "OriginalArchiveOpen.h"
#include "OriginalArchivePropertyList.h"
#include "OriginalSoundbank.h"

struct ElastikOriginalSoundbankReadOnly {
    void* context;
    const ElastikOriginalArchiveOpenPlatform* opening;
    const ElastikOriginalArchiveFactory* factory;
    // Return the initialized typed container of the bank's opaque archive.
    ElastikOriginalArchiveContainer* (*container)(void*, void* archive) noexcept;
    // Borrow the path string until the factory has had a chance to retain it.
    void* (*path_string)(void*, const char* absolute_path) noexcept;
    // Bridge an already decoded native dictionary into the bank's object
    // runtime. The returned document owns a +1 reference, and owns its values.
    // Use the same reference/dictionary_get/description operations as the bank.
    void* (*make_document)(void*, ElastikPropertyValue&& dictionary);
};

// Uses the translated read-only GNFA open and native XML/OpenStep reader.
// Pass the original bank callbacks for source resolution, archive construction,
// object ownership and metadata projection. The old open_archive,
// archive_member and parse_plist callbacks may be null for this entry point.
// Allocation failures can propagate. Archive-open status still clears the
// cached archive. As in the original, calls for one bank must be serialized.
void* elastik_original_bank_archive_readonly(
    ElastikOriginalSoundbank*, const ElastikOriginalSoundbankPlatform*,
    const ElastikOriginalSoundbankReadOnly*);
