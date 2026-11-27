#include "../src/OriginalPropertyListXml.h"
#include "../src/OriginalSoundbankArchive.h"
#include "ArchiveOpenFixture.h"
#include "PropertyListProbeIO.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <new>

namespace {

using Archive = ArchiveOpenFixture::Context;
using namespace property_list_probe_io;

struct Object {
    uint32_t refs = 1;
    uint32_t archive_id = 0;
    ElastikPropertyValue property;
    std::vector<std::pair<std::u16string, Object*>> members;
    std::unique_ptr<Archive, decltype(&ArchiveNameFixture::cleanup)> archive{nullptr, &ArchiveNameFixture::cleanup};
};

struct Context {
    std::string archives[2];
    unsigned active = 0;
    uint32_t flags = 0;
    uint32_t source_mode = 0;
    uint32_t live = 0;
    uint32_t opens = 0;
    uint32_t paths = 0;
    uint32_t documents = 0;
    uint32_t source_lookups = 0;
    std::vector<uint8_t> diagnostics;
    Object* posix;
    Object* name;
    ElastikOriginalArchiveOpenPlatform opening{};
    ElastikOriginalArchiveFactory factory{};
};

Object* make(Context& c, ElastikPropertyValue property) {
    auto* obj = new Object;
    ++c.live;
    obj->property = std::move(property);
    return obj;
}

void release(Context& c, Object* object) {
    if (!object || !object->refs) std::abort();
    if (--object->refs > 0) return;
    for (const auto& entry : object->members) release(c, entry.second);
    delete object;
    --c.live;
}

void reference(void* ctx, int operation, void* ptr) {
    auto& c = *static_cast<Context*>(ctx);
    auto* object = static_cast<Object*>(ptr);
    if (operation == 1) ++object->refs;
    else if (operation == 2) release(c, object);
    else std::abort();
}

int string_length(void*, void* ptr) {
    return static_cast<int>(std::get<std::u16string>(static_cast<Object*>(ptr)->property.value).size());
}

void* system_path(void* ctx, void*) {
    auto& c = *static_cast<Context*>(ctx);
    ++c.source_lookups;
    if (c.source_mode == 2) return nullptr;
    return reinterpret_cast<void*>(c.source_mode == 1 || c.source_mode == 3 ? 2 : 1);
}

bool path_is_file(void*, void* path) {
    return path == reinterpret_cast<void*>(1);
}

void* resource_path(void* ctx, void*) {
    return static_cast<Context*>(ctx)->source_mode == 1 ? reinterpret_cast<void*>(1) : nullptr;
}

void* construct_archive(void* ctx) {
    auto& c = *static_cast<Context*>(ctx);
    const auto& raw = c.archives[c.active];
    auto* bytes = static_cast<unsigned char*>(std::malloc(raw.size() + 1));
    auto* units = static_cast<uint16_t*>(std::malloc(11 * sizeof(uint16_t)));
    void* storage = std::malloc(sizeof(Archive));
    if (!bytes || !units || !storage) std::abort();
    std::memcpy(bytes, raw.data(), raw.size());
    constexpr uint16_t path[]{'/', 'I', 'n', 'f', 'o', '.', 'p', 'l', 'i', 's', 't'};
    std::memcpy(units, path, sizeof(path));
    auto* object = make(c, {});
    object->archive.reset(new (storage) Archive{});
    object->archive_id = ++c.opens;
    int settings[32]{};
    settings[0] = settings[2] = static_cast<int>(raw.size());
    settings[1] = std::size(path);
    settings[4] = (c.flags & 4) == 0;
    settings[6] = settings[7] = settings[13] = 1;
    settings[10] = c.flags & 1;
    settings[11] = (c.flags >> 1) & 1;
    settings[12] = settings[14] = -1;
    ArchiveOpenFixture::setup(object->archive.get(), settings, bytes, units);
    c.opening = object->archive->opening;
    c.factory = object->archive->factory;
    return object;
}

ElastikOriginalArchiveContainer* container(void*, void* archive) noexcept {
    return &static_cast<Object*>(archive)->archive->container;
}

void* path_string(void* ctx, const char* path) noexcept {
    auto& c = *static_cast<Context*>(ctx);
    ++c.paths;
    if (std::string_view(path) != "/Info.plist") std::abort();
    return reinterpret_cast<void*>(1000);
}

void* make_document(void* ctx, ElastikPropertyValue&& root) {
    auto& c = *static_cast<Context*>(ctx);
    ++c.documents;
    auto drop = [&c](Object* object) { release(c, object); };
    std::unique_ptr<Object, decltype(drop)> doc(make(c, {}), drop);
    auto& dictionary = std::get<ElastikPropertyValue::Dictionary>(root.value);
    doc->members.reserve(dictionary.size());
    for (auto& [key, item] : dictionary) {
        doc->members.emplace_back(std::move(key), make(c, std::move(item)));
    }
    return doc.release();
}

void* dictionary_get(void*, void* dictionary, const char* key) {
    auto* doc = static_cast<Object*>(dictionary);
    const std::string_view ascii(key);
    for (const auto& [name, value] : doc->members) {
        if (name.size() == ascii.size() && std::equal(name.begin(), name.end(), ascii.begin())) return value;
    }
    return nullptr;
}

float number_float(void*, void* number) {
    const auto& value = static_cast<Object*>(number)->property.value;
    return elastik_plist_detail::number_real(std::get<std::u16string>(value));
}

void diagnostic(void* ctx, int code, void*) {
    static_cast<Context*>(ctx)->diagnostics.push_back(static_cast<uint8_t>(code));
}

bool field(void* ptr) {
    return scalar(static_cast<uint8_t>(ptr != nullptr)) && (!ptr || value(static_cast<Object*>(ptr)->property));
}

uint32_t archive_id(void* ptr) {
    return ptr ? static_cast<Object*>(ptr)->archive_id : 0;
}

bool snapshot(const Context& c, const ElastikOriginalSoundbank& bank, void* returned) {
    return scalar(archive_id(returned)) && scalar(archive_id(bank.archive)) &&
           scalar(c.opens) && scalar(c.paths) && scalar(c.documents) && scalar(c.source_lookups) &&
           scalar(bank.mounted_at) && scalar(bank.grace_period) &&
           field(bank.title) && field(bank.identifier) && field(bank.serial) && field(bank.response) &&
           field(bank.source_path) && field(bank.root_path) && field(bank.color);
}

bool run(const uint32_t (&header)[6]) {
    Context c{};
    c.flags = header[2];
    c.source_mode = header[3];
    c.diagnostics.reserve(header[5]);
    for (unsigned i = 0; i < 2; ++i) {
        c.archives[i].resize(header[i]);
        if (std::fread(c.archives[i].data(), 1, header[i], stdin) != header[i]) return false;
    }
    std::vector<uint8_t> ops(header[5]);
    if (std::fread(ops.data(), 1, ops.size(), stdin) != ops.size()) return false;
    c.posix = make(c, {std::u16string(u"/fixture/Fallback.elastik")});
    c.name = make(c, {std::u16string(u"Fallback.elastik")});
    ElastikOriginalSoundbank bank{
        header[4] ? make(c, {std::u16string(u"old title")}) : nullptr,
        make(c, {std::u16string(u"old identifier")}), make(c, {std::u16string(u"old serial")}),
        make(c, {std::u16string(u"old response")}),
        make(c, {std::u16string(c.source_mode == 4 ? u"" : u"/fixture/Source.elastik")}),
        make(c, {std::u16string(u"/old/root")}), nullptr, make(c, {std::u16string(u"old color")}),
        123.5, 987.25
    };
    const ElastikOriginalSoundbankPlatform platform{
        &c, reference, [](void*, void*) { return false; }, nullptr, string_length, system_path,
        path_is_file, [](void*, void* source) { return source; }, resource_path,
        [](void* ctx, void*) -> void* { return static_cast<Context*>(ctx)->posix; },
        [](void* ctx, void*) -> void* { return static_cast<Context*>(ctx)->name; },
        construct_archive, nullptr, nullptr, nullptr,
        [](void* ctx, void*) -> void* { return static_cast<Context*>(ctx)->name; },
        dictionary_get, number_float, diagnostic
    };
    const ElastikOriginalSoundbankReadOnly reader{
        &c, &c.opening, &c.factory, container, path_string, make_document
    };
    bool ok = true;
    for (const auto op : ops) {
        void* returned = nullptr;
        switch (op) {
            case 1: returned = elastik_original_bank_archive_readonly(&bank, &platform, &reader); break;
            case 2: elastik_original_bank_set(&bank, ElastikBankSource, bank.source_path, &platform); break;
            case 3: elastik_original_bank_clear(&bank, &platform); break;
            case 4: c.active = 1; break;
            case 5: elastik_original_bank_set_file(&bank, reinterpret_cast<void*>(1), &platform); break;
            default: std::abort();
        }
        ok = snapshot(c, bank, returned) && ok;
    }
    elastik_original_bank_clear(&bank, &platform);
    release(c, c.posix);
    release(c, c.name);
    if (c.live) std::abort();
    return ok && scalar(static_cast<uint32_t>(c.diagnostics.size())) &&
           write(c.diagnostics.data(), c.diagnostics.size());
}

} // namespace

int main() {
    for (;;) {
        uint32_t header[6];
        const size_t size = std::fread(header, 1, sizeof(header), stdin);
        if (!size && std::feof(stdin)) return 0;
        if (size != sizeof(header) || !run(header) || std::fflush(stdout)) return 2;
    }
}
