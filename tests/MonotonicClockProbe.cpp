#include "../src/engine/MonotonicClock.h"
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace {
struct ControlledSource {
  static sophistry::MonotonicTimebase base;
  static std::uint64_t value;
  static unsigned baseCalls, tickCalls;
  static sophistry::MonotonicTimebase timebase() { ++baseCalls; return base; }
  static std::uint64_t ticks() { ++tickCalls; return value; }
};
sophistry::MonotonicTimebase ControlledSource::base{125, 3};
std::uint64_t ControlledSource::value = 24000000;
unsigned ControlledSource::baseCalls = 0, ControlledSource::tickCalls = 0;
void require(bool value, const char *message) {
  if (!value)
    throw std::runtime_error(message);
}
} // namespace

int main(int argc, char **argv) {
  try {
    bool requireRange = argc == 2 && std::string(argv[1]) == "--require-original-timer-range";
    if (argc > 1 && !requireRange)
      throw std::runtime_error("Unknown clock probe argument");
    sophistry::MonotonicClock<ControlledSource> deterministic;
    require(deterministic.timebase().numerator == 1 &&
            deterministic.timebase().denominator == 1, "Deterministic timebase changed");
    require(deterministic.ticks() == 1000 && deterministic.ticks() == 2000,
            "Deterministic clock progression changed");
    require(ControlledSource::baseCalls == 0 && ControlledSource::tickCalls == 0,
            "Deterministic clock queried the native source");
    deterministic.advanceDeterministicSleep(250);
    require(deterministic.ticks() == 253000,
            "Deterministic sleep accounting changed");
    sophistry::MonotonicClock<ControlledSource> controlled(true);
    require(controlled.timebase().numerator == 125 && controlled.timebase().denominator == 3,
            "Native timebase was normalized incorrectly");
    require(controlled.ticks() == 24000000, "Native ticks were changed");
    ControlledSource::value = 48000000;
    require(controlled.ticks() == 48000000 && ControlledSource::baseCalls == 1,
            "Native ticks not refreshed or timebase not cached");
    controlled.advanceDeterministicSleep(250);
    require(controlled.ticks() == 48000000,
            "Native sleep was counted twice");
    for (auto bad : {sophistry::MonotonicTimebase{0, 3}, {125, 0}}) {
      ControlledSource::base = bad;
      bool rejected = false;
      try { sophistry::MonotonicClock<ControlledSource> invalid(true); }
      catch (const std::runtime_error &) { rejected = true; }
      require(rejected, "Zero timebase accepted");
    }
    sophistry::MonotonicClock<> system(true);
    const auto base = system.timebase();
    std::uint64_t first = system.ticks(), previous = first;
    for (unsigned i = 0; i < 1024; ++i) {
      const auto value = system.ticks();
      require(value >= previous, "Native monotonic clock moved backwards");
      previous = value;
    }
    require(previous > first, "Native clock did not advance");
    const long double milliseconds = static_cast<long double>(previous) *
        base.numerator / base.denominator / 1000000.0L;
    const bool timerRange = milliseconds < std::numeric_limits<std::uint32_t>::max();
    std::cout << "{\"deterministic_progression_exact\":true,"
                 "\"native_source_and_timebase_preserved\":true,"
                 "\"timebase_cached\":true,\"invalid_timebases_rejected\":true,"
                 "\"system_clock_monotonic\":true,\"timebase_numerator\":"
              << base.numerator << ",\"timebase_denominator\":" << base.denominator
              << ",\"original_u32_millisecond_timer_in_range\":"
              << (timerRange ? "true" : "false") << ",\"passed\":"
              << (!requireRange || timerRange ? "true" : "false") << "}\n";
    if (requireRange && !timerRange) {
      std::cerr << "Le compteur de millisecondes 32 bits d’origine serait saturé avec "
                   "la durée de fonctionnement actuelle du Mac. Le composant précédent "
                   "est conservé ; redémarrez le Mac avant de relancer la validation.\n";
      return 3;
    }
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
