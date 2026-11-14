#!/usr/bin/env python3
"""Run ORIGINAL i386 instructions in Unicorn and compare isolated C++ kernel.
Buffer acquisition is replaced by synthetic host callbacks; DSP instructions are
unmodified. This is not a whole-plugin or DAW audio test. Requires pinned original.
"""
import argparse, ctypes, hashlib, json, math, random, struct, sys
from pathlib import Path
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_MXCSR

SHA='17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12'
pack=lambda x:struct.pack('<f',x)
unpack=lambda x:struct.unpack('<f',x)[0]
f32=lambda x:unpack(pack(x))

class Original:
    def __init__(self,image):
        if hashlib.sha256(image).hexdigest()!=SHA:raise ValueError('Wrong original')
        self.uc=uc=Uc(UC_ARCH_X86, UC_MODE_32)
        uc.mem_map(0,0x300000);uc.mem_write(0,image)
        uc.mem_map(0x500000,0x1000);uc.mem_write(0x500000,b'\xc3'*0x1000)
        uc.mem_map(0x700000,0x10000)
        self.obj=0x200000; self.iobj=0x202000; self.oobj=0x204000
        self.put(0x200000,0x201000); self.put(0x200010,self.iobj)
        self.put(0x200118,self.oobj);self.put(0x200124,1)
        self.put(self.iobj,0x203000); self.put(self.oobj,0x205000)
        self.put(0x203034,0x500010); self.put(0x205028,0x500000)
        self.put(0x203038,0x500040); self.put(0x20502c,0x500030)
        self.put(0x205040,0x500020);self.put(0x205044,0x500020)
        self.put(0x2010cc,0xc14e4) # execute original additive store callback, too
        uc.hook_add(UC_HOOK_CODE,self.callback,begin=0x500000,end=0x500050)
    def put(self,p,v):self.uc.mem_write(p,struct.pack('<I',v))
    def get(self,p):return struct.unpack('<I',self.uc.mem_read(p,4))[0]
    def callback(self,uc,addr,size,user):
        sp=uc.reg_read(UC_X86_REG_ESP)
        if addr in (0x500000,0x500010,0x500030,0x500040):
            destination=self.get(sp+8)
            self.put(destination,self.out[0] if addr in (0x500000,0x500030) else self.inp[0])
            if addr in (0x500030,0x500040):
                self.put(self.get(sp+12),self.out[1] if addr==0x500030 else self.inp[1])
    def run(self,inputs,outputs,a,b,in_place,active=True):
        uc=self.uc; channels=len(inputs); n=len(inputs[0]);assert n<=4096
        self.inp=[0x210000,0x220000];self.out=self.inp if in_place else [0x230000,0x240000]
        for c in range(channels):
            uc.mem_write(self.inp[c],b''.join(pack(x) for x in inputs[c]))
            if not in_place:uc.mem_write(self.out[c],b''.join(pack(x) for x in outputs[c]))
        uc.mem_write(self.iobj+0x26,bytes([int(channels==1),int(channels==2)]))
        self.put(self.obj+0x124,int(active))
        uc.mem_write(self.obj+0x1e0,pack(a)+pack(b))
        sp=0x70f000
        uc.mem_write(sp,struct.pack('<III',0x500100,self.obj,n))
        uc.reg_write(UC_X86_REG_ESP,sp);uc.reg_write(UC_X86_REG_MXCSR,0x1f80)
        uc.emu_start(0x73fb0,0x500100,count=2_000_000)
        return [bytes(uc.mem_read(self.out[c],n*4)) for c in range(channels)]

def compare(image,library,fixture_path=None):
    lib=ctypes.CDLL(str(library.resolve()))
    fun=lib.sophistry_satur_process
    fp=ctypes.POINTER(ctypes.c_float)
    fun.argtypes=[fp,fp,fp,fp,ctypes.c_uint,ctypes.c_float,ctypes.c_float,ctypes.c_uint,ctypes.c_bool]
    fun.restype=None
    em=Original(image);rng=random.Random(308)
    edge=[0.,-0.,1.,-1.,1e-20,-1e-20,1e-38,-1e-38,1e-45,-1e-45,1e20,-1e20]
    cases=0;samples=0;mismatches=[];max_diff=0.;fixtures=[]
    for channels in [1,2]:
      for ip in [True,False]:
       for n in [0,1,7,8,17,64,257,4096]:
        for a in [0.,0.1,0.5,0.9,1.]:
         # Coefficient calculation is deliberately outside this test's scope.
         a=f32(a);b=f32(1.001-float(a))
         ins=[[f32(edge[(i+c+2)%len(edge)] if i<len(edge) else rng.uniform(-4,4)) for i in range(n)] for c in range(channels)]
         outs=[[f32(rng.uniform(-0.25,0.25)) for i in range(n)] for c in range(channels)]
         orig=em.run(ins,outs,a,b,ip)
         record=struct.pack('<IIIIff',n,channels,int(ip),1,a,b)
         for c in range(channels):record+=b''.join(pack(v) for v in ins[c])+b''.join(pack(v) for v in outs[c])+orig[c]
         fixtures.append(record)
         array=ctypes.c_float*n
         sources=[array(*v) for v in ins]
         dests=sources if ip else [array(*v) for v in outs]
         fun(sources[0],sources[1] if channels==2 else None,dests[0],dests[1] if channels==2 else None,n,a,b,channels,True)
         for c in range(channels):
          actual=bytes(dests[c]);expected=orig[c]
          if actual!=expected:
           for i in range(n):
            x=expected[i*4:i*4+4];y=actual[i*4:i*4+4]
            if x!=y:
             delta=abs(unpack(x)-unpack(y));max_diff=max(max_diff,delta)
             if len(mismatches)<20:mismatches.append({'channels':channels,'in_place':ip,'n':n,'a':a,'index':i,'expected_hex':x.hex(),'actual_hex':y.hex()})
          samples+=n
         cases+=1
    # Disabled kernel must not touch destination buffers.
    disabled=em.run([[0.2,-0.5]],[[0.7,-0.1]],0.5,0.501,False,False)
    array=ctypes.c_float*2
    ds=array(0.2,-0.5);dd=array(0.7,-0.1)
    fun(ds,None,dd,None,2,0.5,0.501,1,False)
    disabled_pass=disabled==[pack(0.7)+pack(-0.1)] and bytes(dd)==disabled[0]
    fixtures.append(struct.pack('<IIIIff',2,1,0,0,0.5,0.501)+pack(.2)+pack(-.5)+pack(.7)+pack(-.1)+disabled[0])
    if fixture_path:fixture_path.write_bytes(b'SPRB0001'+struct.pack('<I',len(fixtures))+b''.join(fixtures))
    return {'scope':'Isolated Satur_c process 0x73fb0, synthetic buffer callbacks; NOT full synth','original_i386_sha256':SHA,'test_cases':cases,'compared_samples':samples,'bit_exact':not mismatches,'max_abs_error':max_diff,'mismatches':mismatches,'disabled_path_unchanged':disabled_pass,'test_backend':'Unicorn 2.1.4 x86-32 SSE, MXCSR=0x1f80, finite inputs, five coefficient pairs','excluded':['full synth','coefficient generation','AU host','state restoration','DAW projects','real Intel hardware comparison','ARM64 execution','NaN/Inf','alternate rounding modes and FTZ/DAZ']}

if __name__=='__main__':
    a=argparse.ArgumentParser();a.add_argument('image',type=Path);a.add_argument('library',type=Path);a.add_argument('--report',type=Path);a.add_argument('--fixtures',type=Path);args=a.parse_args()
    r=compare(args.image.read_bytes(),args.library,args.fixtures);s=json.dumps(r,indent=2);print(s)
    if args.report:args.report.write_text(s+'\n')
    sys.exit(0 if r['bit_exact'] and r['disabled_path_unchanged'] else 1)
