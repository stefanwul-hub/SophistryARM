/* 0007fb5a FUN_0007fb5a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0007fb5a(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  float *local_24;
  float *local_20 [4];
  
  if (*(int *)(param_1 + 0x124) != 0) {
    fVar2 = *(float *)(param_1 + 500);
    fVar3 = *(float *)(param_1 + 0x1f8);
    (**(code **)(**(int **)(param_1 + 0x118) + 0x30))(*(int **)(param_1 + 0x118),&local_3c);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x38))(*(int **)(param_1 + 0x10),local_20,&local_24);
    if (0 < param_2) {
      iVar4 = 1;
      do {
        fVar7 = *local_20[0] * *(float *)(param_1 + 0x210);
        local_20[0] = local_20[0] + 1;
        fVar6 = *local_24 * *(float *)(param_1 + 0x210);
        local_24 = local_24 + 1;
        fVar5 = ((fVar7 + fVar6) - *(float *)(param_1 + 0x1fc)) * *(float *)(param_1 + 0x20c) +
                *(float *)(param_1 + 0x1fc);
        *(float *)(param_1 + 0x1fc) = fVar5;
        *(float *)(param_1 + 0x200) =
             *(float *)(param_1 + 0x200) +
             (fVar5 - *(float *)(param_1 + 0x200)) * *(float *)(param_1 + 0x20c);
        iVar1 = iVar4 * 4;
        *(float *)(local_3c + iVar1 + -4) =
             fVar7 * *(float *)(param_1 + 0x1e4) + *(float *)(local_3c + iVar1 + -4);
        *(float *)(local_38 + iVar1 + -4) =
             fVar6 * *(float *)(param_1 + 0x1e8) + *(float *)(local_38 + iVar1 + -4);
        *(float *)(local_34 + iVar1 + -4) =
             (fVar7 + fVar6) * fVar2 * 0.5 + *(float *)(local_34 + iVar1 + -4);
        *(float *)(local_30 + iVar1 + -4) =
             fVar3 * 0.5 * *(float *)(param_1 + 0x200) + *(float *)(local_30 + iVar1 + -4);
        *(float *)(local_2c + iVar1 + -4) =
             fVar7 * *(float *)(param_1 + 0x1ec) + *(float *)(local_2c + iVar1 + -4);
        *(float *)(iVar1 + local_28 + -4) =
             fVar6 * *(float *)(param_1 + 0x1f0) + *(float *)(iVar1 + local_28 + -4);
        iVar4 = iVar4 + 1;
      } while (iVar4 != param_2 + 1);
    }
    (**(code **)(**(int **)(param_1 + 0x118) + 0x48))(*(int **)(param_1 + 0x118));
  }
  return;
}

