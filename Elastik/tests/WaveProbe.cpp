#include "../src/OriginalWave.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {int kind,length,capacity;unsigned char* data;Node** items;char** keys;};
struct Context {
    const unsigned char* raw;int size,position=0,reads=0,fail_read,maximum,flags,open_ok;
    Node* nodes[2048];int node_count=0;void* allocations[128];int allocation_count=0;
    int trace[16384][5];int traces=0;
    void event(int a,int b=0,int c=0,int d=0,int e=0){if(traces>=16384){abort();}const int row[]{a,b,c,d,e};memcpy(trace[traces++],row,20);}
};
static Node* node(Context* c,int kind,const void* bytes=nullptr,int length=0){
    if(c->node_count>=2048){abort();}auto* n=static_cast<Node*>(calloc(1,sizeof(Node)));if(!n){abort();}n->kind=kind;n->length=length;
    if(kind>=3){n->data=static_cast<unsigned char*>(calloc(static_cast<size_t>(length)+1,1));if(bytes&&length)memcpy(n->data,bytes,length);}
    c->nodes[c->node_count++]=n;return n;
}
static void capacity(Node* n,int wanted){
    if(wanted<=n->capacity)return;
    n->capacity=wanted+8;n->items=static_cast<Node**>(realloc(n->items,n->capacity*sizeof(Node*)));n->keys=static_cast<char**>(realloc(n->keys,n->capacity*sizeof(char*)));
    if(!n->items||!n->keys)abort();
}
static void* create(void* p,int kind,const void* bytes,int length){return node(static_cast<Context*>(p),kind,bytes,length);}
static void set(void*,void* d,const char* key,void* value){
    auto* n=static_cast<Node*>(d);int at=0;while(at<n->length&&strcmp(n->keys[at],key)<0)++at;
    if(at<n->length&&!strcmp(n->keys[at],key)){
        if(value)n->items[at]=static_cast<Node*>(value);
        else{free(n->keys[at]);for(int i=at+1;i<n->length;++i){n->keys[i-1]=n->keys[i];n->items[i-1]=n->items[i];}--n->length;}return;
    }
    if(!value)return;
    capacity(n,n->length+1);
    for(int i=n->length;i>at;--i){n->keys[i]=n->keys[i-1];n->items[i]=n->items[i-1];}
    n->keys[at]=static_cast<char*>(malloc(strlen(key)+1));strcpy(n->keys[at],key);n->items[at]=static_cast<Node*>(value);++n->length;
}
static void* get(void*,void* d,const char* key){auto* n=static_cast<Node*>(d);for(int i=0;i<n->length;++i)if(!strcmp(n->keys[i],key))return n->items[i];return nullptr;}
static void append(void*,void* a,void* value){auto* n=static_cast<Node*>(a);capacity(n,n->length+1);n->keys[n->length]=nullptr;n->items[n->length++]=static_cast<Node*>(value);}
static int count(void*,void* p){return static_cast<Node*>(p)->length;}
static unsigned char* bytes(void*,void* p){return static_cast<Node*>(p)->data;}
static void resize(void*,void* p,int n){auto* d=static_cast<Node*>(p);if(n<0||n>d->length)abort();d->length=n;}
static bool read(void* p,unsigned char* destination,int* size){
    auto* c=static_cast<Context*>(p);const int wanted=*size;int actual=0;
    if(c->position>=0&&c->position<c->size){actual=c->size-c->position;if(actual>wanted)actual=wanted;if(c->maximum>=0&&actual>c->maximum)actual=c->maximum;}
    if(actual)memcpy(destination,c->raw+c->position,actual);
    bool ok=((c->flags&2)||actual==wanted)&&c->reads!=c->fail_read;
    c->event(2,c->position,wanted,actual,ok);++c->reads;c->position+=actual;*size=actual;return ok;
}
static void seek(void* p,int position){auto* c=static_cast<Context*>(p);c->event(1,position);c->position=position;}
static int position(void* p){auto* c=static_cast<Context*>(p);c->event(3,c->position);return c->position;}
static int length(void* p){auto* c=static_cast<Context*>(p);c->event(4,c->size);return c->size;}
static bool open(void* p){auto* c=static_cast<Context*>(p);c->event(5,c->open_ok);return c->open_ok!=0;}
static void retain(void* p){static_cast<Context*>(p)->event(6);}
static void diagnostic(void* p,int code,int a,int b){static_cast<Context*>(p)->event(7,code,a,b);}
static void read_failed(void* p,int wanted,int at,int actual){static_cast<Context*>(p)->event(9,wanted,at,actual);}
static void format_failed(void* p,int code){static_cast<Context*>(p)->event(10,code);}
static void* read_data(void* p,int n){
    auto* c=static_cast<Context*>(p);auto* result=node(c,ElastikWaveData,nullptr,n);if(!n)return result;
    int actual=n;if(!read(p,result->data,&actual))return nullptr;result->length=actual;return result;
}
static void* decode(void* p,bool acid,void* data){
    // Explicit opaque subdecoder boundary, not an inst/ACID implementation.
    if(!data)return nullptr;
    auto* d=static_cast<Node*>(data);auto* c=static_cast<Context*>(p);if(c->flags&4)return nullptr;
    auto* n=node(c,7,nullptr,d->length+4);memcpy(n->data,acid?"acid":"inst",4);memcpy(n->data+4,d->data,d->length);return n;
}
static const char* chunk_name(void*,void* p){return !memcmp(static_cast<Node*>(p)->data,"acid",4)?"GNSoundFileTimeAndScaleChunk":"GNSoundFileInstrumentChunk";}
static void* allocate_dvi(void* p,int n){auto* c=static_cast<Context*>(p);c->event(8,n);if(c->flags&8)return nullptr;if(c->allocation_count>=128||n<0)abort();void* r=calloc(static_cast<size_t>(n)+1,1);c->allocations[c->allocation_count++]=r;return r;}
static bool output(const void* p,size_t n){return fwrite(p,1,n,stdout)==n;}
static bool serialize(Node* n){
    if(!n){int zero=0;return output(&zero,4);}int h[]{n->kind,n->length};if(!output(h,8))return false;
    if(n->kind>=3)return output(n->data,n->length);
    for(int i=0;i<n->length;++i){if(n->kind==1){int len=strlen(n->keys[i]);if(!output(&len,4)||!output(n->keys[i],len))return false;}if(!serialize(n->items[i]))return false;}return true;
}
static const unsigned char known_ids[]{'f','m','t',' ',0,'b','e','x','t',0,'d','a','t','a',0,'m','i','n','f',0,'r','e','g','n',0,'o','v','w','f',0,'e','l','m','1',0,'u','m','i','d',0,'P','A','D',' ',0,'i','n','s','t',0,'L','I','S','T',0,'c','u','e',' ',0,'s','m','p','l',0,'p','l','s','t',0,'w','a','v','l',0,'L','G','W','V',0,'S','y','L','p',0,'a','c','i','d',0,'s','t','r','c',0,'a','n','a','l',0,0xb5,0x4c,0xd0,0x2e,0};
static int run(const int* h){
    auto* raw=static_cast<unsigned char*>(malloc(h[1]+1));if(fread(raw,1,h[1],stdin)!=static_cast<size_t>(h[1]))return 2;
    auto* c=static_cast<Context*>(calloc(1,sizeof(Context)));c->raw=raw;c->size=h[1];c->fail_read=h[4];c->maximum=h[5];c->flags=h[15];c->open_ok=h[3];
    ElastikOriginalWave w{};w.format=h[6];w.channels=h[7];w.bits=h[8];w.sample_bytes=h[9];w.frames=h[10];memset(w.coefficients,0xa5,sizeof(w.coefficients));
    w.metadata=node(c,ElastikWaveDictionary);if(h[15]&1){int value=319;set(c,w.metadata,"preexisting",node(c,ElastikWaveInteger,&value,4));}
    const ElastikOriginalWaveIO io{{c,seek,read},open,retain,position,length,h[2]!=0,diagnostic};
    const ElastikOriginalWaveObjects objects{c,create,set,get,append,count,bytes,resize,read_data,decode,chunk_name,allocate_dvi};
    ElastikOriginalWaveChunk chunk{};int status=0;
    if(h[0]==1)status=elastik_original_wave_chunk(&io,h[11],&chunk,known_ids,21,"data");
    else if(h[0]!=2)status=elastik_original_wave_open(&w,&io,&objects);
    int channels=0,frames=0;float** outputs=nullptr;unsigned char* buffer=nullptr;
    if(h[0]==3&&status==ElastikWaveOk){
        channels=w.channels;frames=h[13];if(channels<1||channels>255||frames<0||h[14]<1)abort();
        outputs=static_cast<float**>(calloc(channels,sizeof(float*)));for(int i=0;i<channels;++i){outputs[i]=static_cast<float*>(malloc((frames+16)*4));for(int f=0;f<frames+16;++f)outputs[i][f]=0.03125f;}
        buffer=static_cast<unsigned char*>(malloc(h[14]));memset(buffer,0xa5,h[14]);ElastikOriginalReadBuffer b{buffer,h[14]};
        const ElastikOriginalReaderDiagnostics diagnostics{c,read_failed,format_failed};
        elastik_original_read_buffered_pcm(&b,outputs,h[12],frames,elastik_original_wave_sample_format(&w),elastik_original_wave_channel_format(&w),w.data_offset,&io.bytes,&diagnostics);
    }
    const int result[]{status,w.stream_open,w.block_align,w.channels,w.bits,w.format,w.sample_bytes,w.sample_rate,w.frames,w.average_bytes,w.data_offset,w.ms_samples_per_block,w.ms_block_bytes,w.ms_coefficient_count,w.dvi_values_per_block,w.dvi_block_bytes,w.dvi_samples?1:0,
        static_cast<int>(elastik_original_wave_sample_format(&w)),static_cast<int>(elastik_original_wave_channel_format(&w)),elastik_original_wave_frames(&w)};
    bool ok=output(result,sizeof(result))&&output(w.coefficients,sizeof(w.coefficients))&&output(chunk.id,5)&&output(&chunk.bytes,4)&&serialize(static_cast<Node*>(w.metadata))&&output(&c->traces,4)&&output(c->trace,c->traces*20);
    const int audio[]{channels,frames,buffer?h[14]:0};ok=ok&&output(audio,sizeof(audio));
    for(int i=0;i<channels;++i){ok=ok&&output(outputs[i],(frames+16)*4);free(outputs[i]);}if(buffer)ok=ok&&output(buffer,h[14]);
    free(outputs);free(buffer);
    for(int i=0;i<c->node_count;++i){auto* n=c->nodes[i];if(n->kind==1)for(int j=0;j<n->length;++j)free(n->keys[j]);free(n->keys);free(n->items);free(n->data);free(n);}
    for(int i=0;i<c->allocation_count;++i)free(c->allocations[i]);
    free(c);free(raw);return ok&&fflush(stdout)==0?0:4;
}
int main(){for(;;){int h[16];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=run(h);if(e)return e;}}
