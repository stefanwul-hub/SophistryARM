/* 0004bc7a FUN_0004bc7a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004bc7a(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  double dVar8;
  int local_20;
  
  iVar5 = param_1 + 0x32aa04;
  iVar1 = Envelope_c_vslot_12(iVar5,0,4);
  iVar3 = iVar1 / 0x14;
  if (iVar1 < 1) {
    local_20 = -iVar3;
  }
  else if (iVar3 == 0) {
    iVar3 = 1;
    local_20 = -1;
  }
  else {
    local_20 = -iVar3;
  }
  Envelope_c_vslot_9(iVar5,0,0xb1,iVar3);
  Envelope_c_vslot_9(iVar5,0,0xb2,local_20);
  Envelope_c_vslot_9(iVar5,0,0xb3,iVar3);
  Envelope_c_vslot_9(iVar5,0,0xb4,local_20);
  Envelope_c_vslot_9(iVar5,0,4,0xffffffff);
  Envelope_c_vslot_9(iVar5,0,0x75,0);
  Envelope_c_vslot_9(iVar5,0,100,0);
  Envelope_c_vslot_7(param_1 + 0xc0e30,0,2,0);
  uVar2 = Envelope_c_vslot_12(iVar5,0,0x53);
  iVar3 = Envelope_c_vslot_12(iVar5,0,0x57);
  if (iVar3 == 0) {
    Envelope_c_vslot_9("Chorus 1 Rate Spread" + param_1 + 4,0,0xc,uVar2);
    Envelope_c_vslot_9("51 Cen Gen 2" + param_1,0,9,uVar2);
    (**(code **)(*(int *)(
                         "    - - -    Ampl Osc 1  Ampl Osc 2  Ampl Osc 3  Ampl Osc 4 Pitch Osc 1 Pitch Osc 2 Pitch Osc 3 Pitch Osc 4 AuxMod Osc 1AuxMod Osc 2AuxMod Osc 3AuxMod Osc 4Balance Osc1Balance Osc2Balance Osc3Balance Osc4  Cutoff 1   Resonance 1Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxx Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4 LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 Amp-Env Att Amp-Env Dec Amp-Env Rel Fil1-Env AttFil1-Env DecFil1-Env RelFil2-Env AttFil2-Env DecFil2-Env RelMod1-Env AttMod1-Env DecMod1-Env RelMod2-Env AttMod2-Env DecMod2-Env RelSampleStart1SampleStart2"
                         + param_1 + 0x1ac) + 0x24))
              ("    - - -    Ampl Osc 1  Ampl Osc 2  Ampl Osc 3  Ampl Osc 4 Pitch Osc 1 Pitch Osc 2 Pitch Osc 3 Pitch Osc 4 AuxMod Osc 1AuxMod Osc 2AuxMod Osc 3AuxMod Osc 4Balance Osc1Balance Osc2Balance Osc3Balance Osc4  Cutoff 1   Resonance 1Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxx Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4 LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 Amp-Env Att Amp-Env Dec Amp-Env Rel Fil1-Env AttFil1-Env DecFil1-Env RelFil2-Env AttFil2-Env DecFil2-Env RelMod1-Env AttMod1-Env DecMod1-Env RelMod2-Env AttMod2-Env DecMod2-Env RelSampleStart1SampleStart2"
               + param_1 + 0x1ac,0,8,uVar2);
  }
  Envelope_c_vslot_9("Reverb X Room" + param_1 + 8,0,0xc,uVar2);
  Envelope_c_vslot_9("KajaSamples" + param_1,0,9,uVar2);
  (**(code **)(*(int *)(
                       "   --       Key Log     Key Lin     Velocity    MonATch     PitchWhl    ModWhl      BreathC     FootC       ExpressC    Contrl16    Contrl17    Contrl18    Contrl19    LFO 1       LFO 2       LFO 3       LFO 4       GenEnvelope1GenEnvelope2   Mod-Env  "
                       + param_1 + 0x7c) + 0x24))
            ("   --       Key Log     Key Lin     Velocity    MonATch     PitchWhl    ModWhl      BreathC     FootC       ExpressC    Contrl16    Contrl17    Contrl18    Contrl19    LFO 1       LFO 2       LFO 3       LFO 4       GenEnvelope1GenEnvelope2   Mod-Env  "
             + param_1 + 0x7c,0,8,uVar2);
  lVar6 = (longdouble)Envelope_c_vslot_8(iVar5,0,0x54);
  dVar8 = (double)(float)lVar6;
  iVar3 = Envelope_c_vslot_12(iVar5,0,0x57);
  if (iVar3 == 0) {
    lVar6 = (longdouble)_log10(dVar8 * -0.999 + 1.0);
    lVar7 = (longdouble)_log10(dVar8 * 0.999);
    iVar3 = (int)((double)lVar7 * 100.0 + 0.5);
  }
  else {
    lVar6 = (longdouble)_log10(dVar8 * -0.999 + 1.0);
    iVar3 = 0;
  }
  Envelope_c_vslot_9(iVar5,0,0xb5,(int)((double)lVar6 * 100.0 + 0.5));
  Envelope_c_vslot_9(iVar5,0,0xb6,iVar3);
  uVar2 = Envelope_c_vslot_12(param_1 + 0xc1200,0,1);
  Envelope_c_vslot_9(iVar5,0,0x74,uVar2);
  uVar2 = Envelope_c_vslot_12(iVar5,0,0x61);
  Envelope_c_vslot_9(iVar5,0,0x6c,uVar2);
  FUN_0004b81e(param_1,0,0);
  uVar2 = Envelope_c_vslot_12(iVar5,0,0x62);
  Envelope_c_vslot_9(iVar5,0,0x6d,uVar2);
  Envelope_c_vslot_9(iVar5,0,0x61,5);
  iVar3 = Envelope_c_vslot_12(param_1 + 0xc9e30,0,2);
  puVar4 = &UNK_000a850c + param_1;
  Envelope_c_vslot_9(puVar4,0,4,iVar3);
  Envelope_c_vslot_7(iVar5,0,0xba,0x3f800000);
  if (iVar3 < 1) {
    Envelope_c_vslot_9(iVar5,0,0x62,0);
  }
  else {
    Envelope_c_vslot_9(iVar5,0,0x62,1);
    Envelope_c_vslot_7(puVar4,0,5,0x3f800000);
    Envelope_c_vslot_7(puVar4,0,6,0);
    Envelope_c_vslot_7(puVar4,0,8,0);
  }
  Envelope_c_vslot_7("Off     Mod-OnlyUp      Down    Up/Down Up/Down+Down/Up Down/Up+Random  Chord   AsPlayed"
                     + param_1 + 0x48,0,2,0);
  Envelope_c_vslot_7("PulseWidth" + param_1 + 8,0,2,0);
  Envelope_c_vslot_7("Loop Counter" + param_1 + 4,0,5,0x3f800000);
  Envelope_c_vslot_7("Off  16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
                     + param_1 + 0x14,0,5,0x3f800000);
  iVar3 = Envelope_c_vslot_12(iVar5,0,0x50);
  if (iVar3 == 0) {
    Envelope_c_vslot_7(iVar5,0,0xae,0);
  }
  else {
    Envelope_c_vslot_7(iVar5,0,0xae,0x3f800000);
  }
  Envelope_c_vslot_7(iVar5,0,0xaf,0);
  Envelope_c_vslot_7(iVar5,0,0xb0,0);
  return;
}

