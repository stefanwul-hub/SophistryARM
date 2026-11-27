#include "OriginalByteFile.h"
static int i32(uint32_t n) noexcept {int v;__builtin_memcpy(&v,&n,4);return v;}
extern "C" ElastikArchiveStatus elastik_original_byte_file_bind_data(
    ElastikOriginalByteFile* f,void* data,const ElastikOriginalByteFilePlatform* p) noexcept {
    if(f->data!=data){
        if(f->data)p->object_operation(p->context,2,f->data);
        f->data=data;if(data)p->object_operation(p->context,1,data);
    }
    const auto status=p->lock_data(p->context,f->data);if(status!=ElastikArchiveOk)return status;
    f->position=0;f->length=p->data_length(p->context,data);return ElastikArchiveOk;
}
extern "C" bool elastik_original_byte_file_read(ElastikOriginalByteFile* f,
    unsigned char* out,int* count,const ElastikOriginalByteFilePlatform* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;
    if(!f||!out||!count||*count<0){*status=ElastikArchiveAssertion;return false;}
    if(!f->data){
        if(f->fork){
            int actual=*count;
            if(!p->read_fork(p->context,f->fork,*count,out,&actual))return true;
            *count=0;
        }
        return false;
    }
    int take=*count;
    if(f->length<i32(static_cast<uint32_t>(f->position)+static_cast<uint32_t>(take))){
        take=i32(static_cast<uint32_t>(f->length)-static_cast<uint32_t>(f->position));*count=take;
    }
    if(take>0){
        const auto* bytes=p->data_bytes(p->context,f->data);
        __builtin_memcpy(out,bytes+f->position,static_cast<unsigned>(take));
        f->position=i32(static_cast<uint32_t>(f->position)+static_cast<uint32_t>(*count));return true;
    }
    *count=0;return false;
}
extern "C" int elastik_original_byte_file_position(const ElastikOriginalByteFile* f,
    const ElastikOriginalByteFilePlatform* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;if(!f){*status=ElastikArchiveAssertion;return 0;}
    if(f->data)return f->position;
    if(!f->fork){*status=ElastikArchiveAssertion;return 0;}
    uint64_t at=0;
    return p->get_fork_position(p->context,f->fork,&at)?0:i32(static_cast<uint32_t>(at));
}
extern "C" ElastikArchiveStatus elastik_original_byte_file_seek(ElastikOriginalByteFile* f,
    int offset,const ElastikOriginalByteFilePlatform* p) noexcept {
    if(!f||offset<0)return ElastikArchiveAssertion;
    if(f->data){f->position=offset;return ElastikArchiveOk;}
    if(!f->fork)return ElastikArchiveAssertion;
    (void)p->set_fork_position(p->context,f->fork,1,offset);return ElastikArchiveOk;
}
extern "C" int elastik_original_byte_file_end(ElastikOriginalByteFile* f,
    const ElastikOriginalByteFilePlatform* p,ElastikArchiveStatus* status) noexcept {
    *status=ElastikArchiveOk;if(!f){*status=ElastikArchiveAssertion;return 0;}
    if(f->data){f->position=f->length;return f->length;}
    if(!f->fork){*status=ElastikArchiveAssertion;return 0;}
    if(p->set_fork_position(p->context,f->fork,2,0))return 0;
    uint64_t at=0;return p->get_fork_position(p->context,f->fork,&at)?0:i32(static_cast<uint32_t>(at));
}
