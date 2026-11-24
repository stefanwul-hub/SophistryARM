#!/usr/bin/env python3
"""Freeze original CronoX SQRTSD/SQRTSS results, including XMM upper lanes."""
from pathlib import Path
import gzip,hashlib,json,random,struct,sys
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
import unicorn.x86_const as x86

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from legacy_image import LegacyImage,SHA
image=LegacyImage((ROOT/'reference/CronoX3.i386').read_bytes())
original=bytes(image.mapped());u=Uc(UC_ARCH_X86,UC_MODE_32)
u.mem_map(0,0x200000);u.mem_write(0,original);u.reg_write(x86.UC_X86_REG_MXCSR,0x1f80)
sites=[]
with gzip.open(ROOT/'analysis/cronox/pcode/instructions.jsonl.gz','rt') as f:
    for line in f:
        row=json.loads(line)
        if any(op['op']=='FLOAT_SQRT' for op in row['pcode']):sites.append(row)
fixtures=[];raw_results=[];descriptions=[]
for number,row in enumerate(sites):
    parts=row['asm'].replace(',',' ').split();dst,src=map(lambda v:int(v.replace('XMM','')),parts[1:])
    width=8 if parts[0]=='SQRTSD' else 4;bits=width*8
    values=([0,1,0x8000000000000000,0x8000000000000001,0x000fffffffffffff,0x0010000000000000,
             0x3ff0000000000000,0x4000000000000000,0x7fefffffffffffff,0x7ff0000000000000,
             0xfff0000000000000,0x7ff8000000000001,0xfff8000000001234,0x7ff0000000000001]
            if width==8 else [0,1,0x80000000,0x80000001,0x007fffff,0x00800000,0x3f800000,
                              0x40000000,0x7f7fffff,0x7f800000,0xff800000,0x7fc00001,0xffc01234,0x7f800001])
    rng=random.Random(36600+number);values += [rng.getrandbits(bits) for _ in range(1024)]
    entry=int(row['address'],16);stop=entry+row['length']
    for value in values:
        source=value|(rng.getrandbits(128-bits)<<bits);destination=rng.getrandbits(128)
        registers={dst:destination,src:source}
        for reg,data in registers.items():u.reg_write(getattr(x86,'UC_X86_REG_XMM'+str(reg)),data)
        u.emu_start(entry,stop,count=1)
        expected=u.reg_read(getattr(x86,'UC_X86_REG_XMM'+str(dst))).to_bytes(16,'little')
        packet=struct.pack('<6I',entry,stop,0,len(registers),0,1)
        for reg,data in registers.items():packet+=struct.pack('<II',0x1200+reg*0x40,16)+data.to_bytes(16,'little')
        packet+=struct.pack('<III',0,0x1200+dst*0x40,16)+expected
        fixtures.append(packet)
        if width==8:raw_results.append(struct.pack('<QQ',value,int.from_bytes(expected[:8],'little')))
    descriptions.append({'address':hex(entry),'asm':row['asm'],'width_bits':bits,'cases':len(values)})
path=ROOT/'evidence/cronox-sqrt-instructions.fixtures'
path.write_bytes(b'SLIP0002'+struct.pack('<I',len(fixtures))+b''.join(fixtures))
(ROOT/'work/cronox-sqrt64-pairs.bin').write_bytes(b''.join(raw_results))
report={'project':'CronoX 3 ARM64','original_sha256':SHA,'reference':'Original i386 SQRT machine instructions executed by Unicorn, default MXCSR nearest-even','sites':descriptions,'cases':len(fixtures),'fixtures_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'native_or_arm64_replay_executed':False}
(ROOT/'evidence/cronox-sqrt-reference.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,indent=2))
