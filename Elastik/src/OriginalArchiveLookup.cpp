#include "OriginalArchiveLookup.h"
extern "C" void elastik_original_archive_resolve_path(ElastikOriginalArchivePath* p,
    const ElastikOriginalArchiveStrings* s) noexcept {
    if(!p->unresolved)return;
    if(s->length(s->context,p->unresolved)<2)p->index=0;
    else{
        void* parts=s->split_slashes(s->context,p->unresolved);
        uint32_t parent=0,index=1;
        for(uint32_t part=0;part<s->count(s->context,parts);++part){
            void* name=s->at(s->context,parts,part);auto* a=p->archive;
            uint32_t entry=0;
            for(;;){
                if(entry>=a->entry_count)return;
                const auto& e=a->entries[entry];
                if(e.parent==parent&&e.length_bits&&s->equal(s->context,e.name,name)){index=entry+1;break;}
                ++entry;
            }
            parent=index;
        }
        // Original empty split result selects index 1, unlike a short path.
        p->index=index;
    }
    if(p->unresolved){s->release(s->context,p->unresolved);p->unresolved=nullptr;}
}
extern "C" ElastikOriginalArchiveOpenFile* elastik_original_archive_open_file(
    ElastikOriginalArchivePath* path,const ElastikOriginalArchiveFactory* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;auto* a=path->archive;a->lock(a->context);
    if(a->stream){
        path->resolve(path->context,path);
        const uint32_t index=path->index;
        if(index){
            const uint64_t length=a->entries[index-1].length_bits;
            if(length&&!(length>>63)){
                auto* f=p->autorelease(p->context,p->initialize(p->context,p->construct(p->context)));
                f->member.path=p->retain_path(p->context,path);
                if(a->read_only)*status=elastik_original_archive_bind_member(&f->member,a->stream);
                else{
                    void* data=elastik_original_archive_read_data(a,path->index,p->data,status);
                    if(*status!=ElastikArchiveOk)return nullptr;
                    *status=elastik_original_byte_file_bind_data(&f->base,data,p->byte_file);
                }
                if(*status!=ElastikArchiveOk)return nullptr;
                a->unlock(a->context);return f;
            }
        }
    }
    a->unlock(a->context);return nullptr;
}
extern "C" int elastik_original_archive_open_file_position(
    const ElastikOriginalArchiveOpenFile* f,const ElastikOriginalByteFilePlatform* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;
    if(f->member.backing){int n;const uint32_t low=static_cast<uint32_t>(f->member.position);__builtin_memcpy(&n,&low,4);return n;}
    return elastik_original_byte_file_position(&f->base,p,status);
}
