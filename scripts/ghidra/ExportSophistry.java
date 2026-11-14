// Export a resumable function database and the actual Ghidra decompiler output.
// @category Sophistry
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.nio.file.*;

public class ExportSophistry extends GhidraScript {
  private String esc(String s) {
    return s.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t");
  }
  public void run() throws Exception {
    String[] args=getScriptArgs();
    Path out=Paths.get(args[0]); Files.createDirectories(out.resolve("functions"));
    if (args.length>1 && Files.exists(Paths.get(args[1]))) {
      for(String line: Files.readAllLines(Paths.get(args[1]))) {
        String[] v=line.split("\\t"); if(v.length<2) continue;
        Address a=toAddr(Long.parseUnsignedLong(v[0].replace("0x",""),16));
        Function f=getFunctionAt(a);
        if(f==null) f=createFunction(a,v[1]);
        if(f!=null) { try { f.setName(v[1],SourceType.USER_DEFINED); } catch(Exception e) {} }
      }
    }
    DecompInterface di=new DecompInterface();
    di.setOptions(new DecompileOptions()); di.openProgram(currentProgram);
    int count=0,ok=0,fail=0;
    try(PrintWriter index=new PrintWriter(Files.newBufferedWriter(out.resolve("function-index.jsonl")));
        PrintWriter all=new PrintWriter(Files.newBufferedWriter(out.resolve("all-functions.c")));
        PrintWriter refs=new PrintWriter(Files.newBufferedWriter(out.resolve("calls.tsv")))) {
      all.println("/* Ghidra 11.3.2 pseudocode, NOT compilable C/C++, NOT a port. */");
      refs.println("caller\tcallee\tname");
      FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);
      while(it.hasNext() && !monitor.isCancelled()) {
        Function f=it.next(); if(f.isExternal()) continue;
        String a=f.getEntryPoint().toString(), name=f.getName();
        DecompileResults r=di.decompileFunction(f,60,monitor);
        boolean good=r.decompileCompleted() && r.getDecompiledFunction()!=null;
        String code=good?r.getDecompiledFunction().getC():"/* ERROR: "+r.getErrorMessage()+" */\n";
        String filename=a+"_"+name.replaceAll("[^A-Za-z0-9_]","_")+".c";
        Files.writeString(out.resolve("functions").resolve(filename),"/* "+a+" "+name+" */\n"+code);
        all.println("\n/* "+a+" "+name+" */\n"+code);
        index.println("{\"address\":\""+a+"\",\"name\":\""+esc(name)+"\",\"bytes\":"+f.getBody().getNumAddresses()+",\"ok\":"+good+",\"error\":\""+esc(r.getErrorMessage())+"\",\"file\":\"functions/"+filename+"\"}");
        for(Function callee:f.getCalledFunctions(monitor)) refs.println(a+"\t"+callee.getEntryPoint()+"\t"+callee.getName());
        count++; if(good)ok++;else fail++;
        if(count%200==0){println("Exported "+count+" functions");index.flush();all.flush();refs.flush();}
      }
    } finally { di.dispose(); }
    Files.writeString(out.resolve("summary.json"),"{\"functions\":"+count+",\"decompiled\":"+ok+",\"failed\":"+fail+",\"language\":\""+currentProgram.getLanguageID()+"\",\"binary_sha256\":\""+currentProgram.getExecutableSHA256()+"\"}\n");
    println("DONE "+count+" functions, "+ok+" decompiled, "+fail+" failures");
  }
}
