/* 0006b0a0 FUN_0006b0a0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006b0a0(int param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  
  iVar2 = *param_2;
  FUN_00033224(*(undefined4 *)(param_1 + 0x29c),0);
  if (0 < iVar2) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 9;
    do {
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x44))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20,
                 local_24 + param_2[1] + 0xc);
      iVar3 = local_24 + param_2[1];
      FUN_00034384(*(undefined4 *)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_28,
                   param_2[2] + *(int *)(iVar3 + 0x4c) * 2,
                   *(int *)(iVar3 + 0x50) - *(int *)(iVar3 + 0x4c),*(undefined4 *)(iVar3 + 0x5c));
      iVar3 = *(int *)(local_24 + param_2[1] + 0x24);
      for (fVar1 = *(float *)(local_24 + param_2[1] + 0x28); 1.0297315 <= fVar1;
          fVar1 = fVar1 * 0.9438743) {
        iVar3 = iVar3 + -1;
      }
      for (; fVar1 <= 0.9719372; fVar1 = fVar1 * 1.0594631) {
        iVar3 = iVar3 + 1;
      }
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 1,iVar3);
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 2,
                 *(undefined4 *)(param_2[1] + 0x2c + local_24));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 3,
                 *(undefined4 *)(param_2[1] + 0x30 + local_24));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 4,
                 *(undefined4 *)(param_2[1] + 0x34 + local_24));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 5,
                 *(undefined4 *)(param_2[1] + 0x38 + local_24));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 8,
                 (int)*(float *)(param_2[1] + 0x3c + local_24));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 9,
                 (int)(*(float *)(param_2[1] + 0x40 + local_24) + 1.0));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 0xb,
                 *(int *)(local_24 + param_2[1] + 0x54) - *(int *)(local_24 + param_2[1] + 0x4c));
      (**(code **)(**(int **)(param_1 + 0x29c) + 0x24))
                (*(int **)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x2a0),local_20 + 0xc,
                 *(int *)(local_24 + param_2[1] + 0x58) - *(int *)(local_24 + param_2[1] + 0x50));
      local_28 = local_28 + 1;
      local_24 = local_24 + 0x7c;
      local_20 = local_20 + 0x14;
    } while (iVar2 != local_28);
    FUN_00033224();
    return;
  }
  FUN_00033224();
  return;
}

