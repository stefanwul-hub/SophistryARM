/* 00088724 FUN_00088724 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00088724(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  param_1[0x81] = (int)((float)param_1[0x50] * 1.3);
  if ((void *)param_1[0x7b] != (void *)0x0) {
    _free((void *)param_1[0x7b]);
  }
  param_1[0x7b] = 0;
  if ((void *)param_1[0x7c] != (void *)0x0) {
    _free((void *)param_1[0x7c]);
  }
  param_1[0x7c] = 0;
  if ((void *)param_1[0x7d] != (void *)0x0) {
    _free((void *)param_1[0x7d]);
  }
  param_1[0x7d] = 0;
  if ((void *)param_1[0x7e] != (void *)0x0) {
    _free((void *)param_1[0x7e]);
  }
  param_1[0x7e] = 0;
  if ((void *)param_1[0x7f] != (void *)0x0) {
    _free((void *)param_1[0x7f]);
  }
  param_1[0x7f] = 0;
  if ((void *)param_1[0x80] != (void *)0x0) {
    _free((void *)param_1[0x80]);
  }
  param_1[0x80] = 0;
  iVar2 = FUN_00013124(param_1,param_1[0x81]);
  param_1[0x7b] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x81]);
  param_1[0x7c] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x81]);
  param_1[0x7d] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x81]);
  param_1[0x7e] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x81]);
  param_1[0x7f] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x81]);
  param_1[0x80] = iVar2;
  if ((((param_1[0x7b] != 0) && (param_1[0x7c] != 0)) && (param_1[0x7d] != 0)) &&
     (((param_1[0x7e] != 0 && (param_1[0x7f] != 0)) && (iVar2 != 0)))) {
    if (0 < param_1[0x81]) {
      fVar3 = 1e-07;
      iVar2 = 0;
      do {
        iVar1 = iVar2 * 4;
        *(float *)(param_1[0x7b] + iVar1) = fVar3;
        *(float *)(param_1[0x7c] + iVar1) = fVar3;
        *(float *)(param_1[0x7d] + iVar1) = fVar3;
        *(float *)(param_1[0x7e] + iVar1) = fVar3;
        *(float *)(param_1[0x7f] + iVar1) = fVar3;
        *(float *)(iVar1 + param_1[0x80]) = fVar3;
        fVar3 = -fVar3;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x81]);
    }
    param_1[0x78] = 0;
    param_1[0x79] = 0;
    param_1[0x7a] = 0;
    param_1[0x86] = 0;
    param_1[0x87] = 0;
    param_1[0x88] = 0;
                    /* WARNING: Could not recover jumptable at 0x00088994. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
  return;
}

