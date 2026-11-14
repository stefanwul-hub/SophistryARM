/* 0004c384 FUN_0004c384 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004c384(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = param_1 + 0x32aa04;
  if (iVar5 != param_3) {
    return;
  }
  if (param_4 == 0xd0) {
    iVar3 = Envelope_c_vslot_12(iVar5,param_2,0x5a);
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xd0);
    if (iVar3 == 1) {
      pcVar6 = "TimeSampler";
      pcVar2 = "51 Cen Gen 2" + param_1;
    }
    else if (iVar3 < 2) {
      if (iVar3 != 0) {
LAB_0004c3a0:
        return;
      }
      pcVar6 = "Oscillator";
      pcVar2 = "Chorus 1 Rate Spread" + param_1 + 4;
    }
    else if (iVar3 == 2) {
      pcVar6 = "Schrader   ";
      pcVar2 = "    - - -    Ampl Osc 1  Ampl Osc 2  Ampl Osc 3  Ampl Osc 4 Pitch Osc 1 Pitch Osc 2 Pitch Osc 3 Pitch Osc 4 AuxMod Osc 1AuxMod Osc 2AuxMod Osc 3AuxMod Osc 4Balance Osc1Balance Osc2Balance Osc3Balance Osc4  Cutoff 1   Resonance 1Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxx Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4 LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 Amp-Env Att Amp-Env Dec Amp-Env Rel Fil1-Env AttFil1-Env DecFil1-Env RelFil2-Env AttFil2-Env DecFil2-Env RelMod1-Env AttMod1-Env DecMod1-Env RelMod2-Env AttMod2-Env DecMod2-Env RelSampleStart1SampleStart2"
               + param_1 + 0x1ac;
    }
    else {
      if (iVar3 != 3) {
        return;
      }
      pcVar6 = "LoopSampler";
      pcVar2 = (char *)(param_1 + 0x8d9e0);
    }
  }
  else if (param_4 == 0xd1) {
    iVar3 = Envelope_c_vslot_12(iVar5,param_2,0x5b);
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xd1);
    if (iVar3 == 1) {
      pcVar6 = "TimeSampler";
      pcVar2 = "KajaSamples" + param_1;
    }
    else if (iVar3 < 2) {
      if (iVar3 != 0) {
        return;
      }
      pcVar6 = "Oscillator";
      pcVar2 = "Reverb X Room" + param_1 + 8;
    }
    else if (iVar3 == 2) {
      pcVar6 = "Schrader   ";
      pcVar2 = "   --       Key Log     Key Lin     Velocity    MonATch     PitchWhl    ModWhl      BreathC     FootC       ExpressC    Contrl16    Contrl17    Contrl18    Contrl19    LFO 1       LFO 2       LFO 3       LFO 4       GenEnvelope1GenEnvelope2   Mod-Env  "
               + param_1 + 0x7c;
    }
    else {
      if (iVar3 != 3) {
        return;
      }
      pcVar6 = "LoopSampler";
      pcVar2 = (char *)(param_1 + 0x97b98);
    }
  }
  else if (param_4 == 0xd2) {
    iVar3 = Envelope_c_vslot_12(iVar5,param_2,0x66);
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xd2);
    if (iVar3 == 1) {
      pcVar6 = "TimeSampler";
      pcVar2 = "   --       Ampl 1      Ampl 2      Ampl 3      Ampl 4      Pitch 1     Pitch 2     Pitch 3     Pitch 4     PW Gen 1    PW Gen 2    AuxMod Osc 3AuxMod Osc 4Osc1Balance Osc2Balance Osc3Balance Osc4Balance Cutoff      Resonanc    Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxxMast.Amp    Mast.Pit    ModAmt 1    ModAmt 2    ModAmt 3    ModAmt 4    LFO1 Frq    LFO2 Frq   "
               + param_1 + 0x16c;
    }
    else if (iVar3 == 2) {
      pcVar6 = "Schrader   ";
      pcVar2 = "    - - -     Note Log    Note Lin    Velocity  AfterT(mono)Pitch Wheel ModulatWheelBreathContr  FootContr  ExpressContrCC16 Contr  CC17 Contr  CC18 Contr  CC19 Contr  LFO 1       LFO 2       LFO 3       LFO 4       GenEnvelope1GenEnvelope2Mod-Envelope"
               + param_1 + 8;
    }
    else {
      if (iVar3 != 0) {
        return;
      }
      pcVar6 = "Oscillator";
      pcVar2 = "PingPong Time Right 2 " + param_1 + 4;
    }
  }
  else if (param_4 == 0xd3) {
    iVar3 = Envelope_c_vslot_12(iVar5,param_2,0x67);
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xd3);
    if (iVar3 == 1) {
      pcVar6 = "TimeSampler";
      pcVar2 = "    - - -    Ampl Osc 1  Ampl Osc 2  Ampl Osc 3  Ampl Osc 4 Pitch Osc 1 Pitch Osc 2 Pitch Osc 3 Pitch Osc 4 Pulsewidth 1Time Samp 2 AuxMod Osc 3AuxMod Osc 4Osc1Balance Osc2Balance Osc3Balance Osc4Balance    Cutoff    Resonance  Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxx Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 "
               + param_1 + 0x1bc;
    }
    else if (iVar3 == 2) {
      pcVar6 = "Schrader   ";
      pcVar2 = "    - - -     Note Log    Note Lin    Velocity  Aftertouch  Pitch Wheel ModulatWheelBreathContr  FootContr  ExpressContrCC16 Contr  CC17 Contr  CC18 Contr  CC19 Contr     LFO 1       LFO 2       LFO 3       LFO 4    GenEnvelope1GenEnvelope2ModEnvelope1ModEnvelope2Fil1EnvelopeFil2EnvelopeAmp EnvelopeGlide Curve Arpeggiator Alternate   Constant    "
               + param_1 + 0x24;
    }
    else {
      if (iVar3 != 0) {
        return;
      }
      pcVar6 = "Oscillator";
      pcVar2 = "Crush 2 Reso" + param_1 + 0xc;
    }
  }
  else if (param_4 == 0xcd) {
    iVar3 = Envelope_c_vslot_12(iVar5,param_2,0x9a);
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xcd);
    if (iVar3 == 1) {
      pcVar6 = "LFO";
      pcVar2 = (char *)(param_1 + 0xb86d4);
    }
    else if (iVar3 < 2) {
      if (iVar3 != 0) {
        return;
      }
      pcVar6 = "LFO";
      pcVar2 = (char *)(param_1 + 0xb7994);
    }
    else if (iVar3 == 2) {
      pcVar6 = "LFO";
      pcVar2 = "Muse Research" + param_1 + 0xc;
    }
    else {
      if (iVar3 != 3) {
        return;
      }
      pcVar6 = "LFO";
      pcVar2 = "3A7Ay6NWGfbAPS8WsT9" + param_1 + 0x10;
    }
  }
  else if (param_4 == 0xca) {
    uVar4 = Envelope_c_vslot_12(iVar5,param_2,0x99);
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xca);
    switch(uVar4) {
    case 0:
      pcVar6 = "Envelope";
      pcVar2 = "Loop Counter" + param_1 + 4;
      break;
    case 1:
      pcVar6 = "Envelope";
      pcVar2 = "Off  16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
               + param_1 + 0x14;
      break;
    case 2:
      pcVar6 = "Envelope";
      pcVar2 = "Tim 1" + param_1 + 4;
      break;
    case 3:
      pcVar6 = "Envelope";
      pcVar2 = "TimeSampler" + param_1;
      break;
    case 4:
      pcVar6 = "Envelope";
      pcVar2 = "Gen 2 Release" + param_1;
      break;
    default:
      goto LAB_0004c3a0;
    }
  }
  else if (param_4 == 0xcb) {
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xcb);
    pcVar6 = "Envelope";
    pcVar2 = "Gen-Tim 2 Reverse" + param_1 + 0x10;
  }
  else {
    if (param_4 != 0xcc) {
      return;
    }
    uVar1 = Envelope_c_vslot_12(iVar5,param_2,0xcc);
    pcVar6 = "Envelope";
    pcVar2 = "Gen-WT 1 Ride" + param_1 + 0xc;
  }
  FUN_000b5a12(param_1 + 0x44f4,pcVar2,param_2,uVar1,pcVar6);
  return;
}

