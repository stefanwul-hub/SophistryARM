#include "OriginalFileArchive.h"

static int i32(uint32_t n) noexcept {int v;__builtin_memcpy(&v,&n,4);return v;}
static uint32_t be32(const unsigned char* b) noexcept {
    uint32_t n=0;for(int i=0;i<4;++i)n=(n<<8)|b[i];return n;
}
static uint64_t be64(const unsigned char* b) noexcept {
    uint64_t n=0;for(int i=0;i<8;++i)n=(n<<8)|b[i];return n;
}
static uint64_t extend_count(int count) noexcept {return static_cast<uint64_t>(static_cast<int64_t>(count));}
static bool positive(uint64_t n) noexcept {return n!=0&&(n>>63)==0;}

extern "C" ElastikArchiveStatus elastik_original_archive_parse(ElastikOriginalArchive* a) noexcept {
    auto* s=a->stream;unsigned char header[20];int count=20;
    s->seek(s->context,0);
    if(!s->read(s->context,header,&count)||count!=20)return ElastikArchiveUnsupported;
    if(__builtin_memcmp(header,"GNFA",4))return ElastikArchiveUnsupported;
    a->header_bytes=be32(header+4);a->version=be32(header+8);
    if(a->header_bytes<20)return ElastikArchiveUnsupported;
    a->directory_layout=be32(header+12);a->entry_count=be32(header+16);
    uint64_t at=a->header_bytes;
    if(a->entry_count){
        a->entries=a->allocate_entries(a->context,a->entry_count);
        __builtin_memset(a->entries,0,sizeof(ElastikOriginalArchiveEntry)*a->entry_count);
    }
    if(a->directory_layout)a->read_only=true;
    for(uint32_t i=0;i<a->entry_count;++i){
        s->seek(s->context,i32(static_cast<uint32_t>(at)));
        if(a->file_bytes<at)return ElastikArchiveUnsupported;
        unsigned char raw[556];count=556;
        if(!s->read(s->context,raw,&count)||count!=556)return ElastikArchiveCorrupted;
        auto& e=a->entries[i];e.record_offset=at;
        e.record_bytes=be32(raw);e.flags=be32(raw+4);e.length_bits=be64(raw+8);e.storage=be64(raw+16);
        e.field6=be32(raw+24);e.field7=be32(raw+28);e.parent=be32(raw+32);
        for(int n=0;n<256;++n)e.name_units[n]=static_cast<uint16_t>((raw[36+n*2]<<8)|raw[37+n*2]);
        int units=0;while(units<256&&e.name_units[units])++units;
        if(units)e.name=a->create_name(a->context,e.name_units,units);
        e.timestamp=be64(raw+548);
        if(a->directory_layout){e.data_offset=e.storage;at+=e.record_bytes;}
        else{e.data_offset=at+e.record_bytes;at+=static_cast<uint64_t>(e.record_bytes)+e.storage;}
    }
    return ElastikArchiveOk;
}

extern "C" bool elastik_original_archive_is_file(ElastikOriginalArchivePath* p) noexcept {
    auto* a=p->archive;a->lock(a->context);
    bool result=false;
    if(a->stream){p->resolve(p->context,p);if(!p->unresolved&&p->index)result=positive(a->entries[p->index-1].length_bits);}
    a->unlock(a->context);return result;
}
extern "C" uint32_t elastik_original_archive_file_size(ElastikOriginalArchivePath* p) noexcept {
    auto* a=p->archive;a->lock(a->context);
    uint32_t result=0;
    if(a->stream){p->resolve(p->context,p);if(!p->unresolved&&p->index){const uint64_t n=a->entries[p->index-1].length_bits;if(!(n>>63))result=static_cast<uint32_t>(n);}}
    a->unlock(a->context);return result;
}
static ElastikOriginalArchiveEntry* descriptor(ElastikOriginalArchivePath* p) noexcept {
    if(!p->archive->stream)return nullptr;
    p->resolve(p->context,p);if(p->unresolved)return nullptr;
    // Valid nonzero resolved index is the original caller contract. An
    // unresolved path is an assertion, not an empty-file success.
    return p->archive->entries+p->index-1;
}
extern "C" ElastikArchiveStatus elastik_original_archive_bind_member(
    ElastikOriginalArchiveMember* m,ElastikOriginalArchiveStream* source) noexcept {
    auto* a=m->path->archive;
    if(!a->force_shared&&source->can_clone(source->context)){
        auto* e=descriptor(m->path);if(!e)return ElastikArchiveAssertion;
        void* path=source->path(source->context);m->backing=source->open_path(source->context,path);
        if(!m->backing)return ElastikArchiveAssertion;
        m->backing->seek(m->backing->context,i32(static_cast<uint32_t>(e->data_offset)));m->shared=false;
    }else{m->backing=source;m->shared=true;}
    if(m->backing)m->backing->retain(m->backing->context);
    return ElastikArchiveOk;
}
extern "C" bool elastik_original_archive_read_member(ElastikOriginalArchiveMember* m,
    unsigned char* out,int* count,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;
    if(!m->backing)return m->base->read(m->base->context,out,count);
    auto* e=descriptor(m->path);if(!e){*status=ElastikArchiveAssertion;return false;}
    const int wanted=*count;
    if(m->position+extend_count(*count)>e->length_bits)
        *count=i32(static_cast<uint32_t>(e->length_bits)-static_cast<uint32_t>(m->position));
    auto* s=m->backing;bool ok;
    if(m->shared){
        auto* a=m->path->archive;a->lock(a->context);
        const int saved=s->position(s->context);
        s->seek(s->context,i32(static_cast<uint32_t>(e->data_offset)+static_cast<uint32_t>(m->position)));
        ok=s->read(s->context,out,count);s->seek(s->context,saved);a->unlock(a->context);
    }else ok=s->read(s->context,out,count);
    m->position+=extend_count(*count);
    if(*count>0&&wanted==*count)return ok;
    if(*count<0)*count=0;
    return false;
}
extern "C" ElastikArchiveStatus elastik_original_archive_seek_member(
    ElastikOriginalArchiveMember* m,int offset) noexcept {
    if(!m->backing){if(offset<0)return ElastikArchiveAssertion;m->base->seek(m->base->context,offset);return ElastikArchiveOk;}
    auto* e=descriptor(m->path);if(!e)return ElastikArchiveAssertion;
    m->position=extend_count(offset);
    if(!m->shared)m->backing->seek(m->backing->context,i32(static_cast<uint32_t>(e->data_offset)+static_cast<uint32_t>(offset)));
    return ElastikArchiveOk;
}
extern "C" int elastik_original_archive_end_member(
    ElastikOriginalArchiveMember* m,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;if(!m->backing)return m->base->end(m->base->context);
    auto* e=descriptor(m->path);if(!e){*status=ElastikArchiveAssertion;return 0;}
    m->position=e->length_bits;const int end=i32(static_cast<uint32_t>(e->length_bits));
    if(!m->shared)m->backing->seek(m->backing->context,i32(static_cast<uint32_t>(e->data_offset)+static_cast<uint32_t>(e->length_bits)));
    return end;
}
extern "C" void* elastik_original_archive_read_data(ElastikOriginalArchive* a,
    uint32_t index,const ElastikOriginalArchiveData* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;
    if(!index||index>a->entry_count||!positive(a->entries[index-1].length_bits)){*status=ElastikArchiveAssertion;return nullptr;}
    const auto& e=a->entries[index-1];const int wanted=i32(static_cast<uint32_t>(e.length_bits));
    void* data=p->allocate(p->context,wanted);a->stream->seek(a->stream->context,i32(static_cast<uint32_t>(e.data_offset)));
    int count=wanted;p->lock(p->context,data);auto* bytes=p->bytes(p->context,data);
    if(!a->stream->read(a->stream->context,bytes,&count)||extend_count(count)!=e.length_bits){*status=ElastikArchiveCannotRead;return nullptr;}
    p->unlock(p->context,data);
    if(p->decode)data=p->decode(p->context,data,e.name,e.field7,e.field6);
    return data;
}
