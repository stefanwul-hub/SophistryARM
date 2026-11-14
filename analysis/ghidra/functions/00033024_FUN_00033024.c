/* 00033024 FUN_00033024 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00033024(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  iVar2 = (int)((float)param_1[0x50] * 0.01);
  if (iVar2 < 2) {
    iVar3 = 1;
    iVar2 = 0;
  }
  else {
    iVar4 = 1;
    do {
      iVar3 = iVar4 * 2;
      iVar1 = iVar4 * -2;
      iVar4 = iVar3;
    } while (iVar2 != iVar3 && SBORROW4(iVar2,iVar3) == iVar2 + iVar1 < 0);
    iVar2 = iVar3 + -1;
  }
  param_1[0x7b] = iVar3;
  param_1[0x7c] = iVar2;
  if ((void *)param_1[0x78] != (void *)0x0) {
    _free((void *)param_1[0x78]);
  }
  param_1[0x78] = 0;
  if ((void *)param_1[0x79] != (void *)0x0) {
    _free((void *)param_1[0x79]);
  }
  param_1[0x79] = 0;
  iVar2 = FUN_00013124(param_1,param_1[0x7b]);
  param_1[0x78] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x7b]);
  param_1[0x79] = iVar2;
  if ((param_1[0x78] != 0) && (iVar2 != 0)) {
    if (0 < param_1[0x7b]) {
      fVar5 = 1e-07;
      iVar2 = 0;
      do {
        *(float *)(iVar2 * 4 + param_1[0x78]) = fVar5;
        *(float *)(iVar2 * 4 + param_1[0x79]) = fVar5;
        fVar5 = -fVar5;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x7b]);
    }
    param_1[0x7a] = 0;
                    /* WARNING: Could not recover jumptable at 0x0003313c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
  return;
}

