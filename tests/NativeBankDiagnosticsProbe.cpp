// Verify that a missing sample is observable and a retained public preset can
// be reloaded after rebuilding the index. No licence or Mac preferences used.
#include "../src/engine/LegacyEngine.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
int main(int argc, char **argv) {
  try {
    if (argc != 4 && argc != 5)
      throw std::runtime_error(
          "Expected FXP, sample folder, unavailable folder");
    std::ifstream input(argv[1], std::ios::binary);
    std::vector<std::uint8_t> file((std::istreambuf_iterator<char>(input)), {});
    if (file.size() < 60)
      throw std::runtime_error("Invalid public FXP");
    std::vector<std::uint8_t> chunk(file.begin() + 60, file.end());
    sophistry::LegacyEngineConfig c;
    c.audioUnitMode = true;
    c.recycleFreedBlocks = true;
    c.recursiveAssetSearch = true;
    c.guestMemoryBytes = 256u * 1024u * 1024u;
    c.assetDirectories = {argv[3]};
    sophistry::LegacyEngine engine(c);
    engine.initialize();
    engine.restoreChunk(chunk, true);
    const auto missingProgram = engine.saveProgram();
    const auto missing = engine.diagnosticJson();
    if (missing.find("BT_cronox18.wav\",\"opened\":false") == std::string::npos)
      throw std::runtime_error("Missing sample was not reported");
    engine.setAssetDirectories({argv[2]});
    engine.restoreChunk(chunk, true);
    const auto reloaded = engine.diagnosticJson();
    if (reloaded.find("BT_cronox18.wav\",\"opened\":true") == std::string::npos)
      throw std::runtime_error("Reindexed sample was not reopened");
    if (reloaded.find(std::filesystem::absolute(argv[2]).string()) !=
        std::string::npos)
      throw std::runtime_error(
          "A private absolute folder leaked into diagnostics");
    auto before = engine.saveProgram();
    if (argc == 5) {
      for (const auto &entry :
           std::vector<std::pair<std::string, std::vector<std::uint8_t>>>{
               {"missing", missingProgram}, {"reloaded", before}}) {
        std::ofstream out(std::string(argv[4]) + "." + entry.first,
                          std::ios::binary);
        out.write(reinterpret_cast<const char *>(entry.second.data()),
                  entry.second.size());
      }
    }
    engine.setAudioUnitOutputChannels(2);
    engine.setSampleRate(44100);
    engine.setBlockSize(512);
    engine.activate();
    auto after = engine.saveProgram();
    if (before != after)
      throw std::runtime_error(
          "Pre-initialization program did not survive initialization");
    if (engine.presetName().empty())
      throw std::runtime_error("Original preset name is empty");
    std::cout << "{\"passed\":true,\"missing_sample_reported\":true,\"sample_"
                 "reopened_after_reindex\":true,\"preset_restored_before_"
                 "initialization_retained\":true,\"preset_name_available\":"
                 "true,\"private_absolute_paths_in_diagnostics\":false,"
                 "\"unlicensed_fixture_only\":true}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
