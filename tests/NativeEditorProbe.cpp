// Public inputs only: original Main/Filter control state and translated paths.
#include "../src/engine/LegacyEngine.h"
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
static void require(bool ok, const char *message) {
  if (!ok)
    throw std::runtime_error(message);
}
using Bytes = std::vector<std::uint8_t>;
static Bytes load(const char *p) {
  std::ifstream f(p, std::ios::binary);
  Bytes b((std::istreambuf_iterator<char>(f)), {});
  require(b.size() > 60, "Invalid public FXP");
  return {b.begin() + 60, b.end()};
}
static void save(const std::string &p, const void *data, std::size_t n) {
  std::ofstream f(p, std::ios::binary);
  f.write(static_cast<const char *>(data), n);
  require(bool(f), "Cannot save editor comparison output");
}
int main(int argc, char **argv) {
  try {
    require(argc == 5, "Expected public FXP, samples, loop fixture and prefix");
    sophistry::LegacyEngineConfig c;
    c.audioUnitMode = true;
    c.recycleFreedBlocks = true;
    c.guestMemoryBytes = sophistry::productionGuestMemoryBytes;
    c.assetDirectories = {argv[2]};
    sophistry::LegacyEngine e(c);
    e.initialize();
    e.restoreChunk(load(argv[1]), true);
    std::string prefix = argv[4];
    std::filesystem::create_directories(
        std::filesystem::path(prefix).parent_path());
    std::ofstream meta(prefix + "-metadata.json");
    meta << std::setprecision(9) << "[";
    unsigned records = 0;
    auto before = e.saveProgram();
    for (unsigned p = 0; p < 2; ++p) {
      auto panel = e.editorPanel(p);
      require(panel.count > 0, "Empty editor panel");
      for (unsigned i = 0; i < panel.count; ++i) {
        auto &x = panel.controls[i];
        require(std::isfinite(x.normalized) && x.normalized >= 0 &&
                    x.normalized <= 1,
                "Invalid normalized value");
        if (records++)
          meta << ",";
        meta << "{\"tag\":" << x.value.tag
             << ",\"name\":" << std::quoted(x.value.name)
             << ",\"text\":" << std::quoted(x.value.text)
             << ",\"value\":" << x.value.value
             << ",\"normalized\":" << x.normalized << "}";
      }
    }
    meta << "]\n";
    meta.close();
    unsigned restoredControls = 0;
    for (unsigned panelID = 0; panelID < 2; ++panelID) {
      auto panel = e.editorPanel(panelID);
      for (unsigned i = 0; i < panel.count; ++i) {
        auto control = panel.controls[i];
        auto tag = control.value.tag;
        if (!(tag == 958 || tag == 614 || tag == 482 ||
              (tag >= 114 && tag <= 117) || (tag >= 585 && tag <= 600)))
          continue;
        e.setEditorControl(tag, control.normalized < .4f ? .82f : .17f);
        e.setEditorControl(tag, control.normalized);
        auto restored = e.editorPanel(panelID);
        bool exact = false;
        for (unsigned j = 0; j < restored.count; ++j)
          if (restored.controls[j].value.tag == tag)
            exact = restored.controls[j].value.value == control.value.value;
        require(exact,
                "Original normalized field/XY restore changed its value");
        ++restoredControls;
      }
    }
    // Restoring a value marks a preset edited; retain the independent drawing
    // comparison's initial serialized state and original cross positions.
    e.restoreChunk(load(argv[1]), true);
    before = e.saveProgram();
    for (unsigned i = 0; i < 8; ++i) {
      auto d = e.editorDrawing(i);
      require(d.count == 10, "XY cross differs from original ten-line design");
      save(prefix + "-xy" + std::to_string(i) + ".bin", &d, sizeof(d));
    }
    require(before == e.saveProgram(), "Preview changed program state");
    std::ofstream inputs(prefix + "-inputs.json");
    inputs << std::setprecision(9) << "[";
    unsigned edits = 0, cases = 0;
    for (unsigned stage = 0; stage < 5; ++stage) {
      if (stage)
        inputs << ",";
      inputs << "[";
      bool comma = false;
      auto set = [&](unsigned tag, float n) {
        e.setEditorControl(tag, n);
        if (comma)
          inputs << ",";
        comma = true;
        inputs << "[" << tag << "," << n << "]";
        ++edits;
      };
      if (stage)
        set(780 + (stage - 1) / 2, float((stage - 1) % 2));
      auto panel = e.editorPanel(stage ? 1 : 0);
      for (unsigned i = 0; i < panel.count; ++i) {
        auto tag = panel.controls[i].value.tag;
        if (tag == 780 || tag == 781)
          continue;
        set(tag, tag == 958 ? 0.55f : 0.37f);
      }
      inputs << "]";
      auto program = e.saveProgram();
      save(prefix + "-edited" + std::to_string(stage) + ".program",
           program.data(), program.size());
      ++cases;
    }
    inputs << "]\n";
    inputs.close();
    auto safe = e.saveProgram();
    unsigned rejected = 0;
    for (auto edit : std::vector<std::pair<unsigned, float>>{
             {765, .5f}, {9999, .5f}, {114, -.1f}, {958, 1.1f}}) {
      try {
        e.setEditorControl(edit.first, edit.second);
      } catch (const std::out_of_range &) {
        ++rejected;
      }
    }
    require(rejected == 4 && safe == e.saveProgram(),
            "Invalid editor input changed program");
    e.restoreChunk(load(argv[3]), true);
    auto loop = e.saveProgram();
    auto d = e.editorDrawing(8);
    require(d.sourceFrames == 334664 && d.count > 300,
            "Loop waveform is missing");
    save(prefix + "-wave.bin", &d, sizeof(d));
    require(loop == e.saveProgram(), "Waveform changed program");
    auto again = e.editorDrawing(8);
    require(!std::memcmp(&again, &d, sizeof(d)), "Cached waveform differs");
    require(e.editorDrawing(9).count == 0, "Empty sample produced a waveform");
    std::cout << "{\"passed\":true,\"xy_plots\":8,\"control_records\":"
              << records << ",\"normalized_edits\":" << edits
              << ",\"edited_programs\":" << cases
              << ",\"rejected_invalid_edits\":" << rejected
              << ",\"field_and_xy_value_roundtrips\":" << restoredControls
              << ",\"waveform_lines\":" << d.count
              << ",\"source_frames\":" << d.sourceFrames
              << ",\"preview_leaves_program_unchanged\":true,\"musical_audio_"
                 "tested\":false}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
