#include "ArchiveOpenFixture.h"
static int run(const int* h){
    using namespace ArchiveOpenFixture;auto* c=static_cast<Context*>(calloc(1,sizeof(Context)));auto* raw=static_cast<unsigned char*>(malloc(h[0]+1));auto* units=static_cast<uint16_t*>(calloc(h[1]+1,2));
    if(fread(raw,1,h[0],stdin)!=static_cast<size_t>(h[0])||fread(units,2,h[1],stdin)!=static_cast<size_t>(h[1]))return 2;
    setup(c,h,raw,units);
    int opened=-1,repeated=-1,path_status=-1;ElastikOriginalArchivePath* path=nullptr;
    if(!h[8]){opened=elastik_original_archive_open_read(&c->container,reinterpret_cast<void*>(1),&c->opening);if(h[16])repeated=elastik_original_archive_open_read(&c->container,reinterpret_cast<void*>(1),&c->opening);}
    if(h[7]&&(opened==ElastikArchiveOk||h[8])){ElastikArchiveStatus s;path=h[6]?elastik_original_archive_path_for_container(&c->container,reinterpret_cast<void*>(1000),&c->opening,&s):elastik_original_archive_path_for_core(&c->archive,c->container.owner,reinterpret_cast<void*>(1000),&c->opening,&s);path_status=s;}
    bool ok=summary(c,opened,repeated,path_status,path);
    int file=0,file_status=-1,read_ok=0,count=0,bytes=0;unsigned char* payload=nullptr;
    if(path&&h[19]>=0){ElastikArchiveStatus s;auto* f=elastik_original_archive_open_file(path,&c->factory,&s);file=ArchiveNameFixture::file_id(c,f);file_status=s;if(f){count=h[19];bytes=count+32;payload=static_cast<unsigned char*>(malloc(bytes));memset(payload,0xa5,bytes);read_ok=elastik_original_archive_read_member(&f->member,payload+16,&count,&s);file_status=s;}}
    const int positions[]{c->pos[0],c->pos[1]};const int body[]{file,file_status,read_ok,count,bytes};ok=ok&&ArchiveNameFixture::output(body,sizeof(body))&&ArchiveNameFixture::output(payload,bytes)&&ArchiveNameFixture::output(positions,8)&&ArchiveNameFixture::snapshot(c);free(payload);ArchiveNameFixture::cleanup(c);return ok&&!fflush(stdout)?0:4;
}
int main(){for(;;){int h[32];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=run(h);if(e)return e;}}
