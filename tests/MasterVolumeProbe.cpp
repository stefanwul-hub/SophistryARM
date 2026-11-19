#include "../src/engine/LegacyEngine.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iterator>
#include <stdexcept>
int main(int argc, char **argv) {
  try {
    if (argc != 3)
      throw std::runtime_error("Expected public FXP and sample folder");
    sophistry::LegacyEngineConfig c;
    c.audioUnitMode = true;
    c.recycleFreedBlocks = true;
    c.collectDiagnostics = false;
    c.assetDirectories = {argv[2]};
    sophistry::LegacyEngine e(c);
    e.initialize();
    const auto initial = e.auParameter(134);
    std::ifstream f(argv[1], std::ios::binary);
    std::vector<unsigned char> b((std::istreambuf_iterator<char>(f)), {});
    if (b.size() < 60 || std::memcmp(b.data(), "CcnK", 4) ||
        std::memcmp(b.data() + 8, "FPCh", 4))
      throw std::runtime_error("Expected original FXP chunk");
    e.restoreChunk({b.begin() + 60, b.end()}, true);
    const auto imported = e.auParameter(134);
    e.setAUParameter(134, 0);
    auto program = e.saveProgram();
    e.setAUParameter(134, -12);
    e.restoreChunk(program, true);
    const auto programResult = e.auParameter(134);
    if (programResult != 0)
      throw std::runtime_error("Program Master restoration failed");
    e.setAUParameter(134, 0);
    auto bank = e.saveBank();
    e.setAUParameter(134, -12);
    e.restoreChunk(bank, false);
    const auto bankResult = e.auParameter(134);
    if (bankResult != 0)
      throw std::runtime_error("Bank Master restoration failed");
    unsigned recallChecks = 0;
    for (float db : {-12.0f, -6.0f, 0.0f}) {
      e.setAUParameter(134, db);
      const auto stored = e.auParameter(134);
      const auto savedProgram = e.saveProgram(), savedBank = e.saveBank();
      e.setAUParameter(134, -3);
      e.restoreChunk(savedProgram, true);
      if (e.auParameter(134) != stored)
        throw std::runtime_error("Saved program Master changed");
      ++recallChecks;
      e.setAUParameter(134, -3);
      e.restoreChunk(savedBank, false);
      if (e.auParameter(134) != stored)
        throw std::runtime_error("Saved bank Master changed");
      ++recallChecks;
    }
    std::printf(
        "{\"passed\":true,\"musical_audio_tested\":false,\"initial_master_db\":"
        "%.9g,\"fxp_master_db\":%.9g,\"program_saved_master_db\":0,\"master_"
        "before_program_restore_db\":-12,\"master_after_program_restore_db\":%."
        "9g,\"bank_saved_master_db\":0,\"master_before_bank_restore_db\":-12,"
        "\"master_after_bank_restore_db\":%.9g,\"program_bytes\":%zu,\"bank_"
        "bytes\":%zu,\"saved_level_recall_checks\":%u}\n",
        initial, imported, programResult, bankResult, program.size(),
        bank.size(), recallChecks);
    return 0;
  } catch (const std::exception &e) {
    std::fprintf(stderr, "%s\n", e.what());
    return 1;
  }
}
