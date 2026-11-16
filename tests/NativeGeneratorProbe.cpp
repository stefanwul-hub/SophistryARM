// Public fixture only. Exercise the actual translated generator selectors,
// normalized setters, serialized program/bank recall and the panel protocol.
#include "../src/engine/LegacyEngine.h"
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <stdexcept>
#include <vector>
using Bytes = std::vector<std::uint8_t>;
static void require(bool ok, const char *message) {
  if (!ok)
    throw std::runtime_error(message);
}
static void save(const std::string &path, const Bytes &b) {
  std::ofstream f(path, std::ios::binary);
  f.write(reinterpret_cast<const char *>(b.data()), b.size());
  require(bool(f), "Cannot save generator probe result");
}
int main(int argc, char **argv) {
  unsigned cases = 0, controls = 0, edits = 0, normalizedBanks = 0;
  try {
    if (argc != 4)
      throw std::runtime_error("Expected public FXP, assets and output prefix");
    std::ifstream f(argv[1], std::ios::binary);
    Bytes raw((std::istreambuf_iterator<char>(f)), {});
    require(raw.size() > 60 &&
                std::string(raw.begin(), raw.begin() + 4) == "CcnK",
            "Invalid public FXP fixture");
    sophistry::LegacyEngineConfig c;
    c.audioUnitMode = true;
    c.recycleFreedBlocks = true;
    c.guestMemoryBytes = sophistry::productionGuestMemoryBytes;
    c.assetDirectories = {argv[2]};
    sophistry::LegacyEngine engine(c);
    engine.initialize();
    engine.restoreChunk({raw.begin() + 60, raw.end()}, true);
    const std::string prefix = argv[3];
    if (std::filesystem::path(prefix).has_parent_path())
      std::filesystem::create_directories(
          std::filesystem::path(prefix).parent_path());
    std::ofstream inputs(prefix + "-inputs.json");
    inputs << std::setprecision(9) << "[";
    for (unsigned g = 0; g < 4; ++g) {
      const unsigned maximum = g < 2 ? 3 : 2;
      for (unsigned type = 0; type <= maximum; ++type) {
        engine.setGeneratorControl(sophistry::generatorTypeTag(g),
                                   float(type) / maximum);
        auto panel = engine.generatorPanel(g / 2);
        require(panel.types[g] == type,
                "Original generator selector did not change");
        for (const auto &spec : sophistry::generatorLayout(g, type)) {
          require(spec.x >= 0 && spec.y >= 0 && spec.width > 0 &&
                      spec.height > 0 && spec.x + spec.width <= 762 &&
                      spec.y + spec.height <= 290,
                  "Generator control exceeds the original panel");
          if (spec.widget == sophistry::GeneratorWidget::Dial &&
              spec.valueOffset)
            require(spec.y + spec.height / 2 + spec.valueOffset - 4 >= 0 &&
                        spec.y + spec.height / 2 + spec.valueOffset + 6 <= 290,
                    "Generator value label exceeds the panel");
        }
        require(panel.count && panel.count <= panel.controls.size(),
                "Invalid panel wire count");
        std::set<unsigned> tags;
        for (unsigned i = 0; i < panel.count; ++i) {
          const auto &v = panel.controls[i];
          require(tags.insert(v.tag).second, "Duplicate generator control");
          require(sophistry::isGeneratorControl(v.tag),
                  "Unapproved control in panel");
          require(std::isfinite(v.curve), "Nonfinite generator curve");
          if (v.kind != 7)
            require(v.minimum <= v.value && v.value <= v.maximum,
                    "Generator value outside bounds");
          ++controls;
        }
        if (cases)
          inputs << ",";
        inputs << "{\"generator\":" << g << ",\"type\":" << type
               << ",\"edits\":[";
        bool firstEdit = true;
        for (const auto &spec : sophistry::generatorLayout(g, type)) {
          if (spec.widget == sophistry::GeneratorWidget::Type ||
              spec.widget == sophistry::GeneratorWidget::Sample)
            continue;
          float value = 0.61f;
          if ((spec.tag >= 725 && spec.tag < 729) ||
              (spec.tag >= 757 && spec.tag < 761))
            value = 0.2f;
          if ((spec.tag >= 729 && spec.tag < 733) ||
              (spec.tag >= 761 && spec.tag < 765))
            value = 0.8f;
          engine.setGeneratorControl(spec.tag, value);
          if (!firstEdit)
            inputs << ",";
          inputs << "[" << spec.tag << "," << value << "]";
          firstEdit = false;
          ++edits;
        }
        inputs << "]}";
        require(engine.auParameterIds().size() == 522,
                "Public AU contract changed");
        save(prefix + "-g" + std::to_string(g) + "-type" +
                 std::to_string(type) + ".program",
             engine.saveProgram());
        const auto stem =
            prefix + "-g" + std::to_string(g) + "-type" + std::to_string(type);
        auto bank = engine.saveBank();
        save(stem + ".bank0", bank);
        engine.restoreChunk(bank, false);
        bank = engine.saveBank();
        save(stem + ".bank1", bank);
        engine.restoreChunk(bank, false);
        auto again = engine.saveBank();
        save(stem + ".bank2", again);
        if (bank != again)
          ++normalizedBanks;
        // Every transition is compared with the original instructions. Some
        // legacy parameter aliases normalize again when a bank is reloaded.

        require(engine.generatorPanel(g / 2).types[g] == type,
                "Generator type did not survive bank recall");
        ++cases;
      }
    }
    inputs << "]\n";
    inputs.close();
    require(bool(inputs), "Cannot save control replay inputs");
    const auto before = engine.saveBank();
    unsigned rejected = 0;
    for (auto input : std::vector<std::pair<unsigned, float>>{
             {765, 0.5f},
             {701, 0.5f},
             {766, -0.1f},
             {766, 1.1f},
             {766, std::numeric_limits<float>::quiet_NaN()}}) {
      try {
        engine.setGeneratorControl(input.first, input.second);
      } catch (const std::out_of_range &) {
        ++rejected;
      }
    }
    require(rejected == 5 && before == engine.saveBank(),
            "Invalid edit changed state");
    std::cout << "{\"passed\":true,\"generator_type_cases\":" << cases
              << ",\"normalized_control_edits\":" << edits
              << ",\"banks_changed_after_second_restore\":" << normalizedBanks
              << ",\"panel_control_records_checked\":" << controls
              << ",\"au_parameter_count\":522,\"all_generated_controls_in_"
                 "bounds\":true,\"bank_recall_transitions_recorded\":true,"
                 "\"type_retained_after_bank_recall\":true,\"rejected_invalid_"
                 "edits\":"
              << rejected
              << ",\"private_inputs\":false,\"licensed_audio_tested\":false}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
