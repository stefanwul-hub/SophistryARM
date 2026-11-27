#pragma once
#include "../src/OriginalArchiveOpen.h"
#include "ArchiveNameFixture.h"
namespace ArchiveOpenFixture {
struct Context:ArchiveNameFixture::Context {
    int settings[32],owners=0,paths=0;ElastikOriginalArchiveContainer container;
    ElastikOriginalArchiveOpenPlatform opening;
};
static Context* ctx(void* p){return static_cast<Context*>(static_cast<ArchiveNameBase::Context*>(p));}
static ElastikOriginalArchiveStream* read_file(void* p,void* path){auto* c=ctx(p);if(path!=reinterpret_cast<void*>(1))abort();c->event(30,1,c->settings[4]);return c->settings[4]?c->streams:nullptr;}
static int size(void* p,void* path){auto* c=ctx(p);if(path!=reinterpret_cast<void*>(1))abort();c->event(31,c->settings[2]);return c->settings[2];}
static ElastikOriginalArchivePath* construct(void* p){auto* c=ctx(p);++c->paths;for(int event=32;event<=35;++event)c->event(event);c->path.archive=nullptr;c->path.index=0;c->path.unresolved=nullptr;return &c->path;}
static uint16_t character(void* p,void*,int index){auto* c=ctx(p);uint16_t value=c->path_units[index];c->event(38,index,value);return value;}
static void* retain_string(void* p,void* value){ctx(p)->event(36);return value;}
static void retain_owner(void* p,void* owner){auto* c=ctx(p);if(owner!=reinterpret_cast<void*>(1))abort();++c->owners;c->event(37);}
static void setup(Context* c,const int* h,unsigned char* raw,uint16_t* units){
    memcpy(c->settings,h,128);c->path_units=units;
    unsigned char empty[]{'G','N','F','A',0,0,0,20,0,0,0,0,0,0,0,1,0,0,0,0};c->raw=empty;
    const int named[]{20,h[1],1,0,h[10],1,h[11],1,0,0,0,0,0,0,0,0};if(ArchiveNameFixture::prepare(c,named)!=ElastikArchiveOk)abort();
    c->raw=raw;c->h[0]=h[0];c->archive.header_bytes=91;c->archive.version=92;c->archive.directory_layout=93;c->archive.read_only=h[5]!=0;c->archive.file_bytes=77;c->archive.stream=h[9]?c->streams:nullptr;c->maximum=h[12];c->read_ok=h[13];c->fail=h[14];c->reads=0;c->pos[0]=11;c->pos[1]=17;c->traces=0;
    c->container={&c->archive,h[3]?c->streams:nullptr,reinterpret_cast<void*>(1)};
    void* p=static_cast<ArchiveNameBase::Context*>(c);
    c->opening={p,read_file,size,construct,ArchiveNameFixture::string_length,character,retain_string,retain_owner};
}
static inline bool summary(Context* c,int open_status,int repeated,int path_status,ElastikOriginalArchivePath* path){
    const auto& a=c->archive;const int h[]{open_status,repeated,path_status,path?1:0,c->container.file?1:0,a.stream?1:0,static_cast<int>(a.header_bytes),static_cast<int>(a.version),static_cast<int>(a.directory_layout),static_cast<int>(a.entry_count),a.entries?1:0,a.read_only,c->capacity,static_cast<int>(a.file_bytes),static_cast<int>(a.file_bytes>>32),c->pos[0],c->pos[1],c->path.archive?1:0,static_cast<int>(c->path.index),c->path.unresolved?1:0,c->depth,c->owners,c->paths};
    if(!ArchiveNameFixture::output(h,sizeof(h)))return false;
    for(int i=0;i<c->capacity;++i)if(!ArchiveNameBase::write_entry(c->entries[i]))return false;
    return true;
}
} // namespace ArchiveOpenFixture
