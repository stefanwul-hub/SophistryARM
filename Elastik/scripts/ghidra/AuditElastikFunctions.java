// @category Elastik
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.util.*;

/** Bounded decompilation of explicit roots and their direct callees. */
public class AuditElastikFunctions extends GhidraScript {
  public void run() throws Exception {
    if (!currentProgram.getExecutableSHA256().equals("5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920"))
      throw new Exception("Wrong Elastik reference image");
    String[] args=getScriptArgs();
    if(args.length<3)throw new Exception("Usage: function-ranges.csv output-directory roots.txt [direct-call-depth:0..2]");
    int depth=args.length>3?Integer.parseInt(args[3]):1;
    if(depth<0||depth>2)throw new Exception("Depth must be 0..2");
    Path output=Paths.get(args[1]);Files.createDirectories(output);
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
    LinkedHashSet<Long> selected=new LinkedHashSet<>();
    Map<String,Long> explicitSizes=new LinkedHashMap<>();
    for(String line:Files.readAllLines(Paths.get(args[2]))) {
      line=line.split("#",2)[0].trim();if(line.isEmpty())continue;
      String[] fields=line.split(",");long address=Long.decode(fields[0]);selected.add(address);
      if(fields.length==2) {
        long size=Long.decode(fields[1]);if(size<1||size>4096)throw new Exception("Invalid explicit size");
        if(ranges.containsKey(address)&&ranges.get(address)!=size)throw new Exception("Explicit size conflicts with unwind range");
        ranges.put(address,size);explicitSizes.put(String.format("0x%08x",address),size);
      }
    }
    if(selected.size()>128)throw new Exception("At most 128 explicit roots");
    List<String> roots=new ArrayList<>();for(Long n:selected)roots.add(String.format("0x%08x",n));
    LinkedHashMap<Long,Function> functions=new LinkedHashMap<>();
    for(int round=0;round<=depth;round++) {
      for(long value:new ArrayList<Long>(selected)) {
        if(functions.containsKey(value))continue;
        Long size=ranges.get(value);if(size==null)throw new Exception("Root has no recovered boundary: "+Long.toHexString(value));
        Address start=toAddr(value);AddressSet body=new AddressSet(start,start.add(size-1));
        new DisassembleCommand(start,body,true).applyTo(currentProgram,monitor);
        Function f=getFunctionAt(start);
        if(f==null)f=currentProgram.getFunctionManager().createFunction("FUN_"+start,start,body,SourceType.USER_DEFINED);
        else f.setBody(body);
        functions.put(value,f);
        if(round<depth) {
          InstructionIterator it=currentProgram.getListing().getInstructions(body,true);
          while(it.hasNext()) {
            Instruction ins=it.next();if(!ins.getFlowType().isCall())continue;
            for(Address target:ins.getFlows())if(ranges.containsKey(target.getOffset())&&selected.size()<128)selected.add(target.getOffset());
          }
        }
      }
    }
    DecompInterface decompiler=new DecompInterface();decompiler.openProgram(currentProgram);
    List<Map<String,Object>> results=new ArrayList<>();
    try {
      for(Map.Entry<Long,Function> item:functions.entrySet()) {
        Function f=item.getValue();String address=f.getEntryPoint().toString();
        DecompileResults r=decompiler.decompileFunction(f,30,monitor);
        Map<String,Object> row=new LinkedHashMap<>();row.put("address","0x"+address);row.put("bytes",ranges.get(item.getKey()));row.put("decompiled",r.decompileCompleted());
        if(r.decompileCompleted())Files.writeString(output.resolve(address+".c"),r.getDecompiledFunction().getC());
        else row.put("error",r.getErrorMessage());
        StringBuilder assembly=new StringBuilder();LinkedHashSet<String> calls=new LinkedHashSet<>();int indirect=0;
        InstructionIterator it=currentProgram.getListing().getInstructions(f.getBody(),true);
        while(it.hasNext()) {
          Instruction ins=it.next();assembly.append(ins.getAddress()).append("  ");
          for(byte b:ins.getBytes())assembly.append(String.format("%02x",b&255));
          assembly.append("  ").append(ins.toString()).append("\n");
          if(ins.getFlowType().isCall()) {
            if(ins.getFlows().length==0)indirect++;
            for(Address target:ins.getFlows())calls.add("0x"+target);
          }
        }
        row.put("direct_calls",calls);row.put("indirect_calls",indirect);results.add(row);
        Files.writeString(output.resolve(address+".asm"),assembly.toString());
        println("Elastik function audit: "+address+" "+r.decompileCompleted());
      }
    } finally {decompiler.dispose();}
    Map<String,Object> report=new LinkedHashMap<>();report.put("checkpoint","ELA002");report.put("scope","Original selected AU/state/render code, analysis only");report.put("original_sha256",currentProgram.getExecutableSHA256());report.put("roots",roots);report.put("explicit_instruction_verified_sizes",explicitSizes);report.put("direct_call_depth",depth);report.put("functions",results);report.put("native_engine_built",false);
    Files.writeString(output.resolve("function-audit.json"),new GsonBuilder().setPrettyPrinting().create().toJson(report)+"\n");
  }
}
