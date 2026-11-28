#include "../src/OriginalProgramSamples.h"
#include "../src/OriginalWaveAdpcm.h"
#include "../src/OriginalWaveChunks.h"
#include "ArchiveNameFixture.h"

#include <deque>
#include <memory>
#include <utility>

namespace WaveFixture {
#define main elastik_sample_fixture_wave_main
#include "WaveProbe.cpp"
#undef main
}

namespace {

using namespace elastik_state;

namespace BankFixture = ArchiveNameFixture;

enum Event { System = 1, IsFile, FindBank, Archive, MemberName, OpenSample };

void free_wave(WaveFixture::Context* c) {
    for (int i = 0; i < c->node_count; ++i) {
        auto* node = c->nodes[i];
        if (node->kind == ElastikWaveDictionary) {
            for (int j = 0; j < node->length; ++j) free(node->keys[j]);
        }
        free(node->keys);
        free(node->items);
        free(node->data);
        free(node);
    }
    for (int i = 0; i < c->allocation_count; ++i) free(c->allocations[i]);
    free(c);
}

struct FixtureSample {
    ElastikOriginalFileOpenState open{};
    ElastikOriginalSampleFile file{};
    ElastikOriginalFileReader reader{};
    ElastikOriginalWave wave{};
    ElastikOriginalWaveIO io{};
    std::unique_ptr<WaveFixture::Context, decltype(&free_wave)> context{nullptr, free_wave};
    std::vector<unsigned char> bytes;
};

int frames(void* p) {
    return static_cast<FixtureSample*>(p)->wave.frames;
}

bool read_samples(void* p, float* const* output, int first, int count) {
    auto& sample = *static_cast<FixtureSample*>(p);
    std::vector<uint8_t> scratch(static_cast<size_t>(count) * sample.wave.block_align);
    ElastikOriginalReadBuffer buffer{scratch.data(), static_cast<int>(scratch.size())};
    const ElastikOriginalWaveReadPlatform platform{sample.context.get(), WaveFixture::allocate_block,
                                                    WaveFixture::release_block};
    return elastik_original_read_wave(&sample.wave, &buffer, output, first, count, &sample.io.bytes,
                                     &platform) == ElastikWaveOk;
}

bool open_wave(FixtureSample& sample) {
    sample.context.reset(static_cast<WaveFixture::Context*>(calloc(1, sizeof(WaveFixture::Context))));
    auto* c = sample.context.get();
    c->raw = sample.bytes.data();
    c->size = static_cast<int>(sample.bytes.size());
    c->fail_read = -1;
    c->maximum = -1;
    c->open_ok = 1;
    sample.wave.metadata = WaveFixture::node(c, ElastikWaveDictionary);
    sample.io = {{c, WaveFixture::seek, WaveFixture::read}, WaveFixture::open, WaveFixture::retain,
                 WaveFixture::position, WaveFixture::length, false, WaveFixture::diagnostic};
    const ElastikOriginalWaveObjects objects{
        c, WaveFixture::create, WaveFixture::set, WaveFixture::get, WaveFixture::append,
        WaveFixture::count, WaveFixture::bytes, WaveFixture::resize, WaveFixture::read_data,
        WaveFixture::decode, WaveFixture::chunk_name, WaveFixture::allocate_dvi
    };
    if (elastik_original_wave_open(&sample.wave, &sample.io, &objects) != ElastikWaveOk) return false;
    sample.reader.samples = {&sample, frames, read_samples};
    return true;
}

struct Context {
    BankFixture::Context* bank{};
    ElastikOriginalArchiveContainer archive{};
    std::deque<ElastikOriginalArchivePath> paths;
    std::vector<uint32_t> events;
    FixtureSample* pending{};
    std::map<const ElastikOriginalFileOpenState*, FixtureSample*> sample_bytes;
    bool broken{};
    bool disk_exists{};
    int disk_token{};
    int bank_token{};
};

void* system_path(void* p, std::u16string_view name) {
    auto& c = *static_cast<Context*>(p);
    c.events.push_back(System);
    c.broken = name == u"/disk/broken.wav";
    c.disk_exists = c.broken || name == u"/disk/ok.wav";
    return c.disk_exists || name == u"/disk/absent.wav" ? &c.disk_token : nullptr;
}

bool is_file(void* p, void*) {
    auto& c = *static_cast<Context*>(p);
    c.events.push_back(IsFile);
    return c.disk_exists;
}

void* find_bank(void* p, std::u16string_view id) {
    auto& c = *static_cast<Context*>(p);
    c.events.push_back(FindBank);
    return id == u"bank-A" || id == u"bank-B" ? &c.bank_token : nullptr;
}

ElastikOriginalArchiveContainer* bank_archive(void* p, void*) {
    auto& c = *static_cast<Context*>(p);
    c.events.push_back(Archive);
    return &c.archive;
}

void* archive_string(void* p, std::u16string_view name) {
    auto& c = *static_cast<Context*>(p);
    c.events.push_back(MemberName);
    auto& bank = *c.bank;
    free(bank.path_units);
    bank.path_units = static_cast<uint16_t*>(calloc(name.size() + 1, sizeof(uint16_t)));
    for (size_t i = 0; i < name.size(); ++i) bank.path_units[i] = name[i];
    bank.path_length = static_cast<int>(name.size());
    return bank.path_units;
}

ElastikOriginalArchivePath* make_path(void* p) {
    auto& c = *static_cast<Context*>(p);
    c.paths.push_back(c.bank->path);
    return &c.paths.back();
}

int string_length(void* p, void*) {
    return static_cast<Context*>(p)->bank->path_length;
}

uint16_t character(void* p, void*, int index) {
    return static_cast<Context*>(p)->bank->path_units[index];
}

void* retain_string(void*, void* value) { return value; }
void retain_owner(void*, void*) {}

OpenedSample create_sample(void* p) {
    auto& c = *static_cast<Context*>(p);
    c.events.push_back(OpenSample);
    auto sample = std::make_shared<FixtureSample>();
    c.pending = sample.get();
    sample->open.file = &sample->file;
    c.sample_bytes[&sample->open] = sample.get();
    return {sample, &sample->open};
}

ElastikOriginalFileReader* construct_reader(void* p, int format) {
    return format == 1 ? &static_cast<Context*>(p)->pending->reader : nullptr;
}

ElastikOriginalFileReader* keep_reader(void*, ElastikOriginalFileReader* reader) { return reader; }

ElastikOriginalFileStatus open_reader(void* p, ElastikOriginalFileReader*, void* path) {
    auto& c = *static_cast<Context*>(p);
    auto& bytes = c.pending->bytes;
    if (path == &c.disk_token) {
        if (c.broken) return ElastikFileCannotRead;
        bytes = {'d', 'i', 's', 'k'};
        return ElastikFileOk;
    }
    auto* member = static_cast<ElastikOriginalArchivePath*>(path);
    ElastikArchiveStatus status;
    auto* file = elastik_original_archive_open_file(member, &c.bank->factory, &status);
    if (!file || status != ElastikArchiveOk) return ElastikFileCannotRead;
    const auto size = elastik_original_archive_file_size(member);
    if (!size || size > static_cast<uint32_t>(c.bank->h[0])) return ElastikFileCannotRead;
    bytes.resize(size);
    int count = static_cast<int>(size);
    const bool read = elastik_original_archive_read_member(&file->member, bytes.data(), &count, &status);
    if (!read || count != static_cast<int>(size) || status != ElastikArchiveOk) return ElastikFileCannotRead;
    return open_wave(*c.pending) ? ElastikFileOk : ElastikFileCannotRead;
}

void object_operation(void*, int, void*) {}
unsigned channels(void* p, ElastikOriginalFileReader*) {
    const auto& wave = static_cast<Context*>(p)->pending->wave;
    return wave.channels ? wave.channels : 2;
}
double rate(void* p, ElastikOriginalFileReader*) {
    const auto& wave = static_cast<Context*>(p)->pending->wave;
    return wave.sample_rate ? wave.sample_rate : 44100;
}
unsigned format(void* p, ElastikOriginalFileReader*) {
    return elastik_original_wave_sample_format(&static_cast<Context*>(p)->pending->wave);
}
int kind(void*, ElastikOriginalFileReader*) { return 1; }
void metadata(void*, ElastikOriginalFileReader*, void*) {}
void* no_partner(void*, void*, int*) { return nullptr; }

template <class T>
bool write(T value) {
    return std::fwrite(&value, sizeof(value), 1, stdout) == 1;
}

bool write_audio(const FixtureSample& sample) {
    const auto* reader = sample.file.reader;
    if (!reader || !reader->frame_count) return write(uint32_t{0});
    if (sample.file.channel_format != 2 || sample.file.sample_rate != 44100) return false;
    const auto count = reader->frame_count(reader->context);
    if (!write(static_cast<uint32_t>(count))) return false;
    std::vector<float> left(count), right(count);
    float* const outputs[]{left.data(), right.data()};
    if (!reader->read(reader->context, outputs, 0, count)) return false;
    for (const auto& channel : {&left, &right}) {
        if (std::fwrite(channel->data(), sizeof(float), channel->size(), stdout) != channel->size()) return false;
    }
    return true;
}

bool report(const std::vector<SampleLookup>& lookups, const Context& context) {
    std::map<const ElastikOriginalFileOpenState*, uint32_t> samples;
    if (!write(static_cast<uint32_t>(lookups.size()))) return false;
    for (const auto& lookup : lookups) {
        if (!write(lookup.status) || !write(static_cast<uint8_t>(lookup.archive_status)) ||
            !write(static_cast<uint8_t>(lookup.file_status))) return false;
        if (!lookup.sample) {
            if (!write(uint32_t{0})) return false;
            continue;
        }
        const auto [entry, added] = samples.emplace(lookup.sample.get(), static_cast<uint32_t>(samples.size() + 1));
        if (!write(entry->second)) return false;
        if (added) {
            const auto& sample = *context.sample_bytes.at(lookup.sample.get());
            const auto& bytes = sample.bytes;
            if (!write(static_cast<uint32_t>(bytes.size())) ||
                std::fwrite(bytes.data(), 1, bytes.size(), stdout) != bytes.size() || !write_audio(sample)) {
                return false;
            }
        }
    }
    if (!write(static_cast<uint32_t>(context.events.size()))) return false;
    for (auto event : context.events) {
        if (!write(event)) return false;
    }
    return true;
}

bool report_preparation(ProgramSampleResolver& resolver, const ProgramState& program) {
    for (const auto& mapping : program.mappings) {
        const auto prepared = resolver.prepare_sample(program, mapping);
        const auto& plan = prepared.plan;
        if (!write(prepared.source.status) || !write(plan.kind) ||
            !write(plan.file_tempo) || !write(plan.source_rate) || !write(plan.target_tempo) ||
            !write(plan.tempo_ratio) || !write(plan.stretch_ratio) || !write(plan.pitch_ratio) ||
            !write(plan.shifter_mode) || !write(plan.program_algorithm) || !write(plan.processor_mode) ||
            !write(plan.output_frames.value_or(-1))) return false;
    }
    return true;
}

bool run(const uint32_t* header) {
    std::string state(header[0], '\0');
    if (std::fread(state.data(), 1, state.size(), stdin) != state.size()) return false;
    auto decoded = decode_program_state(state);
    if (!decoded.program) return false;

    using BankPtr = std::unique_ptr<BankFixture::Context, decltype(&BankFixture::cleanup)>;
    BankPtr bank(static_cast<BankFixture::Context*>(calloc(1, sizeof(BankFixture::Context))), BankFixture::cleanup);
    bank->raw = static_cast<unsigned char*>(malloc(header[1]));
    if (std::fread(bank->raw, 1, header[1], stdin) != header[1]) return false;
    const int inputs[]{static_cast<int>(header[1]), 0, 0, 0, static_cast<int>(header[2] & 1), 1, 0, 1, 0};
    if (BankFixture::prepare(bank.get(), inputs) != ElastikArchiveOk) return false;
    bank->archive.read_only = true;

    Context context{};
    context.bank = bank.get();
    context.archive = {&bank->archive, bank->archive.stream, &context.bank_token};
    const ElastikOriginalArchiveOpenPlatform paths{
        &context, nullptr, nullptr, make_path, string_length, character, retain_string, retain_owner
    };
    const ElastikOriginalFileOpenPlatform files{
        &context, construct_reader, keep_reader, keep_reader, open_reader, object_operation,
        channels, rate, format, kind, metadata, no_partner, nullptr
    };
    ProgramSampleResolver resolver({
        &context, system_path, is_file, find_bank, bank_archive, archive_string, &paths, create_sample, &files
    });
    if (header[2] & 2) return report_preparation(resolver, *decoded.program);
    return report(resolver.resolve_program(*decoded.program), context);
}

} // namespace

int main() {
    for (;;) {
        uint32_t header[3];
        const auto n = std::fread(header, 1, sizeof(header), stdin);
        if (!n && std::feof(stdin)) return 0;
        if (n != sizeof(header) || !run(header) || std::fflush(stdout)) return 2;
    }
}
