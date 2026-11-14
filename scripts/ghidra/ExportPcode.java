// @category Sophistry
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.address.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;
public class ExportPcode extends GhidraScript {
 String esc(String s){return s.replace("\\","\\\\").replace("\"","\\\"").replace("\n","\\n").replace("\r","\\r").replace("\t","\\t");}
 String vn(Varnode v){if(v==null)return "null";return "{\"space\":\""+esc(v.getAddress().getAddressSpace().getName())+"\",\"offset\":\""+Long.toUnsignedString(v.getOffset(),16)+"\",\"size\":"+v.getSize()+"}";}
 public void run() throws Exception {
  String[] args=getScriptArgs();Path output=Paths.get(args[0]);Files.createDirectories(output);
  TreeMap<Long,Instruction> instructions=new TreeMap<>();Set<Long> visited=new HashSet<>();
  ArrayDeque<Function> queue=new ArrayDeque<>();
  for(int i=1;i<args.length;i++){Function f=getFunctionAt(toAddr(Long.parseUnsignedLong(args[i].replace("0x",""),16)));if(f==null)throw new Exception("No function: "+args[i]);queue.add(f);}
  List<String> funcs=new ArrayList<>();
  while(!queue.isEmpty()) {
   Function f=queue.remove();long entry=f.getEntryPoint().getOffset();if(!visited.add(entry)||f.isExternal()||entry>=0x103000)continue;
   funcs.add("{\"address\":\""+Long.toUnsignedString(entry,16)+"\",\"name\":\""+esc(f.getName())+"\"}");
   InstructionIterator it=currentProgram.getListing().getInstructions(f.getBody(),true);
   while(it.hasNext()){Instruction ins=it.next();instructions.put(ins.getAddress().getOffset(),ins);}
   for(Function callee:f.getCalledFunctions(monitor)) if(!callee.isExternal()&&callee.getEntryPoint().getOffset()<0x103000)queue.add(callee);
  }
  try(PrintWriter out=new PrintWriter(Files.newBufferedWriter(output.resolve("instructions.jsonl")))) {
   for(Instruction ins:instructions.values()) {
    out.print("{\"address\":\""+Long.toUnsignedString(ins.getAddress().getOffset(),16)+"\",\"length\":"+ins.getLength()+",\"asm\":\""+esc(ins.toString())+"\",\"pcode\":[");
    PcodeOp[] ops=ins.getPcode();
    for(int i=0;i<ops.length;i++) {
     if(i>0)out.print(",");PcodeOp op=ops[i];
     out.print("{\"op\":\""+op.getMnemonic()+"\",\"output\":"+vn(op.getOutput())+",\"inputs\":[");
     for(int j=0;j<op.getNumInputs();j++){if(j>0)out.print(",");out.print(vn(op.getInput(j)));}
     out.print("]");
     if(op.getOpcode()==PcodeOp.CALLOTHER)out.print(",\"userop\":\""+esc(currentProgram.getLanguage().getUserDefinedOpName((int)op.getInput(0).getOffset()))+"\"");
     out.print("}");
    }
    out.println("]}");
   }
  }
  Files.writeString(output.resolve("functions.json"),"["+String.join(",",funcs)+"]\n");
  Files.writeString(output.resolve("provenance.json"),"{\"sha256\":\""+currentProgram.getExecutableSHA256()+"\",\"language\":\""+currentProgram.getLanguageID()+"\",\"instruction_count\":"+instructions.size()+",\"function_count\":"+funcs.size()+"}\n");
  println("EXPORTED "+instructions.size()+" instructions in "+funcs.size()+" functions");
 }
}
