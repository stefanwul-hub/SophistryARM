#!/usr/bin/env python3
"""Original read-only GNFA open and absolute-path factories versus native C++."""
import argparse,hashlib,itertools,json,struct
from pathlib import Path
from compare_original_file_archive import archive,fixtures as parser_fixtures,pack,BUILTIN,ARCHIVE_SHA,CORE,PATH,OWNER,IOS,IOVT,DESC,NAMES,OUT
from compare_original_archive_names import fixture as name_fixture,graph
from original_archive_name_oracle import ArchiveNameOracle,ROOT
from native_probe import NativeProbe
from legacy_image import SHA
from unicorn import UC_HOOK_CODE
GNA,SOURCE,SOURCEVT,OWNERVT=0xd60000,0xd70000,0xd71000,0xd72000

def fixture(name,raw,path='/root/Pads/Tone.wav'):
    units=path.encode('utf-16-le','surrogatepass');h=[0]*32;h[0:3]=[len(raw),len(units)//2,len(raw)];h[4]=h[7]=h[13]=1;h[12]=h[14]=h[19]=-1
    return dict(name=name,raw=raw,path=units,h=h)
def fixtures(builtin):
    for layout in [0,1]:
        raw=graph(layout)
        for path,wrapper,old,reader,size in itertools.product(['/root/Pads/Tone.wav','/root','/missing','','root/Pads/Tone.wav','//','/root/éclair'],[0,1],[0,1],[0,1],[-1,len(raw),0x7fffffff]):
            c=fixture(f'open-layout{layout}-path{path}-wrapper{wrapper}-old{old}-reader{reader}-size{size}',raw,path);c['h'][2]=size;c['h'][3]=old;c['h'][4]=reader;c['h'][6]=wrapper;c['h'][16]=1;c['h'][19]=17;yield c
    # Reuse the original parser's independent edge corpus behind the new real
    # open wrapper, without injecting any derived directory descriptors.
    for base in parser_fixtures(builtin):
        name=base['name']
        if base['ops'] or name.startswith('entries-'):continue
        c=fixture('through-read-open-'+name,base['raw']);h=c['h'];h[5]=base['h'][4];h[7]=0;h[12:15]=[base['h'][5],base['h'][7],base['h'][6]]
        if 0<=base['h'][2]<0x80000000 and base['h'][3]==0:h[2]=base['h'][2]
        yield c
    for path,stream,wrapper in itertools.product(['','/','//','relative','/not-open','/東京'],[0,1],[0,1]):
        c=fixture(f'path-without-open-{path}-stream{stream}-wrapper{wrapper}',archive([]),path);c['h'][8]=1;c['h'][9]=stream;c['h'][6]=wrapper;yield c
    raw=builtin.read_bytes();assert hashlib.sha256(raw).hexdigest()==ARCHIVE_SHA
    for path,clone,shared in itertools.product(['/elastik/01drm120elastik_2.WAV','/elastik/Info.plist','/Info.plist'],[0,1],[0,1]):
        c=fixture(f'builtin-open-{path}-clone{clone}-shared{shared}',raw,path);c['h'][6]=1;c['h'][10:12]=[clone,shared];c['h'][19]=707036 if path.endswith('.WAV') else 96;yield c

class ArchiveOpenOracle(ArchiveNameOracle):
    def __init__(self,binary):
        super().__init__(binary)
        for at,fn in [(0x9a1a2,self.path_construct),(0x35d80,self.character),(0x500d00,self.source_reader),(0x500d10,self.source_size)]:self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.put(SOURCE,SOURCEVT);self.put(SOURCEVT+0x248,0x500d00);self.put(SOURCEVT+0x1d8,0x500d10);self.put(OWNERVT+0x40,0x2dfe2)
    def raise_error(self,*unused):
        p,=self.arguments(1)
        if self.error_strings[p]==b"GNFileArchiveCannotOpenArchiveException":self.error=5;self.uc.emu_stop()
        else:super().raise_error()
    def new(self):
        n,=self.arguments(1)
        if n==28:self.paths+=1;self.event(32);self.finish(PATH)
        else:super().new()
    def path_construct(self,*unused):p,=self.arguments(1);assert p==PATH;self.event(33);self.uc.mem_write(PATH,bytes(0x28));self.finish(p)
    def identity(self,*unused):
        p,=self.arguments(1)
        if p==PATH:self.event(34);self.finish(p)
        else:super().identity()
    def autorelease(self,*unused):
        p,=self.arguments(1)
        if p==PATH:self.event(35);self.finish(p)
        else:super().autorelease()
    def retain_object(self,*unused):
        p,=self.arguments(1)
        if p==ROOT:self.event(36);self.finish(p)
        elif p==OWNER:self.owners+=1;self.event(37);self.finish(p)
        else:super().retain_object()
    def source_reader(self,*unused):p,=self.arguments(1);assert p==SOURCE;self.event(30,1,self.settings[4]);self.finish(IOS if self.settings[4] else 0)
    def source_size(self,*unused):p,=self.arguments(1);assert p==SOURCE;self.event(31,self.settings[2]);self.finish(self.settings[2])
    def character(self,*unused):p,i=self.arguments(2);assert p==ROOT;v=struct.unpack_from('<H',self.root_units,i*2)[0];self.event(38,i,v);self.finish(v)
    def setup_open(self,c):
        h=c['h'];seed=name_fixture('empty-control',archive([]),c['path'].decode('utf-16-le','surrogatepass'),[],clone=h[10],shared=h[11]);self.prepare(seed);self.settings=h;self.paths=self.owners=0;self.raw=c['raw'];self.maximum=h[12];self.read_ok=h[13];self.fail=h[14];self.reads=0;self.positions=[11,17,11];self.trace=[]
        self.put(CORE+4,91,92,93,0,0,77,0);self.put(CORE+0x24,IOS if h[9] else 0);self.uc.mem_write(CORE+0x2c,bytes([bool(h[5])]));self.put(GNA+0xc,IOS if h[3] else 0);self.put(GNA+0x14,CORE);self.put(OWNER,OWNERVT)
    def execute_open(self,c):
        self.setup_open(c);h=c['h'];opened=repeated=path_status=-1;path=0
        if not h[8]:
            self.phase="parse"
            self.call_reg(0xe13de,(GNA,SOURCE));opened=self.error
            if h[16]:self.call_reg(0xe13de,(GNA,SOURCE));repeated=self.error
        self.phase="lookup"
        if h[7] and (opened==0 or h[8]):
            result=self.call_reg(0xe1a68 if h[6] else 0xe168c,((GNA if h[6] else CORE),ROOT));path_status=self.error;path=result if not self.error else 0
        header=[opened,repeated,path_status,int(bool(path)),int(bool(self.word(GNA+0xc))),int(bool(self.word(CORE+0x24))),*[self.word(CORE+off) for off in [4,8,12,16]],int(bool(self.word(CORE+20))),self.uc.mem_read(CORE+0x2c,1)[0],self.capacity,self.word(CORE+0x18),self.word(CORE+0x1c),*self.positions[:2],int(bool(self.word(PATH+0x10))),self.word(PATH+0x14),int(bool(self.word(PATH+0x18))),self.depth,self.owners,self.paths]
        answer=pack(header)
        for i in range(self.capacity):
            b=bytearray(self.uc.mem_read(DESC+i*576,576));name=struct.unpack_from('<I',b,572)[0];struct.pack_into('<I',b,572,(name-NAMES)//0x100 if name else 0);answer+=b
        file=file_status=-1;file=read_ok=count=0;payload=b''
        if path and h[19]>=0:
            result=self.call_reg(0xe3ff4,(path,));file_status=self.error;file=self.files.index(result)+1 if result in self.files and not self.error else 0
            if file:
                wanted=h[19];self.uc.mem_write(OUT,b'\xa5'*(wanted+32));self.put(OUT+0x110000,wanted);read_ok=self.call_reg(0xe4172,(result,OUT+16,OUT+0x110000));file_status=self.error;count=self.word(OUT+0x110000);payload=bytes(self.uc.mem_read(OUT,wanted+32))
        return answer+pack([file,file_status,int(bool(read_ok)),count,len(payload)])+payload+self.snapshot()

def compare(binary,runner,prefix,platform,builtin):
    oracle=ArchiveOpenOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures(builtin):
        try:expected=oracle.execute_open(c)
        except Exception as e:raise RuntimeError(f'Original archive-open failed {c["name"]}: {e}') from e
        data=pack(c['h'])+c['raw']+c['path'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA013-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-open-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)));raise ValueError(f'Archive-open mismatch {c["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],trace_events=len(oracle.trace),sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA013',scope='Read-only GNFA open -> original directory parser -> absolute path factory -> real lookup -> member file reads',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,original_read_open_parser_path_lookup_and_member_bodies_executed=True,directory_metadata_substituted=False,member_data_substituted=False,complete_builtin_wave_bytes_compared=707036,actual_macos_file_io_executed=False,actual_GN_lifetime_runtime_validated=False,protected_user_bank_compatibility_verified=False,full_engine_built=False,audio_unit_validated=False,cases=cases)
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--builtin',type=Path,default=BUILTIN);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.builtin);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
