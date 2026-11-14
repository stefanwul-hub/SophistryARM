/* 000604ba KajaGlo_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void KajaGlo_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0xdc);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00010f72(iVar1 + 0x70,"PrgName",0,0,0);
    FUN_000118be(iVar1 + 0xe0,"Main Vol.",0xffffffe2,0,0xffffffe2,1);
    FUN_000117e2(iVar1 + 0x150,"Scal.Centr",0x18,0x6c,0,0x3c);
    FUN_00011652(iVar1 + 0x1c0,"Detune","cent",0x40800000,0xffffffff,500,1,0xffffffff,0);
    FUN_00010218(iVar1 + 0x230,"FilterType","",0xffffffff,2,4,0,"LP12LP24 BP  HP ",
                 &PTR_s_LP12LP24HP12BP24_000e208c);
    FUN_00011652(iVar1 + 0x2a0,"EnvDepth","",0,0,100,2,100,0);
    FUN_00010290(iVar1 + 0x310,"EnvInv",0);
    iVar5 = iVar1 + 0x380;
    iVar6 = 0x18;
    do {
      FUN_00010218(iVar5,"Mod.Source","",0xffffffff,0x1b,0xc,0xffffffff,
                   "    - - -     Note Log    Note Lin    Velocity  Aftertouch  Pitch Wheel ModulatWheelBreathContr  FootContr  ExpressContrCC16 Contr  CC17 Contr  CC18 Contr  CC19 Contr     LFO 1       LFO 2       LFO 3       LFO 4    GenEnvelope1GenEnvelope2ModEnvelope1ModEnvelope2Fil1EnvelopeFil2EnvelopeAmp EnvelopeGlide Curve Arpeggiator Alternate   Constant    "
                   ,&PTR_s____Key_Log_Key_Lin_Velocity_PolA_000e2070);
      FUN_00010218(iVar5 + 0x1500,"Mod.Dest.","",0xffffffff,0x38,0xc,0xffffffff,
                   "    - - -    Ampl Gen 1  Ampl Gen 2  Ampl Gen 3  Ampl Gen 4 Pitch Gen 1 Pitch Gen 2 Pitch Gen 3 Pitch Gen 4 AuxMod Gen 1AuxMod Gen 2AuxMod Gen 3AuxMod Gen 4Balance Gen1Balance Gen2Balance Gen3Balance Gen4  Cutoff 1   Resonance 1Env-Depth 1 AuxMod Fil 1 Pan Fil 1  Fil 1 Ampli   Cutoff 2   Resonance 2Env-Depth 2 AuxMod Fil 2 Pan Fil 2  Fil 2 Ampli  Main Ampli  Main Pitch Mod Depth 1 Mod Depth 2 Mod Depth 3 Mod Depth 4 LFO 1 Speed LFO 2 Speed Loop Start 1Loop Start 2 Loop End 1  Loop End 2 Amp-Env Att Amp-Env Dec Amp-Env Rel Fil1-Env AttFil1-Env DecFil1-Env RelFil2-Env AttFil2-Env DecFil2-Env RelMod1-Env AttMod1-Env DecMod1-Env RelMod2-Env AttMod2-Env DecMod2-Env RelSampleStart1SampleStart2"
                   ,&PTR_s____Ampl_1_Ampl_2_Ampl_3_Ampl_4_P_000e2058);
      FUN_00011652(iVar5 + 0xa80,"Mod.Amount","",0,0xffffd8f0,10000,4,0,5);
      iVar5 = iVar5 + 0x70;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_00010290(iVar1 + 0x2300,"DMVol",1);
    FUN_00010290(iVar1 + 0x2370,"DMVel",1);
    FUN_00010290(iVar1 + 0x23e0,"DMWh ",1);
    FUN_00011652(iVar1 + 0x2450,"Unusued Spread","cent",0x40800000,0,2000,2,0,0);
    FUN_00011652(iVar1 + 0x24c0,"Unusued GenMix","% Gen2",0,0,1000,3,500,0);
    FUN_00010f72(iVar1 + 0x2530,"Unused",1,0,0);
    FUN_00010f72(iVar1 + 0x25a0,"Unused",1,0,0);
    FUN_00010218(iVar1 + 0x2610,"Gen0 Routing","",0,2,3,0,"MixAM FM ",0);
    FUN_00010290(iVar1 + 0x2680,"Unused",0);
    FUN_00010290(iVar1 + 0x26f0,"Unused",0);
    FUN_00010218(iVar1 + 0x2760,"Gen 0 Type","",0,3,0xc,0,
                 "Oscillator  Time SamplerSchrader    Loop Sampler",
                 &PTR_s_Analogue_TimeSamp_Schrader_LoopS_000e2050);
    FUN_00010218(iVar1 + 0x27d0,"Gen 1 Type","",0,3,0xc,1,
                 "Oscillator  Time SamplerSchrader    Loop Sampler",
                 &PTR_s_Analogue_TimeSamp_Schrader_LoopS_000e2050);
    FUN_00010290(iVar1 + 0x2840,"Gen 0 OnOff",1);
    FUN_00010290(&UNK_000028b0 + iVar1,"Gen 1 OnOff",1);
    FUN_00010218(iVar1 + 0x2920,"Unused","",0,1,8,0,"SettingsLooppnts",0);
    FUN_00010218(iVar1 + 0x2990,"Unused","",0,1,8,0,"SettingsLooppnts",0);
    FUN_00010218(iVar1 + 0x2a00,"Voices","",1,0xd,4,0xd,
                 "mono  2   3   4   5   6   7   8   9  10  11  12  all",
                 &PTR_s_1_2_3_4_5_6_7_8_xxxxxxxxxxxxxxxx_000e2048);
    FUN_0001042e(iVar1 + 0x2a00,1);
    FUN_00010218(iVar1 + 0x2a70,"Eff 0 Type","",0,0xb,10,0,
                 "DELAY     ST-DELAY  PING PONG CHORUS    PHASER    FILTER    REVERB    FLANGER   GATOR     ST-ENHANC PARAM-EQ  CRUSHER   "
                 ,&PTR_s_Delay_StDelay_xxxxxxxxxxChorus_P_000e2040);
    FUN_00010290(iVar1 + 0x2ae0,"Eff 0 On",1);
    FUN_00010218(iVar1 + 0x2b50,"Eff 0 Type","",0,0xb,10,0,
                 "DELAY     ST-DELAY  PING PONG CHORUS    PHASER    FILTER    REVERB    FLANGER   GATOR     ST-ENHANC PARAM-EQ  CRUSHER   "
                 ,&PTR_s_Delay_StDelay_xxxxxxxxxxChorus_P_000e2040);
    FUN_00010290(iVar1 + 0x2bc0,"Eff 1 On",1);
    FUN_00010218(iVar1 + 0x2c30,"Gen2 Routing","",0,2,3,0,"MixAM FM ",0);
    FUN_00010218(iVar1 + 0x2ca0,"Gen 2 Type","",0,2,0xc,0,"Oscillator  Time SamplerSchrader    ",
                 &PTR_s_Analogue_TimeSamp_Schrader_LoopS_000e2050);
    FUN_00010218(iVar1 + 0x2d10,"Gen 3 Type","",0,2,0xc,0,"Oscillator  Time SamplerSchrader    ",
                 &PTR_s_Analogue_TimeSamp_Schrader_LoopS_000e2050);
    FUN_00010290(iVar1 + 0x2d80,"Gen 2 OnOff",0);
    FUN_00010290(iVar1 + 0x2df0,"Gen 3 OnOff",0);
    FUN_00010218(iVar1 + 0x2e60,"Var 0 Type","",0,1,8,0,"Classic Alltype ",0);
    FUN_00010218(iVar1 + 0x2ed0,"Var 1 Type","",0,1,8,0,"Classic Alltype ",0);
    FUN_00010218(iVar1 + 0x2f40,"Eff X0 Type","",0,0xb,10,0,
                 "DELAY     ST-DELAY  PING PONG CHORUS    PHASER    FILTER    REVERB    FLANGER   GATOR     ST-ENHANC PARAM-EQ  CRUSHER   "
                 ,&PTR_s_Delay_StDelay_xxxxxxxxxxChorus_P_000e2040);
    FUN_00010290(iVar1 + 0x2fb0,"Eff X0 On",0);
    FUN_00010218(iVar1 + 0x3020,"Eff X1 Type","",0,0xb,10,0,
                 "DELAY     ST-DELAY  PING PONG CHORUS    PHASER    FILTER    REVERB    FLANGER   GATOR     ST-ENHANC PARAM-EQ  CRUSHER   "
                 ,&PTR_s_Delay_StDelay_xxxxxxxxxxChorus_P_000e2040);
    FUN_00010290(iVar1 + 0x3090,"Eff X1 On",0);
    FUN_00010218(iVar1 + 0x3100,"Eff X2 Type","",0,0xb,10,0,
                 "DELAY     ST-DELAY  PING PONG CHORUS    PHASER    FILTER    REVERB    FLANGER   GATOR     ST-ENHANC PARAM-EQ  CRUSHER   "
                 ,&PTR_s_Delay_StDelay_xxxxxxxxxxChorus_P_000e2040);
    FUN_00010290(iVar1 + 0x3170,"Eff X2 On",0);
    FUN_00010218(iVar1 + 0x31e0,"Eff X3 Type","",0,0xb,10,0,
                 "DELAY     ST-DELAY  PING PONG CHORUS    PHASER    FILTER    REVERB    FLANGER   GATOR     ST-ENHANC PARAM-EQ  CRUSHER   "
                 ,&PTR_s_Delay_StDelay_xxxxxxxxxxChorus_P_000e2040);
    FUN_00010290(iVar1 + 0x3250,"Eff X3 On",0);
    FUN_00010290(iVar1 + 0x32c0,"Var 0 On",1);
    FUN_00010290(iVar1 + 0x3330,"Var 1 On",1);
    FUN_00011652(iVar1 + 0x33a0,"F0 Cut KeyF ","",0,0,100,2,0,0);
    FUN_00011652(iVar1 + 0x3410,"F0 Cut KeyF ","",0,0,100,2,0,0);
    FUN_00010218(iVar1 + 0x3480,"FilterType","",0xffffffff,2,4,0,"LP12LP24 BP  HP ",
                 &PTR_s_LP12LP24HP12BP24_000e208c);
    FUN_00011652(iVar1 + 0x34f0,"EnvDepth","",0,0,100,2,100,0);
    FUN_00010290(iVar1 + 0x3560,"EnvInv",0);
    FUN_00010f72(iVar1 + 0x35d0,"Import Sampler 0 SF2 Path",0,0,0);
    FUN_00010f72(iVar1 + 0x3640,"Import Sampler 1 SF2 Path",0,0,0);
    iVar5 = iVar1 + 14000;
    iVar6 = 0x18;
    do {
      FUN_00010290(iVar5,"Mod.Active",1);
      iVar5 = iVar5 + 0x70;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_00010290(iVar1 + 0x4130,"LFO0 Perm",0);
    FUN_00010290(iVar1 + 0x41a0,"LFO1 Perm",0);
    FUN_00010290(iVar1 + 0x4210,"LFO2 Perm",0);
    FUN_00010290(iVar1 + 0x4280,"LFO3 Perm",0);
    FUN_00010218(iVar1 + 0x42f0,"Env Sel","",0,4,2,4,"M1M2M3M4A ",0);
    FUN_00010218(iVar1 + 0x4360,"LFO Sel","",0,3,1,0,"1234",0);
    FUN_00011652(iVar1 + 0x43d0,"Sample 0 Scrolling","",0,0,7,0,0,0);
    FUN_00011652(iVar1 + 0x4440,"Sample 0 Editing","",0,0,7,0,0,0);
    FUN_00011652(iVar1 + 0x44b0,"Sample 0 Shown","",0,0,0x3f,0,0,0);
    FUN_00011652(iVar1 + 0x4520,"Sample 1 Scrolling","",0,0,7,0,0,0);
    FUN_00011652(iVar1 + 0x4590,"Sample 1 Editing","",0,0,7,0,0,0);
    FUN_00011652(iVar1 + 0x4600,"Sample 1 Shown","",0,0,0x3f,0,0,0);
    FUN_00010218(iVar1 + 0x4670,"SD Zoom 0","",0,0xd,4,6,
                 "   1   2   4   8  16  32  64 128 256 5121024204840968192",0);
    FUN_00010218(iVar1 + 0x46e0,"SD Zoom 1","",0,0xd,4,6,
                 "   1   2   4   8  16  32  64 128 256 5121024204840968192",0);
    FUN_00011652(iVar1 + 0x4750,"SD Slider 0","pm",0,0,1000,3,0,0);
    FUN_00011652(iVar1 + 0x47c0,"SD Slider 1","pm",0,0,1000,3,0,0);
    FUN_00011652(iVar1 + 0x4830,"SD Slider Size 0","pm",0,10,1000,3,1000,0);
    FUN_00011652(iVar1 + 0x48a0,"SD Slider Size 1","pm",0,10,1000,3,1000,0);
    FUN_00010218(iVar1 + 0x4910,"Var 0 Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00010218(iVar1 + 0x4980,"Var 1 Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00010218(iVar1 + 0x49f0,"Mod 0 Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00010218(iVar1 + 0x4a60,"Mod 1 Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00010218(iVar1 + 0x4ad0,"Mod 2 Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00010218(iVar1 + 0x4b40,"Mod 3 Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00010218(iVar1 + 0x4bb0,"Amp Env","",0,1,6,0,"ADSFR EnhEnv",0);
    FUN_00011652(&UNK_00004c20 + iVar1,"Vel->Vol","%",0,0,100,2,0x42,0);
    FUN_00011652(iVar1 + 0x4c90,"Vel->F1Cut","%",0,0,100,2,0xf,0);
    FUN_00011652(iVar1 + 0x4d00,"Vel->F2Cut","%",0,0,100,2,0xf,0);
    FUN_00011652(iVar1 + 0x4d70,"G3 Cent","cent",0,0xffffff9c,100,0,0,0);
    FUN_00011652(&UNK_00004de0 + iVar1,"G3 Cent","cent",0,0xffffff9c,100,0,0,0);
    FUN_00011652(iVar1 + 0x4e50,"G3 Cent","cent",0,0xffffff9c,100,0,0,0);
    FUN_00011652(iVar1 + 0x4ec0,"G3 Cent","cent",0,0xffffff9c,100,0,0,0);
    FUN_000118be(iVar1 + 0x4f30,"Gen0 Vol.",0xffffffdc,0,0xfffffff1,1);
    FUN_000118be(iVar1 + 0x4fa0,"Gen1 Vol.",0xffffffdc,0,0xfffffff1,1);
    FUN_000118be(iVar1 + 0x5010,"Gen2 Vol.",0xffffffdc,0,0xfffffff1,1);
    FUN_000118be(iVar1 + 0x5080,"Gen3 Vol.",0xffffffdc,0,0xfffffff1,1);
    FUN_00010290(iVar1 + 0x50f0,"Keys",1);
    FUN_00011652(iVar1 + 0x5160,"Fx0 Wet","%",0x40800000,0,1000,3,100,0);
    FUN_00011652(iVar1 + 0x51d0,"Fx1 Wet","%",0x40800000,0,1000,3,100,0);
    FUN_00011652(iVar1 + 0x5240,"Fx2 Wet","%",0x40800000,0,1000,3,100,0);
    FUN_00011652(iVar1 + 0x52b0,"Fx3 Wet","%",0x40800000,0,1000,3,100,0);
    FUN_00011652(&UNK_00005320 + iVar1,"Fx4 Wet","%",0x40800000,0,1000,3,100,0);
    FUN_00011652(iVar1 + 0x5390,"Fx5 Wet","%",0x40800000,0,1000,3,100,0);
    FUN_00010290(iVar1 + 0x5400,"Pow 51 0 ",0);
    FUN_00010290(iVar1 + 0x5470,"Pow 51 1 ",0);
    FUN_00010290(iVar1 + 0x54e0,"Pow 51 2 ",0);
    FUN_00010290(iVar1 + 0x5550,"Pow 51 3 ",0);
    FUN_00010290(iVar1 + 0x55c0,"Pow 51 4 ",0);
    FUN_00010290(iVar1 + 0x5630,"Pow 51 5 ",0);
    FUN_00010290(iVar1 + 0x56a0,"Pow 51 6 ",1);
    FUN_00011652(iVar1 + 0x5710,"Var0Pan","",0,0xffffff9c,100,2,0,0);
    FUN_00011652(iVar1 + 0x5780,"Var1Pan","",0,0xffffff9c,100,2,0,0);
    FUN_00011652(iVar1 + 0x57f0,"Exactness","%",0,0x55,100,2,100,0);
    FUN_00010218(iVar1 + 0x5860,"File IO Env","",2,4,5,2,"Copy PasteInit ",0);
    FUN_00010218(iVar1 + 0x58d0,"File IO EF0","",2,4,5,2,"Copy PasteInit ",0);
    FUN_00010218(iVar1 + 0x5940,"File IO EF1","",2,4,5,2,"Copy PasteInit ",0);
    FUN_00010218(iVar1 + 0x59b0,"File IO LFO","",2,4,5,2,"Copy PasteInit ",0);
    FUN_000118be(iVar1 + 0x5a20,"Gen0 Vol.",0xffffffe8,0,0xfffffff1,1);
    FUN_000118be(iVar1 + 0x5a90,"Gen0 Vol.",0xffffffe8,0,0xfffffff1,1);
    FUN_00010218(iVar1 + 0x5b00,"File IO Gn0","",0,4,5,2,"Load Save Copy PasteInit ",0);
    FUN_00010218(iVar1 + 0x5b70,"File IO Gn1","",0,4,5,2,"Load Save Copy PasteInit ",0);
    FUN_00010218(iVar1 + 0x5be0,"File IO Gn2","",0,4,5,2,"Load Save Copy PasteInit ",0);
    FUN_00010218(iVar1 + 0x5c50,"File IO Gn3","",0,4,5,2,"Load Save Copy PasteInit ",0);
    FUN_00010f72(iVar1 + 0x5cc0,"Export Sample 0",0,0,0);
    FUN_00010f72(iVar1 + 0x5d30,"Export Sample 1",0,0,0);
    FUN_00010f72(iVar1 + 0x5da0,"Export Sample 2",0,0,0);
    FUN_00010f72(iVar1 + 0x5e10,"Export Sample 3",0,0,0);
    FUN_00010f72(iVar1 + 0x5e80,"ExpWTG Sample 0",0,0,0);
    FUN_00010f72(iVar1 + 0x5ef0,"ExpWTG Sample 1",0,0,0);
    FUN_00010f72(iVar1 + 0x5f60,"ExpWTG Sample 2",0,0,0);
    FUN_00010f72(iVar1 + 0x5fd0,"ExpWTG Sample 3",0,0,0);
    FUN_00011b84();
    return;
  }
  return;
}

