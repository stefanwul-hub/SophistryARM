/* 0000c38c FUN_0000c38c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000c38c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int local_28;
  
  local_28 = param_2;
  if (*(int *)(param_1 + 0x16c) == 0) {
    fVar3 = 60.0;
  }
  else {
    if ((-1 < param_3) &&
       (local_28 = 0x18, *(char *)(param_3 * 0x70 + 0x1c + *(int *)(param_1 + 0x124)) != '\0')) {
      local_28 = param_2;
    }
    if (-1 < param_4) {
      iVar1 = *(int *)(param_4 * 0x70 + 8 + *(int *)(param_1 + 0x124));
      iVar2 = FUN_00014ce4(*(int *)(param_1 + 0x16c));
      local_28 = local_28 + iVar1 * iVar2;
    }
    if (-1 < param_5) {
      local_28 = local_28 + *(int *)(param_5 * 0x70 + 8 + *(int *)(param_1 + 0x124));
    }
    fVar3 = (float)local_28;
  }
  if (-1 < param_6) {
    fVar3 = fVar3 + *(float *)(param_6 * 0x70 + 0xc + *(int *)(param_1 + 0x124)) * 0.01;
  }
  if ((fVar3 < 0.0) && (!NAN(fVar3))) {
    FUN_000130fe();
    return;
  }
  FUN_000130fe();
  return;
}

