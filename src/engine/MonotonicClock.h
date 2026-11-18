#pragma once
#include <chrono>
#include <cstdint>
#include <stdexcept>
#ifdef __APPLE__
#include <mach/mach_time.h>
#endif

namespace sophistry {
struct MonotonicTimebase {
  std::uint32_t numerator = 1, denominator = 1;
};

struct SystemMonotonicSource {
  static MonotonicTimebase timebase() {
#ifdef __APPLE__
    mach_timebase_info_data_t value{};
    if (mach_timebase_info(&value) != 0)
      throw std::runtime_error("Cannot read host monotonic timebase");
    return {value.numer, value.denom};
#else
    return {1, 1};
#endif
  }
  static std::uint64_t ticks() {
#ifdef __APPLE__
    // AudioTimeStamp.mHostTime uses these same native Mach tick units.
    return mach_absolute_time();
#else
    return std::uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                             std::chrono::steady_clock::now().time_since_epoch())
                             .count());
#endif
  }
};

// The source type permits controlled clock inputs in differential tests.
// Production uses SystemMonotonicSource; deterministic references retain their
// previous 1000-tick progression without consulting the operating system.
template <class Source = SystemMonotonicSource> class MonotonicClock {
public:
  explicit MonotonicClock(bool native = false)
      : native_(native), base_(native ? Source::timebase()
                                     : MonotonicTimebase{1, 1}) {
    if (!base_.numerator || !base_.denominator)
      throw std::runtime_error("Invalid host monotonic timebase");
  }
  MonotonicTimebase timebase() const { return base_; }
  bool native() const { return native_; }
  std::uint64_t ticks() {
    if (native_)
      return Source::ticks();
    deterministicTicks_ += 1000;
    return deterministicTicks_;
  }
  void advanceDeterministicSleep(std::uint32_t microseconds) {
    if (!native_)
      deterministicTicks_ += std::uint64_t(microseconds) * 1000;
  }

private:
  bool native_;
  MonotonicTimebase base_;
  std::uint64_t deterministicTicks_ = 0;
};
} // namespace sophistry
