/* 0003d5ec FUN_0003d5ec */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003d5ec(int param_1,double param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  
  dVar7 = param_2 * 256.0 * 0.999999999999;
  iVar3 = (int)dVar7;
  iVar2 = 0;
  if (-1 < iVar3) {
    iVar2 = iVar3;
  }
  *(int *)(param_1 + 0x1f0) = iVar2;
  if (0xff < iVar2) {
    *(undefined4 *)(param_1 + 0x1f0) = 0xff;
    iVar2 = *(int *)(param_1 + 0x1f0);
  }
  fVar6 = (float)*(byte *)(iVar2 + 0x694 + param_1) / 255.0;
  fVar6 = (fVar6 + fVar6) - 1.0;
  dVar7 = dVar7 - (double)iVar2;
  uVar1 = iVar2 + 1U & 0x800000ff;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  *(uint *)(param_1 + 0x1f0) = uVar1;
  fVar5 = (float)*(byte *)(uVar1 + 0x694 + param_1) / 255.0;
  fVar5 = (fVar5 + fVar5) - 1.0;
  *(float *)(param_1 + 500) = fVar5;
  if (param_3 != '\0') {
    fVar5 = (float)((double)(fVar5 - fVar6) * dVar7 + (double)fVar6);
  }
  *(float *)(param_1 + 0x798) = fVar5;
  iVar2 = *(int *)(param_1 + 0x124);
  lVar4 = (longdouble)*(float *)(iVar2 + 0x15c);
  if ((*(int *)(iVar2 + 0x254) < *(int *)(iVar2 + 0x238)) && (6.0 <= *(float *)(param_1 + 0x150))) {
    lVar4 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar2 + 0x238));
  }
  lVar4 = (longdouble)FUN_000152c0(0x3f800000,(float)lVar4);
  iVar2 = (int)((double)((float)lVar4 * *(float *)(param_1 + 0x140)) * 0.125 * (1.0 - dVar7));
  *(int *)(param_1 + 0x794) = iVar2;
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  else if (0x7ffffbff < iVar2) {
    iVar2 = 0x7ffffbff;
  }
  *(int *)(param_1 + 0x794) = iVar2;
  if (param_3 == '\0') {
    *(undefined4 *)(param_1 + 0x79c) = 0;
    if (*(float *)(param_1 + 0x79c) <= -1.0 && *(float *)(param_1 + 0x79c) != -1.0)
    goto LAB_0003d7e4;
  }
  else {
    *(float *)(param_1 + 0x79c) =
         (*(float *)(param_1 + 500) - *(float *)(param_1 + 0x798)) /
         (float)*(int *)(param_1 + 0x794);
    if (*(float *)(param_1 + 0x79c) <= -1.0 && *(float *)(param_1 + 0x79c) != -1.0) {
LAB_0003d7e4:
      fVar6 = -1.0;
      *(float *)(param_1 + 0x79c) = -1.0;
      goto LAB_0003d7ac;
    }
  }
  fVar6 = *(float *)(param_1 + 0x79c);
LAB_0003d7ac:
  if (1.0 < fVar6) {
    *(float *)(param_1 + 0x79c) = 1.0;
  }
  return;
}

