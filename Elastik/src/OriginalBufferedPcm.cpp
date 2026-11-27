#include "OriginalBufferedPcm.h"

extern "C" void elastik_original_read_buffered_pcm(
    ElastikOriginalReadBuffer* buffer, float* const* outputs, int first_frame, int frames,
    unsigned sample_format, unsigned channel_format, int data_byte_offset,
    const ElastikOriginalByteIO* io, const ElastikOriginalReaderDiagnostics* diagnostics) noexcept {
    const int sample_bytes = elastik_original_sample_bytes(sample_format);
    const unsigned channels = channel_format & 0x100u ? channel_format & 0xffu : channel_format;
    int position = first_frame;
    while (frames > 0) {
        const int wanted = sample_bytes * frames * static_cast<int>(channels);
        int chunk_frames, bytes;
        if (wanted <= buffer->capacity) {
            chunk_frames = frames;
            bytes = wanted;
        } else {
            chunk_frames = buffer->capacity / (sample_bytes * static_cast<int>(channels));
            bytes = chunk_frames * static_cast<int>(channels) * sample_bytes;
        }
        const int byte_position = position * sample_bytes * static_cast<int>(channels) + data_byte_offset;
        io->seek(io->context, byte_position);
        const bool ok = io->read(io->context, buffer->bytes, &bytes);
        if (!ok && diagnostics && diagnostics->read_failed)
            diagnostics->read_failed(diagnostics->context, wanted, byte_position, bytes);
        // The original converts the planned chunk even after a short/failed
        // read. Keep its buffer reuse/error semantics, without a new fill rule.
        for (unsigned channel = 0; channel != channels; ++channel) {
            if (outputs[channel]) {
                auto* destination = reinterpret_cast<unsigned char*>(outputs[channel] + position - first_frame);
                elastik_original_convert_channel(buffer->bytes, sample_format, static_cast<int>(channels), static_cast<int>(channel),
                    destination, 0x44, 1, 0, chunk_frames,
                    diagnostics ? diagnostics->format : nullptr,
                    diagnostics ? diagnostics->context : nullptr);
            }
        }
        frames -= chunk_frames;
        position += chunk_frames;
    }
}
