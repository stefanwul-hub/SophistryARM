// @category Sophistry
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.address.Address;
import java.nio.file.*;
public class ApplyHints extends GhidraScript {
 public void run() throws Exception {
  int n=0;
  for(String line:Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
   String[] v=line.split("\\t");if(v.length<2)continue;
   Address a=toAddr(Long.parseUnsignedLong(v[0].replace("0x",""),16));
   Function f=getFunctionAt(a);if(f==null)f=createFunction(a,v[1]);
   if(f!=null){f.setName(v[1],SourceType.USER_DEFINED);n++;}
  }
  println("Applied "+n+" inferred vtable function hints; these are not recovered original method names.");
 }
}
