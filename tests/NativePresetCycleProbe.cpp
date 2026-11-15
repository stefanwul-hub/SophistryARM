// Repeated real sample-loader and serializer calls with deliberately little
// guest memory. Public generated fixtures only; this is not a licensed render.
#include "../src/engine/LegacyEngine.h"
#include "../src/lifter/LifterRuntime.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
using Bytes = std::vector<std::uint8_t>;
static std::uint64_t number(const std::string &json, const std::string &key) {
  const std::string token = "\"" + key + "\":";
  auto at = json.find(token);
  if (at == std::string::npos)
    throw std::runtime_error("Missing heap statistic");
  return std::stoull(json.substr(at + token.size()));
}
int main(int argc, char **argv) {
  try {
    if (argc != 2)
      throw std::runtime_error("Expected public sample-fixture folder");
    const std::filesystem::path root = argv[1];
    const std::vector<std::string> names{
        "wav-16-1",       "wav-24-1",       "wav-24-2",  "wav-32-2",
        "wav-float-32-1", "wav-float-32-2", "aiff-16-1", "aiff-24-2",
        "d4u-32-1",       "d4u-32-2",       "d4t-32-1",  "d4t-32-2"};
    sophistry::LegacyEngineConfig c;
    c.audioUnitMode = true;
    c.recycleFreedBlocks = true;
    c.guestMemoryBytes = 64u * 1024u * 1024u;
    sophistry::LegacyEngine engine(c);
    engine.initialize();
    std::map<std::string, Bytes> expected;
    std::uint64_t warmLive = 0, warmBlocks = 0, peak = 0;
    constexpr unsigned rounds = 8;
    for (unsigned round = 0; round < rounds; ++round) {
      for (const auto &name : names) {
        std::ifstream f(root / name / "program.FXP", std::ios::binary);
        Bytes raw((std::istreambuf_iterator<char>(f)), {});
        if (raw.size() < 60 ||
            std::string(raw.begin(), raw.begin() + 4) != "CcnK")
          throw std::runtime_error("Invalid public cycle fixture");
        engine.setAssetDirectories({(root / name).string()});
        engine.restoreChunk({raw.begin() + 60, raw.end()}, true);
        const auto saved = engine.saveProgram();
        if (!round)
          expected[name] = saved;
        else if (saved != expected.at(name))
          throw std::runtime_error(
              "Preset serialization changed during cycling: " + name);
        const auto status = engine.diagnosticJson();
        if (status.find("\"opened\":false") != std::string::npos)
          throw std::runtime_error("Cycle fixture sample was not found");
        peak = std::max(peak, number(status, "heap_high_water_bytes"));
      }
      const auto status = engine.diagnosticJson();
      const auto live = number(status, "heap_live_bytes");
      const auto blocks = number(status, "heap_live_blocks");
      if (round == 1) {
        warmLive = live;
        warmBlocks = blocks;
      }
      if (round > 1 && (live != warmLive || blocks != warmBlocks))
        throw std::runtime_error(
            "Live guest allocations accumulated during cycling");
    }
    // Exercise actual lazy zero-filled storage beyond the former 256 MiB
    // address cap without touching all 1 GiB or changing any DSP operation.
    SlCpu *cpu = sl_create(sophistry::productionGuestMemoryBytes);
    if (!cpu)
      throw std::runtime_error("Cannot reserve production guest arena");
    const unsigned locations[] = {0x1000, 0x11000000, 0x21000000, 0x3ffffff0};
    bool zero = true;
    for (auto address : locations) {
      zero = zero && cpu->memory[address] == 0;
      cpu->memory[address] = 0x5a;
    }
    sl_destroy(cpu);
    if (!zero)
      throw std::runtime_error("Lazy guest storage was not zero initialized");
    std::cout << "{\"passed\":true,\"sample_formats\":" << names.size()
              << ",\"rounds\":" << rounds
              << ",\"preset_loads\":" << rounds * names.size()
              << ",\"serialized_programs_unchanged\":true,\"live_allocations_"
                 "stable\":true,"
                 "\"test_guest_memory_bytes\":67108864,\"peak_reserved_bytes\":"
              << peak << ",\"final_live_bytes\":" << warmLive
              << ",\"final_live_blocks\":" << warmBlocks
              << ",\"production_virtual_bytes\":"
              << sophistry::productionGuestMemoryBytes
              << ",\"zero_filled_sparse_storage_checked\":true,\"licensed_"
                 "audio_tested\":false}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
