#include "SaturKernel.h"
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

static void read(FILE* f,void* p,size_t n) {
    if(std::fread(p,1,n,f)!=n)throw std::runtime_error("Truncated fixture");
}
int main(int argc,char** argv) {
    if(argc!=2){std::fprintf(stderr,"Usage: SaturProbe fixture.bin\n");return 2;}
    FILE* f=std::fopen(argv[1],"rb");if(!f){std::perror(argv[1]);return 2;}
    try {
        char magic[8];read(f,magic,8);if(std::memcmp(magic,"SPRB0001",8))throw std::runtime_error("Wrong fixture version");
        uint32_t count;read(f,&count,4);if(count>100000)throw std::runtime_error("Fixture count too large");
        uint64_t compared=0,mismatches=0;
        for(uint32_t test=0;test<count;++test) {
            uint32_t header[4];float a,b;read(f,header,sizeof(header));read(f,&a,4);read(f,&b,4);
            uint32_t n=header[0],ch=header[1];bool inplace=header[2],enabled=header[3];
            if(n>4096 || (ch!=1 && ch!=2))throw std::runtime_error("Invalid fixture shape");
            std::vector<float> src[2],dst[2],expected[2];
            for(unsigned c=0;c<ch;++c){src[c].resize(n);dst[c].resize(n);expected[c].resize(n);read(f,src[c].data(),n*4);read(f,dst[c].data(),n*4);read(f,expected[c].data(),n*4);}
            float* out0=inplace?src[0].data():dst[0].data();float* out1=inplace?src[1].data():dst[1].data();
            sophistry_satur_process(src[0].data(),ch==2?src[1].data():nullptr,out0,ch==2?out1:nullptr,n,a,b,ch,enabled);
            for(unsigned c=0;c<ch;++c){const float* actual=c==0?out0:out1;for(uint32_t i=0;i<n;++i){if(std::memcmp(actual+i,expected[c].data()+i,4))++mismatches;++compared;}}
        }
        if(std::fgetc(f)!=EOF)throw std::runtime_error("Unexpected fixture trailer");
        std::fclose(f);
        std::printf("{\"scope\":\"isolated saturation kernel\",\"cases\":%u,\"samples\":%llu,\"bit_mismatches\":%llu,\"passed\":%s}\n",count,(unsigned long long)compared,(unsigned long long)mismatches,mismatches?"false":"true");
        return mismatches?1:0;
    }catch(const std::exception& e){std::fclose(f);std::fprintf(stderr,"%s\n",e.what());return 2;}
}
