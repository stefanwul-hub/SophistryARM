#include "OriginalSampleFormat.h"

static_assert(sizeof(int) == 4 && sizeof(unsigned) == 4 && sizeof(short) == 2 && sizeof(float) == 4, "Original scalar sizes");

extern "C" int elastik_original_sample_bytes(unsigned format) noexcept {
    const unsigned normalized = format - 0x10u < 0x11u ? format - 0x10u : format;
    if (static_cast<int>(normalized) < 3) return static_cast<int>(normalized) + 2;
    if (normalized == 3) return 4;
    if (normalized == 4) return 8;
    if (static_cast<int>(normalized) < 0x40) return 4;
    switch (normalized) {
        case 0x40: return 2;
        case 0x41: return 3;
        case 0x42: case 0x44: return 4;
        case 0x43: case 0x45: return 1;
        default: return 0;
    }
}

static int original_kind(unsigned format) noexcept {
    switch (elastik_original_sample_bytes(format)) {
        case 1: return format == 0x43 ? 1 : 6;
        case 2: return 2;
        case 3: return 3;
        case 4: return format == 3 || format == 0x13 || format == 0x44 ? 5 : 4;
        default: return 0;
    }
}
static unsigned load_u32(const unsigned char* p) noexcept {
    return unsigned(p[0]) | unsigned(p[1]) << 8 | unsigned(p[2]) << 16 | unsigned(p[3]) << 24;
}
static void store_u32(unsigned char* p, unsigned value) noexcept {
    p[0] = static_cast<unsigned char>(value); p[1] = static_cast<unsigned char>(value >> 8);
    p[2] = static_cast<unsigned char>(value >> 16); p[3] = static_cast<unsigned char>(value >> 24);
}
static int signed_bits(unsigned value) noexcept { int result; __builtin_memcpy(&result, &value, 4); return result; }
static float float_bits(unsigned value) noexcept { float result; __builtin_memcpy(&result, &value, 4); return result; }
static unsigned raw_float(float value) noexcept { unsigned result; __builtin_memcpy(&result, &value, 4); return result; }
static void swap_bytes(unsigned char* p, int width) noexcept {
    for (int i = 0; i < width / 2; ++i) { unsigned char value = p[i]; p[i] = p[width - i - 1]; p[width - i - 1] = value; }
}
static int original_cvtt_i32(double value) noexcept {
    // CVTTSD2SI/CVTTSS2SI return Intel's indefinite int32 for NaN/overflow.
    // ARM64's native float-to-int saturation differs, so retain this rule.
    if (!(value >= -2147483648.0 && value < 2147483648.0)) return signed_bits(0x80000000u);
    return static_cast<int>(value);
}

extern "C" void elastik_original_convert_channel(
    unsigned char* input, unsigned input_format, int input_stride, int input_channel,
    unsigned char* output, unsigned output_format, int output_stride, int output_channel,
    int samples, ElastikOriginalFormatDiagnostic diagnostic, void* context) noexcept {
    const int input_bytes = elastik_original_sample_bytes(input_format);
    const int output_bytes = elastik_original_sample_bytes(output_format);
    const int input_kind = original_kind(input_format), output_kind = original_kind(output_format);
    if (!input_kind) { if (diagnostic) diagnostic(context, 1); return; }
    if (!output_kind) { if (diagnostic) diagnostic(context, 2); return; }
    const bool input_big = static_cast<int>(input_format) < 0x10;
    const bool output_big = static_cast<int>(output_format) < 0x10;
    unsigned char* first_input = input + input_channel * input_bytes;
    unsigned char* first_output = output + output_channel * output_bytes;
    // Preserve the original input mutation, before any conversion or copying.
    if (input_big && (input_kind == 2 || input_kind == 4 || input_kind == 5)) {
        auto* p = first_input;
        for (int i = 0; i < samples; ++i, p += input_stride * input_bytes) swap_bytes(p, input_bytes);
    }
    auto* src = first_input; auto* dst = first_output;
    for (int i = 0; i < samples; ++i, src += input_stride * input_bytes, dst += output_stride * output_bytes) {
        if (input_format == output_format) {
            // Source/output may alias. Keep the original width-sized load
            // before its store; packed 24-bit copies remain byte-by-byte.
            if (input_bytes == 4) store_u32(dst, load_u32(src));
            else if (input_bytes == 2) { const unsigned value = unsigned(src[0]) | unsigned(src[1]) << 8; dst[0] = static_cast<unsigned char>(value); dst[1] = static_cast<unsigned char>(value >> 8); }
            else for (int b = 0; b < input_bytes; ++b) dst[b] = src[b];
            continue;
        }
        float sample = 0.0f;
        switch (input_kind) {
            case 1: sample = static_cast<float>(static_cast<signed char>(src[0])) * 0x1p-7f; break;
            case 2: sample = static_cast<float>(static_cast<short>(unsigned(src[0]) | unsigned(src[1]) << 8)) * 0x1p-15f; break;
            case 3: {
                const unsigned value = input_big
                    ? unsigned(src[0]) << 16 | unsigned(src[1]) << 8 | unsigned(src[2])
                    : unsigned(src[0]) | unsigned(src[1]) << 8 | unsigned(src[2]) << 16;
                sample = static_cast<float>(signed_bits(value << 8)) * 0x1p-31f; break;
            }
            case 4: sample = static_cast<float>(signed_bits(load_u32(src))) * 0x1p-31f; break;
            case 5: sample = float_bits(load_u32(src)); break;
            case 6: {
                const float value = static_cast<float>(src[0]);
                sample = (value + value) / 255.0f - 1.0f; break;
            }
        }
        switch (output_kind) {
            case 1: dst[0] = static_cast<unsigned char>(original_cvtt_i32(static_cast<double>(sample) * 127.0)); break;
            case 2: {
                const unsigned value = static_cast<unsigned>(original_cvtt_i32(static_cast<double>(sample) * 32768.0));
                dst[0] = static_cast<unsigned char>(value); dst[1] = static_cast<unsigned char>(value >> 8); break;
            }
            case 3: {
                const unsigned value = static_cast<unsigned>(original_cvtt_i32(static_cast<double>(sample) * 2147483648.0));
                if (output_big) { dst[0] = static_cast<unsigned char>(value >> 24); dst[1] = static_cast<unsigned char>(value >> 16); dst[2] = static_cast<unsigned char>(value >> 8); }
                else { dst[0] = static_cast<unsigned char>(value >> 8); dst[1] = static_cast<unsigned char>(value >> 16); dst[2] = static_cast<unsigned char>(value >> 24); }
                break;
            }
            case 4: store_u32(dst, static_cast<unsigned>(original_cvtt_i32(static_cast<double>(sample) * 2147483648.0))); break;
            case 5: store_u32(dst, raw_float(sample)); break;
            case 6: {
                const float biased = sample + 1.0f;
                const float scaled = biased * 255.0f;
                const float half = scaled * 0.5f;
                dst[0] = static_cast<unsigned char>(original_cvtt_i32(half)); break;
            }
        }
    }
    if (output_big && (output_kind == 2 || output_kind == 4 || output_kind == 5)) {
        auto* p = first_output;
        for (int i = 0; i < samples; ++i, p += output_stride * output_bytes) swap_bytes(p, output_bytes);
    }
}
