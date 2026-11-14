/* 0008515a EnvDAD_c_vslot_57 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvDAD_c_vslot_57(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  float fVar6;
  
  if ((*(int *)(param_1 + 0x124) == 0) || (*(char *)(param_1 + 0x1f8) == '\0')) {
    return;
  }
  if (1 < *(int *)(param_1 + 0x1f0)) {
    *(undefined4 *)(param_1 + 0x1f0) = 3;
    **(undefined4 **)(param_1 + 0x1d4) = 0;
    **(undefined4 **)(param_1 + 0x1d8) = 0;
    *(undefined1 *)(param_1 + 0x1e0) = 1;
    **(undefined4 **)(param_1 + 0x1dc) = 0x7ffffbff;
    return;
  }
  iVar3 = *(int *)(param_1 + 0x1f0) + 1;
  *(int *)(param_1 + 0x1f0) = iVar3;
  if ((((*(int *)(param_1 + 0x124) == 0) || (iVar3 < 0)) || (2 < iVar3)) || (iVar3 != 1)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 500) = uVar4;
  iVar3 = *(int *)(param_1 + 0x1f0);
  iVar1 = *(int *)(param_1 + 0x124);
  if (((iVar1 != 0) && (-1 < iVar3)) && (0.0 < *(float *)(param_1 + 0x140))) {
    if (2 < iVar3) {
LAB_000852dc:
      iVar3 = 0x7ffffbff;
      fVar6 = 2.1474826e+09;
      goto LAB_0008525b;
    }
    if (iVar3 == 1) {
      fVar6 = (*(float *)(iVar1 + 0xec) * *(float *)(param_1 + 0x1e8)) / *(float *)(param_1 + 0x1ec)
      ;
    }
    else if (iVar3 == 2) {
      fVar6 = *(float *)(iVar1 + 0x15c) * *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0x1ec);
      cVar2 = FUN_00010462(iVar1 + 0x150);
      if (cVar2 != '\0') goto LAB_000852dc;
    }
    else if (iVar3 == 0) {
      fVar6 = (*(float *)(iVar1 + 0x7c) * *(float *)(param_1 + 0x1e8)) / *(float *)(param_1 + 0x1ec)
      ;
    }
    else {
      fVar6 = 1.0;
    }
    iVar3 = (int)(fVar6 * *(float *)(param_1 + 0x140));
    if (0 < iVar3) {
      fVar6 = (float)iVar3;
      goto LAB_0008525b;
    }
  }
  iVar3 = 1;
  fVar6 = 1.0;
LAB_0008525b:
  lVar5 = (longdouble)FUN_000152c0(*(float *)(param_1 + 500) - **(float **)(param_1 + 0x1d4),fVar6);
  **(float **)(param_1 + 0x1d8) = (float)lVar5;
  **(int **)(param_1 + 0x1dc) = iVar3;
  return;
}

