// Regression checks for the guest AU bridge, executable without Apple
// frameworks. Without a licence these checks establish lifecycle/ABI behavior,
// not synthesis.
#include "../src/engine/LegacyEngine.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>
int main(int argc, char **argv) {
  std::string stage = "arguments";
  unsigned cycles = 0, parameters = 0;
  try {
    if (argc != 3)
      throw std::runtime_error("Expected FXP file and asset directory");
    std::ifstream input(argv[1], std::ios::binary);
    std::vector<std::uint8_t> raw((std::istreambuf_iterator<char>(input)), {});
    if (raw.size() < 60 ||
        std::string(raw.begin(), raw.begin() + 4) != "CcnK" ||
        std::string(raw.begin() + 8, raw.begin() + 12) != "FPCh")
      throw std::runtime_error("Invalid FXP fixture");
    std::vector<std::uint8_t> chunk(raw.begin() + 60, raw.end());
    sophistry::LegacyEngineConfig config;
    config.audioUnitMode = true;
    config.recycleFreedBlocks = true;
    config.recursiveAssetSearch = true;
    config.guestMemoryBytes = 256u * 1024u * 1024u;
    config.assetDirectories = {argv[2]};
    sophistry::LegacyEngine engine(config);
    engine.initialize();
    stage = "AU parameter metadata";
    auto ids = engine.auParameterIds();
    if (ids.size() != 522 ||
        std::set<std::uint32_t>(ids.begin(), ids.end()).size() != 522)
      throw std::runtime_error("AU parameter IDs");
    for (auto id : ids) {
      auto info = engine.auParameterInfo(id);
      float value = engine.auParameter(id);
      if (info.name.empty() || !std::isfinite(value) ||
          !std::isfinite(info.minimum) || !std::isfinite(info.maximum) ||
          !std::isfinite(info.defaultValue))
        throw std::runtime_error("AU parameter metadata");
      engine.setAUParameter(id, value);
      ++parameters;
    }
    if (engine.validAUParameter(603))
      throw std::runtime_error("Invalid AU ID accepted");
    stage = "AU bank round trip";
    engine.restoreChunk(chunk, true);
    auto bank = engine.saveBank();
    engine.restoreChunk(bank, false);
    // The original bank loader clears SYG0 field 21 (SynthEdited).
    // Check stability after that original transition, without patching bytes.
    bank = engine.saveBank();
    engine.restoreChunk(bank, false);
    if (bank != engine.saveBank())
      throw std::runtime_error("Bank changed on round trip");
    for (auto spec :
         std::array<std::array<unsigned, 3>, 8>{{{2, 44100, 512},
                                                 {6, 48000, 1024},
                                                 {2, 96000, 128},
                                                 {6, 44100, 512},
                                                 {2, 22050, 64},
                                                 {2, 96000, 137},
                                                 {2, 48000, 4096},
                                                 {2, 192000, 4096}}}) {
      stage = "AU lifecycle cycle " + std::to_string(cycles) +
              " rate=" + std::to_string(spec[1]) +
              " maxFrames=" + std::to_string(spec[2]);
      engine.setAudioUnitOutputChannels(spec[0]);
      engine.setSampleRate(float(spec[1]));
      engine.setBlockSize(spec[2]);
      engine.activate();
      bool refused = false;
      try {
        engine.persistValidatedRegistration();
      } catch (const std::runtime_error &e) {
        refused = std::string(e.what()).find(
                      "Original registration rejected") != std::string::npos;
      }
      if (!refused)
        throw std::runtime_error(
            "Unregistered preference write was not refused");
      engine.restoreChunk(chunk, true);
      std::vector<std::vector<float>> buffers(spec[0],
                                              std::vector<float>(spec[2]));
      std::vector<float *> pointers;
      for (auto &b : buffers)
        pointers.push_back(b.data());
      sophistry::LegacyTransport transport;
      transport.tempoValid = transport.transportValid =
          transport.musicalLocationValid = true;
      transport.tempo = 137;
      transport.playing = true;
      transport.timeSignatureNumerator = 7;
      transport.timeSignatureDenominator = 8;
      transport.beat = 3.25;
      transport.measureStartBeat = 0;
      transport.samplePosition = 0;
      engine.midi(0x90, 60, 100);
      engine.setTransport(transport);
      engine.process(pointers.data(), spec[0], 1);
      transport.samplePosition = 1;
      transport.beat += 1.0 / spec[1] * 137 / 60;
      engine.setTransport(transport);
      engine.midi(0x80, 60, 0, spec[2] - 1);
      engine.process(pointers.data(), spec[0], spec[2]);
      for (auto &b : buffers)
        for (float v : b)
          if (!std::isfinite(v))
            throw std::runtime_error("Non-finite AU audio");
      engine.resetAudioUnit();
      engine.deactivate();
      ++cycles;
    }
    std::cout << "{\"passed\":true,\"parameter_records\":" << parameters
              << ",\"reinitialization_cycles\":" << cycles
              << ",\"channels\":[2,6],\"sample_rates\":[22050,44100,48000,"
                 "96000,192000],"
                 "\"licensed_musical_audio_tested\":false}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << stage << ": " << e.what() << '\n';
    std::cout << "{\"passed\":false,\"parameter_records\":" << parameters
              << ",\"reinitialization_cycles\":" << cycles << "}\n";
    return 1;
  }
}
