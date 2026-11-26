#pragma once
#include <cstdint>
#if defined(__SSE__)
#include <xmmintrin.h>
#endif

namespace sophistry {
struct NativeAudioFloatState {
  std::uint64_t control = 0, status = 0;
};
inline NativeAudioFloatState nativeAudioFloatState() {
  NativeAudioFloatState state;
#if defined(__aarch64__) || defined(__arm64__)
  asm volatile("mrs %0, fpcr\n\tmrs %1, fpsr"
               : "=r"(state.control), "=r"(state.status)
               :
               : "memory");
#elif defined(__SSE__)
  state.control = _mm_getcsr();
#else
#error Unsupported floating-point control architecture
#endif
  return state;
}
inline void restoreNativeAudioFloatState(NativeAudioFloatState state) {
#if defined(__aarch64__) || defined(__arm64__)
  asm volatile("msr fpcr, %0\n\tmsr fpsr, %1\n\tisb"
               :
               : "r"(state.control), "r"(state.status)
               : "memory");
#elif defined(__SSE__)
  _mm_setcsr(static_cast<unsigned>(state.control));
#endif
}
// CronoX AUBase::DoRender 0xc4280 saves MXCSR, ORs 0x8040 (FTZ/DAZ), and
// restores it before returning. Guest LDMXCSR only changes the register
// image; native SSE/ARM arithmetic also needs the corresponding mode.
class ScopedOriginalAudioFloatMode {
  NativeAudioFloatState previous_;
  bool active_;

public:
#if defined(__aarch64__) || defined(__arm64__)
  static constexpr std::uint64_t mask = std::uint64_t(1) << 24; // FPCR.FZ
#else
  static constexpr std::uint64_t mask = 0x8040;
#endif
  explicit ScopedOriginalAudioFloatMode(bool active = true) : active_(active) {
    if (active_) {
      previous_ = nativeAudioFloatState();
      auto mode = previous_;
      mode.control |= mask;
      restoreNativeAudioFloatState(mode);
    }
  }
  ~ScopedOriginalAudioFloatMode() {
    if (active_)
      restoreNativeAudioFloatState(previous_);
  }
  bool wasAlreadyEnabled() const {
    return active_ && (previous_.control & mask) == mask;
  }
  ScopedOriginalAudioFloatMode(const ScopedOriginalAudioFloatMode &) = delete;
  ScopedOriginalAudioFloatMode &
  operator=(const ScopedOriginalAudioFloatMode &) = delete;
};
} // namespace sophistry
