/* 000c2a82 Delay2R_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble Delay2R_c_vslot_61(int param_1)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  float fVar4;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    lVar2 = (longdouble)_log10((double)*(float *)(*(int *)(param_1 + 0x124) + 0x15c) + 0.0001);
    lVar2 = (longdouble)FUN_00015302(0,0xc0100000,(double)lVar2);
    iVar1 = *(int *)(param_1 + 0x124);
    fVar4 = *(float *)(iVar1 + 0xec) * 0.001;
    if (*(int *)(iVar1 + 0x414) < *(int *)(iVar1 + 0x3f8)) {
      lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar1 + 0x3f8));
      fVar4 = (float)lVar3;
    }
    for (; (float)*(int *)(param_1 + 0xa48) <= *(float *)(param_1 + 0x140) * fVar4;
        fVar4 = fVar4 * 0.5) {
    }
    return (longdouble)((float)lVar2 * fVar4 + 0.1);
  }
  return (longdouble)0.0;
}

