#include "../src/OriginalByteFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Data {unsigned char* storage;int size,refs;bool locked;};
struct Context {int h[16],trace[2048][6],traces=0;Data data[2];uint64_t fork_position,fork_end;
    void event(int a,int b=0,int c=0,int d=0,int e=0,int f=0){if(traces>=2048){abort();}const int v[]{a,b,c,d,e,f};memcpy(trace[traces++],v,24);}
};
static int id(Context* c,void* p){return p?static_cast<int>(static_cast<Data*>(p)-c->data)+1:0;}
static void object(void* p,int op,void* v){auto* c=static_cast<Context*>(p);int n=id(c,v);c->event(1,op,n);c->data[n-1].refs+=op==1?1:-1;}
static ElastikArchiveStatus lock(void* p,void* v){auto* c=static_cast<Context*>(p);int n=id(c,v);c->event(2,n);if(!n)return ElastikArchiveAssertion;c->data[n-1].locked=true;return ElastikArchiveOk;}
static int length(void* p,void* v){auto* c=static_cast<Context*>(p);int n=id(c,v);c->event(3,n,c->data[n-1].size);return c->data[n-1].size;}
static const unsigned char* bytes(void* p,void* v){auto* c=static_cast<Context*>(p);int n=id(c,v);c->event(4,n);return c->data[n-1].storage+16;}
static int16_t read_fork(void* p,int16_t f,int wanted,unsigned char* out,int* actual){auto* c=static_cast<Context*>(p);int n=c->h[11]<0?wanted:c->h[11];if(n>wanted)n=wanted;if(n<0)n=0;for(int i=0;i<n;++i)out[i]=static_cast<unsigned char>((c->fork_position+i)*13);c->fork_position+=n;*actual=n;c->event(5,f,wanted,n,c->h[8]);return c->h[8];}
static int16_t get_position(void* p,int16_t f,uint64_t* at){auto* c=static_cast<Context*>(p);*at=c->fork_position;c->event(6,f,static_cast<uint32_t>(*at),static_cast<uint32_t>(*at>>32),c->h[9]);return c->h[9];}
static int16_t set_position(void* p,int16_t f,int origin,int offset){auto* c=static_cast<Context*>(p);c->event(7,f,origin,offset,c->h[10]);if(!c->h[10])c->fork_position=origin==2?c->fork_end+offset:static_cast<uint32_t>(offset);return c->h[10];}
static bool output(const void* p,size_t n){return !n||fwrite(p,1,n,stdout)==n;}
static int run(Context* c){
    for(int d=0;d<2;++d){c->data[d]={static_cast<unsigned char*>(malloc(c->h[4+d]+32)),c->h[4+d],1,false};memset(c->data[d].storage,0xa5,c->h[4+d]+32);for(int j=0;j<c->h[4+d];++j)c->data[d].storage[16+j]=static_cast<unsigned char>(j*37+(d+1)*19);}
    c->fork_position=static_cast<uint32_t>(c->h[6])|(static_cast<uint64_t>(static_cast<uint32_t>(c->h[7]))<<32);c->fork_end=static_cast<uint32_t>(c->h[14])|(static_cast<uint64_t>(static_cast<uint32_t>(c->h[15]))<<32);
    ElastikOriginalByteFile file{c->h[0]?c->data+c->h[0]-1:nullptr,static_cast<int16_t>(c->h[1]),c->h[2],c->h[3]};const ElastikOriginalByteFilePlatform platform{c,object,lock,length,bytes,read_fork,get_position,set_position};
    for(int i=0;i<c->h[12];++i){
        int op[4];if(fread(op,1,sizeof(op),stdin)!=sizeof(op))return 2;ElastikArchiveStatus status=ElastikArchiveOk;int value=0,count=0,n=0;unsigned char* payload=nullptr;
        if(op[0]==1)status=elastik_original_byte_file_bind_data(&file,op[1]?c->data+op[1]-1:nullptr,&platform);
        else if(op[0]==2){count=op[1];n=(count>256?count:256)+32;payload=static_cast<unsigned char*>(malloc(n));memset(payload,0xa5,n);value=elastik_original_byte_file_read(op[2]&1?nullptr:&file,op[2]&2?nullptr:payload+16,op[2]&4?nullptr:&count,&platform,&status);}
        else if(op[0]==3)status=elastik_original_byte_file_seek(op[2]?nullptr:&file,op[1],&platform);
        else if(op[0]==4)value=elastik_original_byte_file_position(op[1]?nullptr:&file,&platform,&status);
        else if(op[0]==5)value=elastik_original_byte_file_end(op[1]?nullptr:&file,&platform,&status);
        else if(op[0]==6){c->h[8]=op[1];c->h[9]=op[2];c->h[10]=op[3];}
        else if(op[0]==7)c->h[11]=op[1];
        else if(op[0]==8){file.data=op[1]?c->data+op[1]-1:nullptr;file.position=op[2];file.length=op[3];}
        else if(op[0]==9)file.fork=op[1];
        else if(op[0]==10)c->fork_position=static_cast<uint32_t>(op[1])|(static_cast<uint64_t>(static_cast<uint32_t>(op[2]))<<32);
        else return 3;
        const int state[]{status,value,count,id(c,file.data),file.fork,file.position,file.length,static_cast<int>(c->fork_position),static_cast<int>(c->fork_position>>32),c->data[0].refs,c->data[1].refs,c->data[0].locked,c->data[1].locked,n};
        if(!output(state,sizeof(state))||!output(payload,n)){return 4;}free(payload);
    }
    bool ok=output(&c->traces,4)&&output(c->trace,c->traces*24);for(auto& d:c->data)free(d.storage);return ok&&!fflush(stdout)?0:4;
}
int main(){for(;;){Context c{};size_t n=fread(c.h,1,sizeof(c.h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(c.h))return 2;int e=run(&c);if(e)return e;}}
