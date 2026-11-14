/* 0007efaa C51Map_vslot_80 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 C51Map_vslot_80(int param_1,int *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar1 = *(int *)(param_1 + 0xb4) + -1;
  if (param_3 <= iVar1) {
    iVar1 = param_3;
  }
  fVar3 = (float)(*param_2 - (*(int *)(param_1 + 0xb8) / 2 + *(int *)(param_1 + 8))) *
          *(float *)(param_1 + 200) + *(float *)(param_1 + 0xd0);
  fVar2 = (float)(param_2[1] - (*(int *)(param_1 + 0xbc) / 2 + *(int *)(param_1 + 0xc))) *
          *(float *)(param_1 + 0xcc) + *(float *)(param_1 + 0xd4);
  fVar4 = 0.0;
  if ((0.0 <= fVar3) && (fVar4 = 1.0, fVar3 <= 1.0)) {
    fVar4 = fVar3;
  }
  fVar3 = 0.0;
  if ((0.0 <= fVar2) && (fVar3 = 1.0, fVar2 <= 1.0)) {
    fVar3 = fVar2;
  }
  iVar1 = iVar1 * 0x48;
  *(float *)(*(int *)(param_1 + 0x90) + 4 + iVar1) = fVar4;
  *(float *)(*(int *)(param_1 + 0x90) + 0x1c + iVar1) = fVar3;
  if ((ABS(fVar4 - *(float *)(iVar1 + 0xc + *(int *)(param_1 + 0x90))) <= 0.001) &&
     (ABS(fVar3 - *(float *)(iVar1 + 0x24 + *(int *)(param_1 + 0x90))) <= 0.001)) {
    return 0;
  }
  return 1;
}

