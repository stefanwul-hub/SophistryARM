/* 0003f06c FUN_0003f06c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003f06c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  iVar2 = (int)((float)param_1[0x50] * 1.3);
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
  param_1[0x8a] = iVar3;
  param_1[0x83] = iVar2;
  param_1[0x84] = iVar3 * 0x10;
  param_1[0x85] = iVar3 * 0xe;
  *(double *)(param_1 + 0x86) = (double)(iVar3 * 0xe);
  if ((void *)param_1[0x88] != (void *)0x0) {
    _free((void *)param_1[0x88]);
  }
  param_1[0x88] = 0;
  if ((void *)param_1[0x89] != (void *)0x0) {
    _free((void *)param_1[0x89]);
  }
  param_1[0x89] = 0;
  iVar2 = FUN_00013124(param_1,param_1[0x8a]);
  param_1[0x88] = iVar2;
  iVar2 = FUN_00013124(param_1,param_1[0x8a]);
  param_1[0x89] = iVar2;
  if ((param_1[0x88] != 0) && (iVar2 != 0)) {
    if (0 < param_1[0x8a]) {
      fVar5 = 1e-07;
      iVar2 = 0;
      do {
        *(float *)(iVar2 * 4 + param_1[0x88]) = fVar5;
        *(float *)(iVar2 * 4 + param_1[0x89]) = fVar5;
        fVar5 = -fVar5;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x8a]);
    }
    param_1[0x78] = 0;
    param_1[0x79] = 0;
    param_1[0x7a] = 0;
    param_1[0x7b] = 0;
    param_1[0x7c] = 0;
    *(double *)(param_1 + 0x7d) = 1.0;
    *(double *)(param_1 + 0x7f) = 1.0;
    *(double *)(param_1 + 0x81) = (double)param_1[0x8a];
    param_1[0x93] = 0;
    param_1[0x94] = 0;
    param_1[0x8b] = 0;
    param_1[0x8c] = 0;
    param_1[0x8d] = 0;
    param_1[0x8e] = 0;
                    /* WARNING: Could not recover jumptable at 0x0003f217. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
  return;
}

