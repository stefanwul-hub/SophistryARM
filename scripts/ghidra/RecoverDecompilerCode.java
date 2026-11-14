// @category Sophistry
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.address.*;
import java.nio.file.*;
import java.util.*;
public class RecoverDecompilerCode extends GhidraScript {
 String quoted(String s){return "\""+s.replace("\\","\\\\").replace("\"","\\\"").replace("\n","\\n")+"\"";}
 public void run() throws Exception{
  String[] args=getScriptArgs();
  if(args.length<2)throw new Exception("Usage: report.json function_address ...");
  if(!currentProgram.getExecutableSHA256().equals("17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12"))throw new Exception("Wrong original image");
  Listing listing=currentProgram.getListing();TreeSet<Address> seeds=new TreeSet<>();List<String> functions=new ArrayList<>(),conflicts=new ArrayList<>(),recovered=new ArrayList<>();
  boolean all=args[1].equals("--all"),direct=args[1].equals("--seeds");List<Function> selected=new ArrayList<>();List<String> failures=new ArrayList<>();
  if(direct){
   for(int i=2;i<args.length;i++)seeds.add(toAddr(Long.parseUnsignedLong(args[i].replace("0x",""),16)));
  }else if(all){
   FunctionIterator fi=currentProgram.getFunctionManager().getFunctions(true);
   while(fi.hasNext()){Function f=fi.next();if(!f.isExternal()&&f.getEntryPoint().getOffset()<0x103000)selected.add(f);}
  }else{
   for(int i=1;i<args.length;i++){
    Address entry=toAddr(Long.parseUnsignedLong(args[i].replace("0x",""),16));
    Function fn=getFunctionAt(entry);if(fn==null)throw new Exception("No function at "+entry);selected.add(fn);
   }
  }
  DecompInterface decompiler=new DecompInterface();decompiler.toggleCCode(false);decompiler.toggleSyntaxTree(true);decompiler.openProgram(currentProgram);
  try{
   int completed=0;
   for(Function fn:selected){
    Address entry=fn.getEntryPoint();
    DecompileResults result=decompiler.decompileFunction(fn,all?30:120,monitor);
    HighFunction high=result.getHighFunction();
    if(high==null){failures.add("{\"function\":"+quoted(entry.toString())+",\"error\":"+quoted(result.getErrorMessage())+"}");continue;}
    functions.add(quoted(entry.toString()));
    Iterator<PcodeOpAST> it=high.getPcodeOps();
    while(it.hasNext()){
     Address pc=it.next().getSeqnum().getTarget();
     if(pc.getAddressSpace().getName().equals("ram")&&pc.getOffset()<0x103000&&listing.getInstructionAt(pc)==null)seeds.add(pc);
    }
    for(PcodeBlockBasic block:high.getBasicBlocks()){
     Address pc=block.getStart();
     if(pc.getAddressSpace().getName().equals("ram")&&pc.getOffset()<0x103000&&listing.getInstructionAt(pc)==null)seeds.add(pc);
    }
    if((++completed)%100==0)println("Functions checked: "+completed+"/"+selected.size()+"; missing instruction candidates: "+seeds.size());
   }
  }finally{decompiler.dispose();}
  for(Address seed:seeds){
   if(listing.getInstructionAt(seed)!=null)continue;
   Instruction enclosing=listing.getInstructionContaining(seed);
   Data data=listing.getDefinedDataContaining(seed);
   if(enclosing!=null||data!=null){
    conflicts.add("{\"seed\":"+quoted(seed.toString())+",\"reason\":"+quoted(enclosing!=null?"overlapping listing instruction":"defined data")+"}");
    continue;
   }
   if(disassemble(seed))recovered.add(quoted(seed.toString()));
   else conflicts.add("{\"seed\":"+quoted(seed.toString())+",\"reason\":\"disassembly failed\"}");
  }
  String report="{\"scope\":\"Recover actual instruction listing from decompiler-reachable addresses; machine bytes unchanged\",\"functions\":["+String.join(",",functions)+"],\"candidate_seeds\":"+seeds.size()+",\"recovered_seeds\":["+String.join(",",recovered)+"],\"conflicts\":["+String.join(",",conflicts)+"],\"decompilation_failures\":["+String.join(",",failures)+"]}\n";
  Files.writeString(Paths.get(args[0]),report);
  println("RECOVERED "+recovered.size()+" seeds from "+seeds.size()+" candidates; conflicts "+conflicts.size());
 }
}
