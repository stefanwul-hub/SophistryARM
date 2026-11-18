#include "../../src/engine/MonotonicClock.h"
#include <cstdint>

namespace {
struct ControlledSource {
  static sophistry::MonotonicTimebase base;
  static std::uint64_t value;
  static sophistry::MonotonicTimebase timebase() { return base; }
  static std::uint64_t ticks() { return value; }
};
sophistry::MonotonicTimebase ControlledSource::base;
std::uint64_t ControlledSource::value = 0;
using Clock = sophistry::MonotonicClock<ControlledSource>;
}
extern "C" {
void *cp037_clock_create(int native, std::uint32_t numerator, std::uint32_t denominator) {
  ControlledSource::base = {numerator, denominator};
  try { return new Clock(native != 0); }
  catch (...) { return nullptr; }
}
void cp037_clock_destroy(void *handle) { delete static_cast<Clock *>(handle); }
void cp037_clock_input(std::uint64_t ticks) { ControlledSource::value = ticks; }
std::uint64_t cp037_clock_ticks(void *handle) { return static_cast<Clock *>(handle)->ticks(); }
std::uint32_t cp037_clock_numerator(void *handle) {
  return static_cast<Clock *>(handle)->timebase().numerator;
}
std::uint32_t cp037_clock_denominator(void *handle) {
  return static_cast<Clock *>(handle)->timebase().denominator;
}
}
