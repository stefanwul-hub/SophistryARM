#include "OriginalKeyedState.h"

#include <utility>

namespace elastik_state {
namespace {

template <class T>
const T* value_at(const Archive& archive, Reference ref) noexcept {
    const auto* object = archive.get(ref);
    return object ? std::get_if<T>(&object->value) : nullptr;
}

std::optional<ModelId> model_id(const Archive& archive, Reference ref) noexcept {
    const auto* number = value_at<Number>(archive, ref);
    if (!number || !number->payload_present || number->kind != 'i' || number->bits > 0x7fffffff) {
        return std::nullopt;
    }
    return static_cast<ModelId>(number->bits);
}

struct Entries {
    const List* keys;
    const List* values;

    size_t size() const noexcept { return keys ? keys->items.size() : 0; }
};

Entries entries_at(const Archive& archive, Reference ref) noexcept {
    const auto* dict = value_at<Dictionary>(archive, ref);
    if (!dict) return {};
    const auto* keys = value_at<List>(archive, dict->keys);
    const auto* values = value_at<List>(archive, dict->values);
    if (!keys || !values || keys->items.size() != values->items.size()) return {};
    return {keys, values};
}

std::u16string_view without_marker(std::u16string_view name) noexcept {
    if (!name.empty() && name.front() == u'@') name.remove_prefix(1);
    return name;
}

bool valid_keys(const Archive& archive, Entries entries) noexcept {
    if (!entries.keys) return false;
    for (auto ref : entries.keys->items) {
        const auto* key = value_at<String>(archive, ref);
        if (!key || key->text.find(u'\0') != std::u16string::npos) return false;
    }
    return true;
}

} // namespace

Reference KeyedState::record_for(ModelId id) const noexcept {
    const auto found = by_id_.find(id);
    return found == by_id_.end() ? 0 : found->second;
}

bool KeyedState::has_field(const Archive& archive, const ModelRecord& record,
                           std::u16string_view key) const noexcept {
    const auto entries = entries_at(archive, record.dictionary);
    for (size_t i = 0; i < entries.size(); ++i) {
        const auto* name = value_at<String>(archive, entries.keys->items[i]);
        if (name && without_marker(name->text) == key) return true;
    }
    return false;
}

KeyedValue KeyedState::field(const Archive& archive, const ModelRecord& record,
                            std::u16string_view key) const noexcept {
    const auto entries = entries_at(archive, record.dictionary);
    for (size_t i = 0; i < entries.size(); ++i) {
        const auto* name = value_at<String>(archive, entries.keys->items[i]);
        if (!name) continue;
        const auto ref = entries.values->items[i];
        if (name->text == key) return {KeyedValueKind::Inline, ref};
        if (without_marker(name->text) == key) {
            const auto id = model_id(archive, ref);
            const auto target = id ? record_for(*id) : 0;
            return {target ? KeyedValueKind::Model : KeyedValueKind::UnresolvedModel, target};
        }
    }
    return {KeyedValueKind::Absent, 0};
}

KeyedStateResult index_keyed_state(const Archive& archive) {
    if (!valid_keys(archive, entries_at(archive, 1))) {
        return {std::nullopt, KeyedError::InvalidEnvelope, 1};
    }
    const auto list_ref = archive.find_key(1, u"objects");
    const auto* objects = list_ref ? value_at<List>(archive, *list_ref) : nullptr;
    if (!objects) return {std::nullopt, KeyedError::InvalidEnvelope, 1};
    if (objects->items.empty()) return {std::nullopt, KeyedError::NoRecords, *list_ref};

    KeyedState state;
    state.records_.reserve(objects->items.size());
    for (auto ref : objects->items) {
        if (!valid_keys(archive, entries_at(archive, ref))) {
            return {std::nullopt, KeyedError::InvalidRecord, ref};
        }
        const auto id_ref = archive.find_key(ref, u"@id");
        const auto id = id_ref ? model_id(archive, *id_ref) : std::nullopt;
        if (!id) return {std::nullopt, KeyedError::InvalidId, ref};

        const auto name_ref = archive.find_key(ref, u"@isa");
        const auto* name = name_ref ? value_at<String>(archive, *name_ref) : nullptr;
        if (!name || name->text.empty() || name->text.find(u'\0') != std::u16string::npos) {
            return {std::nullopt, KeyedError::InvalidClass, ref};
        }
        if (!state.by_id_.emplace(*id, ref).second) {
            return {std::nullopt, KeyedError::DuplicateId, ref};
        }
        state.records_.push_back({*id, ref, *name_ref});
    }
    return {std::move(state), KeyedError::None, 0};
}

} // namespace elastik_state
