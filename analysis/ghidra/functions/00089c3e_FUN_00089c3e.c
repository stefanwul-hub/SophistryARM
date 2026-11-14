/* 00089c3e FUN_00089c3e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00089c3e(int param_1,uint param_2)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  float *local_24;
  float *local_20 [4];
  
  (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),local_20,0);
  (**(code **)(**(int **)(param_1 + 0x118) + 0x28))(*(int **)(param_1 + 0x118),&local_24,0);
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(param_1 + 0x1e8);
  if (0 < (int)param_2) {
    uVar3 = 0;
    do {
      uVar2 = uVar3 & 7;
      uVar3 = uVar3 + 1;
      if (uVar2 == 0) {
        fVar1 = **(float **)(param_1 + 0x1ec);
        *(float *)(param_1 + 0x1fc) = fVar1;
        *(float **)(param_1 + 0x1ec) = *(float **)(param_1 + 0x1ec) + 1;
        *(float *)(param_1 + 0x200) = (fVar1 - *(float *)(param_1 + 0x1f8)) * 0.125;
      }
      *(float *)(param_1 + 0x1f8) = *(float *)(param_1 + 0x1f8) + *(float *)(param_1 + 0x200);
      fVar1 = *local_20[0];
      local_20[0] = local_20[0] + 1;
      *local_24 = fVar1 * *(float *)(param_1 + 0x1f8) + *local_24;
      local_24 = local_24 + 1;
    } while (uVar3 != param_2);
  }
  (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
  return;
}

