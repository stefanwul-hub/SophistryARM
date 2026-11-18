#pragma once
#include "LifterRuntime.h"

// A compiled unit returns before any host callback. Keep these architectural
// bytes private to the unit so guest RAM accesses cannot alias them in C++.
// Every return, including a fault or instruction limit, commits the same bytes.
struct SlRegisterCache {
    SlCpu& cpu;
    SlU8 gp[32];
    SlU8 flags[16];
    explicit SlRegisterCache(SlCpu& c) noexcept : cpu(c) {
        static_assert(0x210 <= sizeof(c.reg), "register file too small");
        __builtin_memcpy(gp, c.reg, sizeof(gp));
        __builtin_memcpy(flags, c.reg + 0x200, sizeof(flags));
    }
    ~SlRegisterCache() noexcept {
        __builtin_memcpy(cpu.reg, gp, sizeof(gp));
        __builtin_memcpy(cpu.reg + 0x200, flags, sizeof(flags));
    }
    SlRegisterCache(const SlRegisterCache&) = delete;
    SlRegisterCache& operator=(const SlRegisterCache&) = delete;
};

// No callback runs inside a compiled unit. Publish this execution state at the
// unit boundary, retaining exact PC, faults, per-instruction budget and coverage.
struct SlUnitState {
    SlCpu& cpu;
    SlU32 pc, fault;
    SlU64 steps;
    const SlU32 stop;
    const SlU64 limit;
    SlU8* const memory;
    const SlSize memory_size;
    explicit SlUnitState(SlCpu& c) noexcept
        : cpu(c), pc(c.pc), fault(c.fault), steps(c.steps), stop(c.stop),
          limit(c.limit), memory(c.memory), memory_size(c.memory_size) {}
    ~SlUnitState() noexcept {
        cpu.pc = pc;
        cpu.fault = fault;
        cpu.steps = steps;
    }
    bool tick() noexcept {
        if (fault || pc == stop) return false;
        if (pc < sizeof(cpu.seen)) cpu.seen[pc] = 1;
        if (++steps > limit) { fault = 4; return false; }
        return true;
    }
    SlUnitState(const SlUnitState&) = delete;
    SlUnitState& operator=(const SlUnitState&) = delete;
};

template<unsigned N> inline SlU sl_local_get(const SlU8* bytes, SlSize size,
                                           SlU offset, SlUnitState& state) {
    static_assert(N <= 16, "p-code value exceeds 128 bits");
    if (offset > size || N > size - static_cast<SlSize>(offset)) {
        state.fault = 1; return 0;
    }
    SlU value = 0;
    __builtin_memcpy(&value, bytes + static_cast<SlSize>(offset), N);
    return value;
}
template<unsigned N> inline void sl_local_put(SlU8* bytes, SlSize size, SlU offset,
                                            SlU value, SlUnitState& state) {
    static_assert(N <= 16, "p-code value exceeds 128 bits");
    if (offset > size || N > size - static_cast<SlSize>(offset)) {
        state.fault = 1; return;
    }
    __builtin_memcpy(bytes + static_cast<SlSize>(offset), &value, N);
}
inline SlU sl_local_divide(SlUnitState& state, SlU a, SlU b, unsigned inputBits,
                          unsigned quotientBits, bool isSigned, bool remainder) {
    if (state.fault) return 0;
    state.cpu.fault = 0;
    const SlU value = sl_divide(state.cpu, a, b, inputBits, quotientBits,
                              isSigned, remainder);
    state.fault = state.cpu.fault;
    return value;
}
