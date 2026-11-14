/* 00029f38 Tone_c_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Tone_c_vslot_2(int param_1,undefined4 param_2)

{
  float fVar1;
  
  Instrument_c_vslot_2(param_1,param_2);
  fVar1 = *(float *)(param_1 + 0x10) * 1400.0;
  *(float *)(param_1 + 0xc44) = fVar1;
  if ((fVar1 < 0.0025) && (!NAN(fVar1))) {
    *(float *)(param_1 + 0xc44) = 0.0025;
    return;
  }
  *(float *)(param_1 + 0xc44) =
       (float)(~-(uint)(fVar1 <= 0.25) & (uint)0.25 | (uint)fVar1 & -(uint)(fVar1 <= 0.25));
  return;
}

