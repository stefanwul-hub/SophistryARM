/* 000749f8 FilterFree_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void FilterFree_c_vslot_40(int param_1,float param_2)

{
  if (param_2 <= 0.0) {
    return;
  }
  param_2 = 40000.0 / param_2;
  *(float *)(param_1 + 0x220) = param_2;
  if ((param_2 < 0.1) && (!NAN(param_2))) {
    *(float *)(param_1 + 0x220) = 0.1;
    Part_c_vslot_40();
    return;
  }
  *(float *)(param_1 + 0x220) =
       (float)(~-(uint)(param_2 <= 1.0) & (uint)1.0 | (uint)param_2 & -(uint)(param_2 <= 1.0));
  Part_c_vslot_40();
  return;
}

