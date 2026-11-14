/* 00077442 FilterMoogSI_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void FilterMoogSI_c_vslot_40(int param_1,float param_2)

{
  float fVar1;
  
  if (param_2 <= 0.0) {
    return;
  }
  fVar1 = 44100.0 / param_2;
  *(float *)(param_1 + 0x4324) = fVar1;
  if ((fVar1 < 0.1) && (!NAN(fVar1))) {
    *(float *)(param_1 + 0x4324) = 0.1;
    *(float *)(param_1 + 0x1e0) = param_2 * 1.25e-05;
    Part_c_vslot_40();
    return;
  }
  *(float *)(param_1 + 0x4324) =
       (float)(~-(uint)(fVar1 <= 1.0) & (uint)1.0 | (uint)fVar1 & -(uint)(fVar1 <= 1.0));
  *(float *)(param_1 + 0x1e0) = param_2 * 1.25e-05;
  Part_c_vslot_40();
  return;
}

