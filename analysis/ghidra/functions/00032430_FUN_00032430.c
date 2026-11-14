/* 00032430 FUN_00032430 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00032430(undefined4 param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  
  if (param_2 != (float *)0x0) {
    if (param_3 < 1) {
      fVar4 = 1000.0;
    }
    else {
      iVar3 = 0;
      fVar5 = 0.0;
      fVar4 = fVar5;
      do {
        fVar1 = param_2[iVar3];
        fVar2 = fVar1;
        if (fVar1 <= fVar5) {
          fVar2 = fVar5;
        }
        fVar5 = fVar2;
        if (fVar4 <= fVar1) {
          fVar1 = fVar4;
        }
        fVar4 = fVar1;
        iVar3 = iVar3 + 1;
      } while (param_3 != iVar3);
      if (fVar5 <= 0.0) {
        fVar5 = 1000.0;
      }
      else {
        fVar5 = 1.0 / fVar5;
      }
      if (fVar4 < 0.0) {
        fVar4 = -1.0 / fVar4;
      }
      else {
        fVar4 = 1000.0;
      }
      if (fVar5 < fVar4) {
        fVar4 = fVar5;
      }
    }
    if (((1.01 < fVar4) || (fVar4 < 0.99)) && (0 < param_3)) {
      iVar3 = 0;
      do {
        *param_2 = fVar4 * *param_2;
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 1;
      } while (param_3 != iVar3);
    }
  }
  return;
}

