/* 0007734e FilterMoogSI_c_vslot_27 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FilterMoogSI_c_vslot_27(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x124) != 0) {
    if (param_2 == 0) {
      return (longdouble)*(float *)(param_1 + 0x4328);
    }
    if (param_2 == 1) {
      return (longdouble)(*(float *)(*(int *)(param_1 + 0x124) + 0x1cc) * 0.01);
    }
  }
  return (longdouble)0;
}

