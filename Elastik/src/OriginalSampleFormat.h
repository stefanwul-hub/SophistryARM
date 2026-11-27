#pragma once

// Data-effect translation of original 0x161584 and 0x1619b0 on little-endian
// Intel/ARM64 hosts. The original converter modifies big-endian input buffers.
// Float64 has a byte width but is unsupported by this original converter.
using ElastikOriginalFormatDiagnostic = void (*)(void*, int); // 1=input, 2=output

extern "C" int elastik_original_sample_bytes(unsigned format) noexcept;
extern "C" void elastik_original_convert_channel(
    unsigned char* input, unsigned input_format, int input_stride, int input_channel,
    unsigned char* output, unsigned output_format, int output_stride, int output_channel,
    int samples, ElastikOriginalFormatDiagnostic diagnostic = nullptr,
    void* diagnostic_context = nullptr) noexcept;
