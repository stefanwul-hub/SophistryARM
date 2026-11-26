#!/usr/bin/env python3
"""Compare native reverb with original i386 instructions and full static lift.

Only artificial effect states; no synth, registration state, or licence bypass.
All mutable bytes, delay lines, output buffers and buffer flags are compared.
"""
import argparse
import ctypes
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import time

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tests'))
from compare_lifted_dsp import Native,Original
from legacy_image import LegacyImage
from unicorn.x86_const import UC_X86_REG_MXCSR

BASE,SIZE,OBJ=0x300000,0x20000,0x300000


class EngineNative(Native):
    def __init__(self,lib,native):
        super().__init__(lib,b'',0x4000000)
        lib.sl_destroy(self.c)
        lib.cr_reverb_create.argtypes=[ctypes.c_int];lib.cr_reverb_create.restype=ctypes.c_void_p
        lib.cr_reverb_cpu.argtypes=[ctypes.c_void_p];lib.cr_reverb_cpu.restype=ctypes.c_void_p
        lib.cr_reverb_destroy.argtypes=[ctypes.c_void_p]
        lib.cr_reverb_error.restype=ctypes.c_char_p
        lib.cr_reverb_case.argtypes=[ctypes.c_void_p,ctypes.c_uint]
        lib.cr_reverb_run.argtypes=[ctypes.c_void_p]+[ctypes.c_uint]*3+[ctypes.c_int]
        for key in ['blocks','fallbacks']:
            f=getattr(lib,'cr_reverb_'+key);f.argtypes=[ctypes.c_void_p];f.restype=ctypes.c_uint64
        self.context=lib.cr_reverb_create(native)
        if not self.context:raise RuntimeError(lib.cr_reverb_error().decode())
        self.c=lib.cr_reverb_cpu(self.context)
    def prepare(self,number):
        if self.l.cr_reverb_case(self.context,number):raise RuntimeError(self.l.cr_reverb_error().decode())
    def run_case(self,entry,frames,flush):
        if self.l.cr_reverb_run(self.context,entry,OBJ,frames,flush):raise RuntimeError(self.l.cr_reverb_error().decode())
    def close(self):
        if self.c:self.l.cr_reverb_destroy(self.context);self.c=None


def fnv(data):
    result=14695981039346656037
    for byte in data:result=((result^byte)*1099511628211)&0xffffffffffffffff
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--library',type=Path,default=ROOT/'work/native-reverb/libreverb-tests.so')
    p.add_argument('--output',type=Path,default=ROOT/'work/native-reverb')
    p.add_argument('--cases',type=int,default=160)
    p.add_argument('--hardware-oracle',type=Path,default=ROOT/'work/native-reverb/i386-effect-oracle')
    a=p.parse_args();a.output.mkdir(parents=True,exist_ok=True)
    raw=(ROOT/'reference/CronoX3.i386').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='fe5f50d2213cfdd072c98cd4083d92bf24d9dc5ea8115b25a64cc8df08ed9969'
    image=LegacyImage(raw);lib=ctypes.CDLL(str(a.library.resolve()))
    original=Original(bytes(image.mapped()),0x4000000)
    static=EngineNative(lib,False);direct=EngineNative(lib,True)
    def memcpy(pc):
        sp=original.esp();out,source,count=struct.unpack('<III',original.read(sp+4,12))
        original.write(out,original.read(source,count));original.ret()
    for s in image.stubs:
        if s['name']=='_memcpy':original.hook(s['address'],memcpy)
    compared=0;records=[];hashes=[];unicorn_denormal_disagreements=0;start=time.monotonic()
    for number in range(a.cases):
        static.prepare(number);direct.prepare(number)
        original.write(BASE,static.read(BASE,SIZE));original.write(0x11c078,struct.pack('<I',0x302800))
        mono=number%4==0;frames=(1,7,32,64,256)[number%5];flush=number%10>=5
        entry=0xd42d8 if number%5==4 else (0xd3d70 if mono else 0xd400e)
        original.uc.reg_write(UC_X86_REG_MXCSR,0x1f80|(0x8040 if flush else 0))
        hardware=subprocess.run([str(a.hardware_oracle)],input=struct.pack('<IIII',entry,frames,0x1f80|(0x8040 if flush else 0),3)+static.read(BASE,SIZE),stdout=subprocess.PIPE,check=True).stdout
        assert len(hardware)==3*SIZE
        last=[]
        for block in range(3):
            original.run(entry,[OBJ,frames]);static.run_case(entry,frames,flush);direct.run_case(entry,frames,flush)
            expected=hardware[block*SIZE:(block+1)*SIZE]
            if original.read(BASE,SIZE)!=expected:
                assert number>=120 and flush, 'Unexplained original emulator/hardware disagreement'
                unicorn_denormal_disagreements+=1
            for name,backend in [('static',static),('direct',direct)]:
                actual=backend.read(BASE,SIZE);compared+=SIZE
                if actual!=expected:
                    at=next(i for i,(x,y) in enumerate(zip(expected,actual)) if x!=y)
                    result={'passed':False,'case':number,'block':block,'backend':name,'address':hex(BASE+at),
                            'expected':expected[max(0,at-8):at+16].hex(),'actual':actual[max(0,at-8):at+16].hex(),
                            'native_blocks':lib.cr_reverb_blocks(direct.context),'fallbacks':lib.cr_reverb_fallbacks(direct.context)}
                    (a.output/'differential.json').write_text(json.dumps(result,indent=2)+'\n')
                    raise RuntimeError(json.dumps(result))
            assert original.esp()==direct.esp()==static.esp()==0x70f004
            last.append(f'{fnv(expected):016x}')
        hashes.append(last)
        records.append({'case':number,'entry':hex(entry),'frames':frames,'flush_denormals':flush,'block_hashes_fnv64':last})
        if number%20==19:print(f'{number+1}/{a.cases} original/static/direct cases passed',flush=True)
    assert lib.cr_reverb_blocks(direct.context)==3*a.cases, 'Some original calls did not enter native reverb'
    assert lib.cr_reverb_fallbacks(direct.context)==0
    result={'passed':True,'scope':'Effect-only artificial states, actual original i386 instructions on x86 hardware versus static lift and direct float32 C++; not whole-preset or AU validation',
            'cases':a.cases,'blocks_each':3,'compared_bytes':compared,'same_state_delays_and_outputs_bitwise':True,
            'native_blocks':lib.cr_reverb_blocks(direct.context),'fallbacks':lib.cr_reverb_fallbacks(direct.context),
            'elapsed_seconds':time.monotonic()-start,'original_i386_sha256':hashlib.sha256(raw).hexdigest(),
            'original_instruction_oracle':'ELF64 I/O shell, hardware compatibility-mode i386 effect instructions; only memcpy platform adapter',
            'unicorn_ftz_denormal_disagreements_not_used_as_reference':unicorn_denormal_disagreements,
            'mono_stereo_inplace_and_buffer_mix':True,'modulation_and_diffusors':True,'normal_and_denormal_arithmetic':True}
    (a.output/'differential.json').write_text(json.dumps(result,indent=2)+'\n')
    (a.output/'cases.json').write_text(json.dumps(records,indent=2)+'\n')
    if a.cases==160:
        header='// Expected complete-region hashes from original i386 instruction execution.\n#pragma once\n#include <cstdint>\nnamespace reverb_fixture {\nconstexpr std::uint64_t expected[160][3]={\n'
        header+=''.join('{'+','.join('0x'+h+'ull' for h in row)+'},\n' for row in hashes)+'};\n}\n'
        (a.output/'CronoXReverbExpected.h').write_text(header)
    print(json.dumps(result,indent=2))
    static.close();direct.close();original.close()


if __name__=='__main__':main()
