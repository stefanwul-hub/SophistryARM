#!/usr/bin/env python3
"""Compare original i386 and standalone C++ sample loading, without licence.

Fixtures contain only the already supplied public sample; no private snapshots
are accepted. Full object/heap/global/program bytes are checked, not just sound.
"""
import argparse
import hashlib
import json
import struct
import subprocess
from pathlib import Path
from probe_au_render import RenderHost, Original, ROOT, LegacyImage


def original(case, output):
    image = LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
    backend = Original(bytes(image.mapped()), 0x4000000)
    h = RenderHost(backend, image)
    h.asset_directories = [case]
    outer, obj = 0x200000-0xec, 0x200000
    def call(pc, *args):
        backend.run(pc,list(args))
        return h.eax()
    try:
        for pc in image.initializers:
            call(pc)
        call(0x48b0,outer,0x70001000)
        for offset,value in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:
            h.put(outer+offset,value)
        call(0xa6a2a,outer)
        call(0x2918,outer)
        for offset,token in [(0xcc,0x70000200),(0xd0,0x70000210),(0xd4,0x70000220)]:
            h.put(outer+offset,token)
        chunk = (case/'program.FXP').read_bytes()[60:]
        backend.write(0x600000,chunk)
        if call(h.word(obj+0x24),obj+0x20,24,1,len(chunk),0x600000,0) != len(chunk):
            raise ValueError('Original loader did not accept the complete fixture')
        backend.write(0x5f0100,bytes(256))
        call(h.word(obj+0x24),obj+0x20,5,0,0,0x5f0100,0)
        h.put(0x5f0000,0)
        n = call(h.word(obj+0x24),obj+0x20,23,1,0,0x5f0000,0)
        regions = {'chunk':backend.read(h.word(0x5f0000),n),
                   'object':backend.read(obj,0x340000),
                   'heap':backend.read(0x800000,h.heap-0x800000),
                   'globals':backend.read(0xe2000,0x22000)}
        for key,data in regions.items():
            output.with_suffix('.'+key).write_bytes(data)
        return h.conversion_records
    finally:
        backend.close()


def run(fixtures, engine, output, selected=None):
    output.mkdir(parents=True,exist_ok=True)
    cases = json.loads((fixtures/'manifest.json').read_text())['cases']
    reports = []
    for case in cases:
        name = case['case']
        if selected and name not in selected:
            continue
        folder = fixtures/name
        original_prefix = output/(name+'-original')
        conversions = original(folder,original_prefix)
        native_prefix = output/(name+'-native')
        result = subprocess.run([str(engine),'--state',str(folder/'program.FXP'),
                                 '--asset-directory',str(folder),'--au-channels','2',
                                 '--snapshots','--output-prefix',str(native_prefix)],
                                stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        (output/(name+'-native.log')).write_text(result.stdout+result.stderr)
        if result.returncode:
            raise ValueError('Standalone sample loader failed for '+name)
        regions = []
        for region in ['chunk','object','heap','globals']:
            a = original_prefix.with_suffix('.'+region).read_bytes()
            b = native_prefix.with_suffix('.'+region).read_bytes()
            if a != b:
                first = next((i for i,(x,y) in enumerate(zip(a,b)) if x!=y),min(len(a),len(b)))
                raise ValueError(f'{name}: {region} differs at {first}, sizes {len(a)}/{len(b)}')
            regions.append({'region':region,'bytes':len(a),'sha256':hashlib.sha256(a).hexdigest()})
        reports.append({'case':name,'all_regions_byte_exact':True,
                        'original_conversion_calls':len(conversions),'regions':regions})
        # Keep hashes/logs as checkpoints; these public snapshots are
        # reproducible and need not occupy hundreds of MB per test matrix.
        for prefix in (original_prefix,native_prefix):
            for region in ['chunk','object','heap','globals']:
                prefix.with_suffix('.'+region).unlink()
        print(name+': original and standalone regions byte-exact',flush=True)
    report = {'scope':'public synthetic sample formats; original i386 vs standalone translated host; no licence or private inputs',
              'passed':bool(reports),'cases':reports,'compared_regions':len(reports)*4,
              'native_apple_converter_test':'separate Mac primitive oracle, not executed here'}
    (output/'comparison.json').write_text(json.dumps(report,indent=2)+'\n')
    return report


if __name__ == '__main__':
    p = argparse.ArgumentParser()
    p.add_argument('--fixtures',type=Path,required=True)
    p.add_argument('--engine',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--case',action='append')
    a = p.parse_args()
    run(a.fixtures,a.engine,a.output,a.case)
