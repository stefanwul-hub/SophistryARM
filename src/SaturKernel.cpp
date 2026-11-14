#include "SaturKernel.h"

extern "C" float sophistry_satur_sample(float x, float a, float b) noexcept {
    // Original SSE: cvtss2sd; bitwise abs on float; addsd; divsd; addsd;
    // mulsd; cvtsd2ss. Keep the double intermediates and disable contraction.
    const double abs_x = static_cast<double>(__builtin_fabsf(x));
    const double denominator = abs_x + static_cast<double>(b);
    const double ratio = static_cast<double>(a) / denominator;
    const double gain = static_cast<double>(b) + ratio;
    return static_cast<float>(static_cast<double>(x) * gain);
}

extern "C" void sophistry_satur_block(const float* input, float* output,
        unsigned frames, float a, float b, bool in_place) noexcept {
    for (unsigned i=0; i<frames; ++i) {
        const float value = sophistry_satur_sample(input[i], a, b);
        // At 0xc14e4 the original out-of-place callback adds to the destination.
        // The in-place path stores directly. The addition rounds to float.
        if (in_place) output[i] = value;
        else output[i] = value + output[i];
    }
}

extern "C" void sophistry_satur_process(const float* input_l, const float* input_r,
        float* output_l, float* output_r, unsigned frames, float a, float b,
        unsigned channels, bool enabled) noexcept {
    if (!enabled || static_cast<int>(frames) <= 0) return;
    if (channels == 1) {
        sophistry_satur_block(input_l, output_l, frames, a, b, input_l==output_l);
    } else if (channels == 2) {
        if (input_l==output_l && input_r==output_r) {
            for (unsigned i=0; i<frames; ++i) {
                output_l[i] = sophistry_satur_sample(input_l[i],a,b);
                output_r[i] = sophistry_satur_sample(input_r[i],a,b);
            }
        } else {
            // Surprising but present in the original instructions: stereo with
            // separate destinations does NOT advance either source pointer.
            // 0x74112 reloads [ebp-0x24] unchanged on each iteration. Retain it.
            for (unsigned i=0; i<frames; ++i) {
                const float x_l=input_l[0], x_r=input_r[0];
                output_l[i] = sophistry_satur_sample(x_l,a,b) + output_l[i];
                output_r[i] = sophistry_satur_sample(x_r,a,b) + output_r[i];
            }
        }
    }
}
