#!/usr/bin/env python3
"""Compare equal-length WAV renders without alignment, normalization or resampling."""
import argparse,array,json,math,struct,sys
from pathlib import Path

def read_wav(path):
    raw=Path(path).read_bytes()
    if raw[:4]!=b'RIFF' or raw[8:12]!=b'WAVE':raise ValueError('Expected little-endian RIFF/WAVE')
    pos=12;fmt=None;pcm=[]
    while pos+8<=len(raw):
        tag,size=struct.unpack_from('<4sI',raw,pos);pos+=8
        if pos+size>len(raw):raise ValueError('Truncated WAV')
        data=raw[pos:pos+size]
        if tag==b'fmt ':fmt=data
        if tag==b'data':pcm.append(data)
        pos+=size+(size&1)
    if fmt is None or not pcm:raise ValueError('Missing fmt/data')
    form,ch,sr,rate,align,bits=struct.unpack_from('<HHIIHH',fmt)
    if form==0xfffe and len(fmt)>=40:form=struct.unpack_from('<H',fmt,24)[0]
    if form not in [1,3] or bits not in ([8,16,24,32] if form==1 else [32,64]):raise ValueError('Unsupported WAV encoding')
    data=b''.join(pcm);width=bits//8
    if align!=width*ch or len(data)%align:raise ValueError('Invalid block alignment')
    if form==3:
        x=list(struct.unpack('<'+('f' if bits==32 else 'd')*(len(data)//width),data))
    elif bits==8:x=[(v-128)/128 for v in data]
    else:x=[int.from_bytes(data[i:i+width],'little',signed=True)/(2**(bits-1)) for i in range(0,len(data),width)]
    if not all(math.isfinite(v) for v in x):raise ValueError('Nonfinite samples')
    return (sr,ch,len(data)//align),x

def compare(a,b,max_abs):
    ma,x=read_wav(a);mb,y=read_wav(b)
    if ma!=mb:raise ValueError('Sample rate, channels or frame count differ: '+str((ma,mb)))
    if not x:raise ValueError('Empty render')
    maximum=max(abs(v-w) for v,w in zip(x,y)); mse=math.fsum((v-w)**2 for v,w in zip(x,y))/len(x)
    power=math.fsum(v*v for v in x)/len(x);peak=max(abs(v) for v in x)
    return {'format':{'sample_rate':ma[0],'channels':ma[1],'frames':ma[2]},'reference_peak':peak,'reference_rms':math.sqrt(power),'max_abs_error':maximum,'rmse':math.sqrt(mse),'snr_db':None if mse==0 or power==0 else 10*math.log10(power/mse),'bit_equal_sample_values':x==y,'non_silent_reference':peak>1e-8,'tolerance':max_abs,'passed':maximum<=max_abs and peak>1e-8,'alignment_shift':0,'normalization_applied':False}

if __name__=='__main__':
    a=argparse.ArgumentParser();a.add_argument('reference');a.add_argument('candidate');a.add_argument('--max-abs',type=float,default=0.);a.add_argument('--report',type=Path);n=a.parse_args()
    if not math.isfinite(n.max_abs) or n.max_abs<0:raise ValueError('Invalid tolerance')
    r=compare(n.reference,n.candidate,n.max_abs);s=json.dumps(r,indent=2);print(s)
    if n.report:n.report.write_text(s+'\n')
    sys.exit(0 if r['passed'] else 1)
