"""Deterministic WAVE/scanner fixtures, independent of the translated parser."""
from pathlib import Path
import hashlib
import random
import struct

WAVE_SHA='3a34c829da83d0b79773927fd2d026479a8038f4f7666c29a745aff2968b342f'
def chunk(tag,data,*,size=None,pad=True):
    n=len(data) if size is None else size
    return tag+struct.pack('<I',n)+data+(b'\0' if pad and len(data)&1 else b'')
def riff(parts,*,size=None):
    body=b'WAVE'+b''.join(parts)
    return b'RIFF'+struct.pack('<I',len(body) if size is None else size)+body
def fmt(tag=1,channels=2,bits=16,rate=44100,extra=b''):
    width=(bits+7)//8;align=channels*width
    return chunk(b'fmt ',struct.pack('<HHIIHH',tag,channels,rate,rate*align,align,bits)+extra)
def fixture(name,raw,*,mode=0,swap=0,open_ok=1,fail=-1,maximum=-1,initial=None,end=0,first=0,count=17,capacity=257,flags=0):
    return dict(name=name,raw=raw,h=[mode,len(raw),swap,open_ok,fail,maximum,*(initial or [0,0,0,0,0]),end,first,count,capacity,flags])
def scanner_fixtures():
    ids=[b'fmt ',b'bext',b'data',b'minf',b'regn',b'ovwf',b'elm1',b'umid',b'PAD ',b'inst',b'LIST',b'cue ',b'smpl',b'plst',b'wavl',b'LGWV',b'SyLp',b'acid',b'strc',b'anal',bytes.fromhex('b54cd02e'),b'abcd',b'list',b'JUNK']
    for swap in [0,1]:
        for tag in ids:
            for pad in [b'',b'\0']:
                raw=pad+tag+struct.pack('>I' if swap else '<I',12)+b'x'*12
                yield fixture(f'scanner-{tag.hex()}-pad{len(pad)}-swap{swap}',raw,mode=1,swap=swap,end=len(raw))
    for tag in [b'data',b'fmt ',b'zzzz']:
        for size in [0,1,12,1024,0x7fffffff,0xffffffff]:
            raw=tag+struct.pack('<I',size)+b'\0'*12
            yield fixture(f'scanner-size-{tag.decode()}-{size}',raw,mode=1,end=len(raw))
    for size in range(8):
        yield fixture(f'scanner-truncated-header-{size}',(b'data'+struct.pack('<I',12))[:size],mode=1,end=100)
    for index in [0,1]:
        yield fixture(f'scanner-injected-failure-{index}',b'\0data'+struct.pack('<I',12)+b'x'*12,mode=1,end=21,fail=index)

def fixtures(wave):
    rng=random.Random(0xe1a008)
    yield from scanner_fixtures()
    for tag in [-2,-1,0,1,2,3,17,65535]:
        for bits in [-1,0,8,16,24,32,64]:
            for channels in [-1,0,1,2,4,32767]:
                yield fixture(f'getters-format{tag}-bits{bits}-channels{channels}',b'',mode=2,initial=[tag,channels,bits,0,-17])
    for tag,bits in [(1,8),(1,16),(1,24),(1,32),(3,32)]:
        for channels in [1,2,4]:
            for frames in [0,1,17,257]:
                for extra in [b'',b'\x00\x00']:
                    width=(bits+7)//8
                    data=(b''.join(struct.pack('<f',rng.uniform(-0.95,0.95)) for _ in range(frames*channels)) if tag==3 else rng.randbytes(frames*channels*width))
                    raw=riff([fmt(tag,channels,bits,extra=extra),chunk(b'data',data)])
                    yield fixture(f'pcm-tag{tag}-bits{bits}-ch{channels}-frames{frames}-extra{len(extra)}',raw,mode=3,count=min(17,frames),capacity=max(257,channels*width))
    base=riff([fmt(),chunk(b'data',rng.randbytes(4*33))])
    for swap in [0,1]:yield fixture(f'open-forces-little-endian-initial{swap}',base,mode=3,swap=swap,count=17)
    yield fixture('open-failed',base,open_ok=0)
    yield fixture('preexisting-metadata',base,flags=1)
    for tag,bits in [(1,7),(1,12),(1,20),(1,40),(3,16),(3,64)]:
        yield fixture(f'header-width-accepted-but-format-unsupported-tag{tag}-bits{bits}',riff([fmt(tag,bits=bits),chunk(b'data',b'x'*132)]))
    for tag in [0,6,7,0xfffe,0x8000,0xffff]:yield fixture(f'unsupported-format-{tag}',riff([fmt(tag),chunk(b'data',b'x'*16)]))
    for tag,raw in [('not-riff',b'RIFX'+base[4:]),('not-wave',base[:8]+b'AIFF'+base[12:]),('missing-data',riff([fmt()])),('missing-fmt',riff([chunk(b'data',b'')]))]:
        yield fixture(tag,raw)
    for truncated in range(44):yield fixture(f'truncated-mandatory-header-{truncated}',base[:truncated])
    for size in [4,12,20,len(base)-8,len(base)+8,100000]:yield fixture(f'riff-declared-size-{size}',base[:4]+struct.pack('<I',size)+base[8:])
    for declared in [0,1,8,132,256,0x7fffffff]:
        yield fixture(f'data-declared-size-{declared}',riff([fmt(),chunk(b'data',b'x'*132,size=declared)]))
    yield fixture('data-before-fmt-with-valid-prior-metadata',riff([chunk(b'data',b'x'*132),fmt()]),initial=[1,2,16,2,0])
    for tag in [b'LGWV',b'JUNK',b'JNUK',b'PAD ',b'fact',b'plst',b'wavl',b'zzzz']:
        for n in [0,1,3,4,15]:
            for pad in [False,True]:
                raw=riff([fmt(),chunk(tag,b'z'*n,pad=pad),chunk(b'data',b'\0'*132)])
                yield fixture(f'private-ignore-{tag.decode()}-bytes{n}-pad{pad}',raw,flags=1)
    for channels in [1,2]:
        for coefficients in [7,8,255]:
            pairs=[(256,-128)]*coefficients
            payload=struct.pack('<HHIIHHHHH',2,channels,44100,22100,64,4,4+4*coefficients,32,coefficients)+b''.join(struct.pack('<hh',*p) for p in pairs)
            yield fixture(f'ms-adpcm-header-ch{channels}-coefficients{coefficients}',riff([chunk(b'fmt ',payload),chunk(b'data',b'\0'*128)]))
        for samples in [9,18,64]:
            payload=struct.pack('<HHIIHHHH',17,channels,44100,22100,64,4,2,samples)
            for flags in [0,8]:yield fixture(f'dvi-adpcm-header-ch{channels}-values{samples}-allocation-fail{bool(flags)}',riff([chunk(b'fmt ',payload),chunk(b'data',b'\0'*128)]),flags=flags)
    for channels,coefficients in [(0,7),(3,7),(1,6),(1,256)]:
        payload=struct.pack('<HHIIHHHHH',2,channels,44100,22100,64,4,4,32,coefficients)
        yield fixture(f'ms-adpcm-invalid-ch{channels}-coefficients{coefficients}',riff([chunk(b'fmt ',payload),chunk(b'data',b'\0'*128)]))
    metadata=[]
    for count in [0,1,3]:
        payload=struct.pack('<I',count)+b''.join(struct.pack('<II4sIII',i,17+i,b'data',0,0,101+i) for i in range(count))
        metadata.append((f'cue-count{count}',chunk(b'cue ',payload)))
    for loops in [0,1,3]:
        for data in [b'',b'samplerdata']:
            payload=struct.pack('<9I',1,2,22675,60,0x80000000,0,0,loops,len(data))+b''.join(struct.pack('<6I',i,1,17,91,0xffffffff,3) for i in range(loops))+data
            metadata.append((f'smpl-loops{loops}-data{len(data)}',chunk(b'smpl',payload)))
    for tag in [b'labl',b'note',b'ltxt']:
        for text in [b'',b'\0',b'A\0',b'Loop name\0']:
            payload=struct.pack('<I',7)+(struct.pack('<I',17)+b'\0'*12 if tag==b'ltxt' else b'')+text
            metadata.append((f'adtl-{tag.decode()}-text{text.hex()}',chunk(b'LIST',b'adtl'+chunk(tag,payload))))
    metadata += [('adtl-two-labels',chunk(b'LIST',b'adtl'+chunk(b'labl',struct.pack('<I',1)+b'First\0')+chunk(b'note',struct.pack('<I',2)+b'Second\0'))),('list-info-private',chunk(b'LIST',b'INFO'+chunk(b'INAM',b'Name\0'))),('lowercase-list-info',chunk(b'list',b'INFOabcdef'))]
    for count in [0,1,2]:
        for name in [b'',b'Sample loop',b'x'*40]:
            payload=struct.pack('<I',count)
            for i in range(count):payload+=b'u'*16+struct.pack('<5Q',17,91,19,0xffffffffffffffff,0x100000000)+bytes([len(name)])+name+b'\0'*max(0,31-len(name))
            metadata.append((f'regions-count{count}-name{len(name)}',chunk(b'regn',payload)))
    for history in [b'',b'A=PCM,F=44100,W=16,M=stereo\r\n',b'a,,b,\r\n\r\nx, y',b'raw\nline',b'bad\r']:
        payload=(b'Description\0'.ljust(256,b'x')+b'Originator\0'.ljust(32,b' ')+b'Reference\0'.ljust(32,b' ')+b'2026-11-27'+b'12:34:56'+struct.pack('<Qh',0xffffffffffffffff,1)+b'u'*64+b'\0'*190+history)
        metadata.append((f'bext-history{history.hex()}',chunk(b'bext',payload)))
    for tag in [b'inst',b'acid']:
        for n in [0,6,24]:metadata.append((f'{tag.decode()}-payload{n}',chunk(tag,b'q'*n)))
    for name,part in metadata:
        for before in [False,True]:
            parts=[fmt(),part,chunk(b'data',b'\0'*132)] if before else [fmt(),chunk(b'data',b'\0'*132),part]
            yield fixture(name+f'-before-data{before}',riff(parts),flags=1)
    for name,part in metadata:
        if name.startswith(('cue','smpl','bext')):
            raw=riff([fmt(),part,chunk(b'data',b'\0'*132)])
            for read in range(3,18):yield fixture(name+f'-failed-read{read}',raw,fail=read)
    for read in range(15):yield fixture(f'base-failed-read{read}',base,fail=read)
    for tag in [b'inst',b'acid']:yield fixture(f'{tag.decode()}-decoder-returns-nil',riff([fmt(),chunk(tag,b'q'*24),chunk(b'data',b'\0'*132)]),flags=4)
    for flags in [0,1,2,3,0x80000002]:
        for root in [0,60,-1]:
            instrument=chunk(b'inst',bytes([60,239,250,0,127,1,127]))
            acid=chunk(b'acid',struct.pack('<IhHIIhhI',flags,root,0x8000,0x7f800001,16,8,7,0x7fc01234))
            for before in [False,True]:
                parts=[fmt(),instrument,acid,chunk(b'data',b'\0'*132)] if before else [fmt(),chunk(b'data',b'\0'*132),acid,instrument]
                yield fixture(f'instrument-and-acid-flags{flags:x}-root{root}-before{before}',riff(parts),mode=3,count=17,flags=1)
    from compare_original_wave_adpcm import ms_block,dvi_block,MS_COEFFICIENTS
    for tag in [2,17]:
        for channels in [1,2]:
            for units in [1,2,4]:
                if tag==2:
                    block_frames=18;values=18;blocks=[ms_block(rng,channels,values) for _ in range(4)]
                    extra=struct.pack('<HHH',32,values,7)+b''.join(struct.pack('<hh',*pair) for pair in MS_COEFFICIENTS)
                else:
                    block_frames=1+units*8;values=block_frames*channels;blocks=[dvi_block(rng,channels,units,reserved=1 if units==4 else 0) for _ in range(4)]
                    extra=struct.pack('<HH',2,values)
                block_bytes=len(blocks[0]);header=chunk(b'fmt ',struct.pack('<HHIIHH',tag,channels,44100,22100,block_bytes,4)+extra)
                raw=riff([header,chunk(b'data',b''.join(blocks)),chunk(b'inst',bytes([60,0,250,0,127,1,127])),chunk(b'acid',struct.pack('<IhHIIhhI',2,60,0,0,16,4,4,0))])
                for first in [0,1,block_frames-1,block_frames+1]:
                    for count in [0,1,block_frames*2+1]:
                        yield fixture(f'compressed-wave-tag{tag}-ch{channels}-units{units}-first{first}-count{count}',raw,mode=3,first=first,count=count)
                for read in [0,3,7,11,17,30]:
                    yield fixture(f'compressed-wave-failed-read-tag{tag}-ch{channels}-units{units}-read{read}',raw,mode=3,first=1,count=block_frames*2,fail=read)
    raw=Path(wave).read_bytes();assert hashlib.sha256(raw).hexdigest()==WAVE_SHA
    for first in [0,77123,176382]:
        yield fixture(f'embedded-original-wave-first{first}',raw,mode=3,first=first,count=17,capacity=257,flags=1)
    yield fixture('embedded-original-wave-complete',raw,mode=3,first=0,count=176399,capacity=257,flags=1)
