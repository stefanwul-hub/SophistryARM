/* 000057a6 CKnobPl_vslot_80 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CKnobPl_vslot_80(int param_1,int param_2,char param_3)

{
  float fVar1;
  
  if (param_3 == '\0') {
    fVar1 = 1.0;
  }
  else {
    fVar1 = 10.0;
  }
  fVar1 = ((float)(*(int *)(param_1 + 0xa0) - *(int *)(param_2 + 4)) /
           (fVar1 * *(float *)(param_1 + 0xb0)) + 1.0) * 0.5 + (*(float *)(param_1 + 0x78) - 0.5);
  if (*(char *)(param_1 + 0xb5) == '\0') {
    if (fVar1 < 0.0) {
      return (longdouble)0.0;
    }
    if (1.0 < fVar1) {
      return (longdouble)1.0;
    }
  }
  else {
    for (; 1.0 < fVar1; fVar1 = fVar1 - 1.0) {
    }
    for (; (fVar1 < 0.0 && (fVar1 = fVar1 + 1.0, fVar1 < 0.0)); fVar1 = fVar1 + 1.0) {
    }
  }
  return (longdouble)fVar1;
}

