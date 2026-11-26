// Binary fixture runner for the translated original helper. No plugin or bank.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void elastik_original_planar_sum_f32(
    float* const*, const float* const*, unsigned int, unsigned int, unsigned int) noexcept;

int main() {
    uint32_t header[4];
    if (fread(header, sizeof(header), 1, stdin) != 1) return 2;
    const uint32_t words = header[0], frames = header[1];
    const uint32_t format = header[2], channelFormat = header[3];
    const uint32_t channels = (channelFormat & 0x100u) ? channelFormat & 0xffu : channelFormat;
    if (channels > 32 || words > 2097152 || words == 0 || frames > 65536) return 2;
    uint32_t destinationOffsets[32], sourceOffsets[32];
    if (fread(destinationOffsets, 4, channels, stdin) != channels ||
        fread(sourceOffsets, 4, channels, stdin) != channels) return 2;
    float* storage = static_cast<float*>(malloc(static_cast<size_t>(words) * 4));
    if (!storage) return 3;
    if (fread(storage, 4, words, stdin) != words) { free(storage); return 2; }
    float* destination[32]; const float* source[32];
    for (uint32_t channel = 0; channel < channels; ++channel) {
        if (static_cast<uint64_t>(destinationOffsets[channel]) + frames > words ||
            static_cast<uint64_t>(sourceOffsets[channel]) + frames > words) {
            free(storage); return 2;
        }
        destination[channel] = storage + destinationOffsets[channel];
        source[channel] = storage + sourceOffsets[channel];
    }
    elastik_original_planar_sum_f32(destination, source, format, frames, channelFormat);
    const bool ok = fwrite(storage, 4, words, stdout) == words;
    free(storage);
    return ok ? 0 : 4;
}
