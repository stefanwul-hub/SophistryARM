/* 000018d6 CControlPl_vslot_52 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void CControlPl_vslot_52(int param_1,float param_2)

{
  float fVar1;
  
  if ((param_2 < 0.0) && (!NAN(param_2))) {
    *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 0;
    return;
  }
  fVar1 = 1.0;
  if (param_2 <= 1.0) {
    fVar1 = param_2;
  }
  *(float *)(*(int *)(param_1 + 0x90) + 0x14) = fVar1;
  return;
}

