"""Independent PCM reference for original i386 calls, using Python's codecs.

No resampling or channel mixing. Float32 identity preserves its original bits.
"""
import math
import struct


def validate(source, destination):
    for f, output in [(source, False), (destination, True)]:
        rate, kind, flags, packet, frames, stride, channels, bits, _ = f
        width = bits // 8
        buffer_channels = 1 if flags & 32 else channels
        valid = bits in ([32, 64] if flags & 1 else [8, 16, 24, 32])
        if not (kind == 0x6c70636d and 1 <= channels <= 2 and
                math.isfinite(rate) and rate >= 0 and frames == 1 and
                flags & 8 and not flags & ~127 and valid and
                stride == width * buffer_channels and packet == stride and
                (not output or (flags & 1 and bits == 32))):
            raise ValueError('Unsupported PCM reference format: ' + repr(f))
    if source[0] != destination[0] or source[6] != destination[6]:
        raise ValueError('No reference rate or channel conversion')


def convert(source, destination, inputs, frames):
    validate(source, destination)
    si = bool(source[2] & 32)
    di = bool(destination[2] & 32)
    channels = source[6]
    width = source[7] // 8
    if len(inputs) != (channels if si else 1):
        raise ValueError('Invalid reference input buffer count')
    if any(len(data) < frames * source[5] for data in inputs):
        raise ValueError('Truncated reference PCM input')
    output = [bytearray(frames * destination[5])
              for _ in range(channels if di else 1)]
    src_order = 'big' if source[2] & 2 else 'little'
    dst_order = 'big' if destination[2] & 2 else 'little'
    for frame in range(frames):
        for channel in range(channels):
            at = frame * source[5] + (0 if si else channel * width)
            raw = inputs[channel if si else 0][at:at+width]
            if source[2] & 1 and source[7] == 32:
                value = raw if src_order == dst_order else raw[::-1]
            else:
                if source[2] & 1:
                    number = struct.unpack(('>' if source[2] & 2 else '<') + 'd', raw)[0]
                else:
                    number = int.from_bytes(raw, src_order, signed=bool(source[2] & 4))
                    if not source[2] & 4:
                        number -= 1 << (source[7]-1)
                    number = math.ldexp(number, 1-source[7])
                try:
                    value = struct.pack(('>' if destination[2] & 2 else '<') + 'f', number)
                except OverflowError:
                    value = struct.pack(('>' if destination[2] & 2 else '<') + 'f',
                                        math.copysign(math.inf, number))
            at = frame * destination[5] + (0 if di else channel * 4)
            output[channel if di else 0][at:at+4] = value
    return [bytes(data) for data in output]
