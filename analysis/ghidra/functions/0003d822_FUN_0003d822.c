/* 0003d822 FUN_0003d822 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_0003d822(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble extraout_ST0;
  float fVar8;
  float fVar9;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar3 = *(int *)(param_1 + 0x124);
  if ((iVar3 != 0) && (1.0 < *(float *)(param_1 + 0x140))) {
    iVar3 = *(int *)(param_1 + 0x1f0);
    *(undefined4 *)(param_1 + 0x1f0) = param_2;
    iVar5 = *(int *)(param_1 + 0x124);
    if ((*(int *)(iVar5 + 0x254) < *(int *)(iVar5 + 0x238)) && (6.0 <= *(float *)(param_1 + 0x150)))
    {
      FUN_0001329c(param_1,*(int *)(iVar5 + 0x238));
      iVar5 = *(int *)(param_1 + 0x124);
    }
    iVar2 = *(int *)(iVar5 + 0xe8);
    while( true ) {
      local_28 = *(float *)(param_1 + 0x798);
      iVar4 = *(int *)(param_1 + 0x1f0);
      if (*(int *)(param_1 + 0x67c + iVar2 * 4) <= iVar4) {
        *(undefined4 *)(param_1 + 0x1f0) = 0;
        iVar4 = 0;
      }
      if (*(int *)(param_1 + 0x1f0) == 0) {
        *(undefined4 *)(param_1 + 0x798) = 0;
        local_28 = 0.0;
      }
      if ((iVar5 == 0) || (iVar4 < 0)) {
        fVar8 = 0.0;
      }
      else {
        fVar8 = (float)*(int *)(*(int *)(iVar5 + 0xe8) * 0xc0 + iVar4 * 0xc + 0x200 + param_1) *
                0.02;
      }
      *(float *)(param_1 + 500) = fVar8;
      local_24 = *(float *)(iVar5 + 0x15c);
      if ((*(int *)(iVar5 + 0x254) < *(int *)(iVar5 + 0x238)) &&
         (6.0 <= *(float *)(param_1 + 0x150))) {
        lVar6 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar5 + 0x238));
        local_24 = (float)lVar6;
        iVar5 = *(int *)(param_1 + 0x124);
      }
      if ((iVar5 == 0) || (iVar4 < 0)) {
        fVar9 = 0.0;
        fVar8 = *(float *)(param_1 + 0x140);
      }
      else {
        fVar8 = *(float *)(param_1 + 0x140);
        if (fVar8 <= 0.0) {
          fVar9 = 0.0;
        }
        else {
          fVar1 = *(float *)(iVar5 + 0x46c);
          iVar5 = *(int *)(iVar5 + 0xe8) * 0xc0 + iVar4 * 0xc + param_1;
          fVar9 = (float)*(int *)(iVar5 + 0x1fc) * 0.01;
          if ((fVar1 < 0.499) || (0.501 < fVar1)) {
            if (*(int *)(iVar5 + 0x204) == 0) {
              fVar9 = fVar9 * (fVar1 + fVar1);
            }
            else {
              fVar9 = fVar9 * ((1.0 - fVar1) + (1.0 - fVar1));
            }
          }
        }
      }
      lVar6 = (longdouble)_pow(0,0x40000000,(double)*(float *)(param_1 + 0x1e4) * -2.0);
      lVar7 = (longdouble)FUN_000152c0(fVar8,local_24);
      fVar8 = (float)lVar7 * fVar9 * *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0x1ec) *
              (float)lVar6 + *(float *)(param_1 + 0x7a0);
      iVar5 = (int)fVar8;
      *(float *)(param_1 + 0x7a0) = fVar8 - (float)iVar5;
      if (0 < iVar5) break;
      *(undefined4 *)(param_1 + 0x798) = *(undefined4 *)(param_1 + 500);
      iVar4 = *(int *)(param_1 + 0x1f0) + 1;
      *(int *)(param_1 + 0x1f0) = iVar4;
      iVar5 = *(int *)(param_1 + 0x67c + iVar2 * 4);
      if (iVar3 == iVar4 % iVar5) {
        *(undefined4 *)(param_1 + 0x79c) = 0;
        *(undefined4 *)(param_1 + 0x794) = 8;
        return iVar4 / iVar5;
      }
      iVar5 = *(int *)(param_1 + 0x124);
    }
    iVar3 = FUN_000152c0(*(float *)(param_1 + 500) - local_28,(float)iVar5);
    fVar8 = (float)extraout_ST0;
    *(float *)(param_1 + 0x79c) = fVar8;
    if ((fVar8 < -2.0) && (!NAN(fVar8))) {
      iVar3 = -0x40000000;
      *(undefined4 *)(param_1 + 0x79c) = 0xc0000000;
      fVar8 = *(float *)(param_1 + 0x79c);
    }
    if (2.0 < fVar8) {
      *(float *)(param_1 + 0x79c) = 2.0;
    }
    *(int *)(param_1 + 0x794) = iVar5;
    if (0x7ffffbff < iVar5) {
      *(undefined4 *)(param_1 + 0x794) = 0x7ffffbff;
    }
  }
  return iVar3;
}

