#!/usr/bin/env python3
"""Verify the requested AU output compensation against an unchanged DSP WAV."""
import argparse
import hashlib
import json
import math
import struct
from pathlib import Path


def scaled_wave(source, gain_db=6.0):
    if len(source) < 12 or source[:4] != b"RIFF" or source[8:12] != b"WAVE":
        raise ValueError("Expected a RIFF WAVE reference")
    if struct.unpack_from("<I", source, 4)[0] + 8 != len(source):
        raise ValueError("Invalid RIFF byte count")
    gain = struct.unpack("<f", struct.pack("<f", 10 ** (gain_db / 20)))[0]
    if not math.isfinite(gain) or gain <= 0:
        raise ValueError("Invalid output gain")
    chunks, position, fmt = [], 12, None
    while position < len(source):
        if position + 8 > len(source):
            raise ValueError("Truncated WAVE chunk")
        name, size = struct.unpack_from("<4sI", source, position)
        begin = position + 8
        if begin + size > len(source):
            raise ValueError("Truncated WAVE chunk payload")
        if name == b"fmt ":
            if fmt is not None or size < 16:
                raise ValueError("Invalid WAVE format chunk")
            fmt = struct.unpack_from("<HHIIHH", source, begin)
        elif name == b"data":
            chunks.append((begin, size))
        position = begin + size + (size & 1)
    if position != len(source) or fmt is None or len(chunks) != 1:
        raise ValueError("Expected exactly one format and one audio-data chunk")
    tag, channels, rate, byte_rate, alignment, bits = fmt
    if tag != 3 or bits != 32 or channels < 1 or alignment != channels * 4 or byte_rate != rate * alignment:
        raise ValueError("Expected interleaved IEEE float32 WAVE")
    begin, size = chunks[0]
    if size % alignment:
        raise ValueError("Truncated audio frame")
    output = bytearray(source)
    for position in range(begin, begin + size, 4):
        value = struct.unpack_from("<f", source, position)[0]
        if not math.isfinite(value) or not math.isfinite(value * gain):
            raise ValueError("Nonfinite audio in gain reference")
        try:
            struct.pack_into("<f", output, position, value * gain)
        except OverflowError as error:
            raise ValueError("Compensated audio exceeds float32 range") from error
    return bytes(output), {"requested_gain_db": gain_db, "float32_linear_gain": gain,
                           "channels": channels, "sample_rate": rate, "frames": size // alignment}


def compare_wave_bytes(source, actual, gain_db=6.0):
    expected, details = scaled_wave(source, gain_db)
    passed = expected == actual
    return {"scope": "Exact float32 output compensation of original DSP audio; original WAV structure retained",
            **details, "raw_audio_byte_identical": source == actual,
            "audio_matches_original_with_requested_output_gain": passed,
            "reference_sha256": hashlib.sha256(source).hexdigest(),
            "expected_sha256": hashlib.sha256(expected).hexdigest(),
            "actual_sha256": hashlib.sha256(actual).hexdigest(), "passed": passed}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--actual", type=Path, required=True)
    parser.add_argument("--gain-db", type=float, default=6.0)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    try:
        result = compare_wave_bytes(args.reference.read_bytes(), args.actual.read_bytes(), args.gain_db)
    except (OSError, ValueError, OverflowError) as error:
        result = {"passed": False, "error": str(error)}
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2) + "\n")
    if not result["passed"]:
        raise SystemExit(result.get("error", "Audio differs from original with requested output gain"))


if __name__ == "__main__":
    main()
