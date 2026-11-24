#include "../src/engine/LegacyEngine.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>
#include <cmath>
struct Joined {
 std::atomic<bool>& stop;std::thread& thread;
 ~Joined(){stop.store(true);if(thread.joinable())thread.join();}
};
int main(){
 try {
  sophistry::LegacyEngineConfig c;c.audioUnitMode=true;c.recycleFreedBlocks=true;c.nativeMonotonicClock=true;
  sophistry::LegacyEngine engine(c);engine.initialize();engine.setSampleRate(44100);engine.setBlockSize(256);engine.activate();
  std::recursive_mutex mutex;std::atomic<bool> stop{false};unsigned callbacks=0;std::string error;
  std::thread thread([&]{while(!stop.load()){{std::unique_lock<std::recursive_mutex> lock(mutex,std::try_to_lock);if(lock.owns_lock()){try{callbacks+=engine.serviceTimers();}catch(const std::exception& e){error=e.what();stop.store(true);}}}std::this_thread::sleep_for(std::chrono::milliseconds(2));}});
  Joined joined{stop,thread};std::vector<float> l(256),r(256);float* outputs[]={l.data(),r.data()};
  {std::lock_guard<std::recursive_mutex> lock(mutex);engine.midi(0x90,60,100);}
  for(unsigned i=0;i<64;++i){
   std::this_thread::sleep_for(std::chrono::milliseconds(1));
   std::lock_guard<std::recursive_mutex> lock(mutex);
   if(!error.empty())throw std::runtime_error(error);
   if(i==32)engine.midi(0x80,60,0);
   engine.process(outputs,2,256);for(auto value:l)if(!std::isfinite(value))throw std::runtime_error("Non-finite background-control render");
  }
  stop.store(true);thread.join();if(!error.empty())throw std::runtime_error(error);
  if(!callbacks)throw std::runtime_error("Background original callback was not dispatched");
  engine.deactivate();engine.setSampleRate(48000);engine.setBlockSize(256);engine.activate();engine.midi(0xb0,123,0);engine.process(outputs,2,256);engine.deactivate();engine.shutdown();
  std::printf("{\"passed\":true,\"background_original_callbacks\":%u,\"rendered_frames\":16640,\"reinitialized_at_48000\":true,\"original_shutdown_executed\":true}\n",callbacks);return 0;
 }catch(const std::exception& error){std::fprintf(stderr,"CronoX control-thread probe: %s\n",error.what());return 1;}
}
