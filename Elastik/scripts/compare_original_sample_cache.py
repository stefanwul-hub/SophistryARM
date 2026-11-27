#!/usr/bin/env python3
"""Compare original cache slot/read/request/invalidate instructions with C++."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct

from legacy_image import SHA
from native_probe import NativeProbe
from original_cache_oracle import OriginalCacheOracle, CACHE, CLIENTS, STORAGE


def pack(values): return struct.pack('<' + 'i' * len(values), *values)


def fixtures():
    rng = random.Random(0xE1A005)
    for chunk in [1, 7, 16, 31]:
        for channels in [1, 2, 4]:
            frames = chunk * 6 + 3
            slots = (frames + chunk - 1) // chunk
            for profile in ['resident', 'stale-found', 'missing-map', 'stale-absent', 'all-missing']:
                for client_mode in ['none', 'inactive-first', 'active-one', 'three']:
                    ids = list(range(slots)); rng.shuffle(ids)
                    mapping = [ids.index(i) for i in range(slots)] + [-1, -1]
                    if profile == 'stale-found': mapping[1] = (mapping[1] + 1) % slots
                    elif profile == 'missing-map': mapping[2] = -1
                    elif profile == 'stale-absent': ids[mapping[2]] = -9
                    elif profile == 'all-missing': mapping = [-1] * len(mapping)
                    clients = {'none': [], 'inactive-first': [[0, 1, 3], [1, 2, 5]],
                               'active-one': [[2, 1, 4]], 'three': [[1, 1, 4], [0, -1, -1], [1, 2, 5]]}[client_mode]
                    operations = [[1, block, 0, 0, 0, 0] for block in range(len(mapping))]
                    operations.append([5, 0, 0, 0, 0, 0])
                    stride = 2 * chunk + 3 + 16
                    read_index = 0
                    for first in sorted(set([0, chunk - 1, chunk, 2 * chunk - 1, frames - 1, frames, frames + 2])):
                        for count in [0, 1, 2, chunk, 2 * chunk + 3]:
                            for channel in sorted(set([0, channels - 1])):
                                operations.append([2, channel, first, count, 8 + read_index * stride, 0])
                                read_index += 1
                    if clients:
                        for first in [-chunk, -1, 0, chunk, frames - 1, frames, frames + 5]:
                            for count in [-1, 0, 1, chunk, 2 * chunk]:
                                operations.append([3, len(clients) - 1, first, count, 0, 0])
                        operations.append([4, 0, 0, 0, 0, 0])
                        operations.append([5, 0, 0, 0, 0, 0])
                        operations.append([2, 0, 0, chunk + 2, 8, 0])
                    words = 16 + read_index * stride
                    pool = rng.randbytes(slots * chunk * channels * 4)
                    output = rng.randbytes(words * 4)
                    h = [frames, chunk, channels, slots, len(mapping), len(clients), len(operations), words, 7 if channels == 2 else 0]
                    name = f'chunk-{chunk}-channels-{channels}-{profile}-{client_mode}'
                    yield name, h, ids, mapping, clients, pool, output, operations
    # Original slot lookup dereferences the mapped slot before testing the
    # logical slot count. Keep one accessible sentinel allocation in this case.
    yield 'zero-logical-slots', [7, 4, 2, 0, 4, 1, 4, 64, 0], [99], [0, -1, -1, -1], [[1, 0, 1]], bytes(32), bytes([0x55]) * 256, [[1, 0, 0, 0, 0, 0], [2, 0, 0, 6, 8, 0], [4, 0, 0, 0, 0, 0], [5, 0, 0, 0, 0, 0]]
    for name, ids, clients in [('all-protected', [0, 1, 2], [[1, 0, 2]]),
                               ('empty-slot', [1, -1, 2], [[1, 1, 2]]),
                               ('second-client-protects', [0, 1, 2], [[0, 0, 2], [1, 0, 2]])]:
        operations = [[5, 0, 0, 0, 0, 0], [4, len(clients) - 1, 0, 0, 0, 0], [5, 0, 0, 0, 0, 0]]
        yield 'reuse-' + name, [12, 4, 1, 3, 4, len(clients), 3, 32, 0], ids, [0, 1, 2, -1], clients, bytes(48), bytes(128), operations


def compare(binary, runner, prefix, platform):
    oracle = OriginalCacheOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []; operations_count = read_frames = compared_bytes = 0
    for name, h, ids, mapping, clients, pool, output, operations in fixtures():
        oracle.set_cache(h, ids, mapping, clients, pool)
        oracle.uc.mem_write(STORAGE, output)
        results = []
        for kind, a, b, c, d, unused in operations:
            if kind == 1: result = oracle.call(0x218102, CACHE, a)
            elif kind == 2:
                result = oracle.call(0x21900c, CACHE, STORAGE + d * 4, a, b, c)
                read_frames += c
            elif kind == 3: result = oracle.call(0x218cf6, CACHE, CLIENTS + a * 12, 0x12345678, b, c)
            elif kind == 4:
                oracle.call(0x218d48, CACHE, CLIENTS + a * 12); result = 0
            elif kind == 5: result = oracle.call(0x2181d6, CACHE)
            else: raise ValueError('Unknown operation')
            results.append(result)
        underrun, out_clients, out_map, out_ids, out_pool = oracle.cache_snapshot(h)
        original = pack([len(results), underrun, len(oracle.diagnostics), h[5], h[7]]) + pack(results)
        original += out_clients + out_map + out_ids + out_pool
        original += b''.join(pack(row) for row in oracle.diagnostics) + bytes(oracle.uc.mem_read(STORAGE, len(output)))
        fixture = pack(h) + pack(ids) + pack(mapping) + b''.join(pack(c) for c in clients) + pool + output + b''.join(pack(op) for op in operations)
        process = probe.run(fixture, len(original))
        if process.returncode or process.stdout != original:
            folder = Path('work/ELA005-native'); folder.mkdir(parents=True, exist_ok=True)
            for label, data in [('fixture', fixture), ('original', original), ('native', process.stdout), ('stderr', process.stderr)]:
                (folder / f'failing-cache-{label}.bin').write_bytes(data)
            at = next((i for i, (a, b) in enumerate(zip(original, process.stdout)) if a != b), min(len(original), len(process.stdout)))
            raise ValueError(f'Cache mismatch {name}: exit={process.returncode}, byte={at}, original={original[at:at+4].hex()}, native={process.stdout[at:at+4].hex()}')
        compared_bytes += len(original); operations_count += len(operations)
        cases.append({'name': name, 'operations': len(operations), 'diagnostics': len(oracle.diagnostics),
                      'underrun': underrun, 'all_bytes_match': True, 'sha256': hashlib.sha256(original).hexdigest()})
    probe.close()
    return {'checkpoint': 'ELA005', 'original_i386_sha256': SHA,
            'scope': 'Original synchronous cache consumer and range controls, with externally populated cache',
            'original_functions': [{'address':'0x218102','bytes':130}, {'address':'0x2181d6','bytes':168}, {'address':'0x21900c','bytes':337},
                                   {'address':'0x218cf6','bytes':82}, {'address':'0x218d48','bytes':22}],
            'reference_execution': 'Original i386 in Unicorn; only libc memcpy and diagnostic print adapted',
            'compiled_platform': platform, 'persistent_probe_process': True, 'automatic_fixture_retries': 0,
            'fixture_count': len(cases), 'operation_count': operations_count, 'requested_read_frames': read_frames,
            'compared_bytes': compared_bytes, 'all_cases_match_bit_for_bit': True,
            'coverage': ['resident chunks', 'stale map entry found or absent', 'missing map does not scan',
                         'cross-chunk reads and EOF clipping', 'prefix copied before underrun', 'unchanged map and source data',
                         'repeated diagnostic for first client', 'inclusive end of prepared range', 'invalidation preserves active flag',
                         'output guards and persistent underrun flag', 'reusable slots respect every active client request'],
            'asynchronous_cache_producer_executed': False, 'complete_engine_built': False,
            'macos_audio_unit_validated': False, 'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path); p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--platform', required=True); p.add_argument('--output', type=Path, required=True)
    a = p.parse_args(); r = compare(a.binary, a.runner, a.runner_prefix, a.platform)
    a.output.parent.mkdir(parents=True, exist_ok=True); a.output.write_text(json.dumps(r, indent=2) + '\n')
    print(json.dumps({k: r[k] for k in ['fixture_count','operation_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']}, indent=2))
