/* 000748be FilterFree_c_vslot_27 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble FilterFree_c_vslot_27(int param_1,int param_2)

{
  float fVar1;
  
  if (param_2 == 1) {
    return (longdouble)*(float *)(param_1 + 0x2d4);
  }
  if (param_2 != 2) {
    if (param_2 != 0) {
      return (longdouble)0.0;
    }
    return (longdouble)*(float *)(param_1 + 0x2d0);
  }
  fVar1 = *(float *)(param_1 + 0x2d8) - 0.5;
  return (longdouble)(fVar1 + fVar1);
}

