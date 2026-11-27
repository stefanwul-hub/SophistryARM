#include "../src/OriginalCacheLifecycle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

static_assert(sizeof(ElastikOriginalCacheClient) == 12);
struct Allocation { void* p; int kind, count, physical; };
struct Context {
    Allocation allocations[128]; int count=0;
    int trace[2048][6]; int traces=0, reader_frames=0; bool cancel_clears_owner=false;
    ElastikOriginalCacheLifecycle* state;
    void record(int a,int b=0,int c=0,int d=0,int e=0,int f=0) {
        if(traces>=2048) { abort(); } const int row[]{a,b,c,d,e,f}; memcpy(trace[traces++],row,sizeof(row));
    }
    int token(void* p) {
        if(!p) return 0;
        if(p==reinterpret_cast<void*>(1) || p==reinterpret_cast<void*>(2)) return p==reinterpret_cast<void*>(1)?-2:-3;
        for(int i=0;i<count;++i) if(allocations[i].p==p) return i+1;
        return -1; // untouched allocator poison, never dereferenced
    }
};
static void* allocate(void* p,int kind,int count) {
    auto* c=static_cast<Context*>(p); if(c->count>=128||count<0) abort();
    int size=kind==ElastikCacheSlots?sizeof(ElastikOriginalCacheBlock):kind==ElastikCacheClients?12:kind==ElastikCacheMap?4:1;
    int physical=count+(kind==ElastikCacheClients?4:0);
    auto* result=malloc(static_cast<size_t>(physical)*size+1); if(!result) abort();
    memset(result,0xa5,static_cast<size_t>(physical)*size);
    c->allocations[c->count++]={result,kind,count,physical};
    c->record(1,kind,count,c->count,c->state->cache->slot_count,c->state->maximum_clients);
    return result;
}
static void release(void* p,int kind,void* object) { auto* c=static_cast<Context*>(p);c->record(2,kind,c->token(object)); }
static void object_op(void* p,int op,void* object) { auto* c=static_cast<Context*>(p);c->record(3,op,c->token(object)); }
static void warning(void* p,int code) { static_cast<Context*>(p)->record(4,code); }
static void process(void* p) { static_cast<Context*>(p)->record(7); }
static void* timer(void* p,void(*cb)(void*),void* data,double seconds,bool repeat) {
    auto* c=static_cast<Context*>(p); if(cb!=process||data!=p||seconds!=0.2||!repeat) abort(); c->record(5,200,1);return reinterpret_cast<void*>(2);
}
static void cancel(void* p,void* object) {auto* c=static_cast<Context*>(p);c->record(6,c->token(object));if(c->cancel_clears_owner)c->state->timer=nullptr;}
static int frames(void* p) {auto* c=static_cast<Context*>(p);c->record(8,c->reader_frames);return c->reader_frames;}
static bool output(const void* p,size_t n) {return fwrite(p,1,n,stdout)==n;}
static bool snapshot(Context& c,int result,ElastikOriginalCacheScratch& scratch) {
    auto& s=*c.state;auto& cache=*s.cache;auto& r=*s.refill;
    int header[]{result,c.token(cache.blocks),c.token(cache.block_to_slot),c.token(cache.clients),cache.slot_count,r.block_bytes,
        r.slot_capacity,s.maximum_clients,cache.client_count,cache.frames,cache.chunk_frames,r.channels,cache.underrun,r.profiling,r.processing,
        c.token(s.delegate),c.token(s.timer),c.token(scratch.data),scratch.bytes,r.file?1:0};
    if(!output(header,sizeof(header))||!output(&r.elapsed_seconds,8))return false;
    if(cache.blocks) for(int i=0;i<r.slot_capacity;++i) {int row[]{cache.blocks[i].block,c.token(cache.blocks[i].samples)};if(!output(row,sizeof(row)))return false;}
    if(cache.block_to_slot&&!output(cache.block_to_slot,r.slot_capacity*4))return false;
    if(cache.clients&&!output(cache.clients,s.maximum_clients*12))return false;
    return true;
}
static int run(const int* h) {
    Context c{};c.reader_frames=h[3];
    ElastikOriginalSampleCache cache{};cache.frames=-71;cache.chunk_frames=37;cache.client_count=3;cache.underrun=9;
    ElastikOriginalCacheRefill refill{};refill.cache=&cache;refill.block_bytes=h[0];refill.channels=5;
    refill.profiling=3;refill.processing=7;refill.elapsed_seconds=0.125;
    const ElastikOriginalCachePlatform platform{&c,allocate,release,object_op,warning,timer,cancel};
    ElastikOriginalCacheLifecycle state{&cache,&refill,&platform,0,reinterpret_cast<void*>(1),nullptr,process,&c};c.state=&state;
    ElastikOriginalSampleReader reader{&c,frames,nullptr};ElastikOriginalSampleFile file{};
    file.channel_format=h[1];file.known_frames=h[2];file.reader=h[5]?&reader:nullptr;file.sample_format=h[4];
    ElastikOriginalCacheScratch scratch{};
    // Initial scratch is a separate retained fixture allocation, not an original allocation event.
    if(h[6]){void* p=malloc(h[6]);memset(p,0xa5,h[6]);c.allocations[c.count++]={p,5,h[6],h[6]};scratch={p,h[6]};}
    for(int i=0;i<h[7];++i) {
        int op[4];if(fread(op,1,sizeof(op),stdin)!=sizeof(op))return 2;int result=0;
        switch(op[0]){
        case 1:elastik_original_cache_initialize(&state);break;
        case 2:refill.block_bytes=op[3];elastik_original_cache_allocate(&state,op[1],op[2]);break;
        case 3:elastik_original_sound_cache_configure(&state,&file,&scratch);break;
        case 4:result=static_cast<int>(elastik_original_cache_acquire_client(&state)-cache.clients);break;
        case 5:elastik_original_cache_release_client(cache.clients+op[1]);break;
        case 6:cache.clients[op[1]].first_block=op[2];cache.clients[op[1]].last_block=op[3];break;
        case 7:elastik_original_cache_start(&state);break;
        case 8:elastik_original_cache_stop(&state);break;
        case 9:elastik_original_cache_dispose(&state);break;
        case 10:cache.slot_count=op[1];break;
        case 11:state.delegate=op[1]?reinterpret_cast<void*>(1):nullptr;break;
        case 12:c.cancel_clears_owner=op[1]!=0;break;
        default:return 3;
        }
        if(!snapshot(c,result,scratch))return 4;
    }
    if(!output(&c.traces,4)||!output(c.trace,c.traces*24))return 4;
    // Buffers remain readable after logical release for final snapshots only.
    for(int i=0;i<c.count;++i)free(c.allocations[i].p);
    return fflush(stdout)?4:0;
}
int main(){for(;;){int h[8];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=run(h);if(e)return e;}}
