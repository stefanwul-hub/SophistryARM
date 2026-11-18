// Read-only audit of the unchanged public LegacyEngine host API.
// No licence, local preferences, presets or sound-bank files are used.
#include "../../src/engine/LegacyEngine.h"
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>
#ifdef SOPHISTRY_AUDIT_WRAP_SL_RUN
#include "../../src/engine/LegacyImageData.h"
#include "../../src/lifter/LifterRuntime.h"
#include <cstring>
#include <map>
#include <string>

namespace {
SlCpu *observedCpu = nullptr;
std::map<std::uint32_t, std::uint32_t> uppCallbacks;
std::uint32_t pendingUppCallback = 0;
struct TimerRecord {
  std::uint32_t callback;
  double delay, interval;
};
std::vector<TimerRecord> registeredTimers;
template <class T> T guest(SlCpu *cpu, std::uint32_t address) {
  T out{};
  if (sl_mem_read(cpu, address, &out, sizeof(out)))
    throw std::runtime_error("Audit read exceeds guest memory");
  return out;
}
} // namespace

// GNU link-time interception, only in this Linux audit executable. It reads
// import arguments and instruction coverage; it does not change CPU state.
extern "C" int __real_sl_run(SlCpu *, SlU32, SlU32, SlU64);
extern "C" int __wrap_sl_run(SlCpu *cpu, SlU32 entry, SlU32 stop, SlU64 limit) {
  observedCpu = cpu;
  if (pendingUppCallback) {
    std::uint32_t token = 0;
    if (sl_reg_read(cpu, 0, &token, 4))
      throw std::runtime_error("Audit register read failed");
    uppCallbacks[token] = pendingUppCallback;
    pendingUppCallback = 0;
  }
  int result = __real_sl_run(cpu, entry, stop, limit);
  if (result != 3)
    return result;
  std::string name;
  for (std::size_t i = 0; i < sophistry::legacy_import_count; ++i)
    if (sophistry::legacy_imports[i].address == cpu->pc)
      name = sophistry::legacy_imports[i].name;
  std::uint32_t sp = 0;
  if (sl_reg_read(cpu, 0x10, &sp, 4))
    throw std::runtime_error("Audit stack read failed");
  if (name == "_NewEventLoopTimerUPP")
    pendingUppCallback = guest<std::uint32_t>(cpu, sp + 4);
  else if (name == "_InstallEventLoopTimer") {
    auto token = guest<std::uint32_t>(cpu, sp + 24);
    registeredTimers.push_back({uppCallbacks.at(token),
                                guest<double>(cpu, sp + 8),
                                guest<double>(cpu, sp + 16)});
  }
  return result;
}
#endif

namespace {
std::uint32_t word(const std::vector<std::uint8_t> &bytes, unsigned offset) {
  std::uint32_t result = 0;
  for (unsigned i = 0; i < 4; ++i)
    result |= std::uint32_t(bytes.at(offset + i)) << (i * 8);
  return result;
}
void observe(sophistry::LegacyEngine &engine, const char *stage) {
  auto snapshot = engine.objectSnapshot();
  std::cout << "{\"stage\":\"" << stage << "\",\"queue_capacity\":"
            << word(snapshot, 0x38bc) << ",\"queue_write_index\":"
            << word(snapshot, 0x38c4) << ",\"queue_read_index\":"
            << word(snapshot, 0x38c8) << ",\"last_idle_milliseconds\":"
            << word(snapshot, 0xd270) << ",\"original_idle_available_flag\":"
            << unsigned(snapshot.at(0xcfd6))
            << ",\"original_au_idle_requested_flag\":"
            << unsigned(snapshot.at(0x32b32c));
#ifdef SOPHISTRY_AUDIT_WRAP_SL_RUN
  std::cout << ",\"original_au_timer_entry_executed\":"
            << (observedCpu && observedCpu->seen[0x3aba] ? "true" : "false")
            << ",\"original_synth_idle_entry_executed\":"
            << (observedCpu && observedCpu->seen[0x1a54a] ? "true" : "false")
            << ",\"registered_timers\":[";
  bool first = true;
  for (const auto &timer : registeredTimers) {
    if (!first)
      std::cout << ',';
    first = false;
    std::cout << "{\"callback\":" << timer.callback
              << ",\"delay\":" << timer.delay
              << ",\"interval\":" << timer.interval << '}';
  }
  std::cout << ']';
#endif
  std::cout << ",\"engine\":" << engine.diagnosticJson() << "}\n";
}
} // namespace

int main() {
  try {
    sophistry::LegacyEngineConfig config;
    config.audioUnitMode = true;
    sophistry::LegacyEngine engine(config);
    engine.initialize();
    observe(engine, "initialized");
    engine.activate();
    observe(engine, "active_without_registration_or_notes");
    auto info = engine.auParameterInfo(134);
    float value = engine.auParameter(134);
    engine.setAUParameter(134, std::clamp(value + 0.1f, info.minimum, info.maximum));
    engine.setAUParameter(134, std::clamp(value + 0.2f, info.minimum, info.maximum));
    observe(engine, "after_public_parameter_edits");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    // The Cocoa refresh uses public read-only getters. Exercise those here.
    engine.presetName();
    engine.completeEditor(0);
    observe(engine, "after_300ms_and_editor_getters");
    engine.deactivate();
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
