// @category Elastik
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.util.*;

public class AuditElastikEntries extends GhidraScript {
  public void run() throws Exception {
    if (!currentProgram.getExecutableSHA256().equals("5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920"))
      throw new Exception("Wrong Elastik reference image");
    String[] args=getScriptArgs();
    if(args.length<2)throw new Exception("Usage: function-ranges.csv output-directory");
    Path output=Paths.get(args[1]);Files.createDirectories(output);
    // Recognise the original GCC PIC helper without changing its bytes.
    Address thunk=toAddr(0x2e501cL);byte[] bytes=new byte[4];currentProgram.getMemory().getBytes(thunk,bytes);
    if(!Arrays.equals(bytes,new byte[]{(byte)0x8b,(byte)0x1c,(byte)0x24,(byte)0xc3}))throw new Exception("Unexpected PIC helper");
    AddressSet thunkBody=new AddressSet(thunk,thunk.add(3));new DisassembleCommand(thunk,thunkBody,true).applyTo(currentProgram,monitor);
    Function pic=getFunctionAt(thunk);
    if(pic==null)pic=currentProgram.getFunctionManager().createFunction("__i686.get_pc_thunk.bx",thunk,thunkBody,SourceType.USER_DEFINED);
    pic.setCallFixup("get_pc_thunk_bx");
    Map<Long,Long> ranges=new HashMap<>();
    for(String line:Files.readAllLines(Paths.get(args[0]))) {
      if(line.startsWith("address,"))continue;
      String[] row=line.split(",");ranges.put(Long.decode(row[0]),Long.parseLong(row[1]));
    }
    LinkedHashSet<Long> selected=new LinkedHashSet<>(Arrays.asList(0x7490L,0x6bceL,0x38acL,0x823cL,0x75daL));
    for(int i=2;i<args.length;i++)selected.add(Long.decode(args[i]));
    List<Function> functions=new ArrayList<>();
    // Follow one level of direct calls in these small interface functions,
    // without analysing the entire stripped application/GUI framework.
    for(int round=0;round<2;round++) {
      for(long value:new ArrayList<Long>(selected)) {
        Long size=ranges.get(value);if(size==null)continue;
        Address start=toAddr(value);AddressSet body=new AddressSet(start,start.add(size-1));
        new DisassembleCommand(start,body,true).applyTo(currentProgram,monitor);
        Function f=getFunctionAt(start);
        if(f==null)f=currentProgram.getFunctionManager().createFunction("FUN_"+start,start,body,SourceType.USER_DEFINED);
        else f.setBody(body);
        if(!functions.contains(f))functions.add(f);
        if(round==0) {
          InstructionIterator it=currentProgram.getListing().getInstructions(body,true);
          while(it.hasNext()) {
            Instruction ins=it.next();if(!ins.getFlowType().isCall())continue;
            for(Address target:ins.getFlows())if(ranges.containsKey(target.getOffset())&&selected.size()<32)selected.add(target.getOffset());
          }
        }
      }
    }
    DecompInterface decompiler=new DecompInterface();decompiler.openProgram(currentProgram);
    List<String> results=new ArrayList<>();
    try {
      for(Function f:functions) {
        DecompileResults r=decompiler.decompileFunction(f,25,monitor);
        String address=f.getEntryPoint().toString();
        if(r.decompileCompleted()) {
          Files.writeString(output.resolve(address+".c"),r.getDecompiledFunction().getC());
          results.add("{\"address\":\""+address+"\",\"decompiled\":true}");
        } else results.add("{\"address\":\""+address+"\",\"decompiled\":false}");
        println("Elastik entry audit: "+address+" "+r.decompileCompleted());
      }
    } finally {decompiler.dispose();}
    Files.writeString(output.resolve("entry-audit.json"),"{\"checkpoint\":\"ELA001\",\"scope\":\"Selected original Audio Unit interface functions, decompilation only\",\"native_port_built\":false,\"functions\":["+String.join(",",results)+"]}\n");
  }
}
