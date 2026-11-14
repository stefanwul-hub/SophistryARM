/* 0007f9c0 FUN_0007f9c0 */

void FUN_0007f9c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  float *local_10;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    (**(code **)(**(int **)(param_1 + 0x118) + 0x30))(*(int **)(param_1 + 0x118),&local_28);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),&local_10,0);
    if (0 < param_2) {
      iVar2 = 1;
      do {
        fVar4 = *local_10 * *(float *)(param_1 + 0x210);
        local_10 = local_10 + 1;
        fVar3 = (fVar4 - *(float *)(param_1 + 0x1fc)) * *(float *)(param_1 + 0x20c) +
                *(float *)(param_1 + 0x1fc);
        *(float *)(param_1 + 0x1fc) = fVar3;
        *(float *)(param_1 + 0x200) =
             *(float *)(param_1 + 0x200) +
             (fVar3 - *(float *)(param_1 + 0x200)) * *(float *)(param_1 + 0x20c);
        iVar1 = iVar2 * 4;
        *(float *)(local_28 + iVar1 + -4) =
             fVar4 * *(float *)(param_1 + 0x1e4) + *(float *)(local_28 + iVar1 + -4);
        *(float *)(local_24 + iVar1 + -4) =
             fVar4 * *(float *)(param_1 + 0x1e8) + *(float *)(local_24 + iVar1 + -4);
        *(float *)(local_20 + iVar1 + -4) =
             fVar4 * *(float *)(param_1 + 500) + *(float *)(local_20 + iVar1 + -4);
        *(float *)(local_1c + iVar1 + -4) =
             *(float *)(param_1 + 0x200) * *(float *)(param_1 + 0x1f8) +
             *(float *)(local_1c + iVar1 + -4);
        *(float *)(local_18 + iVar1 + -4) =
             fVar4 * *(float *)(param_1 + 0x1ec) + *(float *)(local_18 + iVar1 + -4);
        *(float *)(iVar1 + local_14 + -4) =
             fVar4 * *(float *)(param_1 + 0x1f0) + *(float *)(iVar1 + local_14 + -4);
        iVar2 = iVar2 + 1;
      } while (iVar2 != param_2 + 1);
    }
    (**(code **)(**(int **)(param_1 + 0x118) + 0x48))(*(int **)(param_1 + 0x118));
  }
  return;
}

