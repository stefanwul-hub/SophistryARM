#include "../src/engine/LegacyEngine.h"
#include "../src/engine/MonotonicClock.h"
#include <algorithm>
#include <cstdint>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) {
  try {
    sophistry::LegacyEngineConfig config;
    config.audioUnitMode = true;
    config.nativeMonotonicClock = argc == 2 && std::string(argv[1]) == "--native-clock";
    if (argc > 1 && !config.nativeMonotonicClock)
      throw std::runtime_error("Unknown clock-host probe argument");
    const auto base = sophistry::SystemMonotonicSource::timebase();
    const auto before = sophistry::SystemMonotonicSource::ticks();
    sophistry::LegacyEngine engine(config);
    engine.initialize();
    engine.activate();
    const auto after = sophistry::SystemMonotonicSource::ticks();
    const auto snapshot = engine.objectSnapshot();
    std::uint32_t initializedAt = 0;
    for (unsigned i = 0; i < 4; ++i)
      initializedAt |= std::uint32_t(snapshot.at(0x9a70 + i)) << (8 * i);
    if (config.nativeMonotonicClock) {
      auto milliseconds = [&](std::uint64_t ticks) {
        long double value = static_cast<long double>(ticks) * base.numerator /
                            base.denominator / 1000000.0L;
        return std::uint64_t(std::min(value,
            static_cast<long double>(std::numeric_limits<std::uint32_t>::max())));
      };
      const auto low = milliseconds(before), high = milliseconds(after);
      if (std::uint64_t(initializedAt) + 2 < low || initializedAt > high + 2)
        throw std::runtime_error("Original timer did not receive native 64-bit ticks/timebase");
    } else if (initializedAt != 0)
      throw std::runtime_error("Original deterministic initialization timestamp changed");
    std::cout << "{\"scope\":\"Original timer ABI through the actual host adapter; "
                 "unregistered fixture, no audio or private preferences\","
                 "\"native_clock\":"
              << (config.nativeMonotonicClock ? "true" : "false")
              << ",\"original_timer_receives_expected_clock\":true,"
                 "\"engine_diagnostics\":" << engine.diagnosticJson()
              << ",\"passed\":true}\n";
    engine.deactivate();
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
