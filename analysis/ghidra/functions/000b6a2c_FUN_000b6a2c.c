/* 000b6a2c FUN_000b6a2c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000b6a2c(int *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int local_30;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  float *local_20 [4];
  
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_24,local_28);
  (**(code **)(*(int *)param_1[4] + 0x34))((int *)param_1[4],local_20,0);
  if (0 < param_2) {
    local_30 = 0;
    do {
      pfVar1 = (float *)(param_1[0x1d2] + param_1[0x1d5] * 4);
      fVar9 = *pfVar1;
      *pfVar1 = *local_20[0];
      iVar5 = param_1[0x1d5];
      param_1[0x1d5] = iVar5 + 1;
      if (param_1[0x1d7] <= iVar5 + 1) {
        param_1[0x1d5] = 0;
      }
      fVar9 = fVar9 * (float)param_1[0x21a];
      fVar8 = 0.0;
      fVar7 = 0.0;
      iVar5 = 0;
      piVar4 = param_1 + 0x105;
      do {
        fVar2 = *(float *)(piVar4[-0x8b] + piVar4[-0x88] * 4);
        fVar6 = (1.0 - (float)piVar4[-0x85]) * fVar2 + (float)piVar4[-0x85] * (float)piVar4[-0x86];
        piVar4[-0x86] = (int)fVar6;
        *(float *)(piVar4[-0x8b] + piVar4[-0x88] * 4) = fVar6 * (float)piVar4[-0x8c] + fVar9;
        iVar3 = piVar4[-0x88];
        piVar4[-0x88] = iVar3 + 1;
        if (piVar4[-0x8a] <= iVar3 + 1) {
          piVar4[-0x88] = 0;
        }
        fVar7 = fVar7 + fVar2;
        fVar2 = *(float *)(piVar4[-3] + *piVar4 * 4);
        fVar6 = (1.0 - (float)piVar4[3]) * fVar2 + (float)piVar4[3] * (float)piVar4[2];
        piVar4[2] = (int)fVar6;
        *(float *)(piVar4[-3] + *piVar4 * 4) = fVar6 * (float)piVar4[-4] + fVar9;
        iVar3 = *piVar4;
        *piVar4 = iVar3 + 1;
        if (piVar4[-2] <= iVar3 + 1) {
          *piVar4 = 0;
        }
        fVar8 = fVar8 + fVar2;
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0x11;
      } while (iVar5 != 8);
      iVar5 = 0;
      piVar4 = param_1 + 0x1b1;
      do {
        pfVar1 = (float *)(piVar4[-0x27] + piVar4[-0x24] * 4);
        fVar9 = *pfVar1;
        *pfVar1 = fVar9 * (float)piVar4[-0x28] + fVar7;
        iVar3 = piVar4[-0x24];
        piVar4[-0x24] = iVar3 + 1;
        if (piVar4[-0x26] <= iVar3 + 1) {
          piVar4[-0x24] = 0;
        }
        fVar7 = fVar9 - fVar7;
        pfVar1 = (float *)(piVar4[-3] + *piVar4 * 4);
        fVar9 = *pfVar1;
        *pfVar1 = fVar9 * (float)piVar4[-4] + fVar8;
        iVar3 = *piVar4;
        *piVar4 = iVar3 + 1;
        if (piVar4[-2] <= iVar3 + 1) {
          *piVar4 = 0;
        }
        fVar8 = fVar9 - fVar8;
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 6;
      } while (iVar5 != 6);
      (**(code **)(*param_1 + 0xcc))(param_1,local_24,fVar7 * (float)param_1[0x78] + *local_20[0]);
      (**(code **)(*param_1 + 0xcc))(param_1,local_28,fVar8 * (float)param_1[0x78] + *local_20[0]);
      local_20[0] = local_20[0] + 1;
      local_30 = local_30 + 1;
    } while (param_2 != local_30);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
  return;
}

