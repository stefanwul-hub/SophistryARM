#!/usr/bin/env python3
"""Compare the ARM64-compatible XML plist branch with the i386 Elastik image."""

import argparse
import hashlib
import itertools
import json
import random
import struct
import subprocess
from pathlib import Path

from compare_original_archive_open import ArchiveOpenOracle
from compare_original_file_archive import BUILTIN, archive
from compare_original_property_list import archive_expected, archive_fixtures, fixtures
from legacy_image import SHA
from native_probe import NativeProbe
from original_xml_plist_oracle import XmlPropertyListOracle


DECLARATION = b'<?xml version="1.0" encoding="UTF-8"?>'
APPLE_DOCTYPE = b'<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">'
BOM = b'\xef\xbb\xbf'


def document(contents, prefix=b''):
    return prefix + b'<plist version="1.0"><dict>' + contents + b'</dict></plist>'


def entry(tag, text):
    tag = tag.encode()
    return b'<key>item</key><' + tag + b'>' + text + b'</' + tag + b'>'


def typed_documents():
    return {
        'string': [
            b'', b'  white\n space    around \t ', b'<tag>child</tag>after',
            b'pre <tag>child</tag> after', b'<!--comment-->next',
            b'&lt; &gt; &amp; &quot; &apos; &#65; &#x1F3B9;',
            b'&no; &nbsp; & test', b'&amp;no; &amp;&no;',
            b'&#32; &#x9; &#10; \t x', b'caf\xc3\xa9 \xf0\x9f\x8e\xb9',
            b'a\r\nb\nc\rd', b'<![CDATA[  a&b\nz  ]]>', b'<![CDATA[x>y]]>',
            b'abc &#x0; def', b'\xe9', b'&#xD800;', b'&#x110000;', b'&#bad;',
            b'&#x;', b'&#X41;', b'<dict/>', b'\xed\xa0\x80', b'&#xE9;',
        ],
        'integer': [
            b'', b'+42', b'-2147483648', b'2147483647', b'2147483648', b'-2147483647',
            b'9223372036854775807', b'-9223372036854775808', b'123junk', b'0x20', b'no',
        ],
        'real': [
            b'', b'0', b'1.0', b'+1.25', b'-0', b'-.5', b'1.25e+2', b'9E-2',
            b'9.99e 2', b'9.99e -2', b'1e+', b'-2..7', b'naN',
            b'1e9999999999999', b'1e-9999999999999', b'&#32; 1.5',
        ],
        'date': [
            b'', b'10.03.2008 13:20:45', b'2026-03-01T20:00:05Z',
            b'1.2.3 4:5:6 extra', b' 7. 8.9 1:2:3', b'7', b'01.01.2001 00:00:00',
        ],
        'data': [
            b'', b'YQ==', b'YWI=', b'YWJj', b'AA==', b'AAA=', b'AAAA', b'A', b'YQ',
            b'SGVs bG8=', b'SGVs\n bG8=', b'YWJj&#10;ZGVm', b'YWJj&#9;ZGVm',
            b'YWJj&#13;ZGVm', b'!.', b'//8=', b'<![CDATA[ A A ]]>',
        ],
        'true': [b'', b'text', b'<nested/>'],
        'false': [b'', b'text', b'<nested/>'],
        'array': [
            b'', b'<real>1.5</real><dict/><data>AA==</data>',
            b'mixed <false/> and <true/>', b'<string>first</string><unknown/>',
        ],
        'dict': [
            b'', b'<key>a</key><string>1</string><key>a</key><integer>2</integer>',
            b'<key/> <string>empty key</string>', b'<key><!--comment-->later</key><integer>2</integer>',
            b'<key>a</key>', b'<unknown>a</unknown><true/>', b'<key>z</key><!--comment--><true/>',
        ],
    }


def xml_fixtures():
    for tag, values in typed_documents().items():
        for index, text in enumerate(values):
            for prefix_name, prefix in [('nodecl', b''), ('utf8', DECLARATION + APPLE_DOCTYPE)]:
                yield f'xml-value-{tag}-{index}-{prefix_name}', document(entry(tag, text), prefix), True, True
    structures = {
        'roots': b'<other/><plist><dict/></plist><tail/>',
        'comment': b'<!--comment--><plist><!--comment--><dict/></plist>',
        'whitespace-before-bom': b' \t' + BOM + b'<plist><dict/></plist>',
        'text-in-plist': b'<plist>text<dict/></plist>',
        'first-child-is-array': b'<plist><array/><dict/></plist>',
        'dict-with-text': b'<plist><dict>text</dict></plist>',
        'nul-truncation': b'<plist><dict/></plist>\0unparsed',
        'tag-mismatch': b'<plist><dict></plist>',
        'unknown-root': b'<none/>',
        'empty-plist': b'<plist/>',
        'partial-document': b'<plist><dict/></plist><tail>',
        'dom-unknown': b'<!arbitrary><plist><dict/></plist>',
        'metadata': document(
            b'<key>color</key><string>blue</string>'
            b'<key>identifier</key><string>com.synthetic.bank</string>'
            b'<key>title</key><string>Sample Bank</string>'
            b'<key>gracePeriode</key><real>3.125e1</real>',
            DECLARATION + APPLE_DOCTYPE,
        ),
        'processing-instruction': b'<?x test?><plist><dict/></plist>',
        'first-plist-selected': b'<plist/><plist><dict/></plist>',
        'bom-utf8-references': document(entry('string', b'&#xE9; &#x1F3B9;'), BOM),
        'unsupported-plist-case': b'<PLIST><dict/></PLIST>',
        'utf16-not-xml': b'\xff\xfe' + '<plist><dict/></plist>'.encode('utf-16-le'),
    }
    for (name, raw), reader in itertools.product(structures.items(), (False, True)):
        yield f'xml-structure-{name}', raw, reader, True
    rng = random.Random(0xE1A015)
    for index in range(160):
        items = []
        for j in range(rng.randrange(1, 9)):
            if rng.randint(0, 1):
                value = f'{rng.randint(-999_999_999_999, 999_999_999_999)}'.encode()
                tag = b'integer'
            else:
                value = f'{rng.randint(-123, 124)}.{rng.randint(0, 99)}e{rng.randint(-45, 45):+d}'.encode()
                tag = b'real'
            items += [f'<key>value{j}</key>'.encode(), b'<' + tag + b'>' + value + b'</' + tag + b'>']
        yield f'xml-number-sequence-{index}', document(b''.join(items), DECLARATION), bool(index & 1), True


def xml_archive_fixtures():
    valid = document(
        b'<key>title</key><string>Bank &#xE9;</string><key>gracePeriode</key><real>1.25e2</real>',
        DECLARATION + APPLE_DOCTYPE,
    )
    for layout, flags, (name, payload) in itertools.product(
        (0, 1), range(4), [('valid', valid), ('invalid', b'<plist><dict></plist>')]
    ):
        yield f'xml-{name}-layout{layout}', archive([('Info.plist', payload, {})], layout=layout), '/Info.plist', flags
    nested = archive([
        ('samples', b'', {'length': 0x8000000000000001}),
        ('Info.plist', valid, {'parent': 1}),
    ])
    yield 'xml-nested', nested, '/samples/Info.plist', 0
    yield 'xml-nested', nested, '/Info.plist', 0


def compare(binary, runner, prefix, platform, builtin):
    oracle = XmlPropertyListOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []

    def check(name, group, expected, fixture, unchanged=False, **extra):
        actual = probe.run(fixture, len(expected))
        if actual.returncode or actual.stdout != expected:
            raise ValueError(f'{name}: expected={expected.hex()} found={actual.stdout.hex()} '
                             f'fixture={fixture[:240]!r} stderr={actual.stderr!r}')
        cases.append({'name': name, 'group': group, 'bytes': len(expected),
                      'sha256': hashlib.sha256(expected).hexdigest(),
                      'matches_prior_contract': unchanged, **extra})

    for group, examples in (('ela014-direct', fixtures()), ('xml-direct', xml_fixtures())):
        for name, raw, reader, parse in examples:
            name += '-path-reader' if reader else '-no-reader'
            expected = oracle.run(raw, reader, parse)
            unchanged = group == 'ela014-direct' and (not parse or expected[0] != 0)
            fixture = struct.pack('<III', len(raw), reader, parse) + raw
            check(name, group, expected, fixture, unchanged=unchanged)

    legacy = ArchiveOpenOracle(binary)
    for group, examples in (
        ('ela014-archive', archive_fixtures(builtin)), ('xml-archive', xml_archive_fixtures())
    ):
        for name, raw, path, flags in examples:
            name = f'archive-{name}-{path}-clone{flags & 1}-shared{flags >> 1}'
            expected, member_sha = archive_expected(legacy, oracle, raw, path, flags)
            units = path.encode('utf-16-le')
            fixture = struct.pack('<III', len(raw), flags, 2) + raw + struct.pack('<I', len(units) // 2) + units
            unchanged = group == 'ela014-archive' and '-xml-route-' not in name
            check(name, group, expected, fixture, unchanged=unchanged, original_member_sha256=member_sha)
    probe.close()

    trailing = b'<plist><dict/></plist>text after the document'
    fixture = struct.pack('<III', len(trailing), 1, 1) + trailing
    strict = subprocess.run(prefix + [str(runner.resolve())], input=fixture, capture_output=True, check=True)
    assert oracle.run(trailing, True)[:2] == b'\0\x02'
    assert strict.stdout == b'\0\x01'
    padding = XmlPropertyListOracle(binary, base64_padding=0xA5)
    minimal = document(entry('data', b'YQ=='))
    assert oracle.run(minimal, True).endswith(b'a\0\0\0')
    assert padding.run(minimal, True).endswith(b'a\0\xa5\xa5')

    return {
        'checkpoint': 'ELA015',
        'original_i386_sha256': SHA,
        'compiled_platform': platform,
        'fixture_count': len(cases),
        'compared_bytes': sum(result['bytes'] for result in cases),
        'groups': {group: sum(result['group'] == group for result in cases)
                   for group in ('ela014-direct', 'xml-direct', 'ela014-archive', 'xml-archive')},
        'original_xml_dom_and_gn_value_dispatch_executed': True,
        'gn_object_storage_ownership_and_libc_are_bindings': True,
        'date_compared_at_gregorian_constructor_boundary': True,
        'xml_base64_original_unwritten_padding_uses_per_fixture_fill': True,
        'xml_trailing_text_original_accepts_native_rejects': True,
        'all_cases_match_bit_for_bit': True,
        'actual_macos_execution': False,
        'cases': cases,
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
    print(json.dumps({key: report[key] for key in ('fixture_count', 'compared_bytes', 'groups', 'compiled_platform')}))
