#pragma once

#include "OriginalStateArchive.h"

#include <map>

namespace elastik_state {

using ModelId = uint32_t;

struct ModelRecord {
    ModelId id;
    Reference dictionary;
    Reference class_name;
};

enum class KeyedValueKind : uint8_t { Absent, Inline, Model, UnresolvedModel };

struct KeyedValue {
    KeyedValueKind kind;
    // Wire reference to the value or to the model's record dictionary.
    Reference reference;
};

enum class KeyedError : uint8_t {
    None, InvalidEnvelope, NoRecords, InvalidRecord, InvalidId, InvalidClass, DuplicateId
};

struct KeyedStateResult;

class KeyedState {
public:
    const std::vector<ModelRecord>& records() const noexcept { return records_; }
    Reference record_for(ModelId) const noexcept;

    // These methods take the same archive used to construct the index.
    // The i386 keyed presence and value lookups differ for an input key
    // starting with '@'. Property names declared by Elastik are ASCII.
    bool has_field(const Archive&, const ModelRecord&, std::u16string_view key) const noexcept;
    KeyedValue field(const Archive&, const ModelRecord&, std::u16string_view key) const noexcept;

private:
    friend KeyedStateResult index_keyed_state(const Archive&);
    std::vector<ModelRecord> records_; // Original restoration order. First entry is the root.
    std::map<ModelId, Reference> by_id_;
};

struct KeyedStateResult {
    std::optional<KeyedState> state;
    KeyedError error;
    Reference object; // Archive reference associated with the error.
};

// Indexes the in-memory GNKeyValue envelope decoded by GNArchiver. This
// does not instantiate classes or apply model setters.
KeyedStateResult index_keyed_state(const Archive&);

} // namespace elastik_state
