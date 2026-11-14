/* 0004c9a2 FUN_0004c9a2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004c9a2(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  undefined1 local_15c [332];
  
  iVar1 = param_3 + -0xd8;
  Envelope_c_vslot_18(param_1 + 0xcaa81,param_2,param_3,local_15c);
  lVar3 = (longdouble)FUN_0008e3f2(param_1 + iVar1 * 0x1ba + 0x22f90,param_2,local_15c,0);
  iVar2 = (**(code **)(param_1[iVar1 * 0xa3 + 0x2fab4] + 0x30))
                    ("    - - -    Ampl Osc 1  Ampl Osc 2  Ampl Osc 3  Ampl Osc 4 Pitch Osc 1 Pitch Osc 2 Pitch Osc 3 Pitch Osc 4 AuxMod Osc 1AuxMod Osc 2AuxMod Osc 3AuxMod Osc 4Balance Osc1Balance Osc2Balance Osc3Balance Osc4  Cutoff 1   Resonance 1Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxx Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4 LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 Amp-Env Att Amp-Env Dec Amp-Env Rel Fil1-Env AttFil1-Env DecFil1-Env RelFil2-Env AttFil2-Env DecFil2-Env RelMod1-Env AttMod1-Env DecMod1-Env RelMod2-Env AttMod2-Env DecMod2-Env RelSampleStart1SampleStart2"
                     + iVar1 * 0x28c + 0x1ac + (int)param_1,param_2,6);
  (**(code **)(param_1[iVar1 * 0xa3 + 0x2fab4] + 0x24))
            ("    - - -    Ampl Osc 1  Ampl Osc 2  Ampl Osc 3  Ampl Osc 4 Pitch Osc 1 Pitch Osc 2 Pitch Osc 3 Pitch Osc 4 AuxMod Osc 1AuxMod Osc 2AuxMod Osc 3AuxMod Osc 4Balance Osc1Balance Osc2Balance Osc3Balance Osc4  Cutoff 1   Resonance 1Env-Depth 1 AuxMod Fil 1 Pan Fil 1    xxxxxxxxxxxxCutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  xxxxxxxxxxxx Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4 LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 Amp-Env Att Amp-Env Dec Amp-Env Rel Fil1-Env AttFil1-Env DecFil1-Env RelFil2-Env AttFil2-Env DecFil2-Env RelMod1-Env AttMod1-Env DecMod1-Env RelMod2-Env AttMod2-Env DecMod2-Env RelSampleStart1SampleStart2"
             + iVar1 * 0x28c + 0x1ac + (int)param_1,param_2,6,
             (int)((float)iVar2 * (float)lVar3 + 0.25));
  (**(code **)(*param_1 + 0x350))(param_1);
  return;
}

