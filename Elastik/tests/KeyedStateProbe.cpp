#include "../src/OriginalKeyedState.h"

#include <cstdio>
#include <limits>

namespace {

using namespace elastik_state;

template <class T>
bool write(T value) {
    return std::fwrite(&value, sizeof(value), 1, stdout) == 1;
}

bool write_value(KeyedValue value) {
    return write(static_cast<uint8_t>(value.kind == KeyedValueKind::Model)) &&
        write(value.reference);
}

bool run(uint32_t bytes, uint32_t queries) {
    std::string raw(bytes, '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != bytes) return false;
    const auto decoded = decode(raw);
    if (!decoded.archive) return false;
    const auto& archive = *decoded.archive;
    const auto indexed = index_keyed_state(archive);
    if (!write(indexed.error) || !write(indexed.object)) return false;
    if (!indexed.state) return queries == 0;

    const auto& state = *indexed.state;
    const auto& records = state.records();
    if (!write(static_cast<uint32_t>(records.size()))) return false;
    for (const auto& record : records) {
        if (!write(record.id) || !write(state.record_for(record.id)) || !write(record.class_name)) {
            return false;
        }
        const auto items = state.list_items(archive, record);
        const auto count = items ? static_cast<uint32_t>(items->size())
                                 : std::numeric_limits<uint32_t>::max();
        if (!write(count)) return false;
        if (items) {
            for (auto value : *items) {
                if (!write_value(value)) return false;
            }
        }
    }

    for (uint32_t i = 0; i < queries; ++i) {
        uint32_t query[2];
        if (std::fread(query, sizeof(uint32_t), 2, stdin) != 2 || query[0] >= records.size()) return false;
        std::u16string key(query[1], u'\0');
        if (std::fread(key.data(), sizeof(char16_t), key.size(), stdin) != key.size()) return false;
        const auto& record = records[query[0]];
        if (!write(static_cast<uint8_t>(state.has_field(archive, record, key))) ||
            !write_value(state.field(archive, record, key))) return false;
    }
    return true;
}

} // namespace

int main() {
    for (;;) {
        uint32_t header[2];
        const auto read = std::fread(header, 1, sizeof(header), stdin);
        if (!read && std::feof(stdin)) return 0;
        if (read != sizeof(header) || !run(header[0], header[1]) || std::fflush(stdout)) return 2;
    }
}
