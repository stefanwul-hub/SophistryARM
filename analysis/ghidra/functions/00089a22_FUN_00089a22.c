/* 00089a22 FUN_00089a22 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00089a22(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20 [4];
  
  (**(code **)(**(int **)(param_1 + 0x10) + 0x38))(*(int **)(param_1 + 0x10),local_20,&local_24);
  (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))(*(int **)(param_1 + 0x118),&local_28,&local_2c);
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(param_1 + 0x1e8);
  *(undefined4 *)(param_1 + 500) = *(undefined4 *)(param_1 + 0x1f0);
  if (0 < (int)param_2) {
    uVar2 = 0;
    do {
      uVar1 = uVar2 & 7;
      uVar2 = uVar2 + 1;
      if (uVar1 == 0) {
        fVar3 = **(float **)(param_1 + 0x1ec);
        *(float *)(param_1 + 0x1fc) = fVar3;
        *(float **)(param_1 + 0x1ec) = *(float **)(param_1 + 0x1ec) + 1;
        *(float *)(param_1 + 0x200) = (fVar3 - *(float *)(param_1 + 0x1f8)) * 0.125;
        fVar4 = *(float *)(param_1 + 0x204) * 0.75 + (**(float **)(param_1 + 500) + 1.0) * 0.25;
        *(float *)(param_1 + 0x204) = fVar4;
        *(float **)(param_1 + 500) = *(float **)(param_1 + 500) + 1;
        fVar3 = 1e-05;
        if (1e-05 <= fVar4) {
          fVar3 = (float)(~-(uint)(fVar4 <= 1.99999) & (uint)1.99999 |
                         (uint)fVar4 & -(uint)(fVar4 <= 1.99999));
        }
        *(float *)(param_1 + 0x204) = fVar3;
      }
      fVar3 = *(float *)(param_1 + 0x1f8) + *(float *)(param_1 + 0x200);
      *(float *)(param_1 + 0x1f8) = fVar3;
      *local_28 = *local_28 + fVar3 * *local_20[0] * (2.0 - *(float *)(param_1 + 0x204));
      local_28 = local_28 + 1;
      local_20[0] = local_20[0] + 1;
      *local_2c = *local_24 * *(float *)(param_1 + 0x1f8) * *(float *)(param_1 + 0x204) + *local_2c;
      local_2c = local_2c + 1;
      local_24 = local_24 + 1;
    } while (param_2 != uVar2);
  }
  (**(code **)(**(int **)(param_1 + 0x118) + 0x44))(*(int **)(param_1 + 0x118));
  return;
}

