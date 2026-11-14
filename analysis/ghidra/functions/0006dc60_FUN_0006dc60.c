/* 0006dc60 FUN_0006dc60 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006dc60(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  iVar3 = (int)((float)param_1[0x50] * 0.68);
  if (iVar3 < 2) {
    iVar4 = 1;
    param_1[0x292] = 1;
    param_1[0x293] = 0;
    pvVar1 = (void *)param_1[0x291];
  }
  else {
    iVar5 = 1;
    do {
      iVar4 = iVar5 * 2;
      iVar2 = iVar5 * -2;
      iVar5 = iVar4;
    } while (iVar3 != iVar4 && SBORROW4(iVar3,iVar4) == iVar3 + iVar2 < 0);
    param_1[0x292] = iVar4;
    param_1[0x293] = iVar4 + -1;
    pvVar1 = (void *)param_1[0x291];
  }
  if (pvVar1 == (void *)0x0) {
    param_1[0x291] = 0;
    iVar3 = FUN_00013124(param_1,iVar4);
    param_1[0x291] = iVar3;
  }
  else {
    _free(pvVar1);
    param_1[0x291] = 0;
    iVar3 = FUN_00013124(param_1,param_1[0x292]);
    param_1[0x291] = iVar3;
  }
  if (iVar3 != 0) {
    param_1[0x78] = 0;
    param_1[0x79] = 0;
    param_1[0x7a] = 0;
    param_1[0x7b] = 0;
    param_1[0x7c] = 0;
    param_1[0x7d] = 0;
    param_1[0x7e] = 0;
    param_1[0x7f] = 0;
    param_1[0x81] = param_1[0x292] + param_1[0x292] / 2;
    if (0 < param_1[0x292]) {
      fVar6 = 1e-07;
      iVar3 = 0;
      do {
        *(float *)(param_1[0x291] + iVar3 * 4) = fVar6;
        fVar6 = -fVar6;
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[0x292]);
    }
                    /* WARNING: Could not recover jumptable at 0x0006dd61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
  return;
}

