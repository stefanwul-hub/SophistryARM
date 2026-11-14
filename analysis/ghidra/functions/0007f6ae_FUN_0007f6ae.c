/* 0007f6ae FUN_0007f6ae */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0007f6ae(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  float fVar9;
  float fVar10;
  int local_38;
  int local_34;
  float *local_20 [4];
  
  if (*(int *)(param_1 + 0x124) != 0) {
    (**(code **)(**(int **)(param_1 + 0x118) + 0x30))(*(int **)(param_1 + 0x118),&local_38);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),local_20,0);
    fVar6 = *(float *)(param_1 + 500) * 0.5;
    fVar1 = *(float *)(param_1 + 0x1e4);
    fVar2 = *(float *)(param_1 + 0x1ec);
    fVar3 = *(float *)(param_1 + 0x1e8);
    fVar4 = *(float *)(param_1 + 0x1f0);
    fVar5 = *(float *)(param_1 + 0x1f8);
    if (0 < param_2) {
      iVar7 = 0;
      do {
        fVar10 = *local_20[0] * *(float *)(param_1 + 0x210);
        local_20[0] = local_20[0] + 1;
        fVar9 = (fVar10 - *(float *)(param_1 + 0x1fc)) * *(float *)(param_1 + 0x20c) +
                *(float *)(param_1 + 0x1fc);
        *(float *)(param_1 + 0x1fc) = fVar9;
        fVar9 = (fVar9 - *(float *)(param_1 + 0x200)) * *(float *)(param_1 + 0x20c) +
                *(float *)(param_1 + 0x200);
        *(float *)(param_1 + 0x200) = fVar9;
        fVar9 = fVar5 * 0.5 * fVar9;
        pfVar8 = (float *)(local_38 + iVar7 * 4);
        *pfVar8 = (fVar1 + fVar6 + fVar2) * fVar10 + fVar9 + *pfVar8;
        pfVar8 = (float *)(local_34 + iVar7 * 4);
        *pfVar8 = fVar9 + fVar10 * (fVar6 + fVar3 + fVar4) + *pfVar8;
        iVar7 = iVar7 + 1;
      } while (param_2 != iVar7);
    }
    (**(code **)(**(int **)(param_1 + 0x118) + 0x48))(*(int **)(param_1 + 0x118));
  }
  return;
}

