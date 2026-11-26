#!/usr/bin/env python3
"""Require real ARM64 compile/link evidence for every shipping engine/AU probe.

The probe names come from the actual build scripts, rather than a second
hand-maintained subset. This checks coverage; macOS execution remains separate.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

ROOT=Path(__file__).resolve().parents[2]


def shipping_probes(root=ROOT):
    result=set()
    for name in ['scripts/build-cronox-engine.sh','scripts/build-cronox-audio-unit.sh']:
        text=(root/name).read_text()
        result.update(re.findall(r'\$ROOT/tests/([A-Za-z0-9_]+)\.(?:cpp|mm)',text))
        for group in re.findall(r'for probe in ([^;\n]+); do',text):
            names=group.split()
            if not names or any(not re.fullmatch(r'[A-Za-z0-9_]+',x) for x in names):
                raise ValueError('Unsupported probe loop: '+name)
            result.update(names)
    return result


def verify(record,root=ROOT):
    required=shipping_probes(root)
    binaries={b['binary'].removesuffix('-macos'):b for b in record['binaries']}
    missing=required-binaries.keys()
    if missing:
        raise ValueError('Missing shipping probe compile/link: '+', '.join(sorted(missing)))
    for name in required:
        b=binaries[name]
        if not (b.get('arm64_mach_o') and b.get('strict_link_passed') and b.get('newly_compiled')):
            raise ValueError('Incomplete real compiler/link evidence: '+name)
        source=root/b['source']
        if source.stem!=name or hashlib.sha256(source.read_bytes()).hexdigest()!=b['source_sha256']:
            raise ValueError('Source mismatch: '+name)
    return {'passed':True,'shipping_probe_count':len(required),
            'all_shipping_probes_newly_compiled_and_strictly_linked_arm64':True,
            'required_probes':sorted(required),'macos_execution_is_separate':True}


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('record',type=Path)
    args=p.parse_args()
    print(json.dumps(verify(json.loads(args.record.read_text())),indent=2))
