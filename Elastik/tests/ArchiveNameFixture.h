#pragma once
#include "../src/OriginalArchiveLookup.h"
#include "LegacyArchiveStringTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
namespace ArchiveNameBase {
#define ELASTIK_ARCHIVE_TRACE_CAPACITY 32768
#define main elastik_archive_name_base_main
#include "FileArchiveProbe.cpp"
#undef main
#undef ELASTIK_ARCHIVE_TRACE_CAPACITY
}
namespace ArchiveNameFixture {
struct Context;
struct File {ElastikOriginalArchiveOpenFile value;ElastikOriginalArchiveStream stream;Context* owner;int id;ElastikArchiveStatus last_error;};
struct Context :ArchiveNameBase::Context {
    uint16_t* path_units=nullptr;int path_length=0;bool path_present=false;
    unsigned char* components[512]{};int component_count=0;
    File* files[32]{};int file_count=0,current=0,depth=0,path_releases=0,path_retains=0,refs[128]{};
    ElastikOriginalArchivePath path{};ElastikOriginalArchiveStrings strings{};
    ElastikOriginalArchiveData data_platform{};ElastikOriginalByteFilePlatform byte_platform{};ElastikOriginalArchiveFactory factory{};
};
static Context* context(void* p){return static_cast<Context*>(static_cast<ArchiveNameBase::Context*>(p));}
static unsigned char character(uint16_t u){if(u>=32&&u<=126)return static_cast<unsigned char>(u);for(auto pair:legacy_archive_characters)if(pair.unicode==u)return pair.byte;return 26;}
static unsigned char* encode(const uint16_t* units,int n){auto* b=static_cast<unsigned char*>(malloc(n+1));for(int i=0;i<n;++i)b[i]=character(units[i]);b[n]=0;return b;}
static int string_length(void* p,void*){auto* c=context(p);c->event(22,c->path_length);return c->path_length;}
static void* split(void* p,void*){
    auto* c=context(p);c->event(23);for(int i=0;i<c->component_count;++i)free(c->components[i]);c->component_count=0;
    auto* bytes=encode(c->path_units,c->path_length);const auto* at=bytes;
    while(*at){const auto* end=reinterpret_cast<const unsigned char*>(strchr(reinterpret_cast<const char*>(at),'/'));if(!end)end=at+strlen(reinterpret_cast<const char*>(at));int n=end-at;
        if(n){if(c->component_count>=512)abort();auto* part=static_cast<unsigned char*>(malloc(n+1));memcpy(part,at,n);part[n]=0;c->components[c->component_count++]=part;}
        at=*end?end+1:end;
    }
    free(bytes);return reinterpret_cast<void*>(3000);
}
static uint32_t count(void* p,void*){auto* c=context(p);c->event(24,c->component_count);return c->component_count;}
static void* at(void* p,void*,uint32_t i){auto* c=context(p);c->event(25,i);return reinterpret_cast<void*>(static_cast<uintptr_t>(2000+i));}
static bool equal(void* p,void* name,void* part){
    auto* c=context(p);const int name_id=reinterpret_cast<uintptr_t>(name),component=reinterpret_cast<uintptr_t>(part)-2000;c->event(26,name_id,component);
    const ElastikOriginalArchiveEntry* entry=nullptr;for(uint32_t i=0;i<c->archive.entry_count;++i)if(c->archive.entries[i].name==name){entry=c->archive.entries+i;break;}if(!entry||!name)abort();
    int n=0;while(n<256&&entry->name_units[n])++n;auto* b=encode(entry->name_units,n);const bool result=!strcmp(reinterpret_cast<char*>(b),reinterpret_cast<char*>(c->components[component]));free(b);return result;
}
static void release_string(void* p,void*){auto* c=context(p);c->event(27);++c->path_releases;}
static void resolve(void* p,ElastikOriginalArchivePath* path){auto* c=context(p);c->event(10,path->index,path->unresolved?1:0);elastik_original_archive_resolve_path(path,&c->strings);}
static void lock(void* p){auto* c=context(p);++c->depth;c->event(7);}
static void unlock(void* p){auto* c=context(p);--c->depth;c->event(8);}
static int data_id(Context* c,void* d){return d?static_cast<ArchiveNameBase::Data*>(d)-c->data+1:0;}
static void* allocate_data(void* p,int n){auto* c=context(p);void* result=ArchiveNameBase::allocate_data(p,n);c->refs[data_id(c,result)-1]=1;return result;}
static void object(void* p,int op,void* d){auto* c=context(p);const int id=data_id(c,d);c->event(21,op,id);c->refs[id-1]+=op==1?1:-1;}
static ElastikArchiveStatus data_lock(void* p,void* d){auto* c=context(p);if(!d){c->event(12,0);return ElastikArchiveAssertion;}ArchiveNameBase::data_lock(p,d);return ElastikArchiveOk;}
static int data_length(void* p,void* d){auto* c=context(p);auto* v=ArchiveNameBase::data(p,d);c->event(28,data_id(c,d),v->size);return v->size;}
static const unsigned char* data_bytes(void* p,void* d){auto* c=context(p);c->event(29,data_id(c,d));return ArchiveNameBase::data_bytes(p,d);}
static unsigned char* mutable_data_bytes(void* p,void* d){return const_cast<unsigned char*>(data_bytes(p,d));}
static void archive_data_lock(void* p,void* d){if(data_lock(p,d)!=ElastikArchiveOk)abort();}
static int16_t no_fork_read(void*,int16_t,int,unsigned char*,int*){abort();}
static int16_t no_fork_get(void*,int16_t,uint64_t*){abort();}
static int16_t no_fork_set(void*,int16_t,int,int){abort();}
static bool base_read(void* p,unsigned char* bytes,int* n){auto* f=static_cast<File*>(p);return elastik_original_byte_file_read(&f->value.base,bytes,n,&f->owner->byte_platform,&f->last_error);}
static void base_seek(void* p,int at){auto* f=static_cast<File*>(p);f->last_error=elastik_original_byte_file_seek(&f->value.base,at,&f->owner->byte_platform);}
static int base_position(void* p){auto* f=static_cast<File*>(p);return elastik_original_byte_file_position(&f->value.base,&f->owner->byte_platform,&f->last_error);}
static int base_end(void* p){auto* f=static_cast<File*>(p);return elastik_original_byte_file_end(&f->value.base,&f->owner->byte_platform,&f->last_error);}
static ElastikOriginalArchiveOpenFile* construct(void* p){auto* c=context(p);if(c->file_count>=32)abort();auto* f=static_cast<File*>(calloc(1,sizeof(File)));f->owner=c;f->id=c->file_count+1;c->files[c->file_count++]=f;f->stream={f,base_seek,base_read,base_position,nullptr,nullptr,nullptr,nullptr,base_end};f->value.member.base=&f->stream;c->event(17,f->id);return &f->value;}
static int file_id(Context* c,const ElastikOriginalArchiveOpenFile* f){for(int i=0;i<c->file_count;++i)if(&c->files[i]->value==f)return i+1;return 0;}
static ElastikOriginalArchiveOpenFile* initialize(void* p,ElastikOriginalArchiveOpenFile* f){auto* c=context(p);c->event(18,file_id(c,f));return f;}
static ElastikOriginalArchiveOpenFile* autorelease(void* p,ElastikOriginalArchiveOpenFile* f){auto* c=context(p);c->event(19,file_id(c,f));return f;}
static ElastikOriginalArchivePath* retain_path(void* p,ElastikOriginalArchivePath* path){auto* c=context(p);c->event(20);++c->path_retains;return path;}
static ElastikArchiveStatus prepare(Context* c,const int* h){
    c->h[0]=h[0];c->h[10]=h[4];c->h[11]=h[5];c->h[12]=h[6];c->h[13]=h[8];c->maximum=-1;c->read_ok=1;c->fail=-1;c->pos[0]=11;c->pos[1]=17;c->pos[2]=11;c->path_length=h[1];c->path_present=h[2]!=0;
    void* p=static_cast<ArchiveNameBase::Context*>(c);
    for(int i=0;i<3;++i){c->stream_contexts[i]={c,i};c->streams[i]={c->stream_contexts+i,ArchiveNameBase::seek,ArchiveNameBase::read,ArchiveNameBase::position,ArchiveNameBase::retain,ArchiveNameBase::can_clone,ArchiveNameBase::path,ArchiveNameBase::open_path,ArchiveNameBase::end};}
    c->archive={91,92,93,0,nullptr,static_cast<uint32_t>(h[0]),false,h[6]!=0,c->streams,p,ArchiveNameBase::allocate_entries,ArchiveNameBase::create_name,lock,unlock};
    const auto status=elastik_original_archive_parse(&c->archive);
    c->strings={p,string_length,split,count,at,equal,release_string};c->path={&c->archive,static_cast<uint32_t>(h[3]),h[2]?reinterpret_cast<void*>(1000):nullptr,p,resolve};
    c->data_platform={p,allocate_data,archive_data_lock,mutable_data_bytes,ArchiveNameBase::data_unlock,h[8]?ArchiveNameBase::decode:nullptr};
    c->byte_platform={p,object,data_lock,data_length,data_bytes,no_fork_read,no_fork_get,no_fork_set};c->factory={p,construct,initialize,autorelease,retain_path,&c->data_platform,&c->byte_platform};
    if(!h[7]){c->archive.stream=nullptr;}return status;
}
static void cleanup(Context* c){for(int i=0;i<c->component_count;++i)free(c->components[i]);for(int i=0;i<c->file_count;++i)free(c->files[i]);for(int i=0;i<c->data_count;++i)free(c->data[i].bytes);free(c->entries);free(c->raw);free(c->path_units);free(c);}
static bool output(const void* p,size_t n){return !n||fwrite(p,1,n,stdout)==n;}
static bool snapshot(Context* c){
    const int n=c->file_count;if(!output(&n,4))return false;
    for(int i=0;i<n;++i){const auto& f=c->files[i]->value;const int v[]{data_id(c,f.base.data),f.base.fork,f.base.position,f.base.length,f.member.path?1:0,f.member.backing?static_cast<int>(f.member.backing-c->streams)+1:0,f.member.shared,static_cast<int>(f.member.position),static_cast<int>(f.member.position>>32),f.writing};if(!output(v,sizeof(v)))return false;}
    if(!output(&c->data_count,4))return false;
    for(int i=0;i<c->data_count;++i){const int v[]{c->data[i].size,c->data[i].locked,c->refs[i]};if(!output(v,12)||!output(c->data[i].bytes,c->data[i].size))return false;}
    return output(&c->traces,4)&&output(c->trace,c->traces*24);
}
} // namespace ArchiveNameFixture
