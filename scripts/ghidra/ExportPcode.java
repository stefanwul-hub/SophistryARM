// @category Sophistry
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.address.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;
import java.util.zip.GZIPOutputStream;
public class ExportPcode extends GhidraScript {
 String esc(String s){return s.replace("\\","\\\\").replace("\"","\\\"").replace("\n","\\n").replace("\r","\\r").replace("\t","\\t");}
 String vn(Varnode v){if(v==null)return "null";return "{\"space\":\""+esc(v.getAddress().getAddressSpace().getName())+"\",\"offset\":\""+Long.toUnsignedString(v.getOffset(),16)+"\",\"size\":"+v.getSize()+"}";}
 public void run() throws Exception {
  String[] args=getScriptArgs();Path output=Paths.get(args[0]);Files.createDirectories(output);
  if(!currentProgram.getExecutableSHA256().equals("17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12"))throw new Exception("Wrong original image");
  boolean gzip=Arrays.asList(args).contains("--gzip");
  TreeMap<Long,Instruction> instructions=new TreeMap<>();Set<Long> visited=new HashSet<>();
  List<String> funcs=new ArrayList<>();
  boolean all=args.length>1 && args[1].equals("--all");
  if(args.length==4 && args[1].equals("--range")) {
   long start=Long.parseUnsignedLong(args[2].replace("0x",""),16),end=Long.parseUnsignedLong(args[3].replace("0x",""),16);
   InstructionIterator it=currentProgram.getListing().getInstructions(toAddr(start),true);
   while(it.hasNext()){Instruction ins=it.next();long pc=ins.getAddress().getOffset();if(pc>=end)break;instructions.put(pc,ins);}
  } else if(all) {
   InstructionIterator it=currentProgram.getListing().getInstructions(true);
   while(it.hasNext()){Instruction ins=it.next();if(ins.getAddress().getOffset()<0x103000)instructions.put(ins.getAddress().getOffset(),ins);}
   FunctionIterator fi=currentProgram.getFunctionManager().getFunctions(true);
   while(fi.hasNext()){Function f=fi.next();if(!f.isExternal()&&f.getEntryPoint().getOffset()<0x103000)funcs.add("{\"address\":\""+Long.toUnsignedString(f.getEntryPoint().getOffset(),16)+"\",\"name\":\""+esc(f.getName())+"\"}");}
  } else {
   ArrayDeque<Function> queue=new ArrayDeque<>();
   for(int i=1;i<args.length;i++){Function f=getFunctionAt(toAddr(Long.parseUnsignedLong(args[i].replace("0x",""),16)));if(f==null)throw new Exception("No function: "+args[i]);queue.add(f);}
   while(!queue.isEmpty()) {
    Function f=queue.remove();long entry=f.getEntryPoint().getOffset();if(!visited.add(entry)||f.isExternal()||entry>=0x103000)continue;
    funcs.add("{\"address\":\""+Long.toUnsignedString(entry,16)+"\",\"name\":\""+esc(f.getName())+"\"}");
    InstructionIterator it=currentProgram.getListing().getInstructions(f.getBody(),true);
    while(it.hasNext()){Instruction ins=it.next();instructions.put(ins.getAddress().getOffset(),ins);}
    for(Function callee:f.getCalledFunctions(monitor))if(!callee.isExternal()&&callee.getEntryPoint().getOffset()<0x103000)queue.add(callee);
   }
  }
  Path streamPath=output.resolve(gzip?"instructions.jsonl.gz":"instructions.jsonl");
  OutputStream stream=Files.newOutputStream(streamPath);
  if(gzip)stream=new GZIPOutputStream(stream,65536);
  try(PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream,java.nio.charset.StandardCharsets.UTF_8)))) {
   int exported=0;
   for(Instruction ins:instructions.values()) {
    if((++exported)%10000==0)println("P-code instructions exported: "+exported);
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
