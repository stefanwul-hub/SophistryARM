// Reuse the WAVE byte-I/O and GN primitive fixture without changing its
// standalone executable. These are test bindings, not plugin UI/runtime code.
#define main elastik_wave_fixture_standalone_main
#include "WaveProbe.cpp"
#undef main
#include "../src/OriginalFileOpen.h"
#include "../src/OriginalVoiceChunk.h"
#include <stdint.h>

namespace Pipeline {
struct State {
    Context* c;ElastikOriginalWave wave;ElastikOriginalReadBuffer buffer;
    ElastikOriginalWaveIO io;ElastikOriginalWaveObjects objects;ElastikOriginalWaveReadPlatform read_platform;ElastikOriginalReaderDiagnostics reader_diagnostics;
    ElastikOriginalFileReader readers[2];ElastikOriginalSampleFile file;ElastikOriginalFileOpenState opened;
    ElastikOriginalSampleCache cache;ElastikOriginalCacheRefill refill;ElastikOriginalCachePlatform cache_platform;ElastikOriginalCacheLifecycle lifecycle;
    ElastikOriginalCacheScratch scratch;ElastikOriginalCacheLifecycle* owner=nullptr;
    void* allocations[128];int allocation_count=0,constructs=0;bool initial_timer=false;
};
static void* alloc(State* s,int bytes){if(s->allocation_count>=128||bytes<0)abort();void* p=malloc(static_cast<size_t>(bytes)+1);if(!p)abort();memset(p,0xa5,bytes);s->allocations[s->allocation_count++]=p;return p;}
static int frames(void* p){return elastik_original_wave_frames(&static_cast<State*>(p)->wave);}
static bool read_samples(void* p,float* const* outputs,int first,int count){auto* s=static_cast<State*>(p);return elastik_original_read_wave(&s->wave,&s->buffer,outputs,first,count,&s->io.bytes,&s->read_platform,&s->reader_diagnostics,&s->io)==ElastikWaveOk;}
static ElastikOriginalFileReader* construct_reader(void* p,int kind){auto* s=static_cast<State*>(p);if(kind>1)abort();s->c->event(24,kind);return s->readers+kind;}
static ElastikOriginalFileReader* identity(void*,ElastikOriginalFileReader* r){return r;}
static ElastikOriginalFileStatus open_reader(void* p,ElastikOriginalFileReader* r,void*){
    auto* s=static_cast<State*>(p);if(r==s->readers)return ElastikFileUnsupported;
    return static_cast<ElastikOriginalFileStatus>(elastik_original_wave_open(&s->wave,&s->io,&s->objects));
}
static void object_operation(void*,int,void*){}
static unsigned channels(void* p,ElastikOriginalFileReader*){return elastik_original_wave_channel_format(&static_cast<State*>(p)->wave);}
static double rate(void* p,ElastikOriginalFileReader*){return static_cast<State*>(p)->wave.sample_rate;}
static unsigned format(void* p,ElastikOriginalFileReader*){return elastik_original_wave_sample_format(&static_cast<State*>(p)->wave);}
static int file_kind(void*,ElastikOriginalFileReader*){return 2;}
static void* source(void* p){return static_cast<State*>(p)->wave.metadata;}
static bool contains(void* p,void* d,const char* key){return get(static_cast<State*>(p)->c,d,key)!=nullptr;}
static void* meta_get(void* p,void* d,const char* key){return get(static_cast<State*>(p)->c,d,key);}
static void meta_set(void* p,void* d,const char* key,void* v){set(static_cast<State*>(p)->c,d,key,v);}
static void* integer(void* p,int v){return create(static_cast<State*>(p)->c,3,&v,4);}
static void export_metadata(void* p,ElastikOriginalFileReader*,void* d){auto* s=static_cast<State*>(p);const ElastikOriginalMetadataBinding b{s,source,contains,meta_get,meta_set,integer};elastik_original_export_wave_metadata(&s->wave,&b,d);}
static void* partner(void*,void*,int*){return nullptr;}
static bool exists(void*,void*){return false;}
static void lock(void* p){static_cast<State*>(p)->c->event(25);}
static void unlock(void* p){static_cast<State*>(p)->c->event(26);}
static void emit(void* p,int code,int a,int b,int c,int d){auto* s=static_cast<State*>(p);if(code==2)s->c->event(30,code,a,b,c);else if(code==3)s->c->event(30,code);else{(void)d;abort();}}
static void* cache_allocate(void* p,int kind,int count){
    auto* s=static_cast<State*>(p);if(s->file.cache!=&s->cache)abort();s->c->event(20,kind,count,1,s->cache.slot_count);
    int width=kind==ElastikCacheSlots?sizeof(ElastikOriginalCacheBlock):kind==ElastikCacheMap?4:kind==ElastikCacheClients?12:1;
    return alloc(s,count*width);
}
static void cache_release(void*,int,void*){abort();}
static void cache_object(void* p,int op,void* timer){if(op!=1||timer!=reinterpret_cast<void*>(1))abort();static_cast<State*>(p)->c->event(22);}
static void warning(void*,int){abort();}
static void process(void* p){elastik_original_cache_refill(&static_cast<State*>(p)->refill);}
static void* timer(void* p,void(*callback)(void*),void* data,double seconds,bool repeat){auto* s=static_cast<State*>(p);if(callback!=process||data!=s||seconds!=0.2||!repeat)abort();s->c->event(21,200,1);return reinterpret_cast<void*>(1);}
static void cancel(void*,void*){abort();}
static float* block(void* p,int bytes){auto* s=static_cast<State*>(p);s->c->event(23,bytes,s->cache.slot_count);auto* r=static_cast<float*>(alloc(s,bytes));for(int i=0;i<bytes/4;++i)r[i]=0.03125f;return r;}
static void capacity_warning(void*){abort();}
static double clock(void*){abort();}
static ElastikOriginalCacheLifecycle* construct_cache(void* p){auto* s=static_cast<State*>(p);++s->constructs;s->c->event(24,2);elastik_original_cache_initialize(&s->lifecycle);if(s->initial_timer)s->lifecycle.timer=reinterpret_cast<void*>(1);return &s->lifecycle;}
static void reset_voice(ElastikOriginalVoiceChunkState* v,const int* h,int n){
    *v={};v->sample_frames=n;v->loop_start=h[10]?n/2:0;v->loop_stop=h[10]?n/4:n-1;v->direction=h[4];v->looping=h[5];v->released=h[6];v->last_direction=-7;
    for(int c=0;c<2;++c){v->fade_in[c]={1.0f,h[11]?0.25f:1.0f,h[11]?0.03125f:0.0f};v->fade_out[c]={0.0f,1.0f,0.0f};}
}
static int run(const int* h){
    auto* raw=static_cast<unsigned char*>(malloc(h[0]+1));if(fread(raw,1,h[0],stdin)!=static_cast<size_t>(h[0]))return 2;
    auto* c=static_cast<Context*>(calloc(1,sizeof(Context)));c->raw=raw;c->size=h[0];c->open_ok=1;c->maximum=-1;c->fail_read=-1;
    State s{};s.c=c;s.initial_timer=h[8]!=0;s.wave.metadata=node(c,1);memset(s.wave.coefficients,0xa5,sizeof(s.wave.coefficients));
    s.buffer={static_cast<unsigned char*>(malloc(h[7])),h[7]};memset(s.buffer.bytes,0xa5,h[7]);
    s.io={{c,seek,read},open,retain,position,length,false,diagnostic};s.objects={c,create,set,get,append,count,bytes,resize,read_data,decode,chunk_name,allocate_dvi};s.read_platform={c,allocate_block,release_block};s.reader_diagnostics={c,read_failed,format_failed};
    for(int i=0;i<2;++i)s.readers[i]={{&s,frames,read_samples},reinterpret_cast<void*>(static_cast<uintptr_t>(i+1))};
    s.file.lock_context=&s;s.file.lock=lock;s.file.unlock=unlock;s.file.diagnostics={&s,emit};s.cache.diagnostics={&s,emit};
    s.opened.file=&s.file;s.opened.metadata=node(c,1);
    const ElastikOriginalFileOpenPlatform open_platform{&s,construct_reader,identity,identity,open_reader,object_operation,channels,rate,format,file_kind,export_metadata,partner,exists};
    const auto status=elastik_original_open_sample_file(&s.opened,&open_platform,reinterpret_cast<void*>(11));if(status!=ElastikFileOk)return 3;
    s.refill={&s.cache,nullptr,0,0,0,0,0,0.0,&s,block,capacity_warning,clock};s.cache_platform={&s,cache_allocate,cache_release,cache_object,warning,timer,cancel};s.lifecycle={&s.cache,&s.refill,&s.cache_platform,0,nullptr,nullptr,process,&s};
    for(int i=0;i<h[9];++i)elastik_original_ensure_file_cache(&s.file,&s.owner,&s,construct_cache,&s.scratch);
    auto* client=elastik_original_cache_acquire_client(&s.lifecycle);
    ElastikOriginalSampleHandle handle{&s.file,client,false};
    int records[3][8];float ramps[3][12];float* audio[3];
    for(int i=0;i<3;++i){
        if(i==1)elastik_original_cache_refill(&s.refill);
        handle.direct=i==2;
        audio[i]=static_cast<float*>(malloc((h[1]+16)*4));for(int j=0;j<h[1]+16;++j)audio[i][j]=0.03125f;
        ElastikOriginalVoiceChunkState voice{};reset_voice(&voice,h,s.wave.frames);int next=0x12345678;ElastikOriginalReadRange range{-11,-13};
        const int result=elastik_original_read_voice_chunk(&voice,audio[i],h[3],h[2],h[1],&next,&range,elastik_original_sample_provider,&handle);
        const int record[]{result,next,range.start,range.count,voice.last_direction,s.cache.underrun,client->first_block,client->last_block};memcpy(records[i],record,sizeof(record));
        memcpy(ramps[i],voice.fade_in,24);memcpy(ramps[i]+6,voice.fade_out,24);
    }
    const int header[]{status,static_cast<int>(s.file.sample_format),s.opened.file_kind,static_cast<int>(s.file.channel_format),s.wave.frames,s.file.cache?1:0,s.refill.slot_capacity,s.lifecycle.maximum_clients,s.cache.client_count,s.cache.slot_count,s.cache.underrun,s.scratch.bytes,s.lifecycle.timer?1:0,s.constructs};
    bool ok=output(header,sizeof(header))&&output(&s.file.sample_rate,8)&&serialize(static_cast<Node*>(s.opened.metadata));
    for(int i=0;i<3;++i)ok=ok&&output(records[i],sizeof(records[i]))&&output(ramps[i],sizeof(ramps[i]))&&output(audio[i],(h[1]+16)*4);
    for(int i=0;i<s.refill.slot_capacity;++i){const int block_id=s.cache.blocks[i].block;ok=ok&&output(&block_id,4);}
    ok=ok&&output(s.cache.block_to_slot,s.refill.slot_capacity*4);
    for(int i=0;i<s.cache.slot_count;++i)ok=ok&&output(s.cache.blocks[i].samples,s.refill.block_bytes);
    ok=ok&&output(&c->traces,4)&&output(c->trace,c->traces*20);
    for(auto* samples:audio)free(samples);
    free(s.buffer.bytes);for(int i=0;i<s.allocation_count;++i)free(s.allocations[i]);
    for(int i=0;i<c->node_count;++i){auto* n=c->nodes[i];if(n->kind==1)for(int j=0;j<n->length;++j)free(n->keys[j]);free(n->keys);free(n->items);free(n->data);free(n);}
    for(int i=0;i<c->allocation_count;++i){free(c->allocations[i]);}free(c);free(raw);
    return ok&&!fflush(stdout)?0:4;
}
} // namespace Pipeline
int main(){for(;;){int h[12];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=Pipeline::run(h);if(e)return e;}}
