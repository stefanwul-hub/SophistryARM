#include "OriginalKeyedState.h"

#include <limits>
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

std::optional<size_t> list_index(std::u16string_view name) noexcept {
    if (name.empty() || (name.size() > 1 && name.front() == u'0')) return std::nullopt;
    size_t index = 0;
    for (auto ch : name) {
        if (ch < u'0' || ch > u'9') return std::nullopt;
        const auto digit = static_cast<size_t>(ch - u'0');
        if (index > (std::numeric_limits<size_t>::max() - digit) / 10) return std::nullopt;
        index = index * 10 + digit;
    }
    return index;
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

KeyedValue KeyedState::resolve_model(const Archive& archive, Reference ref) const noexcept {
    const auto id = model_id(archive, ref);
    const auto target = id ? record_for(*id) : 0;
    return {target ? KeyedValueKind::Model : KeyedValueKind::UnresolvedModel, target};
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
        if (without_marker(name->text) == key) return resolve_model(archive, ref);
    }
    return {KeyedValueKind::Absent, 0};
}

std::optional<std::vector<KeyedValue>> KeyedState::list_items(
    const Archive& archive, const ModelRecord& record) const {
    const auto* cls = value_at<String>(archive, record.class_name);
    if (!cls || cls->text != u"GNList") return std::nullopt;

    const auto entries = entries_at(archive, record.dictionary);
    const auto count = field(archive, record, u"count");
    if (count.kind != KeyedValueKind::Inline) return std::nullopt;
    const auto length = model_id(archive, count.reference);
    if (!length || *length > entries.size()) return std::nullopt;

    std::vector<KeyedValue> items(*length, {KeyedValueKind::Absent, 0});
    size_t missing = *length;
    for (size_t i = 0; i < entries.size() && missing; ++i) {
        const auto* key = value_at<String>(archive, entries.keys->items[i]);
        if (!key) continue;
        const auto name = without_marker(key->text);
        const auto index = list_index(name);
        if (!index || *index >= items.size() || items[*index].kind != KeyedValueKind::Absent) continue;
        const auto ref = entries.values->items[i];
        items[*index] = name.size() == key->text.size()
            ? KeyedValue{KeyedValueKind::Inline, ref} : resolve_model(archive, ref);
        --missing;
    }
    if (missing) return std::nullopt;
    return items;
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
