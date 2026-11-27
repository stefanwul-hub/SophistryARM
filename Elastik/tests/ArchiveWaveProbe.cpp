#include "../src/OriginalFileArchive.h"
#include "../src/OriginalWave.h"
#include "../src/OriginalWaveChunks.h"
#include "../src/OriginalWaveAdpcm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Share the exact existing GN/I/O fixture primitives; isolate their names.
namespace ArchiveFixture {
#define ELASTIK_ARCHIVE_TRACE_CAPACITY 32768
#define main elastik_archive_fixture_main
#include "FileArchiveProbe.cpp"
#undef main
#undef ELASTIK_ARCHIVE_TRACE_CAPACITY
}
namespace WaveFixture {
#define main elastik_wave_fixture_main
#include "WaveProbe.cpp"
#undef main
}
namespace ArchiveWave {
struct Bridge;
struct WaveContext :WaveFixture::Context {Bridge* bridge;};
struct Bridge {ArchiveFixture::Context* archive;WaveContext* wave;ElastikOriginalArchiveMember* member;ElastikOriginalArchivePath* path;};
static bool read(void* p,unsigned char* out,int* count){
    auto* b=static_cast<Bridge*>(p);const int wanted=*count,at=static_cast<int>(b->member->position);
    ElastikArchiveStatus status;const bool ok=elastik_original_archive_read_member(b->member,out,count,&status);if(status!=ElastikArchiveOk)abort();
    b->wave->event(2,at,wanted,*count,ok);++b->wave->reads;return ok;
}
static void seek(void* p,int at){auto* b=static_cast<Bridge*>(p);b->wave->event(1,at);if(elastik_original_archive_seek_member(b->member,at)!=ElastikArchiveOk)abort();}
static int position(void* p){auto* b=static_cast<Bridge*>(p);const int at=static_cast<int>(b->member->position);b->wave->event(3,at);return at;}
static int length(void* p){auto* b=static_cast<Bridge*>(p);const int n=elastik_original_archive_file_size(b->path);b->wave->event(4,n);return n;}
static bool open(void* p){static_cast<Bridge*>(p)->wave->event(5,1);return true;}
static void retain(void* p){static_cast<Bridge*>(p)->wave->event(6);}
static void diagnostic(void* p,int code,int a,int c){static_cast<Bridge*>(p)->wave->event(7,code,a,c);}
static void* read_data(void* p,int n){auto* w=static_cast<WaveContext*>(static_cast<WaveFixture::Context*>(p));auto* result=WaveFixture::node(w,ElastikWaveData,nullptr,n);if(!n)return result;int actual=n;if(!read(w->bridge,result->data,&actual))return nullptr;result->length=actual;return result;}
static int run(const int* h){
    auto* a=static_cast<ArchiveFixture::Context*>(calloc(1,sizeof(ArchiveFixture::Context)));a->h[0]=h[0];a->h[10]=h[2];a->h[11]=1;a->maximum=-1;a->read_ok=1;a->fail=-1;a->pos[0]=11;a->pos[1]=17;a->pos[2]=11;
    a->raw=static_cast<unsigned char*>(malloc(h[0]+1));if(fread(a->raw,1,h[0],stdin)!=static_cast<size_t>(h[0]))return 2;
    for(int i=0;i<3;++i){a->stream_contexts[i]={a,i};a->streams[i]={a->stream_contexts+i,ArchiveFixture::seek,ArchiveFixture::read,ArchiveFixture::position,ArchiveFixture::retain,ArchiveFixture::can_clone,ArchiveFixture::path,ArchiveFixture::open_path,ArchiveFixture::end};}
    a->archive={91,92,93,0,nullptr,static_cast<uint32_t>(h[0]),false,false,a->streams,a,ArchiveFixture::allocate_entries,ArchiveFixture::create_name,ArchiveFixture::lock,ArchiveFixture::unlock};
    if(elastik_original_archive_parse(&a->archive)!=ElastikArchiveOk)return 3;
    ElastikOriginalArchivePath path{&a->archive,static_cast<uint32_t>(h[1]),nullptr,a,ArchiveFixture::resolve};
    ElastikOriginalArchiveMember member{&path,nullptr,a->streams+2,0,false};if(elastik_original_archive_bind_member(&member,a->streams)!=ElastikArchiveOk)return 3;
    auto* c=static_cast<WaveContext*>(calloc(1,sizeof(WaveContext)));c->fail_read=-1;c->maximum=-1;c->open_ok=1;Bridge bridge{a,c,&member,&path};c->bridge=&bridge;
    ElastikOriginalWave w{};w.metadata=WaveFixture::node(c,ElastikWaveDictionary);memset(w.coefficients,0xa5,sizeof(w.coefficients));
    const ElastikOriginalWaveIO io{{&bridge,seek,read},open,retain,position,length,false,diagnostic};
    const ElastikOriginalWaveObjects objects{static_cast<WaveFixture::Context*>(c),WaveFixture::create,WaveFixture::set,WaveFixture::get,WaveFixture::append,WaveFixture::count,WaveFixture::bytes,WaveFixture::resize,read_data,WaveFixture::decode,WaveFixture::chunk_name,WaveFixture::allocate_dvi};
    int status=elastik_original_wave_open(&w,&io,&objects);int channels=0,frames=0;float** outputs=nullptr;unsigned char* buffer=nullptr;
    if(status==ElastikWaveOk){
        channels=w.channels;frames=h[4];outputs=static_cast<float**>(calloc(channels,sizeof(float*)));for(int ch=0;ch<channels;++ch){outputs[ch]=static_cast<float*>(malloc((frames+16)*4));for(int i=0;i<frames+16;++i)outputs[ch][i]=0.03125f;}
        buffer=static_cast<unsigned char*>(malloc(h[5]));memset(buffer,0xa5,h[5]);ElastikOriginalReadBuffer b{buffer,h[5]};
        const ElastikOriginalReaderDiagnostics d{static_cast<WaveFixture::Context*>(c),WaveFixture::read_failed,WaveFixture::format_failed};const ElastikOriginalWaveReadPlatform platform{static_cast<WaveFixture::Context*>(c),WaveFixture::allocate_block,WaveFixture::release_block};
        status=elastik_original_read_wave(&w,&b,outputs,h[3],frames,&io.bytes,&platform,&d,&io);
    }
    const int result[]{status,w.stream_open,w.block_align,w.channels,w.bits,w.format,w.sample_bytes,w.sample_rate,w.frames,w.average_bytes,w.data_offset,w.ms_samples_per_block,w.ms_block_bytes,w.ms_coefficient_count,w.dvi_values_per_block,w.dvi_block_bytes,w.dvi_samples?1:0,static_cast<int>(elastik_original_wave_sample_format(&w)),static_cast<int>(elastik_original_wave_channel_format(&w)),elastik_original_wave_frames(&w)};
    const unsigned char chunk_id[5]{};const int chunk_bytes=0;
    bool ok=WaveFixture::output(result,sizeof(result))&&WaveFixture::output(w.coefficients,sizeof(w.coefficients))&&WaveFixture::output(chunk_id,5)&&WaveFixture::output(&chunk_bytes,4)&&WaveFixture::serialize(static_cast<WaveFixture::Node*>(w.metadata))&&WaveFixture::output(&c->traces,4)&&WaveFixture::output(c->trace,c->traces*20);
    const int audio[]{channels,frames,buffer?h[5]:0};ok=ok&&WaveFixture::output(audio,sizeof(audio));for(int ch=0;ch<channels;++ch)ok=ok&&WaveFixture::output(outputs[ch],(frames+16)*4);if(buffer)ok=ok&&WaveFixture::output(buffer,h[5]);
    const uint32_t state[]{a->archive.entry_count,static_cast<uint32_t>(member.position),static_cast<uint32_t>(member.position>>32),static_cast<uint32_t>(a->pos[0]),static_cast<uint32_t>(a->pos[1])};
    ok=ok&&WaveFixture::output(state,sizeof(state))&&WaveFixture::output(&a->traces,4)&&WaveFixture::output(a->trace,a->traces*24);
    for(int ch=0;ch<channels;++ch){free(outputs[ch]);}free(outputs);free(buffer);
    for(int i=0;i<c->node_count;++i){auto* n=c->nodes[i];if(n->kind==1)for(int j=0;j<n->length;++j)free(n->keys[j]);free(n->keys);free(n->items);free(n->data);free(n);}
    for(int i=0;i<c->allocation_count;++i){free(c->allocations[i]);}free(c);free(a->entries);free(a->raw);free(a);return ok&&!fflush(stdout)?0:4;
}
} // namespace ArchiveWave
int main(){for(;;){int h[8];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=ArchiveWave::run(h);if(e)return e;}}
