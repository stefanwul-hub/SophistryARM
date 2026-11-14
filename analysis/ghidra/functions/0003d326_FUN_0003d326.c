/* 0003d326 FUN_0003d326 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003d326(int param_1)

{
  uint uVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fVar5;
  undefined4 local_14;
  
  if ((1.0 < *(float *)(param_1 + 0x140)) && (iVar2 = *(int *)(param_1 + 0x124), iVar2 != 0)) {
    local_14 = *(float *)(iVar2 + 0x15c);
    if ((*(int *)(iVar2 + 0x254) < *(int *)(iVar2 + 0x238)) && (6.0 <= *(float *)(param_1 + 0x150)))
    {
      lVar3 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar2 + 0x238));
      local_14 = (float)lVar3;
    }
    lVar3 = (longdouble)_pow(0,0x40000000,(double)*(float *)(param_1 + 0x1e4) * -2.0);
    uVar1 = *(int *)(param_1 + 0x1f0) + 1U & 0x800000ff;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
    }
    *(uint *)(param_1 + 0x1f0) = uVar1;
    fVar5 = (float)*(byte *)(uVar1 + 0x694 + param_1) / 255.0;
    fVar5 = (fVar5 + fVar5) - 1.0;
    *(float *)(param_1 + 0x798) = fVar5;
    *(float *)(param_1 + 500) = fVar5;
    lVar4 = (longdouble)FUN_000152c0(0x3f800000,local_14);
    iVar2 = (int)((float)lVar4 * *(float *)(param_1 + 0x140) * 0.125 * *(float *)(param_1 + 0x1e8) *
                  *(float *)(param_1 + 0x1ec) * (float)lVar3);
    *(int *)(param_1 + 0x794) = iVar2;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    else if (0x7ffffbff < iVar2) {
      iVar2 = 0x7ffffbff;
    }
    *(int *)(param_1 + 0x794) = iVar2;
    *(undefined4 *)(param_1 + 0x79c) = 0;
  }
  return;
}

