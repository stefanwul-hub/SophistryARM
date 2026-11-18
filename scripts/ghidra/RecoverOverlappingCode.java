// Recover decompiler-reachable code hidden by an incorrect listing alignment.
// Work on a checkpoint copy. Original executable bytes are never modified.
// @category Sophistry
import ghidra.app.script.GhidraScript;
import ghidra.app.util.PseudoDisassembler;
import ghidra.app.util.PseudoInstruction;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.util.*;
public class RecoverOverlappingCode extends GhidraScript {
 String q(String s){return "\""+s.replace("\\","\\\\").replace("\"","\\\"").replace("\n","\\n")+"\"";}
 public void run() throws Exception {
  if(!currentProgram.getExecutableSHA256().equals("17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12"))throw new Exception("Wrong original image");
  String[] args=getScriptArgs();if(args.length<2)throw new Exception("report.json seed_address ...");
  Listing listing=currentProgram.getListing();PseudoDisassembler decoder=new PseudoDisassembler(currentProgram);List<String> changes=new ArrayList<>(),already=new ArrayList<>();
  for(int n=1;n<args.length;n++){
   Address seed=toAddr(Long.parseUnsignedLong(args[n].replace("0x",""),16));
   if(listing.getInstructionAt(seed)!=null){already.add(q(seed.toString()));continue;}
   Address cursor=seed;List<String> decoded=new ArrayList<>();
   for(int count=0;;count++){
    if(count>512)throw new Exception("No stable listing boundary after "+seed);
    PseudoInstruction instruction=decoder.disassemble(cursor);if(instruction==null)throw new Exception("Cannot decode "+cursor);
    decoded.add("{\"address\":"+q(cursor.toString())+",\"length\":"+instruction.getLength()+",\"asm\":"+q(instruction.toString())+"}");
    cursor=cursor.add(instruction.getLength());
    if(listing.getInstructionAt(cursor)!=null)break;
    if(instruction.getFlowType().isTerminal() || instruction.getFlowType().isJump())throw new Exception("Control boundary before listing realignment at "+cursor);
   }
   Instruction enclosing=listing.getInstructionContaining(seed);Address first=enclosing==null?seed:enclosing.getMinAddress();Address last=cursor.subtract(1);List<String> removed=new ArrayList<>();
   InstructionIterator old=listing.getInstructions(new AddressSet(first,last),true);
   while(old.hasNext()){
    Instruction instruction=old.next();Address pc=instruction.getAddress();
    if(getFunctionAt(pc)!=null)throw new Exception("Refuse to clear function entry "+pc);
    ReferenceIterator refs=currentProgram.getReferenceManager().getReferencesTo(pc);
    while(refs.hasNext()){
     Reference ref=refs.next();if((ref.getReferenceType().isJump()||ref.getReferenceType().isCall()) && !new AddressSet(first,last).contains(ref.getFromAddress()))throw new Exception("Conflicting direct flow to old listing at "+pc);
    }
    removed.add("{\"address\":"+q(pc.toString())+",\"length\":"+instruction.getLength()+",\"asm\":"+q(instruction.toString())+"}");
   }
   clearListing(first,last);
   if(!disassemble(seed)||listing.getInstructionAt(seed)==null)throw new Exception("Recovery failed at "+seed);
   changes.add("{\"seed\":"+q(seed.toString())+",\"cleared_start\":"+q(first.toString())+",\"cleared_end\":"+q(last.toString())+",\"previous_listing\":["+String.join(",",removed)+"],\"recovered_instructions\":["+String.join(",",decoded)+"]}");
   println("Recovered aligned code at "+seed+" through "+last);
  }
  Files.writeString(Paths.get(args[0]),"{\"scope\":\"Instruction-listing corrections only; original machine bytes unchanged\",\"changes\":["+String.join(",",changes)+"],\"already_present\":["+String.join(",",already)+"]}\n");
 }
}
