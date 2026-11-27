#include "OriginalWave.h"

static int signed_bits(unsigned u) noexcept { int v; __builtin_memcpy(&v,&u,4); return v; }
static int add(int a,int b) noexcept { return signed_bits(unsigned(a)+unsigned(b)); }
static int mul(int a,int b) noexcept { return signed_bits(unsigned(a)*unsigned(b)); }
static unsigned u32(const unsigned char* p) noexcept { return unsigned(p[0])|unsigned(p[1])<<8|unsigned(p[2])<<16|unsigned(p[3])<<24; }
static unsigned swap32(unsigned v) noexcept { return __builtin_bswap32(v); }
static bool equal(const unsigned char* a,const unsigned char* b) noexcept { for(int i=0;i<4;++i)if(a[i]!=b[i])return false;return true; }
static bool tag(const unsigned char* a,const char* b) noexcept { return equal(a,reinterpret_cast<const unsigned char*>(b)); }
static bool known(const unsigned char* id,const unsigned char* names,int count) noexcept {
    for(int i=0;i<count;++i)if(equal(id,names+i*5))return true;
    return false;
}
extern "C" bool elastik_original_wave_chunk(const ElastikOriginalWaveIO* io,int end,
    ElastikOriginalWaveChunk* out,const unsigned char* names,int count,const char* oversize) noexcept {
    unsigned char header[8];int n=8;
    bool ok=io->bytes.read(io->bytes.context,header,&n);if(!ok)return false;
    unsigned size=u32(header+4);if(io->swap_integers)size=swap32(size);
    bool shift=false;
    if(!known(header,names,count)) {
        if(known(header+1,names,count))shift=true;
        else if(signed_bits(size)<1)shift=true;
        else if(end<add(io->position(io->bytes.context),signed_bits(size)))shift=true;
    }
    if(shift) {
        unsigned char extra=0; n=1;ok=io->bytes.read(io->bytes.context,&extra,&n);
        // A failed one-byte read must still initialize its destination at the
        // platform boundary if the caller expects the original partial output.
        for(int i=0;i<4;++i)out->id[i]=header[i+1];
        size=unsigned(header[5])|unsigned(header[6])<<8|unsigned(header[7])<<16|unsigned(extra)<<24;
        if(io->swap_integers)size=swap32(size);
    } else for(int i=0;i<4;++i)out->id[i]=header[i];
    out->bytes=signed_bits(size);
    if(out->bytes>=0 && (add(io->position(io->bytes.context),out->bytes)<=end || tag(out->id,oversize)))return ok;
    return false;
}
extern "C" unsigned elastik_original_wave_sample_format(const ElastikOriginalWave* w) noexcept {
    if(w->format==2)return 0x49;
    if(w->format==17)return 0x48;
    if(w->format==3)return w->bits==32?0x13:9999;
    if(w->format==1){switch(w->bits){case 8:return 0x45;case 16:return 0x10;case 24:return 0x11;case 32:return 0x12;}}
    return 9999;
}
extern "C" unsigned elastik_original_wave_channel_format(const ElastikOriginalWave* w) noexcept {
    if(w->channels==1)return 1;
    if(w->channels==2)return 2;
    return unsigned(int(w->channels)+0x100);
}
extern "C" int elastik_original_wave_frames(const ElastikOriginalWave* w) noexcept { return w->frames; }

namespace {
struct Parser {
    ElastikOriginalWave* w;const ElastikOriginalWaveIO* io;const ElastikOriginalWaveObjects* o;ElastikWaveStatus error=ElastikWaveOk;
    void* ctx()const noexcept{return io->bytes.context;}
    int pos()const noexcept{return io->position(ctx());}
    void seek(int p)const noexcept{io->bytes.seek(ctx(),p);}
    bool fail(ElastikWaveStatus e=ElastikWaveCannotRead)noexcept{error=e;return false;}
    bool read(void* p,int n)noexcept{return io->bytes.read(ctx(),static_cast<unsigned char*>(p),&n);}
    bool scalar(void* p,int n)noexcept{
        if(!read(p,n))return false;
        if(io->swap_integers){auto* b=static_cast<unsigned char*>(p);for(int i=0;i<n/2;++i){auto v=b[i];b[i]=b[n-1-i];b[n-1-i]=v;}}return true;
    }
    bool r16(short* p)noexcept{return scalar(p,2);}
    bool r32(int* p)noexcept{return scalar(p,4);}
    bool r64(unsigned long long* p)noexcept{return scalar(p,8);}
    void* object(int kind,const void* p=nullptr,int n=0)const noexcept{return o->create(o->context,kind,p,n);}
    void* dict()const noexcept{return object(ElastikWaveDictionary);}
    void* array()const noexcept{return object(ElastikWaveArray);}
    void set(void* d,const char* k,void* v)const noexcept{o->set(o->context,d,k,v);}
    void append(void* a,void* v)const noexcept{o->append(o->context,a,v);}
    void integer(void* d,const char* k,int v)const noexcept{set(d,k,object(ElastikWaveInteger,&v,4));}
    void* blob(int n)const noexcept{return o->read_data(o->context,n);}
    bool fields(void* d,const char* const* keys,int count)noexcept{for(int i=0;i<count;++i){int v;if(!r32(&v))return fail();integer(d,keys[i],v);}return true;}
    void* text(void* data)const noexcept{return object(ElastikWaveString,o->bytes(o->context,data),o->count(o->context,data));}
    void* fixed_text(int n)noexcept{
        // 0x2498bc zero-fills n+1 bytes and stops at the first NUL. The
        // temporary buffer belongs to a native data object for this binding.
        auto* data=object(ElastikWaveData,nullptr,add(n,1));auto* p=o->bytes(o->context,data);
        for(int i=0;i<=n;++i)p[i]=0;
        if(!read(p,n)){fail();return nullptr;}int len=0;while(p[len])++len;return object(ElastikWaveString,p,len);
    }
    bool format(int size,int prior_data)noexcept{
        if(!r16(&w->format))return fail();
        if(!r16(&w->channels)||!r32(&w->sample_rate)||!r32(&w->average_bytes)||!r16(&w->block_align)||!r16(&w->bits))return fail();
        if(w->format==1||w->format==3){
            int rounded=add(int(w->bits),7);if(rounded<0)rounded=add(int(w->bits),14);w->sample_bytes=rounded>>3;
            if(prior_data)w->frames=prior_data/int(w->channels)/w->sample_bytes;
            seek(add(pos(),add(size,-16)));return true;
        }
        short extra;
        if(w->format==17){if(!r16(&extra)||!r16(&w->dvi_values_per_block))return fail();w->dvi_block_bytes=w->block_align;return true;}
        if(w->format==2){
            if(!r16(&extra)||!r16(&w->ms_samples_per_block)||!r16(&w->ms_coefficient_count))return fail();
            if(unsigned(static_cast<unsigned short>(w->channels-1))>=2 || unsigned(static_cast<unsigned short>(w->ms_coefficient_count-7))>=249)return fail(ElastikWaveUnsupported);
            for(int i=0;i<w->ms_coefficient_count;++i){short a,b;if(!r16(&a)||!r16(&b))return fail();w->coefficients[i][0]=a;w->coefficients[i][1]=b;}
            w->ms_block_bytes=w->block_align;return true;
        }
        if(io->diagnostic)io->diagnostic(ctx(),1,w->format,0);
        return fail(ElastikWaveUnsupported);
    }
    bool cue(void* chunks,int size)noexcept{
        const int end=add(pos(),size);void* entries=array();int count;if(!r32(&count))return fail();
        if(size<add(mul(count,24),4))return fail();
        for(int i=0;i<count;++i){void* d=dict();int id,position;if(!r32(&id)||!r32(&position)||!blob(16))return fail();integer(d,"cuePointID",id);integer(d,"cuePointPosition",position);append(entries,d);}
        set(chunks,"cuePoints",entries);seek(end);return true;
    }
    bool list(void* chunks,void* priv,const unsigned char* id,int size)noexcept{
        unsigned char type[4];if(!read(type,4))return fail(ElastikWaveUnsupported);
        if(!tag(type,"adtl")){
            seek(add(pos(),-4));if(size>0){void* b=blob(size);if(b){append(priv,object(ElastikWaveString,id,4));append(priv,b);}}return true;
        }
        void* entries=o->get(o->context,chunks,"dataList");if(!entries){entries=array();set(chunks,"dataList",entries);}
        int consumed=4;
        while(consumed<size){
            unsigned char child[4];int bytes;if(!read(child,4)||!r32(&bytes))return fail();int next=add(consumed,8);
            const bool label=tag(child,"labl"),note=tag(child,"note"),labeled_text=tag(child,"ltxt");
            if(!label&&!note&&!labeled_text)return fail();
            int cue_id,sample_length=0;if(!r32(&cue_id))return fail();next=add(consumed,12);
            const int fixed=labeled_text?20:4;
            if(labeled_text){if(!r32(&sample_length)||!blob(12))return fail();next=add(consumed,28);}
            void* data=nullptr;const int remaining=add(bytes,-fixed);
            if(remaining<1){if(bytes!=fixed)return fail();}
            else {
                data=blob(remaining);if(!data)return fail();
                // Preserve original labl/note +4 consumed-count discrepancy.
                next=add(next,labeled_text?remaining:bytes);
                int count=o->count(o->context,data);
                if(label&&count<2)data=nullptr;
                else if(count)o->resize(o->context,data,count-1);
            }
            // note/ltxt's zero-length branch bypasses odd padding; fixed sizes
            // are even, so this is observably the same for that valid branch.
            if(bytes&1){unsigned char pad;if(!read(&pad,1))return fail();next=add(next,1);}
            void* d=dict();integer(d,"cuePointID",cue_id);
            if(labeled_text){integer(d,"sampleLength",sample_length);if(data)set(d,"labeledText",text(data));}
            else if(data)set(d,label?"label":"note",text(data));
            else set(d,label?"label":"note",object(ElastikWaveString,"",0));
            append(entries,d);consumed=next;
        }
        return true;
    }
    bool sample(void* chunks,int size)noexcept{
        const int end=add(pos(),size);void* d=dict();
        const char* keys[]{"manufacturerId","productId","samplePeriod","midiUnityNote","midiPitchFraction","smpteFormat","smpteOffset"};
        if(!fields(d,keys,7))return false;
        int count,bytes;if(!r32(&count)||!r32(&bytes))return fail();
        void* loops=count?array():nullptr;
        const char* loop_keys[]{"cuePointID","type","start","end","fraction","playCount"};
        for(int i=0;i<count;++i){void* loop=dict();if(!fields(loop,loop_keys,6))return false;append(loops,loop);}
        if(loops)set(d,"loops",loops);
        if(bytes){void* data=blob(bytes);if(!data)return fail();set(d,"samplerData",data);}
        set(chunks,"sample",d);seek(end);return true;
    }
    bool regions(void* chunks,int size)noexcept{
        const int end=add(pos(),size);int count;if(!r32(&count))return fail();void* d=dict();void* entries=nullptr;
        const char* keys[]{"startFrame","stopFrame","syncFrame","userTimeStamp","timeStamp"};
        for(int i=0;i<count;++i){
            void* r=dict();if(!entries){entries=array();set(d,"regions",entries);}
            void* umid=blob(16);if(!umid)return fail();set(r,"DigiDesign umid",umid);
            for(const auto* key:keys){unsigned long long v=0;if(!r64(&v))return fail();set(r,key,object(ElastikWaveLongInteger,&v,8));}
            unsigned char len=0;(void)read(&len,1);
            if(len){void* name=blob(len);if(name){void* s=text(name);if(s)set(r,"name",s);}}
            for(int j=0;j<31-int(len);++j){unsigned char pad=0;(void)read(&pad,1);}
            append(entries,r);
        }
        set(chunks,"regionList",d);seek(end);return true;
    }
    bool broadcast(void* chunks,int size)noexcept{
        const int end=add(pos(),size);const int history_bytes=add(size,-602);void* d=dict();set(chunks,"Broadcast Audio Extension",d);
        const char* keys[]{"Description","Originator","OriginatorRef","Date","Time"};const int lengths[]{256,32,32,10,8};
        for(int i=0;i<5;++i){void* s=fixed_text(lengths[i]);if(error)return false;set(d,keys[i],s);}
        unsigned long long time=0;if(!r64(&time))return fail();set(d,"TimeRef",object(ElastikWaveLongInteger,&time,8));
        short version=0;if(!r16(&version))return fail();integer(d,"Version",version);
        set(d,"UMID",blob(64));set(d,"Reserved",blob(190));
        if(history_bytes>0){
            void* rows=array();void* data=blob(history_bytes);if(!data)return fail(ElastikWaveAssertion);auto* p=o->bytes(o->context,data);
            int start=0;void* row=nullptr;
            for(int i=0;i<=history_bytes;){
                if(i==history_bytes||p[i]==','||p[i]=='\r'){
                    if(start<i){if(!row){row=array();append(rows,row);}append(row,object(ElastikWaveString,p+start,i-start));}
                    if(i<history_bytes&&p[i]=='\r'){++i;if(i==history_bytes||p[i]!='\n')return fail();row=nullptr;}
                    ++i;start=i;
                }else ++i;
            }
            set(d,"CodingHistory",rows);
        }
        seek(end);return true;
    }
};
// Exact 21 * 5 bytes passed by the original, including its final non-text row.
static const unsigned char known_ids[]{
    'f','m','t',' ',0,'b','e','x','t',0,'d','a','t','a',0,'m','i','n','f',0,
    'r','e','g','n',0,'o','v','w','f',0,'e','l','m','1',0,'u','m','i','d',0,
    'P','A','D',' ',0,'i','n','s','t',0,'L','I','S','T',0,'c','u','e',' ',0,
    's','m','p','l',0,'p','l','s','t',0,'w','a','v','l',0,'L','G','W','V',0,
    'S','y','L','p',0,'a','c','i','d',0,'s','t','r','c',0,'a','n','a','l',0,0xb5,0x4c,0xd0,0x2e,0
};
}
extern "C" ElastikWaveStatus elastik_original_wave_open(ElastikOriginalWave* w,
    const ElastikOriginalWaveIO* io,const ElastikOriginalWaveObjects* objects) noexcept {
    // 0x17f560(stream, 0) selects little-endian integers; it is not a seek.
    ElastikOriginalWaveIO little_endian=*io;little_endian.swap_integers=false;io=&little_endian;
    Parser p{w,io,objects};void* chunks=p.dict();void* priv=p.array();
    w->stream_open=io->open(p.ctx());if(!w->stream_open)return ElastikWaveCannotRead;io->retain(p.ctx());
    unsigned char id[5]{};int four=4;if(!io->bytes.read(p.ctx(),id,&four))return ElastikWaveCannotRead;if(!tag(id,"RIFF"))return ElastikWaveUnsupported;
    int riff_bytes;if(!p.r32(&riff_bytes))return ElastikWaveCannotRead;
    if(!io->bytes.read(p.ctx(),id,&four))return ElastikWaveCannotRead;
    if(!tag(id,"WAVE"))return ElastikWaveUnsupported;
    bool have_format=false,have_data=false;int prior_data=0;
    while(p.pos()<add(riff_bytes,-1)){
        ElastikOriginalWaveChunk c{};if(!elastik_original_wave_chunk(io,add(riff_bytes,8),&c,known_ids,21,"data"))break;
        if(c.bytes>=0)(void)p.pos();
        if(tag(c.id,"fmt ")){if(!p.format(c.bytes,prior_data))return p.error;have_format=true;}
        else if(tag(c.id,"data")){
            int end=io->length(p.ctx());if(add(riff_bytes,8)<end)end=add(riff_bytes,8);w->data_offset=p.pos();
            int bytes=c.bytes;const int available=add(end,-w->data_offset);
            if(available<bytes){if(io->diagnostic)io->diagnostic(p.ctx(),2,available,bytes);bytes=available;}
            if(w->format==2)w->frames=static_cast<int>((static_cast<unsigned long long>(w->ms_samples_per_block)*unsigned(bytes))/static_cast<unsigned long long>(w->ms_block_bytes));
            else if(w->format==17){
                w->frames=static_cast<int>((static_cast<unsigned long long>(w->dvi_values_per_block)*unsigned(bytes))/static_cast<unsigned long long>(w->dvi_block_bytes)/static_cast<unsigned long long>(w->channels));
                w->dvi_samples=objects->allocate_dvi(objects->context,mul(mul(w->channels,w->dvi_values_per_block),2));
                if(!w->dvi_samples)return ElastikWaveAssertion;
            }else if(w->format==1||w->format==3){w->frames=bytes/int(w->channels)/w->sample_bytes;prior_data=bytes;}
            p.seek(add(p.pos(),bytes));have_data=true;
        }else if(tag(c.id,"plst")||tag(c.id,"wavl")){
            if(io->diagnostic)io->diagnostic(p.ctx(),tag(c.id,"plst")?3:4,0,0);
            p.seek(add(p.pos(),c.bytes));
        }else if(tag(c.id,"cue ")){if(!p.cue(chunks,c.bytes))return p.error;}
        else if(tag(c.id,"list")||tag(c.id,"LIST")){if(!p.list(chunks,priv,c.id,c.bytes))return p.error;}
        else if(tag(c.id,"JNUK")||tag(c.id,"PAD "))p.seek(add(p.pos(),c.bytes));
        else if(tag(c.id,"smpl")){if(!p.sample(chunks,c.bytes))return p.error;}
        else if(tag(c.id,"regn")){if(!p.regions(chunks,c.bytes))return p.error;}
        else if(tag(c.id,"bext")){if(!p.broadcast(chunks,c.bytes))return p.error;}
        else if(tag(c.id,"inst")||tag(c.id,"acid")){
            const int end=add(p.pos(),c.bytes);
            if(c.bytes){void* decoded=objects->decode_chunk(objects->context,tag(c.id,"acid"),p.blob(c.bytes));if(decoded)p.set(chunks,objects->chunk_name(objects->context,decoded),decoded);}
            p.seek(end);
        }else if(c.bytes>0){void* data=p.blob(c.bytes);if(data){p.append(priv,p.object(ElastikWaveString,c.id,4));p.append(priv,data);}}
    }
    if(!have_format||!have_data)return ElastikWaveCannotRead;
    if(objects->count(objects->context,chunks))p.set(w->metadata,"chunks",chunks);
    if(objects->count(objects->context,priv))p.set(w->metadata,"privateChunks",priv);
    return ElastikWaveOk;
}
