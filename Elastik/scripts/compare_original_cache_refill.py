#!/usr/bin/env python3
"""Compare original cache refill, allocation and PCM-to-cache-to-voice path.

The original 0x218d5e pass, 0x21827e growth and 0x1afed2 multichannel read
execute unmodified. Memory allocation, Carbon clock/warning, byte I/O and
platform GN thread/exception interfaces are explicit test bindings.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct

from compare_original_sample_file import (fixture, serialized, OriginalFileOracle, WIDTHS, WAVE_SHA,
                                          FILE, HANDLE, VOICE, RANGE, NEXT)
from original_cache_oracle import CACHE, BLOCKS, MAP, CLIENTS, POOL, STORAGE
from legacy_image import SHA
from native_probe import NativeProbe
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_FPCW, UC_X86_REG_FPSW, UC_X86_REG_FPTAG

CLOCK_VALUE, CLOCK_TRAMPOLINE = 0x550000, 0x500a00


def pack(values): return struct.pack('<' + 'i' * len(values), *values)
def op(kind, *args): return [kind, *args] + [0] * (7 - len(args))


def refill_fixture(rng, name, *, scenario='cold', profiling=0, initial_processing=7,
                   elapsed=0.125, soft_capacity=None, operations=None, **options):
    case = fixture(rng, name, **options)
    frames, chunk, channels = case['h'][:3]
    map_count = (frames + chunk - 1) // chunk + 2
    physical = map_count if frames <= 1024 else 8
    ids = [-1] * physical; mapping = [-1] * map_count
    clients = [[1, 1, min(3, map_count - 2)], [0, -1, -1]]
    initial = 0
    if scenario == 'empty-preallocated': initial = 2
    elif scenario == 'protected-grow':
        initial = 1; ids[0] = 1; mapping[1] = 0; clients[0] = [1, 0, min(3, map_count - 2)]
    elif scenario == 'evict':
        initial = 2; ids[:2] = [0, 1]; mapping[:2] = [0, 1]; clients[0] = [1, 3, 4]
    elif scenario == 'multiple-clients': clients = [[1, 0, 2], [2, 2, 4], [0, 0, map_count - 2]]
    elif scenario == 'stale-found':
        initial = 2; ids[:2] = [1, 2]; mapping[1:3] = [1, 1]; clients[0] = [1, 1, 3]
    elif scenario == 'no-clients': clients = []
    elif scenario != 'cold': raise ValueError('Unknown scenario')
    # No decoded fixture is used to populate the new cache. Untouched/failed
    # loads retain this deterministic finite allocation content, like the
    # original allocator's caller-supplied initial memory in the oracle.
    pool = struct.pack('<f', 0.03125) * (physical * chunk * channels)
    case.update(ids=ids, mapping=mapping, clients=clients, pool=pool)
    case['h'][3:6] = [physical, map_count, len(clients)]
    case['h'][6] = 0; case['h'][7] = 256
    case['storage'] = struct.pack('<256f', *(rng.uniform(-0.01, 0.01) for _ in range(256)))
    if operations is None:
        first = clients[0][1] * chunk + 1 if clients else 0
        operations = [op(1), op(5, channels - 1, first, 19, 8), op(1), op(6, min(1, channels - 1), frames // 2, 17, 80),
                      op(2, 0, frames - chunk, chunk), op(1, 0, 0, 0, 0), op(5, 0, frames - 10, 19, 144)]
        if len(clients) > 1: operations.insert(4, op(3, 1))
    if soft_capacity is None: soft_capacity = physical
    case['refill'] = [initial, soft_capacity, profiling, initial_processing, len(operations), 0, 0]
    case['times'] = [elapsed, 1000.25, 0.25]
    case['operations'] = operations
    return case


def fixtures(wave):
    rng = random.Random(0xE1A0062)
    scenarios = ['cold','empty-preallocated','protected-grow','evict','multiple-clients','stale-found']
    for fmt in WIDTHS:
        for channels in [1, 2, 0x104]:
            for chunk in [7, 16, 31]:
                for i, scenario in enumerate(scenarios):
                    for profiling in [0, 1]:
                        yield refill_fixture(rng, f'{scenario}-fmt{fmt:x}-ch{channels:x}-chunk{chunk}-profile{profiling}',
                                             scenario=scenario, profiling=profiling, fmt=fmt, channels=channels,
                                             chunk=chunk, frames=96 if i % 2 else 97)
    for separate in [0, 1]:
        for fail in [0, 1, 2, 3, 4]:
            yield refill_fixture(rng, f'reader-error-separate{separate}-target{fail}', separate=separate,
                                 fail=fail, frames=96, chunk=16, profiling=1)
    for ok in [0, 1]:
        for short in [0, 1, 3]:
            yield refill_fixture(rng, f'short-raw-ok{ok}-bytes{short}', read_ok=ok, max_read=short, frames=96, chunk=16)
    for profiling in [0, 1, 2]:
        for elapsed in [0.0, -0.0, 0.125]:
            yield refill_fixture(rng, f'no-clients-profile{profiling}-elapsed{elapsed!r}', scenario='no-clients',
                                 profiling=profiling, elapsed=elapsed, operations=[op(7), op(1), op(1)])
    for capacity in [0, 1, 2]:
        yield refill_fixture(rng, f'capacity-warning-limit{capacity}', soft_capacity=capacity,
                             scenario='protected-grow', profiling=1, frames=96, chunk=16)
    for direction in [0, 1]:
        operations = [op(6, 0, 50, 17, 8), op(1), op(6, 0, 50, 17, 80), op(1)]
        voice = [0, 96, direction, 1, 0, -7, 1, 0x12345678, -11, -13]
        ramps = [1.0, 0.25, 0.03125] * 2 + [0.0, 0.75, -0.015625] * 2
        yield refill_fixture(rng, f'cold-voice-before-after-fill-dir{direction}', operations=operations,
                             voice=voice, ramps=ramps, frames=97, chunk=16, profiling=1)
    # Unknown frame count uses the original metadata getter during actual
    # multichannel reads. Voice getters use the known native state in other cases.
    yield refill_fixture(rng, 'unknown-frame-count', known=False, frames=97, chunk=16,
                         operations=[op(1), op(5, 0, 17, 19, 8), op(1)])
    raw = wave.read_bytes(); assert hashlib.sha256(raw).hexdigest() == WAVE_SHA
    at = 12
    while at + 8 <= len(raw):
        size = struct.unpack_from('<I', raw, at + 4)[0]
        if raw[at:at + 4] == b'data': data_offset = at + 8; break
        at += 8 + size + (size & 1)
    else: raise ValueError('No WAVE data chunk')
    for block in [0, 55, 172]:
        for profiling in [0, 1]:
            operations = [op(1), op(5, 0, block * 1024 + 13, 65, 8), op(6, 1, block * 1024 + 20, 32, 128)]
            case = refill_fixture(rng, f'embedded-wave-block{block}-profile{profiling}', frames=176399, chunk=1024,
                                  raw=raw, data_offset=data_offset, profiling=profiling, operations=operations)
            case['clients'] = [[1, block, min(block + 1, 172)], [0, -1, -1]]
            yield case


class RefillOracle(OriginalFileOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.import_handlers['_GetCurrentEventTime'] = self.clock
        self.uc.hook_add(UC_HOOK_CODE, self.allocate, begin=0xaecc, end=0xaecc)
        self.uc.hook_add(UC_HOOK_CODE, self.capacity_warning, begin=0xacae, end=0xacae)
        # Adapt a double-returning platform clock through actual x87 FLD/RET,
        # preserving the original i386 return ABI for the unmodified caller.
        self.uc.mem_write(CLOCK_TRAMPOLINE, b'\xdd\x05' + struct.pack('<I', CLOCK_VALUE) + b'\xc3')

    def state(self): return self.uc.mem_read(CACHE + 0x3c, 1)[0], self.uc.mem_read(CACHE + 0x30, 1)[0], self.word(CACHE + 0x1c)

    def allocate(self, uc, address, size, user):
        requested, = self.arguments(1); processing, underrun, slot = self.state()
        assert requested == self.block_bytes and 0 <= slot < self.case['h'][3]
        self.trace.append([11, requested, slot, processing, underrun]); self.allocations += 1
        self.finish(POOL + slot * self.block_bytes)

    def capacity_warning(self, uc, address, size, user):
        text_at, = self.arguments(1)
        text = bytes(uc.mem_read(text_at, 100)).split(b'\0', 1)[0]
        assert text == b'GNFileCache: Buffer block count to low.'
        processing, underrun, slot = self.state()
        self.trace.append([12, slot, self.word(CACHE + 0x20), processing, underrun]); self.finish()

    def clock(self):
        processing, underrun, slot = self.state()
        self.trace.append([10, self.clock_calls, processing, underrun, slot])
        value = self.case['times'][1] + self.clock_calls * self.case['times'][2]
        self.clock_calls += 1; self.uc.mem_write(CLOCK_VALUE, struct.pack('<d', value))
        self.uc.reg_write(UC_X86_REG_EIP, CLOCK_TRAMPOLINE)

    def observe_reader_call(self, index, first, count):
        processing, underrun, slots = self.state(); block = first // self.case['h'][1]
        self.trace.append([13, processing, underrun, slots, self.word(MAP + block * 4)])
        for slot in range(slots):
            block_id = self.word(BLOCKS + slot * 8)
            pointer = self.word(BLOCKS + slot * 8 + 4)
            self.trace.append([14, slot, block_id, int(pointer != 0), self.word(MAP + block_id * 4) if block_id >= 0 else -1])

    def execute_refill(self, case):
        self.case = case; self.setup(case)
        self.clock_calls = self.allocations = 0
        h, r, v = case['h'], case['refill'], case['v']
        self.block_bytes = h[1] * h[2] * 4
        self.put(CACHE + 0x18, self.block_bytes, r[0], r[1])
        self.uc.mem_write(CACHE + 0x31, bytes([r[2] & 255]))
        self.uc.mem_write(CACHE + 0x34, struct.pack('<d', case['times'][0]))
        self.uc.mem_write(CACHE + 0x3c, bytes([r[3] & 255])); self.put(CACHE + 0x48, FILE)
        self.put(CACHE + 0x54, h[2])
        for slot in range(r[0], h[3]): self.put(BLOCKS + slot * 8 + 4, 0)
        self.uc.reg_write(UC_X86_REG_FPCW, 0x37f); self.uc.reg_write(UC_X86_REG_FPSW, 0); self.uc.reg_write(UC_X86_REG_FPTAG, 0xffff)
        results = []
        for kind, a, b, c, d, unused1, unused2, unused3 in case['operations']:
            if kind == 1: self.call(0x218d5e, CACHE); result = 0
            elif kind == 2: result = self.call(0x218cf6, CACHE, CLIENTS + a * 12, 0, b, c)
            elif kind == 3: self.call(0x218d48, CACHE, CLIENTS + a * 12); result = 0
            elif kind == 4: self.uc.mem_write(CLIENTS + a * 12, bytes([b & 255])); result = 0
            elif kind == 5:
                args = struct.pack('<5I2d', HANDLE, STORAGE + d * 4, a, b, c, *case['window'][:2])
                result = self.call_packed(0x1f0c92, args)
            elif kind == 6: result = self.call(0x152664, VOICE, STORAGE + d * 4, a, b, c, NEXT if v[6] else 0, RANGE)
            elif kind == 7: result = self.call(0x21827e, CACHE)
            else: raise ValueError('Unknown operation')
            results.append(result)
        assert self.depth == 0
        processing, underrun, slots = self.state()
        _, clients, mapping, ids, pool = self.cache_snapshot(h)
        header = [len(results), slots, underrun, processing, len(self.diagnostics), len(self.trace), self.clock_calls,
                  self.word(NEXT), self.word(RANGE), self.word(RANGE + 4), self.word(VOICE + 0xb0), self.allocations]
        answer = pack(header) + bytes(self.uc.mem_read(CACHE + 0x34, 8)) + pack(results) + clients + mapping
        for slot in range(h[3]):
            pointer = self.word(BLOCKS + slot * 8 + 4)
            assert not pointer or pointer == POOL + slot * self.block_bytes
            answer += pack([self.word(BLOCKS + slot * 8), slot if pointer else -1])
        answer += pool + bytes(self.uc.mem_read(VOICE + 0x110, 24)) + bytes(self.uc.mem_read(VOICE + 0xf8, 24))
        answer += b''.join(pack(row) for row in self.trace) + b''.join(pack(row) for row in self.diagnostics)
        for i in range(len(case['raws'])): answer += bytes(self.uc.mem_read(0x640000 + i * 0x2000, case['f'][9]))
        answer += bytes(self.uc.mem_read(STORAGE, len(case['storage'])))
        return answer


def compare(binary, runner, prefix, platform, wave):
    oracle = RefillOracle(binary); probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []; total = reads = passes = 0
    for case in fixtures(wave):
        expected = oracle.execute_refill(case)
        data = serialized(case) + pack(case['refill']) + struct.pack('<3d', *case['times']) + b''.join(pack(row) for row in case['operations'])
        actual = probe.run(data, len(expected))
        if actual.returncode or actual.stdout != expected:
            folder = Path('work/ELA006-native'); folder.mkdir(parents=True, exist_ok=True)
            for label, b in [('fixture', data), ('original', expected), ('native', actual.stdout), ('stderr', actual.stderr)]:
                (folder / f'failing-refill-{label}.bin').write_bytes(b)
            at = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b), min(len(expected), len(actual.stdout)))
            raise ValueError(f'Refill mismatch {case["name"]}: exit={actual.returncode}, byte={at}, original={expected[at:at+4].hex()}, native={actual.stdout[at:at+4].hex()}')
        total += len(expected); reads += sum(t[0] == 6 for t in oracle.trace); passes += sum(o[0] == 1 for o in case['operations'])
        cases.append({'name':case['name'],'operations':len(case['operations']),'allocations':oracle.allocations,
                      'clock_calls':oracle.clock_calls,'trace_events':len(oracle.trace),'diagnostics':len(oracle.diagnostics),
                      'all_bytes_match':True,'sha256':hashlib.sha256(expected).hexdigest()})
    probe.close()
    return {'checkpoint':'ELA006','scope':'Original refill/growth and encoded PCM -> cache -> sample provider -> voice chunk path',
            'original_i386_sha256':SHA,'original_refill_function':'0x218d5e','original_refill_bytes':686,
            'original_add_slot_function':'0x21827e','original_add_slot_bytes':79,
            'reference_execution':'Unmodified original i386 refill, growth, multichannel read, WAVE PCM branch, provider and chunk DSP in Unicorn',
            'boundaries_adapted':['GN allocator and capacity warning','Carbon GetCurrentEventTime with x87 return ABI','libc memcpy/memset',
                                  'raw byte I/O','thread context and shared mutex','setjmp and injected reader exception'],
            'compiled_platform':platform,'fixture_count':len(cases),'refill_passes':passes,'byte_read_calls':reads,'compared_bytes':total,
            'all_cases_match_bit_for_bit':True,'decoded_cache_population_substituted':False,'pointer_fields_compared_as_logical_slot_tokens':True,
            'embedded_original_wave_cases':6,'embedded_original_wave_sha256':WAVE_SHA,'automatic_fixture_retries':0,
            'original_wave_header_parser_executed':False,'real_GN_memory_exception_runtime_validated':False,
            'actual_thread_scheduler_executed':False,'concurrent_cache_mutation_tested':False,'complete_engine_built':False,
            'macos_audio_unit_validated':False,'cases':cases}


if __name__ == '__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path)
    p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True)
    p.add_argument('--wave',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.wave)
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n')
    print(json.dumps({k:r[k] for k in ['fixture_count','refill_passes','byte_read_calls','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
