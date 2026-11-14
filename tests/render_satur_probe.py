#!/usr/bin/env python3
"""An audible regression fixture of ONLY the isolated saturation kernel."""
import argparse,ctypes,json,math,random,struct
from pathlib import Path
from compare_satur_original import Original,f32,pack

def wav(path,channels,rate):
    data=b''.join(pack(x) for pair in zip(*channels) for x in pair)
    ch=len(channels); fmt=struct.pack('<HHIIHH',3,ch,rate,rate*ch*4,ch*4,32)
    fact=struct.pack('<I',len(channels[0]))
    body=b'WAVE'+b'fmt '+struct.pack('<I',len(fmt))+fmt+b'fact'+struct.pack('<I',4)+fact+b'data'+struct.pack('<I',len(data))+data
    path.write_bytes(b'RIFF'+struct.pack('<I',len(body))+body)

def run(image,library,out):
    out.mkdir(parents=True,exist_ok=True); sr=48000;n=sr
    rng=random.Random(308);phase=0.;x=[[],[]]
    for i in range(n):
        frequency=30.*(16000./30.)**(i/(n-1));phase+=2*math.pi*frequency/sr
        x[0].append(f32(math.sin(phase)*1.4))
        x[1].append(f32((0.8 if i%4000==0 else 0.)+rng.uniform(-.05,.05)))
    em=Original(image.read_bytes());lib=ctypes.CDLL(str(library.resolve()));fun=lib.sophistry_satur_process
    fp=ctypes.POINTER(ctypes.c_float);fun.argtypes=[fp,fp,fp,fp,ctypes.c_uint,ctypes.c_float,ctypes.c_float,ctypes.c_uint,ctypes.c_bool];fun.restype=None
    original=[[],[]];translated=[[],[]]
    for start in range(0,n,512):
        vals=[c[start:start+512] for c in x];num=len(vals[0]);a=f32(.9);b=f32(1.001-a)
        ref=em.run(vals,vals,a,b,True)
        arr=ctypes.c_float*num;left=arr(*vals[0]);right=arr(*vals[1]);fun(left,right,left,right,num,a,b,2,True)
        for c,v in enumerate([left,right]):
            original[c].extend(struct.unpack('<'+'f'*num,ref[c]));translated[c].extend(v)
    wav(out/'satur-original-instructions.wav',original,sr);wav(out/'satur-cpp.wav',translated,sr)
    print('Wrote two one-second stereo WAVs, saturation only, no synthesizer or AU.')

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('image',type=Path);p.add_argument('library',type=Path);p.add_argument('output',type=Path);n=p.parse_args();run(n.image,n.library,n.output)
