/* 00032344 FUN_00032344 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00032344(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    if (param_4 < 1) {
      fVar5 = 1000.0;
    }
    else {
      iVar1 = 0;
      fVar4 = 0.0;
      fVar5 = fVar4;
      do {
        fVar3 = *(float *)(param_2 + iVar1 * 4);
        fVar6 = fVar3;
        if (fVar3 <= fVar4) {
          fVar6 = fVar4;
        }
        if (fVar5 <= fVar3) {
          fVar3 = fVar5;
        }
        fVar5 = *(float *)(param_3 + iVar1 * 4);
        fVar4 = fVar5;
        if (fVar5 <= fVar6) {
          fVar4 = fVar6;
        }
        if (fVar3 <= fVar5) {
          fVar5 = fVar3;
        }
        iVar1 = iVar1 + 1;
      } while (param_4 != iVar1);
      if (fVar4 <= 0.0) {
        fVar4 = 1000.0;
      }
      else {
        fVar4 = 1.0 / fVar4;
      }
      if (fVar5 < 0.0) {
        fVar5 = -1.0 / fVar5;
      }
      else {
        fVar5 = 1000.0;
      }
      if (fVar4 < fVar5) goto LAB_000323e4;
    }
    fVar4 = fVar5;
    if (0 < param_4) {
LAB_000323e4:
      iVar1 = 0;
      do {
        pfVar2 = (float *)(param_2 + iVar1 * 4);
        *pfVar2 = fVar4 * *pfVar2;
        pfVar2 = (float *)(param_3 + iVar1 * 4);
        *pfVar2 = fVar4 * *pfVar2;
        iVar1 = iVar1 + 1;
      } while (param_4 != iVar1);
      return;
    }
  }
  return;
}

