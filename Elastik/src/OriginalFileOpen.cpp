#include "OriginalFileOpen.h"

static int bits_i32(unsigned n) noexcept {int v;__builtin_memcpy(&v,&n,4);return v;}
static void retain(const ElastikOriginalFileOpenPlatform* p,ElastikOriginalFileReader* r) noexcept {
    if(r)p->object_operation(p->context,1,r->identity);
}
static void replace_path(const ElastikOriginalFileOpenPlatform* p,void** location,void* value) noexcept {
    if(*location==value)return;
    if(*location)p->object_operation(p->context,2,*location);
    *location=value;
    if(value)p->object_operation(p->context,1,value);
}
static void publish_pair(ElastikOriginalFileOpenState* s,int index,ElastikOriginalFileReader* r) noexcept {
    s->paired[index]=r;
    s->channel_readers[index]=r?&r->samples:nullptr;
}

extern "C" ElastikOriginalFileStatus elastik_original_create_file_reader(
    const ElastikOriginalFileOpenPlatform* p,void* path,ElastikOriginalFileReader** result) noexcept {
    *result=nullptr;
    for(int format=0;format<4;++format){
        auto* reader=p->autorelease(p->context,p->initialize(p->context,p->construct(p->context,format)));
        if(!reader)continue;
        const auto status=p->open(p->context,reader,path);
        if(status==ElastikFileOk){*result=reader;return status;}
        if(status!=ElastikFileUnsupported)return status;
    }
    // Original fifth pass has a null reader, then throws Unsupported. Its GN
    // exception-frame push/pop has no reader/object side effects.
    return ElastikFileUnsupported;
}

extern "C" ElastikOriginalFileStatus elastik_original_open_sample_file(
    ElastikOriginalFileOpenState* s,const ElastikOriginalFileOpenPlatform* p,void* path) noexcept {
    if(!s||s->primary)return ElastikFileAssertion;
    auto* f=s->file;
    ElastikOriginalFileReader* reader=nullptr;
    const auto status=elastik_original_create_file_reader(p,path,&reader);
    if(status!=ElastikFileOk)return status;
    s->primary=reader;f->reader=reader?&reader->samples:nullptr;
    if(!reader)return ElastikFileUnsupported;
    retain(p,reader);
    f->channel_format=p->channels(p->context,reader);
    f->sample_rate=p->sample_rate(p->context,reader);
    f->sample_format=p->sample_format(p->context,reader);
    s->file_kind=p->file_kind(p->context,reader);
    p->export_metadata(p->context,reader,s->metadata);
    replace_path(p,&s->path,path);
    if(f->channel_format!=1)return ElastikFileOk;
    int side=0;
    void* partner=p->find_mono_partner(p->context,path,&side);
    if(!partner||!p->path_exists(p->context,partner))return ElastikFileOk;
    reader=nullptr;
    const auto paired_status=elastik_original_create_file_reader(p,partner,&reader);
    if(paired_status!=ElastikFileOk)return paired_status;
    publish_pair(s,1,reader);
    if(!reader)return ElastikFileOk;
    // Separate statements force the original candidate-before-primary getter
    // order. NaNs fail ==, as on the original UCOMISD/JP sequence.
    const double candidate_rate=p->sample_rate(p->context,reader);
    const double primary_rate=p->sample_rate(p->context,s->primary);
    bool match=candidate_rate==primary_rate;
    if(match){
        const unsigned a=p->sample_format(p->context,reader);
        const unsigned b=p->sample_format(p->context,s->primary);
        match=a==b;
    }
    if(match){
        const int a=reader->samples.frame_count(reader->samples.context);
        const int b=s->primary->samples.frame_count(s->primary->samples.context);
        match=a==b;
    }
    if(!match){publish_pair(s,1,nullptr);return ElastikFileOk;}
    if(side==1){
        publish_pair(s,0,reader);publish_pair(s,1,s->primary);
        replace_path(p,&s->paired_paths[0],partner);replace_path(p,&s->paired_paths[1],path);
    }else{
        publish_pair(s,0,s->primary);
        replace_path(p,&s->paired_paths[0],path);replace_path(p,&s->paired_paths[1],partner);
    }
    f->separate_channel_readers=1;f->channel_format=2;f->channel_readers=s->channel_readers;
    retain(p,s->paired[1]);retain(p,s->paired[0]);
    return ElastikFileOk;
}

extern "C" void elastik_original_ensure_file_cache(
    ElastikOriginalSampleFile* file,ElastikOriginalCacheLifecycle** owner,
    void* context,ElastikOriginalCacheLifecycle* (*construct)(void*),
    ElastikOriginalCacheScratch* scratch) noexcept {
    if(file->cache)return;
    auto* cache=construct(context);*owner=cache;file->cache=cache->cache;
    elastik_original_sound_cache_configure(cache,file,scratch);
    elastik_original_cache_start(cache);
}

extern "C" void elastik_original_export_file_metadata(
    const ElastikOriginalMetadataBinding* p,void* destination) noexcept {
    if(!destination||!p->source(p->context))return;
    const char* keys[]{"chunks","privateChunks"};
    for(const char* key:keys){
        void* source=p->source(p->context);
        if(p->contains(p->context,source,key)){
            source=p->source(p->context);
            void* value=p->get(p->context,source,key);
            p->set(p->context,destination,key,value);
        }
    }
}

extern "C" void elastik_original_export_wave_metadata(
    const ElastikOriginalWave* w,const ElastikOriginalMetadataBinding* p,void* destination) noexcept {
    elastik_original_export_file_metadata(p,destination);
    if(w->sample_bytes){
        const int denominator=bits_i32(static_cast<unsigned>(w->channels)*static_cast<unsigned>(w->sample_bytes));
        const int adjusted=bits_i32(static_cast<unsigned>(elastik_original_wave_frames(w))-
            static_cast<unsigned>(w->data_offset/denominator));
        p->set(p->context,destination,"Melodyne1WaveSampleCount",p->integer(p->context,adjusted));
    }
}
