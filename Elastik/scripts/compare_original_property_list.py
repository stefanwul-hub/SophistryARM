#!/usr/bin/env python3
"""Compare native property lists with the pinned i386 dispatcher and parser."""

import argparse
import hashlib
import itertools
import json
import random
import struct
from pathlib import Path

from compare_original_archive_open import ArchiveOpenOracle, GNA, ROOT, SOURCE, fixture as open_fixture
from compare_original_file_archive import ARCHIVE_SHA, BUILTIN, OUT, archive
from legacy_image import SHA
from native_probe import NativeProbe
from original_plist_oracle import PropertyListOracle


def fixtures():
    documents = {
        'empty-dict': b'{}',
        'group': b'{ identifier = com.example.Bank; title = "Test Bank"; color = blue; gracePeriode = 1.25; }',
        'nested': b'{ list = (a, 123, "123", 0.125, (b, <EE ff>,), { z; }); flags = { no = n; }; }',
        'collision': b'{ a = first; b = x; a = second; "a" = 3; "a"; }',
        'empty-collections': b'{ "" = <>; array = (); obj = { }; text = ""; }',
        'semicolon-optional-when-assigned': b'{ final = last }',
        'semicolon-required-when-key-alone': b'{ flag }',
        'numbers-as-keys': b'{ 1 = a; 2.0 = b; _ = dollar$:test/path; }',
        'whitespace': b'{ \t\r\n\v\fa\v=\fb\r; }',
        'comments': b' // first\n /* x */ { a /* y **/ = b; // third\n z = <AB /* comment */ cd>; }',
        'last-root-only': b'{} trailing data { additional = ignored; }',
        'unterminated-document': b'{ a = "text',
        'line-comment-no-newline': b'{ a = b // comment }',
        'nested-comment': b'{ /* aa /* bb */ c */ a = b; }',
        'prefix-xml': b'<?xml version="1.0"?><plist><dict/></plist>',
        'prefix-binary': b'bplist00',
        'prefix-text-array': b'(hello, there)',
        'no-bytes': b'',
        'invalid-prefix': b'  { a = invalid - text; }',
        'utf8-bom': b'\xef\xbb\xbf{}',
        'leading-nul': b'\0{}',
        'both-quotes': b'''{ a = 'double " char'; b = "single ' char"; }''',
        'stress-numeric-scale': b'{ big = ' + b'9' * 330 + b'.1; small = 0.' + b'0' * 350 + b'1; }',
        'stress-nesting': b'{ x = ' + b'(' * 31 + b'1' + b')' * 31 + b'; }',
    }
    for name, doc in documents.items():
        for has_reader in (False, True):
            yield name, doc, has_reader, True

    for name, raw in {
        'le': b'\xff\xfe',
        'be': b'\xfe\xff',
    }.items():
        endian = f'utf-16-{name}'
        for reader, prefix, trailing in itertools.product((False, True), ('', '  ', '\n'), (b'', b'x')):
            doc = prefix + '{ title = "Éclair 🎵"; color = green; }'
            yield f'utf16-{name}-{prefix!r}-{trailing!r}', raw + doc.encode(endian) + trailing, reader, True

    for token in [
        b'0', b'00', b'01', b'42', b'123456789', b'2147483645', b'2147483646',
        b'2147483647', b'2147483648', b'429496728', b'429496729', b'4294967288',
        b'999999999999999', b'0.0', b'.', b'..', b'.1', b'1.', b'1.2.3', b'1..2',
        b'1.000000059604644775390625', b'0.12345678901234567890123456789',
        b'1e3', b'1.0e3', b'3e-2', b'-1', b'-0.0', b'+2', b'12.5Hz',
        b'yes', b'NO', b'True', b'Infinity', b'NaN', b'Infinity.0', b'5_000',
        b'a/b:c.d', b'space separated', b';', b')', b'{', b'""', b'$identifier',
    ]:
        yield f'token-{token!r}', b'{ key = ' + token + b'; }', True, True

    for value in [
        b'', b'  ', b'0A', b'dEaD bEeF', b'0A 0B 0c', b'0a\t0b\n0c',
        b'a b', b'ab c', b'0x41', b'ABC', b'12G0', b'00FF', b'////comment\nff',
        b'AB /* comment */ CD', b'/* odd **/ 12', b'12 / 34', b'1234/5678',
    ]:
        yield f'hex-{value!r}', b'{ key = <' + value + b'>; }', True, True

    for escape in [
        b'a', b'b', b'f', b'n', b'r', b't', b'v', b'\n', b'\r', b'"', b"'",
        b'\\', b'?', b'0', b'7', b'8', b'123', b'7777', b'U00e9', b'UABCD',
        b'Ud83D\\Ude00', b'U20', b'U', b'U0000start', b'U12345', b'Uxyz',
    ]:
        yield f'escape-{escape!r}', b'{ key = "pre\\' + escape + b'post"; }', True, True

    for has_reader in (False, True):
        for byte in range(256):
            yield f'single-quoted-byte-{byte}', b'{ key = "' + bytes([byte]) + b'"; }', has_reader, True
        for token in ['🎹'.encode(), b'\xed\xa0\x80', b'\xc0\xaf', b'\xe0\x9f\x80', b'\xf4\x90\x80\x80']:
            yield f'encoded-{token.hex()}', b'{ key = "' + token + b'"; }', has_reader, True

    rng = random.Random(0xe1a014)
    for n in range(500):
        prefix = rng.choice([b'', b'//', b'/*', b' /**', b'\xff\xfe', b'\xfe\xff'])
        marker = rng.choice(b'\0{} \t\r\n/*\xff\xfe')
        raw = prefix + bytes(rng.choice(b'\0{ \r\n/*\xff\xfeX') for _ in range(rng.randrange(12))) + bytes([marker])
        for has_reader in (False, True):
            yield f'format-{n}-{raw.hex()}', raw, has_reader, False


def archive_fixtures(builtin):
    demo = builtin.read_bytes()
    if hashlib.sha256(demo).hexdigest() != ARCHIVE_SHA:
        raise ValueError('Expected the pinned built-in GNFA archive')
    for path, flags in itertools.product(('/Info.plist', '/elastik/Info.plist'), range(4)):
        yield 'builtin', demo, path, flags
    documents = {
        'openstep': b'{ identifier = example.synthetic; title = "Fixture"; gracePeriode = .25; }',
        'invalid': b'{ title = (1, 2; }',
        'xml-route': b'<?xml version="1.0"?><plist><dict/></plist>',
        'utf16': b'\xff\xfe' + '{ title = "Éclair"; }'.encode('utf-16-le'),
    }
    for (name, doc), layout, flags in itertools.product(documents.items(), (0, 1), range(4)):
        yield f'{name}-layout{layout}', archive([('Info.plist', doc, {})], layout=layout), '/Info.plist', flags
    nested = archive([
        ('samples', b'', {'length': 0x8000000000000001}),
        ('Info.plist', documents['openstep'], {'parent': 1}),
    ])
    yield 'nested', nested, '/samples/Info.plist', 0
    yield 'nested', nested, '/Info.plist', 0
    yield 'directory', nested, '/samples', 0
    yield 'truncated-member', archive([('Info.plist', b'{abc}', {'length': 120})]), '/Info.plist', 0
    yield 'bad-header', b'bad!', '/Info.plist', 0


def archive_expected(legacy, oracle, raw, path, flags):
    fixture = open_fixture('plist', raw, path)
    fixture['h'][10:12] = [flags & 1, flags >> 1]
    legacy.setup_open(fixture)
    legacy.phase = 'parse'
    legacy.call_reg(0xe13de, (GNA, SOURCE))
    result = struct.pack('<i', legacy.error)
    if legacy.error:
        return result, None

    legacy.phase = 'lookup'
    member_path = legacy.call_reg(0xe1a68, (GNA, ROOT))
    result += struct.pack('<i', legacy.error)
    if not member_path or not legacy.call_reg(0xe05a2, (member_path,)):
        return result + struct.pack('<iB', 0, 0), None

    length = legacy.call_reg(0xe09c0, (member_path,))
    reader = legacy.call_reg(0xe3ff4, (member_path,))
    if legacy.error or not reader:
        return result + struct.pack('<iB', legacy.error or 3, 0), None
    actual_count = OUT + 1024 * 1024
    legacy.put(actual_count, length)
    ok = legacy.call_reg(0xe4172, (reader, OUT, actual_count))
    if not ok or legacy.error or legacy.word(actual_count) != length:
        return result + struct.pack('<iB', legacy.error or 3, 0), None
    text = bytes(legacy.uc.mem_read(OUT, length))
    decoded = oracle.run(text, True)
    return result + struct.pack('<iB', 0, 1) + decoded, hashlib.sha256(text).hexdigest()


def compare(binary, runner, prefix, platform, builtin):
    oracle = PropertyListOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []
    for name, raw, reader, parse in fixtures():
        name += '-path-reader' if reader else '-no-reader'
        expected = oracle.run(raw, reader, parse)
        fixture = struct.pack('<III', len(raw), reader, parse) + raw
        actual = probe.run(fixture, len(expected))
        if actual.returncode or actual.stdout != expected:
            raise ValueError(f'{name}: fixture={raw!r} expected={expected.hex()} '
                             f'native={actual.stdout.hex()} stderr={actual.stderr!r}')
        cases.append({
            'name': name, 'parse_requested': parse, 'result_bytes': len(expected),
            'result_sha256': hashlib.sha256(expected).hexdigest(),
        })
    legacy = ArchiveOpenOracle(binary)
    archived = []
    for group, raw, path, flags in archive_fixtures(builtin):
        name = f'archive-{group}-{path}-clone{flags & 1}-shared{flags >> 1}'
        expected, member_sha = archive_expected(legacy, oracle, raw, path, flags)
        units = path.encode('utf-16-le')
        fixture = struct.pack('<III', len(raw), flags, 2) + raw + struct.pack('<I', len(units) // 2) + units
        actual = probe.run(fixture, len(expected))
        if actual.returncode or actual.stdout != expected:
            raise ValueError(f'{name}: expected={expected.hex()} '
                             f'native={actual.stdout.hex()} stderr={actual.stderr!r}')
        archived.append({
            'name': name, 'member_found_and_read': member_sha is not None,
            'original_member_sha256': member_sha, 'result_bytes': len(expected),
            'result_sha256': hashlib.sha256(expected).hexdigest(),
        })
    probe.close()
    builtin_root = [row for row in archived if row['name'].startswith('archive-builtin-/Info.plist')]
    builtin_nested = [row for row in archived if row['name'].startswith('archive-builtin-/elastik/Info.plist')]
    if len(builtin_root) != 4 or len(builtin_nested) != 4:
        raise ValueError('Expected both built-in plist paths in all four sharing configurations')
    if any(not row['member_found_and_read'] for row in builtin_root):
        raise ValueError('Built-in root plist was not read')
    if any(row['member_found_and_read'] for row in builtin_nested):
        raise ValueError('Unexpected nested member in the built-in bank')
    direct_count = len(cases)
    cases.extend(archived)
    return {
        'checkpoint': 'ELA014', 'original_i386_sha256': SHA, 'compiled_platform': platform,
        'scope': 'Original GN plist routing, OpenStep grammar, text conversions and scalar number scanners',
        'fixture_count': len(cases), 'compared_bytes': sum(row['result_bytes'] for row in cases),
        'direct_fixtures': direct_count, 'archive_pipeline_fixtures': len(archived),
        'builtin_root_resolved_and_read': True, 'builtin_nested_path_has_no_member': True,
        'original_archived_plist_passed_between_two_vms': True,
        'all_cases_match_bit_for_bit': True, 'automatic_fixture_retries': 0,
        'original_xml_parser_executed': False, 'original_gn_collection_ownership_executed': False,
        'actual_macos_execution': False, 'cases': cases,
    }


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--platform', required=True)
    p.add_argument('--builtin', type=Path, default=BUILTIN)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    report = compare(args.binary, args.runner, args.runner_prefix, args.platform, args.builtin)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key: report[key] for key in ('fixture_count', 'compared_bytes', 'compiled_platform')}))
