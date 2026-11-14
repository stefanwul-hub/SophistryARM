/* 00038f48 SamWT_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 SamWT_c_vslot_61(int param_1,int param_2,int param_3)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  int local_70;
  int local_44;
  float local_40;
  uint local_30;
  float *local_28;
  float *local_24;
  float *local_20 [4];
  
  *(undefined4 *)(param_1 + 0x204) = *(undefined4 *)(param_1 + 0x1f8);
  *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(param_1 + 0x1fc);
  *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x200);
  local_24 = *(float **)(param_1 + 0x288);
  local_20[0] = local_24;
  if (*(int *)(param_1 + 0x1dc) == 1) {
    (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),local_20,0);
  }
  else if (*(int *)(param_1 + 0x1dc) == 2) {
    (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),&local_24,0);
  }
  dVar8 = *(double *)(param_1 + 0x21c + param_3 * 8);
  dVar9 = *(double *)(param_1 + 0x244 + param_3 * 8);
  dVar1 = *(double *)(param_1 + 0x26c);
  *(double *)(param_1 + 0x26c) = (double)*(float *)(param_1 + 0x1e8) * dVar1;
  (**(code **)(**(int **)(param_1 + 0x118) + 0x28))(*(int **)(param_1 + 0x118),&local_28,0);
  param_2 = param_2 + 1;
  local_30 = 0;
  do {
    param_2 = param_2 + -1;
    if (param_2 < 1) {
      *(double *)(param_1 + 0x21c + param_3 * 8) = dVar8;
      *(double *)(param_1 + 0x244 + param_3 * 8) = dVar9;
      (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
      *(double *)(param_1 + 0x26c) = dVar1;
      return 0;
    }
    uVar2 = local_30 & 7;
    local_30 = local_30 + 1;
    if (uVar2 == 0) {
      *(undefined4 *)(param_1 + 0x214) = **(undefined4 **)(param_1 + 0x204);
      *(undefined4 **)(param_1 + 0x204) = *(undefined4 **)(param_1 + 0x204) + 1;
      dVar6 = (double)**(float **)(param_1 + 0x208);
      *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
      dVar6 = dVar6 * dVar6 * dVar6 * 0.05362607007876781 + dVar6 * dVar6 * 0.2480732860777168 +
              dVar6 * 0.695218770961068 + 1.0;
      *(double *)(param_1 + 0x274) = dVar6 * dVar6 * dVar6 * dVar6 * *(double *)(param_1 + 0x26c);
      dVar9 = dVar9 + *(double *)(param_1 + 0x27c);
      fVar5 = **(float **)(param_1 + 0x20c);
      *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
      for (dVar6 = (double)fVar5 * 64.0 + dVar9; 64.0 <= dVar6; dVar6 = dVar6 - 64.0) {
      }
      for (; (dVar6 < 0.0 && (dVar6 = dVar6 + 64.0, dVar6 < 0.0)); dVar6 = dVar6 + 64.0) {
      }
      iVar3 = (int)dVar6;
      if (iVar3 < 0) {
        fVar5 = 0.0;
        uVar2 = 1;
        iVar4 = 0;
LAB_00039137:
        local_40 = (float)(dVar6 - (double)fVar5);
LAB_00039155:
        if ((int)uVar2 < 0x40) {
          iVar3 = uVar2 << 9;
        }
        else {
          iVar3 = 0x7e00;
        }
      }
      else {
        if (0x3f < iVar3) {
          fVar5 = 63.0;
          uVar2 = 0;
          iVar4 = 0x7e00;
          goto LAB_00039137;
        }
        iVar4 = iVar3 << 9;
        local_40 = (float)(dVar6 - (double)iVar3);
        uVar2 = iVar3 + 1U & 0x8000003f;
        if ((-1 < (int)uVar2) || (uVar2 = (uVar2 - 1 | 0xffffffc0) + 1, -1 < (int)uVar2))
        goto LAB_00039155;
        iVar3 = 0;
      }
      local_44 = *(int *)(param_1 + 0x218) + iVar4;
      local_70 = *(int *)(param_1 + 0x218) + iVar3;
    }
    fVar7 = (float)(dVar8 - (double)(int)dVar8);
    iVar3 = (int)dVar8 * 4;
    fVar5 = *local_24;
    local_24 = local_24 + 1;
    *local_28 = ((1.0 - fVar7) * *(float *)(local_44 + iVar3) * (1.0 - local_40) +
                 fVar7 * *(float *)(local_44 + 4 + iVar3) * (1.0 - local_40) +
                 (1.0 - fVar7) * *(float *)(local_70 + iVar3) * local_40 +
                fVar7 * *(float *)(local_70 + 4 + iVar3) * local_40) * fVar5 *
                *(float *)(param_1 + 0x214) + *local_28;
    local_28 = local_28 + 1;
    fVar5 = *local_20[0];
    local_20[0] = local_20[0] + 1;
    dVar8 = dVar8 + (double)fVar5 * *(double *)(param_1 + 0x274);
    if (128.0 <= dVar8) {
      dVar8 = dVar8 - 128.0;
    }
  } while( true );
}

