/* 0008beea FUN_0008beea */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008beea(int param_1,int *param_2,int *param_3,int *param_4,float *param_5)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  *param_5 = 0.0;
  if (*param_4 - 2U < 2) {
    iVar1 = FUN_0002e1c0(param_1 + 0x168);
    iVar2 = iVar1 - *(int *)(param_1 + 0x32c);
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    else if (999999999 < iVar2) {
      iVar2 = 999999999;
    }
    if ((*(int *)(param_1 + 0x324) == *param_3) && (*(int *)(param_1 + 0x328) == *param_2)) {
      fVar4 = (25.0 / (float)iVar2 - 0.05) / 0.95;
      if ((0.0 <= fVar4) || (NAN(fVar4))) {
        fVar3 = 1.0;
        if (fVar4 <= 1.0) {
          fVar3 = fVar4 * fVar4;
        }
      }
      else {
        fVar3 = 0.0;
      }
      *param_5 = fVar3;
    }
    *(int *)(param_1 + 0x324) = *param_3;
    *(int *)(param_1 + 0x328) = *param_2;
    *(int *)(param_1 + 0x32c) = iVar1;
    return;
  }
  return;
}

