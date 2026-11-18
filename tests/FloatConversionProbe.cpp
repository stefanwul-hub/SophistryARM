// Check optimized storage conversions against the prior general integer
// algorithm, including noncanonical extended encodings and rounding edges.
#include "../src/lifter/LifterRuntime.h"
#include <cstdio>
// Link stub: this arithmetic-only probe never calls sl_run or executes code.
int sl_execute(SlCpu &, SlU32, SlU32, SlU64) { return 0; }
static SlU64 rounded(SlU64 n, unsigned shift) {
  if (!shift)
    return n;
  if (shift > 64)
    return 0;
  if (shift == 64)
    return n > (SlU64(1) << 63) ? 1 : 0;
  const SlU64 q = n >> shift, r = n & ((SlU64(1) << shift) - 1),
              h = SlU64(1) << (shift - 1);
  return q + (r > h || (r == h && (q & 1)));
}
static SlU reference(SlU bits, unsigned fraction, unsigned bias,
                     unsigned ebits) {
  const SlU64 m = static_cast<SlU64>(bits);
  const unsigned se = unsigned(bits >> 64) & 0xffff, exponent = se & 0x7fff;
  const SlU64 sign = SlU64(se >> 15) << (fraction + ebits);
  const SlU64 mask = (SlU64(1) << fraction) - 1;
  const SlU64 inf = ((SlU64(1) << ebits) - 1) << fraction;
  if (exponent == 0x7fff) {
    if (m == 0x8000000000000000ULL)
      return sign | inf;
    return sign | inf | (SlU64(1) << (fraction - 1)) |
           ((m >> (63 - fraction)) & mask);
  }
  if (!m)
    return sign;
  const int power = exponent ? int(exponent) - 16383 : -16382;
  const unsigned leading = 63 - __builtin_clzll(m);
  int e = power + int(leading) - 63;
  if (e > int(bias))
    return sign | inf;
  if (e < 1 - int(bias)) {
    const int shift = 64 - int(bias) - int(fraction) - power;
    return sign |
           (shift >= 0 ? rounded(m, unsigned(shift)) : m << unsigned(-shift));
  }
  SlU64 r = leading >= fraction ? rounded(m, leading - fraction)
                                : m << (fraction - leading);
  if (r == (SlU64(1) << (fraction + 1))) {
    r >>= 1;
    ++e;
  }
  if (e > int(bias))
    return sign | inf;
  return sign | (SlU64(e + int(bias)) << fraction) | (r & mask);
}
int main() {
  SlU64 cases = 0;
  auto check = [&](SlU value) {
    ++cases;
    if (sl_ext80_to_f64(value) != reference(value, 52, 1023, 11) ||
        sl_ext80_to_f32(value) != reference(value, 23, 127, 8)) {
      std::fprintf(stderr, "Conversion mismatch in case %llu\n",
                   (unsigned long long)cases);
      return false;
    }
    return true;
  };
  const SlU64 mantissas[] = {0,
                             1,
                             0x7fffffffffffffffULL,
                             0x8000000000000000ULL,
                             0x8000000000000001ULL,
                             0x8000000000000400ULL,
                             0x80000000000007ffULL,
                             0x8000000000000800ULL,
                             0x8000008000000000ULL,
                             0xffffff8000000000ULL,
                             0xfffffffffffffbffULL,
                             0xfffffffffffffc00ULL,
                             0xffffffffffffffffULL};
  for (unsigned exponent = 0; exponent < 65536; ++exponent)
    for (auto m : mantissas)
      if (!check(SlU(m) | (SlU(exponent) << 64)))
        return 1;
  SlU64 random = 0x2026a18b3c4d5e6fULL;
  auto next = [&] {
    random ^= random << 13;
    random ^= random >> 7;
    random ^= random << 17;
    return random;
  };
  for (unsigned i = 0; i < 300000; ++i) {
    const auto m = next(), e = next();
    if (!check(SlU(m) | (SlU(e & 0xffff) << 64)) ||
        !check(sl_fp_to_ext80(m, 8)) || !check(sl_fp_to_ext80(SlU32(m), 4)))
      return 1;
  }
  std::printf("{\"passed\":true,\"extended_encodings\":%llu,\"ieee_results_"
              "checked\":%llu,\"bit_mismatches\":0}\n",
              (unsigned long long)cases, (unsigned long long)(cases * 2));
}
