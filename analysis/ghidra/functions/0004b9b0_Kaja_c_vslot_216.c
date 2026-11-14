/* 0004b9b0 Kaja_c_vslot_216 */

void Kaja_c_vslot_216(int param_1,int param_2)

{
  int iVar1;
  
  Synth_vslot_216(param_1,param_2);
  Envelope_c_vslot_9("Gen 2 Release" + param_1,param_2,6,0);
  Envelope_c_vslot_9("Gen 2 Release" + param_1,param_2,7,0);
  Envelope_c_vslot_9("Gen-Tim 2 Reverse" + param_1 + 0x10,param_2,6,0);
  Envelope_c_vslot_9("Gen-Tim 2 Reverse" + param_1 + 0x10,param_2,7,0);
  Envelope_c_vslot_9("Gen-WT 1 Ride" + param_1 + 0xc,param_2,6,0);
  Envelope_c_vslot_9("Gen-WT 1 Ride" + param_1 + 0xc,param_2,7,0);
  Envelope_c_vslot_9("Loop Counter" + param_1 + 4,param_2,6,0);
  Envelope_c_vslot_9("Loop Counter" + param_1 + 4,param_2,7,0);
  Envelope_c_vslot_9("Off  16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
                     + param_1 + 0x14,param_2,6,0);
  Envelope_c_vslot_9("Off  16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
                     + param_1 + 0x14,param_2,7,0);
  Envelope_c_vslot_9("Tim 1" + param_1 + 4,param_2,6,0);
  Envelope_c_vslot_9("Tim 1" + param_1 + 4,param_2,7,0);
  Envelope_c_vslot_9("TimeSampler" + param_1,param_2,6,0);
  Envelope_c_vslot_9("TimeSampler" + param_1,param_2,7,0);
  Envelope_c_vslot_9("Chorus 1 Rate Spread" + param_1 + 4,param_2,1,1);
  Envelope_c_vslot_9("KajaSamples" + param_1,param_2,1,1);
  iVar1 = param_2 * 0x14ff4;
  Envelope_c_vslot_9(iVar1 + 0xa59d8 + param_1,param_2,7,1);
  Envelope_c_vslot_9(iVar1 + 0xab710 + param_1,param_2,7,1);
  Envelope_c_vslot_9(iVar1 + 0xb1448 + param_1,param_2,7,1);
  FUN_0004b81e(param_1,param_2,0xffffffff);
  return;
}

