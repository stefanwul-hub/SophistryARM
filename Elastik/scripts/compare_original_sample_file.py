#!/usr/bin/env python3
"""Compare original sample file/cache/PCM/voice-chunk path with compiled C++.

The original sample provider is executed, not replaced with decoded samples.
Container metadata/cache contents are fixtures; libc, byte I/O, TLS, mutex and
setjmp/exception boundaries are adapted. No bank or full instrument is loaded.
"""
import argparse
import hashlib
import json
import math
from pathlib import Path
import random
import struct

from legacy_image import SHA
from native_probe import NativeProbe
from original_cache_oracle import OriginalCacheOracle, CACHE, CLIENTS, STORAGE
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX,
                               UC_X86_REG_EBP, UC_X86_REG_EBX, UC_X86_REG_ESI, UC_X86_REG_EDI)

FILE, HANDLE, READERS, VOICE, KEY, RANGE, NEXT = 0x524000, 0x525000, 0x526000, 0x528000, 0x529000, 0x52a000, 0x52a100
READER_VT, IOS, IO_VT, THREAD, MUTEX, MUTEX_VT, BUFFERS = 0x530000, 0x538000, 0x53f000, 0x54d000, 0x54e000, 0x54f000, 0x640000
SEEK, READ, LOCK, UNLOCK = 0x500720, 0x500730, 0x500740, 0x500750
WIDTHS = {0x10: 2, 0x11: 3, 0x12: 4, 0x13: 4, 0x45: 1}
WAVE_SHA = '3a34c829da83d0b79773927fd2d026479a8038f4f7666c29a745aff2968b342f'


def pack(values): return struct.pack('<' + 'i' * len(values), *values)
def f32(value): return struct.unpack('<f', struct.pack('<f', value))[0]


def decoded_word(word, fmt):
    if fmt == 0x13: return word
    if fmt == 0x45:
        value = float(word[0]); sample = f32(f32(f32(value + value) / 255.0) - 1.0)
    else:
        value = int.from_bytes(word, 'little', signed=True)
        if fmt == 0x10: sample = f32(value * (2.0 ** -15))
        else:
            if fmt == 0x11: value <<= 8
            sample = f32(f32(float(value)) * (2.0 ** -31))
    return struct.pack('<f', sample)


def fixture(rng, name, *, fmt=0x10, channels=2, frames=259, first=17, count=65,
            channel=0, entry=2, direct=0, known=True, closed=0, separate=0, fail=0,
            profile='resident', before=100.0, after=100.0, unit=44100.0, cache=True,
            max_read=-1, read_ok=1, chunk=17, raw=None, data_offset=13, voice=None, ramps=None):
    actual_channels = channels & 255 if channels & 0x100 else channels
    sample_channels = max(1, actual_channels)
    width = WIDTHS[fmt]
    if raw is None:
        words = []
        for i in range(frames * sample_channels):
            if fmt == 0x13: word = struct.pack('<f', rng.uniform(-0.8, 0.8))
            elif fmt == 0x45: word = bytes([(i * 37 + 19) & 255])
            else:
                value = ((i * 104729 + 17) & ((1 << (width * 8)) - 1)) - (1 << (width * 8 - 1))
                word = value.to_bytes(width, 'little', signed=True)
            words.append(word)
        raw = rng.randbytes(data_offset) + b''.join(words)
    reader_count = actual_channels + 1 if separate == 1 else 1
    raws = [raw]
    if separate == 1:
        for ch in range(actual_channels):
            raws.append(raw[:data_offset] + b''.join(raw[data_offset + (i * sample_channels + ch) * width:data_offset + (i * sample_channels + ch + 1) * width] for i in range(frames)))
    capacity = width * sample_channels * 7 + 1
    buffers = [rng.randbytes(capacity) for _ in range(reader_count)]
    # Large WAVE fixtures only use the direct path; their inactive cache
    # needs a single accessible slot, without duplicating the complete bank.
    slots = (frames + chunk - 1) // chunk if frames <= 1024 else 1
    slots = max(1, slots)
    ids = list(range(slots)); rng.shuffle(ids)
    mapping = [ids.index(i) for i in range(slots)] + [-1, -1]
    if profile == 'stale-found' and slots > 1: mapping[1] = (mapping[1] + 1) % slots
    elif profile == 'missing-first': mapping[0] = -1
    elif profile == 'missing-middle': mapping[min(2, slots - 1)] = -1
    elif profile == 'all-missing': mapping = [-1] * len(mapping)
    clients = [[2, 1, 4], [1, 2, 5], [0, -1, -1]]
    pool = bytearray(rng.randbytes(slots * chunk * sample_channels * 4))
    for slot, block in enumerate(ids):
        for ch in range(sample_channels):
            for within in range(chunk):
                frame = block * chunk + within
                if frame < frames:
                    start = data_offset + (frame * sample_channels + ch) * width
                    at = (slot * chunk * sample_channels + ch * chunk + within) * 4
                    pool[at:at + 4] = decoded_word(raw[start:start + width], fmt)
    storage = rng.randbytes((count + 16) * 4)
    h = [frames, chunk, sample_channels, slots, len(mapping), len(clients), 0, count + 16, 7]
    f = [fmt, channels, entry, direct, frames if known else 0, frames, closed, separate,
         fail, capacity, data_offset, first, count, channel, max_read, read_ok, int(cache)]
    if voice is None: voice = [0, frames - 1, 0, 1, 0, -7, 1, 0x12345678, -11, -13]
    if ramps is None: ramps = [1.0, 1.0, 0.0] * 2 + [0.0, 1.0, 0.0] * 2
    return {'name': name, 'h': h, 'ids': ids, 'mapping': mapping, 'clients': clients, 'pool': bytes(pool),
            'storage': storage, 'f': f, 'window': [before, after, unit], 'v': voice,
            'ramps': ramps, 'raws': raws, 'buffers': buffers}


def fixtures(wave_path):
    rng = random.Random(0xE1A005F)
    for direct in [0, 1]:
        for entry in [0, 2, 3]:
            for first in [-20, -1, 0, 16, 258, 259, 260]:
                for count in [0, 1, 17, 65]:
                    yield fixture(rng, f'clip-d{direct}-entry{entry}-first{first}-n{count}', direct=direct,
                                  entry=entry, first=first, count=count, channel=9, known=count % 2 == 0)
    for fmt in WIDTHS:
        for channels in [1, 2, 0x104]:
            for direct in [0, 1]:
                for separate in [0, 1, 2]:
                    for known in [False, True]:
                        yield fixture(rng, f'pcm-{fmt:x}-ch{channels:x}-d{direct}-separate{separate}-known{known}',
                                      fmt=fmt, channels=channels, direct=direct, separate=separate, known=known,
                                      channel=(channels & 255) - 1, first=7)
    for profile in ['resident', 'stale-found', 'missing-first', 'missing-middle', 'all-missing']:
        for entry in [0, 2, 3]:
            yield fixture(rng, f'cache-{profile}-entry{entry}', profile=profile, entry=entry, first=0)
    for closed in [0, 1]:
        for channels in [0, 2]:
            for known in [False, True]:
                for entry in [0, 1, 2, 3]:
                    yield fixture(rng, f'metadata-closed{closed}-ch{channels}-known{known}-entry{entry}',
                                  closed=closed, channels=channels, known=known, entry=entry)
    for entry in [0, 2, 3]:
        for separate in [0, 1]:
            for known in [False, True]:
                yield fixture(rng, f'exception-entry{entry}-separate{separate}-known{known}', entry=entry,
                              direct=1, fail=1, separate=separate, known=known, channel=1)
        for ok in [0, 1]:
            for short in [0, 1, 3]:
                yield fixture(rng, f'short-entry{entry}-ok{ok}-bytes{short}', entry=entry, direct=1,
                              max_read=short, read_ok=ok)
    windows = [(0.0, 0.0, 44.1), (1.5, 2.25, 1.0), (100.0, 100.0, 44.1),
               (-1.0, -2.0, 44.1), (math.nan, math.nan, 44.1), (math.inf, math.inf, 0.0),
               (math.inf, 1.0, 1.0), (1.0, math.inf, 1.0), (1e30, 1e30, 44.1),
               (1.0, 1.0, math.nan), (1.0, 1.0, -2.0),
               (0.0001, 0.00025, 44100.0), (0.0001, 0.00025, 48000.0), (0.0001, 0.00025, 96000.0)]
    for i, (before, after, unit) in enumerate(windows):
        for first in [-30, 0, 17, 258, 259, 0x7ffffff0]:
            for known in [False, True]:
                yield fixture(rng, f'prepare-window{i}-first{first}-known{known}', entry=1, first=first,
                              before=before, after=after, unit=unit, known=known)
    for cache in [False, True]:
        for closed in [0, 1]:
            yield fixture(rng, f'prepare-cache{cache}-closed{closed}', entry=1, cache=cache, closed=closed, known=False)
    # Whole sample-provider chain under the original chunk DSP, including
    # wrapping/reversed loops, both channels and simultaneous fade ramps.
    for fmt in [0x10, 0x11, 0x13]:
        for direct in [0, 1]:
            for a, b in [(0, 258), (40, 220), (210, 50)]:
                for direction in [0, 1]:
                    for channel in [0, 1]:
                        positions = [a, 250, 0, b] if a > b else [a, b]
                        for position in sorted(set(positions)):
                            voice = [a, b, direction, 1, 0, -7, position & 1, 0x12345678, -11, -13]
                            ramps = [1.0, 0.25, 0.03125] * 2 + [0.0, 0.75, -0.015625] * 2
                            yield fixture(rng, f'voice-{fmt:x}-d{direct}-loop{a}-{b}-dir{direction}-ch{channel}-pos{position}',
                                          fmt=fmt, direct=direct, entry=4, first=position, count=32, channel=channel,
                                          voice=voice, ramps=ramps)
    raw = wave_path.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == WAVE_SHA
    at = 12
    while at + 8 <= len(raw):
        size = struct.unpack_from('<I', raw, at + 4)[0]
        if raw[at:at + 4] == b'data': data_offset = at + 8; break
        at += 8 + size + (size & 1)
    else: raise ValueError('Missing WAVE data fixture')
    for entry in [0, 2, 3, 4]:
        for first in [0, 57001, 176399 - 65]:
            for channel in [0, 1]:
                yield fixture(rng, f'embedded-wave-entry{entry}-first{first}-ch{channel}', entry=entry, direct=1,
                              frames=176399, first=first, count=65, channel=channel, raw=raw,
                              data_offset=data_offset, cache=False)


class OriginalFileOracle(OriginalCacheOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.trace = []
        self.import_handlers['_setjmp'] = self.setjmp
        for address, callback in [(SEEK, self.seek), (READ, self.read), (LOCK, self.lock), (UNLOCK, self.unlock),
                                  (0x410a8, self.thread), (0x249a3c, self.get_frames), (0x24cc60, self.reader_call)]:
            self.uc.hook_add(UC_HOOK_CODE, callback, begin=address, end=address)

    def reader_index(self, address):
        index, remainder = divmod(address - READERS, 0x200)
        if remainder or index < 0 or index >= len(self.raws): raise ValueError('Unknown reader')
        return index

    def io_index(self, address):
        index, remainder = divmod(address - IOS, 0x100)
        if remainder or index < 0 or index >= len(self.raws): raise ValueError('Unknown I/O object')
        return index

    def thread(self, uc, address, size, user): self.finish(THREAD)

    def get_frames(self, uc, address, size, user):
        reader, = self.arguments(1); index = self.reader_index(reader)
        self.trace.append([1, index, self.word(reader + 0x28), 0, 0])
        # Execute the original getter after observing it.

    def lock(self, uc, address, size, user):
        assert self.arguments(1) == (MUTEX,) and self.depth == 0
        self.depth = 1; self.trace.append([2, 0, 0, 0, 0]); self.finish()

    def unlock(self, uc, address, size, user):
        assert self.arguments(1) == (MUTEX,) and self.depth == 1
        self.depth = 0; self.trace.append([3, 0, 0, 0, 0]); self.finish()

    def seek(self, uc, address, size, user):
        obj, position = self.arguments(2); index = self.io_index(obj)
        assert position <= len(self.raws[index])
        self.positions[index] = position
        self.trace.append([5, index, position, 0, 0]); self.finish()

    def read(self, uc, address, size, user):
        obj, destination, count_at = self.arguments(3); index = self.io_index(obj)
        wanted = self.word(count_at); position = self.positions[index]
        actual = min(wanted, len(self.raws[index]) - position)
        if self.f[14] >= 0: actual = min(actual, self.f[14])
        assert destination == BUFFERS + index * 0x2000 and 0 <= actual <= self.f[9]
        if actual: uc.mem_write(destination, self.raws[index][position:position + actual])
        self.positions[index] += actual; self.put(count_at, actual)
        self.trace.append([6, index, wanted, actual, self.f[15]])
        self.finish(self.f[15])

    def setjmp(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        registers = [UC_X86_REG_EBP, UC_X86_REG_EBX, UC_X86_REG_ESI, UC_X86_REG_EDI]
        self.jump = (sp, self.word(sp) & 0xffffffff, {r: self.uc.reg_read(r) for r in registers}, self.arguments(1)[0])
        self.finish()

    def reader_call(self, uc, address, size, user):
        reader, outputs, first, count = self.arguments(4); index = self.reader_index(reader)
        channels = 1 if index else (self.f[1] & 255 if self.f[1] & 0x100 else self.f[1])
        mask = sum((1 << c) for c in range(channels) if self.word(outputs + c * 4))
        self.trace.append([4, index, first, count, mask])
        if self.f[8]:
            # Simulate the platform GN exception boundary, not a sample decode.
            sp, ret, registers, frame = self.jump
            assert self.word(THREAD + 0x28) == frame
            self.put(THREAD + 0x28, self.word(frame + 0x48))
            for register, value in registers.items(): uc.reg_write(register, value)
            uc.reg_write(UC_X86_REG_ESP, sp + 4); uc.reg_write(UC_X86_REG_EIP, ret); uc.reg_write(UC_X86_REG_EAX, 1)
        # Otherwise execute the actual original WAVE -> buffered PCM reader.

    def setup(self, case):
        h, f, v = case['h'], case['f'], case['v']
        self.set_cache(h, case['ids'], case['mapping'], case['clients'], case['pool'])
        self.f = f; self.raws = case['raws']; self.positions = [0] * len(self.raws)
        self.trace = []; self.depth = 0
        self.uc.mem_write(STORAGE, case['storage'])
        self.uc.mem_write(FILE, bytes(0x100)); self.uc.mem_write(HANDLE, bytes(0x40))
        self.put(FILE + 0xc, CACHE if f[16] else 0)
        self.put(FILE + 0x14, f[1]); self.uc.mem_write(FILE + 0x18, struct.pack('<d', case['window'][2]))
        self.put(FILE + 0x24, f[4]); self.put(FILE + 0x4c, f[7]); self.put(FILE + 0x54, 0 if f[6] else READERS)
        self.put(HANDLE + 0xc, FILE, CLIENTS)
        self.uc.mem_write(0x3d4a48, bytes([bool(f[3])]))
        self.put(0x3d4a90, MUTEX); self.put(MUTEX, MUTEX_VT)
        self.put(MUTEX_VT + 0x1a4, LOCK); self.put(MUTEX_VT + 0x1ac, UNLOCK)
        self.uc.mem_write(THREAD, bytes(0x100))
        self.put(READER_VT + 0x1b0, 0x249976); self.put(READER_VT + 0x1b4, 0x2499f8)
        self.put(READER_VT + 0x1bc, 0x249a3c); self.put(READER_VT + 0x1c8, 0x24cc60)
        self.put(IO_VT + 0x1c0, SEEK); self.put(IO_VT + 0x1ac, READ)
        channels = f[1] & 255 if f[1] & 0x100 else f[1]
        for i, buffer in enumerate(case['buffers']):
            at = READERS + i * 0x200; io = IOS + i * 0x100
            self.uc.mem_write(at, bytes(0x80)); self.put(at, READER_VT)
            self.put(at + 0xc, f[9], BUFFERS + i * 0x2000, io)
            self.uc.mem_write(at + 0x1a, struct.pack('<3H', 1 if i else channels, WIDTHS[f[0]] * 8, 3 if f[0] == 0x13 else 1))
            self.put(at + 0x28, f[5]); self.put(at + 0x30, f[10])
            self.put(io, IO_VT); self.uc.mem_write(BUFFERS + i * 0x2000, buffer)
            if i: self.put(FILE + 0x5c + (i - 1) * 4, at)
        self.uc.mem_write(VOICE, bytes(0x140)); self.uc.mem_write(KEY, bytes(0x120))
        self.put(VOICE + 0x98, KEY); self.put(KEY + 0x8c, HANDLE)
        self.put(VOICE + 0x9c, v[0], v[1]); self.put(VOICE + 0xb0, v[5])
        self.put(KEY + 0x58, v[3], v[2]); self.uc.mem_write(VOICE + 0x91, bytes([v[4]]))
        self.uc.mem_write(VOICE + 0x110, struct.pack('<6f', *case['ramps'][:6]))
        self.uc.mem_write(VOICE + 0xf8, struct.pack('<6f', *case['ramps'][6:]))
        self.put(NEXT, v[7]); self.put(RANGE, v[8], v[9])

    def execute(self, case):
        h, f, v = case['h'], case['f'], case['v']; self.setup(case)
        if f[2] == 0: result = self.call(0x1af4e2, FILE, STORAGE + 32, f[13], f[11], f[12], f[3])
        elif f[2] == 1:
            args = struct.pack('<4I2d', FILE, HANDLE, f[11] & 0xffffffff, f[12], *case['window'][:2])
            self.call_packed(0x1aecf0, args); result = 0
        elif f[2] == 2:
            args = struct.pack('<6I2d', FILE, HANDLE, STORAGE + 32, f[13], f[11] & 0xffffffff, f[12], *case['window'][:2])
            result = self.call_packed(0x1afb00, args)
        elif f[2] == 3:
            args = struct.pack('<5I2d', HANDLE, STORAGE + 32, f[13], f[11] & 0xffffffff, f[12], *case['window'][:2])
            result = self.call_packed(0x1f0c92, args)
        else: result = self.call(0x152664, VOICE, STORAGE + 32, f[13], f[11], f[12], NEXT if v[6] else 0, RANGE)
        assert self.depth == 0 and self.word(THREAD + 0x28) == 0
        underrun, clients, mapping, ids, pool = self.cache_snapshot(h)
        answer = pack([result, underrun, len(self.diagnostics), len(self.trace), self.word(NEXT), self.word(RANGE), self.word(RANGE + 4), self.word(VOICE + 0xb0)])
        answer += clients + mapping + ids + pool
        answer += bytes(self.uc.mem_read(VOICE + 0x110, 24)) + bytes(self.uc.mem_read(VOICE + 0xf8, 24))
        answer += b''.join(pack(event) for event in self.trace) + b''.join(pack(event) for event in self.diagnostics)
        for i in range(len(self.raws)): answer += bytes(self.uc.mem_read(BUFFERS + i * 0x2000, f[9]))
        answer += bytes(self.uc.mem_read(STORAGE, len(case['storage'])))
        return answer


def serialized(case):
    data = pack(case['h']) + pack(case['ids']) + pack(case['mapping']) + b''.join(pack(c) for c in case['clients'])
    data += case['pool'] + case['storage'] + pack(case['f']) + struct.pack('<3d', *case['window'])
    data += pack(case['v']) + struct.pack('<12f', *case['ramps'])
    for raw, buffer in zip(case['raws'], case['buffers']): data += pack([len(raw)]) + raw + buffer
    return data


def compare(binary, runner, prefix, platform, wave_path):
    oracle = OriginalFileOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []; total_bytes = io_calls = voice_cases = 0
    for case in fixtures(wave_path):
        original = oracle.execute(case); fixture_bytes = serialized(case)
        process = probe.run(fixture_bytes, len(original))
        if process.returncode or process.stdout != original:
            folder = Path('work/ELA005-native'); folder.mkdir(parents=True, exist_ok=True)
            for label, data in [('fixture', fixture_bytes), ('original', original), ('native', process.stdout), ('stderr', process.stderr)]:
                (folder / f'failing-file-{label}.bin').write_bytes(data)
            at = next((i for i, (a, b) in enumerate(zip(original, process.stdout)) if a != b), min(len(original), len(process.stdout)))
            raise ValueError(f'Sample file mismatch {case["name"]}: exit={process.returncode}, byte={at}, original={original[at:at+4].hex()}, native={process.stdout[at:at+4].hex()}')
        total_bytes += len(original); io_calls += sum(e[0] == 6 for e in oracle.trace); voice_cases += case['f'][2] == 4
        cases.append({'name': case['name'], 'entry': case['f'][2], 'direct': bool(case['f'][3]),
                      'diagnostics': len(oracle.diagnostics), 'trace_events': len(oracle.trace),
                      'all_bytes_match': True, 'sha256': hashlib.sha256(original).hexdigest()})
    probe.close()
    return {'checkpoint': 'ELA005', 'original_i386_sha256': SHA,
            'scope': 'Sample file wrapper and cache range control connected to original PCM and chunk DSP',
            'reference_execution': 'Original i386 provider, wrapper, cache consumer, WAVE PCM read branch, converter and chunk DSP in Unicorn',
            'boundaries_adapted': ['libc memcpy/memset', 'raw byte seek/read', 'shared mutex callbacks', 'thread-local context accessor',
                                   'setjmp and injected reader exception context'],
            'original_sample_provider_executed': True, 'decoded_sample_provider_substituted': False,
            'compiled_platform': platform, 'persistent_probe_process': True, 'automatic_fixture_retries': 0,
            'fixture_count': len(cases), 'voice_chunk_integration_cases': voice_cases, 'byte_read_calls': io_calls,
            'compared_bytes': total_bytes, 'all_cases_match_bit_for_bit': True,
            'embedded_original_wave_cases': 24, 'embedded_original_wave_sha256': WAVE_SHA,
            'container_metadata_and_cache_contents_supplied_by_fixtures': True,
            'asynchronous_cache_producer_executed': False, 'original_wave_header_parser_executed': False,
            'actual_platform_GN_exception_runtime_validated': False, 'concurrent_cache_mutation_tested': False,
            'complete_engine_built': False, 'macos_audio_unit_validated': False, 'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path); p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[]); p.add_argument('--platform', required=True)
    p.add_argument('--wave', type=Path, required=True); p.add_argument('--output', type=Path, required=True)
    a = p.parse_args(); r = compare(a.binary, a.runner, a.runner_prefix, a.platform, a.wave)
    a.output.parent.mkdir(parents=True, exist_ok=True); a.output.write_text(json.dumps(r, indent=2) + '\n')
    print(json.dumps({k: r[k] for k in ['fixture_count','voice_chunk_integration_cases','byte_read_calls','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']}, indent=2))
