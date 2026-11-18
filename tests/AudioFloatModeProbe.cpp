#include "../src/engine/AudioFloatMode.h"
#include <cstdio>
#include <cstring>
#include <stdexcept>
using sophistry::NativeAudioFloatState;
using sophistry::ScopedOriginalAudioFloatMode;
static bool equal(NativeAudioFloatState a, NativeAudioFloatState b) {
  return a.control == b.control && a.status == b.status;
}
static void require(bool ok) {
  if (!ok)
    throw std::runtime_error("Original render float mode mismatch");
}
__attribute__((noinline)) static std::uint64_t
multiply(unsigned width, std::uint64_t a, std::uint64_t b) {
  if (width == 4) {
    float x, y;
    std::uint32_t ia = a, ib = b, bits;
    std::memcpy(&x, &ia, 4);
    std::memcpy(&y, &ib, 4);
    volatile float result = x * y;
    const float copy = result;
    std::memcpy(&bits, &copy, 4);
    return bits;
  }
  double x, y;
  std::memcpy(&x, &a, 8);
  std::memcpy(&y, &b, 8);
  volatile double result = x * y;
  const double copy = result;
  std::uint64_t bits;
  std::memcpy(&bits, &copy, 8);
  return bits;
}
int main() {
  const auto caller = sophistry::nativeAudioFloatState();
  try {
    auto ieee = caller;
    ieee.control &= ~ScopedOriginalAudioFloatMode::mask;
#if defined(__SSE__)
    ieee.control = (ieee.control & ~0x603fULL) | 0x1f80;
#else
    ieee.control &= ~(0x1f00ULL | (3ULL << 22));
    ieee.status = 0;
#endif
    const struct Case {
      unsigned width;
      std::uint64_t a, b, ordinary, rendered;
    } cases[] = {{4, 1, 0x71800000, 0x27000000, 0},
                 {4, 0x00800000, 0x3f000000, 0x00400000, 0},
                 {4, 0x80000001, 0x71800000, 0xa7000000, 0x80000000},
                 {4, 0x3fc00000, 0x40000000, 0x40400000, 0x40400000},
                 {8, 1, 0x7e70000000000000ULL, 0x3b50000000000000ULL, 0},
                 {8, 0x0010000000000000ULL, 0x3fe0000000000000ULL,
                  0x0008000000000000ULL, 0},
                 {8, 0x8000000000000001ULL, 0x7e70000000000000ULL,
                  0xbb50000000000000ULL, 0x8000000000000000ULL},
                 {8, 0x3ff8000000000000ULL, 0x4000000000000000ULL,
                  0x4008000000000000ULL, 0x4008000000000000ULL}};
    for (auto c : cases) {
      sophistry::restoreNativeAudioFloatState(ieee);
      require(multiply(c.width, c.a, c.b) == c.ordinary);
      sophistry::restoreNativeAudioFloatState(ieee);
      {
        ScopedOriginalAudioFloatMode render;
        require(!render.wasAlreadyEnabled());
        require(multiply(c.width, c.a, c.b) == c.rendered);
        {
          ScopedOriginalAudioFloatMode nested;
          require(nested.wasAlreadyEnabled());
          require(multiply(c.width, c.a, c.b) == c.rendered);
        }
        require((sophistry::nativeAudioFloatState().control &
                 ScopedOriginalAudioFloatMode::mask) ==
                ScopedOriginalAudioFloatMode::mask);
      }
      require(equal(sophistry::nativeAudioFloatState(), ieee));
    }
    sophistry::restoreNativeAudioFloatState(ieee);
    try {
      ScopedOriginalAudioFloatMode render;
      (void)multiply(4, 1, 0x71800000);
      throw 1;
    } catch (int) {
    }
    require(equal(sophistry::nativeAudioFloatState(), ieee));
    {
      ScopedOriginalAudioFloatMode disabled(false);
      require(equal(sophistry::nativeAudioFloatState(), ieee));
    }
    require(equal(sophistry::nativeAudioFloatState(), ieee));
    sophistry::restoreNativeAudioFloatState(caller);
    std::puts(
        "{\"passed\":true,\"multiply_cases\":8,\"nested_scopes\":true,"
        "\"exception_restores_caller\":true,\"inactive_scope_unchanged\":true,"
        "\"caller_control_and_status_restored\":true}");
    return 0;
  } catch (const std::exception &e) {
    sophistry::restoreNativeAudioFloatState(caller);
    std::fprintf(stderr, "%s\n", e.what());
    return 1;
  }
}
