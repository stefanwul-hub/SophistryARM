/* 0003d4b8 LFOSimp_c_vslot_58 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble LFOSimp_c_vslot_58(int param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  float fVar3;
  
  if ((0.0 < *(float *)(param_1 + 0x144)) && (iVar1 = FUN_00012888(param_1,param_2), iVar1 != 0)) {
    fVar3 = *(float *)(iVar1 + 0x15c);
    if (*(int *)(iVar1 + 0x254) < *(int *)(iVar1 + 0x238)) {
      lVar2 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar1 + 0x238));
      fVar3 = (float)lVar2;
      iVar1 = *(int *)(iVar1 + 0xe8);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xe8);
    }
    if (iVar1 - 4U < 2) {
      fVar3 = fVar3 * 8.0 * 0.00390625;
    }
    return (longdouble)(fVar3 * *(float *)(param_1 + 0x144));
  }
  return (longdouble)0;
}

