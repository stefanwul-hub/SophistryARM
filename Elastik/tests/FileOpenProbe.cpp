#include "../src/OriginalFileOpen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Context;
struct ReaderContext {Context* c;int token;};
struct Context {
    int h[48];double rates[3];int phase=0;
    ElastikOriginalFileReader readers[9];ReaderContext reader_contexts[9];
    int trace[512][6];int traces=0;int destination[4]{26,27,24,-999};
    int integer_value=0;
    void event(int a,int b=0,int c=0,int d=0,int e=0,int f=0){
        if(traces>=512){abort();}const int row[]{a,b,c,d,e,f};memcpy(trace[traces++],row,sizeof(row));
    }
};
static void* object(int token){return reinterpret_cast<void*>(static_cast<uintptr_t>(token));}
static int token(void* p){return static_cast<int>(reinterpret_cast<uintptr_t>(p));}
static int token(ElastikOriginalFileReader* r){return r?token(r->identity):0;}
static ElastikOriginalFileReader* reader(Context* c,int n){return n?c->readers+n-1:nullptr;}
static ElastikOriginalFileReader* construct(void* p,int format){auto* c=static_cast<Context*>(p);int n=c->phase*4+format+1;const int sizes[]{56,2112,52,48};c->event(1,format,n,sizes[format]);return reader(c,n);}
static ElastikOriginalFileReader* initialize(void* p,ElastikOriginalFileReader* r){static_cast<Context*>(p)->event(2,token(r));return r;}
static ElastikOriginalFileReader* autorelease(void* p,ElastikOriginalFileReader* r){auto* c=static_cast<Context*>(p);int n=token(r),mask=c->h[32+c->phase];auto* value=(mask&(1<<((n-1)%4)))?nullptr:r;c->event(3,n,token(value));return value;}
static ElastikOriginalFileStatus open_reader(void* p,ElastikOriginalFileReader* r,void* path){auto* c=static_cast<Context*>(p);int n=token(r),phase=(n-1)/4,format=(n-1)%4,status=c->h[24+phase*4+format];c->event(4,n,token(path),status);return static_cast<ElastikOriginalFileStatus>(status);}
static void operation(void* p,int op,void* value){static_cast<Context*>(p)->event(5,op,token(value));}
static unsigned channels(void* p,ElastikOriginalFileReader* r){auto* c=static_cast<Context*>(p);int n=token(r),v=c->h[n<=4?16:20];c->event(6,1,n,v);return v;}
static double rate(void* p,ElastikOriginalFileReader* r){auto* c=static_cast<Context*>(p);int n=token(r);double v=c->rates[n<=4?1:2];int bits[2];memcpy(bits,&v,8);c->event(6,2,n,bits[0],bits[1]);return v;}
static unsigned format(void* p,ElastikOriginalFileReader* r){auto* c=static_cast<Context*>(p);int n=token(r),v=c->h[n<=4?17:21];c->event(6,3,n,v);return v;}
static int kind(void* p,ElastikOriginalFileReader* r){auto* c=static_cast<Context*>(p);int n=token(r),v=c->h[n<=4?19:23];c->event(6,4,n,v);return v;}
static int frames(void* p){auto* rc=static_cast<ReaderContext*>(p);int v=rc->c->h[rc->token<=4?18:22];rc->c->event(6,5,rc->token,v);return v;}
static void metadata(void* p,ElastikOriginalFileReader* r,void* d){static_cast<Context*>(p)->event(7,token(r),token(d));}
static void* partner(void* p,void* path,int* side){auto* c=static_cast<Context*>(p);*side=c->h[15];c->phase=1;int n=c->h[13]?12:0;c->event(8,token(path),*side,n);return object(n);}
static bool exists(void* p,void* path){auto* c=static_cast<Context*>(p);c->event(9,token(path),c->h[14]);return c->h[14]!=0;}
static int key_id(const char* key){if(!strcmp(key,"chunks"))return 1;if(!strcmp(key,"privateChunks"))return 2;if(!strcmp(key,"Melodyne1WaveSampleCount"))return 3;abort();}
static void* source(void* p){auto* c=static_cast<Context*>(p);int n=c->h[34]?21:0;c->event(10,n);return object(n);}
static bool contains(void* p,void* d,const char* key){auto* c=static_cast<Context*>(p);int k=key_id(key),yes=(c->h[35]>>(k-1))&1;c->event(11,token(d),k,yes);return yes;}
static void* get(void* p,void* d,const char* key){auto* c=static_cast<Context*>(p);int k=key_id(key),n=21+k;c->event(12,token(d),k,n);return object(n);}
static void set(void* p,void* d,const char* key,void* value){auto* c=static_cast<Context*>(p);int k=key_id(key),n=token(value);c->event(13,token(d),k,n);if(!d)abort();c->destination[k==3?3:k-1]=k==3?c->integer_value:n;}
static void* integer(void* p,int value){auto* c=static_cast<Context*>(p);c->integer_value=value;c->event(14,value,25);return object(25);}
static bool output(const void* p,size_t size){return fwrite(p,1,size,stdout)==size;}
static int run(Context* c){
    for(int i=0;i<9;++i){c->reader_contexts[i]={c,i+1};c->readers[i]={{c->reader_contexts+i,frames,nullptr},object(i+1)};}
    auto* h=c->h;ElastikOriginalSampleFile f{};f.channel_format=h[3];f.separate_channel_readers=h[4];f.known_frames=h[5];f.sample_format=h[6];f.sample_rate=c->rates[0];
    ElastikOriginalFileOpenState s{};s.file=&f;s.primary=reader(c,h[2]);s.paired[0]=reader(c,h[9]);s.paired[1]=reader(c,h[10]);s.path=object(h[8]);s.paired_paths[0]=object(h[11]);s.paired_paths[1]=object(h[12]);s.metadata=h[40]?object(20):nullptr;s.file_kind=h[7];
    f.reader=s.primary?&s.primary->samples:nullptr;
    const ElastikOriginalFileOpenPlatform platform{c,construct,initialize,autorelease,open_reader,operation,channels,rate,format,kind,metadata,partner,exists};
    const ElastikOriginalMetadataBinding meta{c,source,contains,get,set,integer};
    ElastikOriginalFileReader* result=nullptr;int status=0;
    if(h[0]==0)status=elastik_original_create_file_reader(&platform,object(11),&result);
    else if(h[0]==1)status=elastik_original_open_sample_file(h[1]?nullptr:&s,&platform,object(11));
    else if(h[0]==2)elastik_original_export_file_metadata(&meta,h[40]?object(20):nullptr);
    else if(h[0]==3){ElastikOriginalWave w{};w.channels=h[38];w.sample_bytes=h[36];w.data_offset=h[37];w.frames=h[39];elastik_original_export_wave_metadata(&w,&meta,h[40]?object(20):nullptr);}
    else return 3;
    const int out[]{status,token(result),token(s.primary),token(s.paired[0]),token(s.paired[1]),token(s.path),token(s.paired_paths[0]),token(s.paired_paths[1]),static_cast<int>(f.channel_format),static_cast<int>(f.sample_format),s.file_kind,f.separate_channel_readers,f.known_frames,c->destination[0],c->destination[1],c->destination[2],c->destination[3],f.reader?1:0,0,0};
    return output(out,sizeof(out))&&output(&f.sample_rate,8)&&output(&c->traces,4)&&output(c->trace,c->traces*24)&&!fflush(stdout)?0:4;
}
int main(){for(;;){Context c{};size_t n=fread(c.h,1,sizeof(c.h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(c.h)||fread(c.rates,1,sizeof(c.rates),stdin)!=sizeof(c.rates))return 2;int e=run(&c);if(e)return e;}}
