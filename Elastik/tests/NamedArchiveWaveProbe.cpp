#include "../src/OriginalWave.h"
#include "../src/OriginalWaveChunks.h"
#include "../src/OriginalWaveAdpcm.h"
#include "ArchiveNameFixture.h"
namespace NamedWaveBase {
#define main elastik_named_wave_base_main
#include "WaveProbe.cpp"
#undef main
}
namespace NamedWave {
struct Bridge;
struct WaveContext :NamedWaveBase::Context {Bridge* bridge;};
struct Bridge {ArchiveNameFixture::Context* archive;ArchiveNameFixture::File* file;WaveContext* wave;};
static int logical(Bridge* b){ElastikArchiveStatus status;int at=elastik_original_archive_open_file_position(&b->file->value,&b->archive->byte_platform,&status);if(status!=ElastikArchiveOk)abort();return at;}
static bool read(void* p,unsigned char* out,int* count){auto* b=static_cast<Bridge*>(p);int at=logical(b),wanted=*count;ElastikArchiveStatus status;b->file->last_error=ElastikArchiveOk;bool ok=elastik_original_archive_read_member(&b->file->value.member,out,count,&status);if(status!=ElastikArchiveOk||b->file->last_error!=ElastikArchiveOk)abort();b->wave->event(2,at,wanted,*count,ok);++b->wave->reads;return ok;}
static void seek(void* p,int at){auto* b=static_cast<Bridge*>(p);b->wave->event(1,at);if(elastik_original_archive_seek_member(&b->file->value.member,at)!=ElastikArchiveOk)abort();}
static int position(void* p){auto* b=static_cast<Bridge*>(p);int at=logical(b);b->wave->event(3,at);return at;}
static int length(void* p){auto* b=static_cast<Bridge*>(p);int n=elastik_original_archive_file_size(&b->archive->path);b->wave->event(4,n);return n;}
static bool open(void* p){auto* b=static_cast<Bridge*>(p);b->wave->event(5,b->file?1:0);return b->file!=nullptr;}
static void retain(void* p){static_cast<Bridge*>(p)->wave->event(6);}
static void diagnostic(void* p,int code,int a,int c){static_cast<Bridge*>(p)->wave->event(7,code,a,c);}
static void* read_data(void* p,int n){auto* c=static_cast<WaveContext*>(static_cast<NamedWaveBase::Context*>(p));auto* d=NamedWaveBase::node(c,ElastikWaveData,nullptr,n);if(!n)return d;int actual=n;if(!read(c->bridge,d->data,&actual))return nullptr;d->length=actual;return d;}
static int run(const int* h){
    auto* a=static_cast<ArchiveNameFixture::Context*>(calloc(1,sizeof(ArchiveNameFixture::Context)));a->raw=static_cast<unsigned char*>(malloc(h[0]+1));a->path_units=static_cast<uint16_t*>(calloc(h[1]+1,2));if(fread(a->raw,1,h[0],stdin)!=static_cast<size_t>(h[0])||fread(a->path_units,2,h[1],stdin)!=static_cast<size_t>(h[1]))return 2;
    const int named[]{h[0],h[1],h[7],0,h[2],1,h[6],1,0,0,0,0,0,0,0,0};if(ArchiveNameFixture::prepare(a,named)!=ElastikArchiveOk)return 3;
    ElastikArchiveStatus file_status;auto* result=elastik_original_archive_open_file(&a->path,&a->factory,&file_status);if(file_status!=ElastikArchiveOk)return 3;a->current=ArchiveNameFixture::file_id(a,result);auto* file=a->current?a->files[a->current-1]:nullptr;
    auto* c=static_cast<WaveContext*>(calloc(1,sizeof(WaveContext)));c->maximum=-1;c->fail_read=-1;c->open_ok=file?1:0;Bridge bridge{a,file,c};c->bridge=&bridge;
    ElastikOriginalWave w{};w.metadata=NamedWaveBase::node(c,ElastikWaveDictionary);memset(w.coefficients,0xa5,sizeof(w.coefficients));
    const ElastikOriginalWaveIO io{{&bridge,seek,read},open,retain,position,length,false,diagnostic};
    const ElastikOriginalWaveObjects objects{static_cast<NamedWaveBase::Context*>(c),NamedWaveBase::create,NamedWaveBase::set,NamedWaveBase::get,NamedWaveBase::append,NamedWaveBase::count,NamedWaveBase::bytes,NamedWaveBase::resize,read_data,NamedWaveBase::decode,NamedWaveBase::chunk_name,NamedWaveBase::allocate_dvi};
    int status=elastik_original_wave_open(&w,&io,&objects);int channels=0,frames=0;float** outputs=nullptr;unsigned char* buffer=nullptr;
    if(status==ElastikWaveOk){
        channels=w.channels;frames=h[4];outputs=static_cast<float**>(calloc(channels,sizeof(float*)));for(int ch=0;ch<channels;++ch){outputs[ch]=static_cast<float*>(malloc((frames+16)*4));for(int i=0;i<frames+16;++i)outputs[ch][i]=0.03125f;}
        buffer=static_cast<unsigned char*>(malloc(h[5]));memset(buffer,0xa5,h[5]);ElastikOriginalReadBuffer b{buffer,h[5]};const ElastikOriginalReaderDiagnostics d{static_cast<NamedWaveBase::Context*>(c),NamedWaveBase::read_failed,NamedWaveBase::format_failed};const ElastikOriginalWaveReadPlatform platform{static_cast<NamedWaveBase::Context*>(c),NamedWaveBase::allocate_block,NamedWaveBase::release_block};status=elastik_original_read_wave(&w,&b,outputs,h[3],frames,&io.bytes,&platform,&d,&io);
    }
    const int summary[]{status,w.stream_open,w.block_align,w.channels,w.bits,w.format,w.sample_bytes,w.sample_rate,w.frames,w.average_bytes,w.data_offset,w.ms_samples_per_block,w.ms_block_bytes,w.ms_coefficient_count,w.dvi_values_per_block,w.dvi_block_bytes,w.dvi_samples?1:0,static_cast<int>(elastik_original_wave_sample_format(&w)),static_cast<int>(elastik_original_wave_channel_format(&w)),elastik_original_wave_frames(&w)};
    const unsigned char zero_chunk[9]{};bool ok=NamedWaveBase::output(summary,sizeof(summary))&&NamedWaveBase::output(w.coefficients,sizeof(w.coefficients))&&NamedWaveBase::output(zero_chunk,9)&&NamedWaveBase::serialize(static_cast<NamedWaveBase::Node*>(w.metadata))&&NamedWaveBase::output(&c->traces,4)&&NamedWaveBase::output(c->trace,c->traces*20);
    const int audio[]{channels,frames,buffer?h[5]:0};ok=ok&&NamedWaveBase::output(audio,sizeof(audio));for(int ch=0;ch<channels;++ch)ok=ok&&NamedWaveBase::output(outputs[ch],(frames+16)*4);if(buffer)ok=ok&&NamedWaveBase::output(buffer,h[5]);
    const int state[]{static_cast<int>(a->path.index),a->path.unresolved?1:0,a->depth,a->current,a->file_count,a->path_releases,a->path_retains};const int physical[]{a->pos[0],a->pos[1]};ok=ok&&NamedWaveBase::output(state,sizeof(state))&&NamedWaveBase::output(physical,8)&&ArchiveNameFixture::snapshot(a);
    for(int ch=0;ch<channels;++ch){free(outputs[ch]);}free(outputs);free(buffer);for(int i=0;i<c->node_count;++i){auto* n=c->nodes[i];if(n->kind==1)for(int j=0;j<n->length;++j)free(n->keys[j]);free(n->keys);free(n->items);free(n->data);free(n);}for(int i=0;i<c->allocation_count;++i){free(c->allocations[i]);}free(c);ArchiveNameFixture::cleanup(a);return ok&&!fflush(stdout)?0:4;
}
}
int main(){for(;;){int h[8];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=NamedWave::run(h);if(e)return e;}}
