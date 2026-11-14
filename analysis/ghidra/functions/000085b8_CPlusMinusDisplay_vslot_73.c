/* 000085b8 CPlusMinusDisplay_vslot_73 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CPlusMinusDisplay_vslot_73(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  
  lVar3 = (longdouble)FUN_000019e8(param_1);
  fVar4 = (float)lVar3;
  *(undefined1 *)(param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  iVar1 = *param_2;
  if ((iVar1 < *(int *)(param_1 + 0xd0)) || (*(int *)(param_1 + 0xd8) < iVar1)) {
    iVar2 = param_2[1];
  }
  else {
    iVar2 = param_2[1];
    if ((*(int *)(param_1 + 0xd4) <= iVar2) && (iVar2 <= *(int *)(param_1 + 0xdc))) {
      *(undefined1 *)(param_1 + 0x6d) = 1;
      goto LAB_00008678;
    }
  }
  if ((((iVar1 < *(int *)(param_1 + 0xe0)) || (*(int *)(param_1 + 0xe8) < iVar1)) ||
      (iVar2 < *(int *)(param_1 + 0xe4))) || (*(int *)(param_1 + 0xec) < iVar2)) {
    if (param_3 == '\0') {
      fVar4 = 1.0;
    }
    else {
      fVar4 = 0.2;
    }
    fVar4 = ((float)((*(int *)(param_1 + 0xc4) + *(int *)(param_1 + 0xcc)) / 2 - iVar2) / 160.0) *
            fVar4 + 0.5 + (*(float *)(param_1 + 0x78) - 0.5);
  }
  else {
    *(undefined1 *)(param_1 + 0x6c) = 1;
  }
LAB_00008678:
  return (longdouble)fVar4;
}

