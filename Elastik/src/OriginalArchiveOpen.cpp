#include "OriginalArchiveOpen.h"
extern "C" int elastik_original_archive_open_read(
    ElastikOriginalArchiveContainer* a,void* path,
    const ElastikOriginalArchiveOpenPlatform* p) noexcept {
    if(a->file)return ElastikArchiveAssertion;
    a->core->read_only=true;
    a->file=p->read_file(p->context,path);
    if(a->file)a->file->retain(a->file->context);
    if(!a->file)return ElastikArchiveCannotOpen;
    a->core->file_bytes=static_cast<uint64_t>(static_cast<int64_t>(p->file_size(p->context,path)));
    a->core->stream=a->file;
    return elastik_original_archive_parse(a->core);
}
extern "C" ElastikOriginalArchivePath* elastik_original_archive_path_for_core(
    ElastikOriginalArchive* core,void* owner,void* string,
    const ElastikOriginalArchiveOpenPlatform* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;
    auto* path=p->construct_path(p->context);
    if(p->string_length(p->context,string)<1||p->character(p->context,string,0)!='/'){
        *status=ElastikArchiveAssertion;return nullptr;
    }
    path->archive=core;path->index=0;path->unresolved=p->retain_string(p->context,string);
    core->lock(core->context);
    if(core->stream)path->resolve(path->context,path);
    core->unlock(core->context);
    p->retain_owner(p->context,owner);return path;
}
extern "C" ElastikOriginalArchivePath* elastik_original_archive_path_for_container(
    ElastikOriginalArchiveContainer* a,void* path,
    const ElastikOriginalArchiveOpenPlatform* p,ElastikArchiveStatus* status) noexcept {
    return elastik_original_archive_path_for_core(a->core,a->owner,path,p,status);
}
