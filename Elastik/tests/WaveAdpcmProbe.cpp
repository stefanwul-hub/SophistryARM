#include "../src/OriginalWaveAdpcm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Context {
    unsigned char* raw;int size,position=0,reads=0,maximum,fail,read_ok;
    unsigned char* allocations[16];int allocated=0,released=0;
    int trace[8192][5];int traces=0;
    void event(int a,int b=0,int c=0,int d=0,int e=0){if(traces>=8192){abort();}const int row[]{a,b,c,d,e};memcpy(trace[traces++],row,20);}
};
static void seek(void* p,int at){auto* c=static_cast<Context*>(p);c->event(1,at);c->position=at;}
static bool read(void* p,unsigned char* destination,int* count){
    auto* c=static_cast<Context*>(p);int wanted=*count,actual=0;
    if(c->position>=0&&c->position<c->size){actual=c->size-c->position;if(actual>wanted)actual=wanted;if(c->maximum>=0&&actual>c->maximum)actual=c->maximum;}
    if(actual)memcpy(destination,c->raw+c->position,actual);
    bool ok=c->read_ok&&c->reads!=c->fail;c->event(2,c->position,wanted,actual,ok);++c->reads;c->position+=actual;*count=actual;return ok;
}
static unsigned char* allocate(void* p,int n){auto* c=static_cast<Context*>(p);if(c->allocated>=16)abort();auto* b=static_cast<unsigned char*>(malloc(n+1));memset(b,0xa5,n);c->allocations[c->allocated++]=b;c->event(3,n,c->allocated);return b;}
static void release(void* p,unsigned char* b){auto* c=static_cast<Context*>(p);for(int i=0;i<c->allocated;++i)if(c->allocations[i]==b){++c->released;c->event(4,i+1);return;}abort();}
static void codec_diag(void* p,int code,int,int){if(code!=5)abort();static_cast<Context*>(p)->event(5,code);}
static void read_diag(void* p,int wanted,int at,int actual){static_cast<Context*>(p)->event(6,wanted,at,actual);}
static void format_diag(void* p,int code){static_cast<Context*>(p)->event(7,code);}
static bool output(const void* p,size_t n){return fwrite(p,1,n,stdout)==n;}
static int run(const int* h){
    ElastikOriginalWave w{};w.format=h[2];w.channels=h[3];w.ms_samples_per_block=h[4];w.ms_block_bytes=h[5];w.dvi_values_per_block=h[4];w.dvi_block_bytes=h[5];w.data_offset=h[14];w.bits=h[2]==3?32:16;w.sample_bytes=w.bits/8;
    if(fread(w.coefficients,1,sizeof(w.coefficients),stdin)!=sizeof(w.coefficients))return 2;
    auto* storage=static_cast<float*>(malloc(h[3]*h[9]*4));if(fread(storage,1,h[3]*h[9]*4,stdin)!=static_cast<size_t>(h[3]*h[9]*4))return 2;
    auto* raw=static_cast<unsigned char*>(malloc(h[1]+1));if(fread(raw,1,h[1],stdin)!=static_cast<size_t>(h[1]))return 2;
    auto* ctx=static_cast<Context*>(calloc(1,sizeof(Context)));ctx->raw=raw;ctx->size=h[1];ctx->maximum=h[11];ctx->fail=h[12];ctx->read_ok=h[13];
    float* outputs[8]{};for(int c=0;c<h[3];++c)if(!(h[10]&(1<<c)))outputs[c]=storage+c*h[9]+(h[0]==2?h[8]:0);
    const int scratch_values=(h[0]==1||h[2]==17)?h[3]*h[4]:0;
    auto* scratch=static_cast<short*>(malloc((scratch_values+16)*2));memset(scratch,0xa5,(scratch_values+16)*2);w.dvi_samples=scratch_values?scratch+8:nullptr;
    auto* buffer=static_cast<unsigned char*>(malloc(h[15]+1));memset(buffer,0xa5,h[15]);ElastikOriginalReadBuffer pcm{buffer,h[15]};
    const ElastikOriginalByteIO io{ctx,seek,read};const ElastikOriginalWaveIO diagnostics{io,nullptr,nullptr,nullptr,nullptr,false,codec_diag};
    const ElastikOriginalReaderDiagnostics reader_diagnostics{ctx,read_diag,format_diag};const ElastikOriginalWaveReadPlatform platform{ctx,allocate,release};
    unsigned char before[sizeof(w)];memcpy(before,&w,sizeof(w));int status=0;
    if(h[0]==0)elastik_original_decode_ms_adpcm(&w,raw,h[6],h[7],outputs,h[8]);
    else if(h[0]==1)elastik_original_decode_dvi_adpcm(&w,raw,h[6],h[7],outputs,h[8],&diagnostics);
    else status=elastik_original_read_wave(&w,&pcm,outputs,h[6],h[7],&io,&platform,&reader_diagnostics,&diagnostics);
    if(memcmp(before,&w,sizeof(w)))abort();
    const int state[]{status,ctx->allocated,ctx->released,ctx->position,scratch_values};
    bool ok=output(state,20)&&output(storage,h[3]*h[9]*4)&&output(scratch,(scratch_values+16)*2)&&output(buffer,h[15])&&output(raw,h[1])&&output(&ctx->traces,4)&&output(ctx->trace,ctx->traces*20);
    for(int i=0;i<ctx->allocated;++i)free(ctx->allocations[i]);
    free(ctx);free(raw);free(storage);free(scratch);free(buffer);return ok&&fflush(stdout)==0?0:4;
}
int main(){for(;;){int h[16];size_t n=fread(h,1,64,stdin);if(!n&&feof(stdin))return 0;if(n!=64)return 2;int e=run(h);if(e)return e;}}
