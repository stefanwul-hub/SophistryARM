#include "../src/engine/LegacyEngine.h"
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <stdexcept>
static void require(bool ok, const char *message) {
  if (!ok)
    throw std::runtime_error(message);
}
int main(int argc, char **argv) {
  try {
    require(argc == 4,
            "Expected original FXP, sample directory and output prefix");
    std::string prefix = std::filesystem::absolute(argv[3]).string();
    std::filesystem::create_directories(
        std::filesystem::path(prefix).parent_path());
    auto write = [&](const std::string &name, const void *data, std::size_t n) {
      std::ofstream f(prefix + name, std::ios::binary);
      f.write(static_cast<const char *>(data), n);
      require(bool(f), "Cannot write public comparison output");
    };
    auto hex = [](const char *data, std::size_t n) {
      static const char *digits = "0123456789abcdef";
      std::string out;
      for (std::size_t i = 0; i < n; ++i) {
        unsigned c = static_cast<unsigned char>(data[i]);
        out += digits[c >> 4];
        out += digits[c & 15];
      }
      return out;
    };
    std::ifstream file(argv[1], std::ios::binary);
    std::vector<std::uint8_t> fxp((std::istreambuf_iterator<char>(file)), {});
    require(fxp.size() > 60, "Invalid public fixture");
    sophistry::LegacyEngineConfig cfg;
    cfg.audioUnitMode = true;
    cfg.recycleFreedBlocks = true;
    cfg.guestMemoryBytes = sophistry::productionGuestMemoryBytes;
    cfg.assetDirectories = {argv[2]};
    sophistry::LegacyEngine e(cfg);
    e.initialize();
    e.restoreChunk({fxp.begin() + 60, fxp.end()}, true);
    std::set<unsigned> seen;
    unsigned pages = 0, choiceLists = 0;
    std::ofstream metadata(prefix + "-metadata.json");
    metadata << std::setprecision(9) << "[";
    bool first = true;
    auto inspect = [&](unsigned page) {
      auto before = e.saveProgram();
      auto state = e.completeEditor(page);
      require(state.page == page && state.count > 0, "Empty original page");
      for (unsigned i = 0; i < state.count; ++i) {
        auto &c = state.controls[i];
        require(c.value.tag != 765, "Registration exposed by editor state");
        require(std::isfinite(c.normalized), "Invalid editor normalized value");
        if (seen.insert(c.value.tag).second) {
          if (!first)
            metadata << ",";
          first = false;
          metadata << "{\"case\":" << pages << ",\"tag\":" << c.value.tag
                   << ",\"kind\":" << c.value.kind
                   << ",\"minimum\":" << c.value.minimum
                   << ",\"maximum\":" << c.value.maximum
                   << ",\"default\":" << c.value.defaultValue
                   << ",\"value\":" << c.value.value
                   << ",\"normalized\":" << c.normalized << ",\"name_hex\":\""
                   << hex(c.value.name,
                          strnlen(c.value.name, sizeof(c.value.name)))
                   << "\",\"text_hex\":\""
                   << hex(c.value.text,
                          strnlen(c.value.text, sizeof(c.value.text)))
                   << "\",\"choices\":[";
          auto choices = e.editorChoices(c.value.tag);
          for (unsigned j = 0; j < choices.count; ++j) {
            if (j)
              metadata << ",";
            metadata << "\""
                     << hex(choices.labels[j].data(),
                            strnlen(choices.labels[j].data(),
                                    choices.labels[j].size()))
                     << "\"";
          }
          metadata << "]}";
        }
        if (c.value.kind == 2) {
          auto choices = e.editorChoices(c.value.tag);
          require(choices.count ==
                      unsigned(c.value.maximum - c.value.minimum + 1),
                  "Original choices incomplete");
          ++choiceLists;
        }
      }
      require(before == e.saveProgram(),
              "Reading original editor page changed program");
      ++pages;
      std::cerr << "page " << page << " controls " << state.count << "\n";
    };
    for (unsigned page = 0; page < 9; ++page)
      inspect(page);
    for (unsigned g = 0; g < 4; ++g)
      for (unsigned type = 0; type < (g < 2 ? 4u : 3u); ++type) {
        e.setEditorControl(g < 2 ? 766 + g : 772 + g,
                           float(type) / (g < 2 ? 3 : 2));
        inspect(g < 2 ? 1 : 2);
      }
    for (unsigned slot = 0; slot < 6; ++slot)
      for (unsigned type = 0; type < 12; ++type) {
        e.setEditorControl(213 + slot, float(type) / 11);
        inspect(4);
      }
    for (unsigned lfo = 0; lfo < 4; ++lfo) {
      e.setEditorControl(606, float(lfo) / 3);
      inspect(5);
    }
    for (unsigned env = 0; env < 5; ++env) {
      e.setEditorControl(605, float(env) / 4);
      inspect(5);
    }
    metadata << "]\n";
    metadata.close();
    std::cerr << "all page reads complete\n";
    e.restoreChunk({fxp.begin() + 60, fxp.end()}, true);
    auto inspectUnchanged = [&](auto action) {
      auto before = e.saveProgram();
      action();
      auto after = e.saveProgram();
      if (before != after) {
        write("-read-before.program", before.data(), before.size());
        write("-read-after.program", after.data(), after.size());
      }
      require(before == after, "Read-only original helper changed program");
    };
    unsigned menus = 0;
    for (unsigned tag = 643; tag <= 647; ++tag)
      for (unsigned op = 0; op < 2; ++op) {
        inspectUnchanged([&] {
          auto info = e.editorFileInfo(tag, op);
          require(info.count > 0 && info.save == op,
                  "Original file dialog information incomplete");
          std::cerr << "file-info " << tag << " " << op << " " << info.title
                    << " " << info.extensions[0].data() << "\n";
        });
        ++menus;
      }
    auto numeric = [&](unsigned tag) {
      for (unsigned p = 0; p < 7; ++p) {
        auto state = e.completeEditor(p);
        for (unsigned i = 0; i < state.count; ++i)
          if (state.controls[i].value.tag == tag)
            return state.controls[i].value.value;
      }
      throw std::runtime_error("Parameter absent from active editor pages");
    };
    unsigned fileCount = 0;
    for (unsigned tag = 643; tag <= 647; ++tag) {
      auto info = e.editorFileInfo(tag, 1);
      auto path = prefix + "-module" + std::to_string(tag) + "." +
                  info.extensions[0].data();
      unsigned changed = tag == 643 ? 96 : tag < 647 ? 13 + tag - 644 : 649;
      auto baseline = numeric(changed);
      e.editorFileOperation(tag, 1, path);
      require(std::filesystem::file_size(path) > 0,
              "Empty original module file");
      e.setEditorControl(changed, .25f);
      e.editorFileOperation(tag, 0, path);
      require(numeric(changed) == baseline,
              "Original module file did not restore parameter");
      std::cerr << "file-roundtrip " << tag << "\n";
      ++fileCount;
    }
    for (unsigned operation : {4u, 5u}) {
      auto info = e.editorFileInfo(610, operation);
      require(info.count == 1 && info.save == unsigned(operation == 5),
              "Original MIDI file dialog information incomplete");
      ++menus;
    }
    e.editorFileOperation(610, 5, prefix + "-midi.mod");
    e.editorFileOperation(610, 4, prefix + "-midi.mod");
    ++fileCount;
    unsigned moduleEdits = 0;
    for (auto [menu, parameter] :
         std::array<std::pair<unsigned, unsigned>, 2>{{{643, 96}, {644, 13}}}) {
      e.setEditorControl(parameter, .75f);
      auto expected = numeric(parameter);
      e.setEditorControl(menu, .5f);
      e.setEditorControl(parameter, .25f);
      require(numeric(parameter) != expected,
              "Module mutation did not affect active generator");
      e.setEditorControl(menu, .75f);
      require(numeric(parameter) == expected,
              "Original module Copy/Paste failed");
      ++moduleEdits;
    }
    auto seq = e.editorString(648);
    require(seq.size() == 258, "Missing original sequence");
    seq[2] = 61;
    seq[3] = 101;
    e.setEditorString(648, seq);
    require(e.editorString(648) == seq,
            "Original arpeggiator byte edit failed");
    e.setEditorControl(647, .5f);
    auto arpBefore = e.editorString(648);
    auto arpChanged = arpBefore;
    arpChanged[2] = 73;
    e.setEditorString(648, arpChanged);
    e.setEditorControl(647, .75f);
    require(e.editorString(648) == arpBefore,
            "Original arpeggiator Copy/Paste failed");
    ++moduleEdits;
    auto program = e.saveProgram();
    write("-actions.program", program.data(), program.size());
    std::vector<sophistry::EditorKeyHit> keys;
    inspectUnchanged([&] {
      for (unsigned y : {0, 30, 59, 60, 94})
        for (unsigned x = 0; x < 648; ++x)
          keys.push_back(e.editorKeyHit(x, y));
    });
    write("-keys.bin", keys.data(), keys.size() * sizeof(keys[0]));
    std::vector<float> knobs;
    unsigned pointerKinds = 0;
    for (auto kind : std::array<sophistry::RecoveredWidget, 4>{
             sophistry::RecoveredWidget::Dial,
             sophistry::RecoveredWidget::Drawbar,
             sophistry::RecoveredWidget::ThinSlider,
             sophistry::RecoveredWidget::Scrollbar}) {
      unsigned key = 0;
      for (const auto &c : sophistry::recoveredControls())
        if (c.kind == kind &&
            (kind != sophistry::RecoveredWidget::Dial || c.tag == 114)) {
          key = c.key;
          break;
        }
      inspectUnchanged([&] {
        for (int y = -8; y <= 40; y += 4)
          for (int x = -8; x <= 40; x += 4)
            knobs.push_back(e.editorKnob(key, x, y));
      });
      ++pointerKinds;
    }
    write("-knobs.bin", knobs.data(), knobs.size() * 4);
    bool wrongModule = false;
    try {
      e.editorFileOperation(643, 0, prefix + "-module644.mod");
    } catch (const std::runtime_error &) {
      wrongModule = true;
    }
    require(wrongModule, "Original incompatible module type was accepted");
    auto loop = std::filesystem::path(argv[2]).parent_path().parent_path() /
                "tests/fixtures/loop-preview.fxp";
    std::ifstream loopFile(loop, std::ios::binary);
    std::vector<std::uint8_t> loopBytes(
        (std::istreambuf_iterator<char>(loopFile)), {});
    require(loopBytes.size() > 60, "Missing public Loop fixture");
    e.restoreChunk({loopBytes.begin() + 60, loopBytes.end()}, true);
    unsigned loopEdits = 0;
    for (auto [tag, value] : std::array<std::pair<unsigned, int>, 4>{
             {{950, 1024}, {952, 4096}, {954, 32000}, {956, 8000}}}) {
      e.setEditorString(tag, std::to_string(value));
      auto state = e.completeEditor(1);
      bool found = false;
      for (unsigned i = 0; i < state.count; ++i)
        if (state.controls[i].value.tag == tag)
          found = state.controls[i].value.value == value;
      require(found, "Numeric Loop text did not update original marker");
      ++loopEdits;
    }
    program = e.saveProgram();
    write("-loop-edited.program", program.data(), program.size());
    unsigned sampleActions = 0;
    for (unsigned command : {2u, 3u, 4u, 41u, 42u, 43u}) {
      e.restoreChunk({fxp.begin() + 60, fxp.end()}, true);
      if (command < 10) {
        e.setEditorControl(766, 1.f / 3);
        e.setEditorString(713, "BT_cronox18.wav");
      }
      auto it = std::find_if(
          sophistry::recoveredControls().begin(),
          sophistry::recoveredControls().end(), [&](const auto &c) {
            return c.kind == sophistry::RecoveredWidget::Action &&
                   unsigned(c.extra[0]) == command &&
                   (command < 10 ? c.extra[1] == 0 : c.extra[2] == 0);
          });
      require(it != sophistry::recoveredControls().end(),
              "Missing original sample command");
      e.editorAction(it->key);
      program = e.saveProgram();
      write("-sample-action" + std::to_string(command) + ".program",
            program.data(), program.size());
      ++sampleActions;
    }
    unsigned rejected = 0;
    for (auto tag : {765u, 962u}) {
      try {
        e.setEditorString(tag, "test");
      } catch (const std::out_of_range &) {
        ++rejected;
      }
      try {
        e.setEditorControl(tag, .5f);
      } catch (const std::out_of_range &) {
        ++rejected;
      }
    }
    require(rejected == 4, "Unexposed editor field accepted");
    std::cout << "{\"passed\":true,\"pages_and_modes\":" << pages
              << ",\"unique_controls\":" << seen.size()
              << ",\"choice_lists\":" << choiceLists
              << ",\"file_dialogs\":" << menus
              << ",\"file_roundtrips\":" << fileCount
              << ",\"module_copy_paste\":" << moduleEdits
              << ",\"key_hits\":" << keys.size()
              << ",\"knob_positions\":" << knobs.size()
              << ",\"pointer_kinds\":" << pointerKinds
              << ",\"numeric_loop_edits\":" << loopEdits
              << ",\"sample_actions\":" << sampleActions
              << ",\"wrong_module_rejected\":true,\"page_reads_leave_program_"
                 "unchanged\":true,\"musical_audio_tested\":false}\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
