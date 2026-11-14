/* 000898fe FUN_000898fe */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000898fe(int param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20 [4];
  
  (**(code **)(**(int **)(param_1 + 0x10) + 0x38))(*(int **)(param_1 + 0x10),local_20,&local_24);
  (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))(*(int **)(param_1 + 0x118),&local_28,&local_2c);
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(param_1 + 0x1e8);
  if (0 < (int)param_2) {
    uVar4 = 0;
    do {
      uVar3 = uVar4 & 7;
      uVar4 = uVar4 + 1;
      if (uVar3 == 0) {
        fVar1 = **(float **)(param_1 + 0x1ec);
        *(float *)(param_1 + 0x1fc) = fVar1;
        *(float **)(param_1 + 0x1ec) = *(float **)(param_1 + 0x1ec) + 1;
        *(float *)(param_1 + 0x200) = (fVar1 - *(float *)(param_1 + 0x1f8)) * 0.125;
      }
      *(float *)(param_1 + 0x1f8) = *(float *)(param_1 + 0x1f8) + *(float *)(param_1 + 0x200);
      fVar1 = *local_20[0];
      local_20[0] = local_20[0] + 1;
      fVar2 = *local_24;
      local_24 = local_24 + 1;
      *local_28 = fVar1 * *(float *)(param_1 + 0x1f8) + *local_28;
      local_28 = local_28 + 1;
      *local_2c = fVar2 * *(float *)(param_1 + 0x1f8) + *local_2c;
      local_2c = local_2c + 1;
    } while (uVar4 != param_2);
  }
  (**(code **)(**(int **)(param_1 + 0x118) + 0x44))(*(int **)(param_1 + 0x118));
  return;
}

