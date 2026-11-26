// Elastik 1.5.2.3 i386, original routine 0x00161700..0x00161774.
// Direct translation of its complete 117-byte instruction sequence.
// Source SHA-256 is pinned by scripts/legacy_image.py.
// This is one original DSP helper, not the complete engine or an Audio Unit.
// No allocation, gain change, voice limit or silent-tail shortcut is added.
static_assert(sizeof(float) == 4, "Original samples are IEEE binary32");
static_assert(sizeof(unsigned int) == 4, "Original counters are 32-bit");

extern "C" void elastik_original_planar_sum_f32(
    float* const* output,
    const float* const* input,
    unsigned int /* original_sample_format_unused */,
    unsigned int frames,
    unsigned int channel_format) noexcept {
    // 0x161711..0x161720: bit 8 selects the low-byte channel count.
    const unsigned int channels = (channel_format & 0x100u)
        ? (channel_format & 0xffu) : channel_format;
    // 0x16172d..0x16176c: channels in ascending order, no alias assumption.
    for (unsigned int channel = 0; channel != channels; ++channel) {
        float* destination = output[channel];
        const float* source = input[channel];
        // 0x16174d movss; 0x161751 addss; 0x161755 movss.
        // Retain destination + source order and one binary32 rounding.
        for (unsigned int frame = 0; frame != frames; ++frame) {
            destination[frame] = destination[frame] + source[frame];
        }
    }
}
