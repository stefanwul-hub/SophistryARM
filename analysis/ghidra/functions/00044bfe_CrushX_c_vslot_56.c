/* 00044bfe CrushX_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CrushX_c_vslot_56(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20 [4];
  
  if ((*(char *)(param_1 + 0x15c) != '\0') &&
     (iVar15 = *(int *)(param_1 + 0x10), *(int *)(iVar15 + 0x20) != 0)) {
    if (*(char *)(iVar15 + 0x26) != '\0') {
      pfVar14 = (float *)(param_1 + 0x288);
      _memcpy(pfVar14,PTR_DAT_00103834,0x400);
      (**(code **)(**(int **)(param_1 + 0x118) + 0x28))(*(int **)(param_1 + 0x118),&local_28,0);
      (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),local_20,0);
      FUN_00043fd4(param_1,param_2,local_20[0],pfVar14);
      fVar1 = *(float *)(param_1 + 0x200);
      if (0 < param_2) {
        iVar15 = 0;
        do {
          fVar2 = *pfVar14;
          fVar3 = *local_20[0];
          fVar4 = *(float *)(param_1 + 500);
          *(float *)(param_1 + 500) = -fVar4;
          *local_28 = fVar2 * *(float *)(param_1 + 0x200) + (1.0 - fVar1) * fVar3 + -fVar4;
          local_28 = local_28 + 1;
          pfVar14 = pfVar14 + 1;
          local_20[0] = local_20[0] + 1;
          iVar15 = iVar15 + 1;
        } while (param_2 != iVar15);
      }
      (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
      return;
    }
    if (*(char *)(iVar15 + 0x27) != '\0') {
      pfVar14 = (float *)(param_1 + 0x288);
      _memcpy(pfVar14,PTR_DAT_00103834,0x400);
      (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
                (*(int **)(param_1 + 0x118),&local_28,&local_2c);
      (**(code **)(**(int **)(param_1 + 0x10) + 0x38))(*(int **)(param_1 + 0x10),local_20,&local_24)
      ;
      FUN_00043fd4(param_1,param_2,local_20[0],pfVar14);
      fVar1 = *(float *)(param_1 + 0x200);
      if (0 < param_2) {
        iVar15 = 0;
        pfVar13 = pfVar14;
        do {
          fVar2 = *pfVar13;
          fVar3 = *local_20[0];
          fVar4 = *(float *)(param_1 + 500);
          *(float *)(param_1 + 500) = -fVar4;
          *local_28 = fVar2 * *(float *)(param_1 + 0x200) + (1.0 - fVar1) * fVar3 + -fVar4;
          local_28 = local_28 + 1;
          pfVar13 = pfVar13 + 1;
          local_20[0] = local_20[0] + 1;
          iVar15 = iVar15 + 1;
        } while (iVar15 != param_2);
      }
      _memcpy(pfVar14,PTR_DAT_00103834,0x400);
      uVar11 = *(undefined4 *)(param_1 + 0x1f0);
      uVar8 = *(undefined8 *)(param_1 + 0x228);
      uVar9 = *(undefined8 *)(param_1 + 0x220);
      uVar10 = *(undefined8 *)(param_1 + 0x230);
      uVar12 = *(undefined4 *)(param_1 + 0x248);
      uVar5 = *(undefined4 *)(param_1 + 0x240);
      uVar6 = *(undefined4 *)(param_1 + 0x244);
      uVar7 = *(undefined4 *)(param_1 + 0x284);
      *(undefined4 *)(param_1 + 0x1f0) = *(undefined4 *)(param_1 + 600);
      *(undefined8 *)(param_1 + 0x228) = *(undefined8 *)(param_1 + 0x264);
      *(undefined8 *)(param_1 + 0x220) = *(undefined8 *)(param_1 + 0x25c);
      *(undefined8 *)(param_1 + 0x230) = *(undefined8 *)(param_1 + 0x26c);
      *(undefined4 *)(param_1 + 0x248) = *(undefined4 *)(param_1 + 0x27c);
      *(undefined4 *)(param_1 + 0x240) = *(undefined4 *)(param_1 + 0x274);
      *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(param_1 + 0x278);
      *(undefined4 *)(param_1 + 0x284) = *(undefined4 *)(param_1 + 0x280);
      FUN_00043fd4(param_1,param_2,local_24,pfVar14);
      *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x1f0);
      *(undefined8 *)(param_1 + 0x264) = *(undefined8 *)(param_1 + 0x228);
      *(undefined8 *)(param_1 + 0x25c) = *(undefined8 *)(param_1 + 0x220);
      *(undefined8 *)(param_1 + 0x26c) = *(undefined8 *)(param_1 + 0x230);
      *(undefined4 *)(param_1 + 0x27c) = *(undefined4 *)(param_1 + 0x248);
      *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(param_1 + 0x240);
      *(undefined4 *)(param_1 + 0x278) = *(undefined4 *)(param_1 + 0x244);
      *(undefined4 *)(param_1 + 0x280) = *(undefined4 *)(param_1 + 0x284);
      *(undefined4 *)(param_1 + 0x1f0) = uVar11;
      *(undefined8 *)(param_1 + 0x228) = uVar8;
      *(undefined8 *)(param_1 + 0x220) = uVar9;
      *(undefined8 *)(param_1 + 0x230) = uVar10;
      *(undefined4 *)(param_1 + 0x248) = uVar12;
      *(undefined4 *)(param_1 + 0x240) = uVar5;
      *(undefined4 *)(param_1 + 0x244) = uVar6;
      *(undefined4 *)(param_1 + 0x284) = uVar7;
      fVar1 = *(float *)(param_1 + 0x200);
      if (0 < param_2) {
        iVar15 = 0;
        do {
          fVar2 = *pfVar14;
          fVar3 = *local_24;
          fVar4 = *(float *)(param_1 + 500);
          *(float *)(param_1 + 500) = -fVar4;
          *local_2c = fVar2 * *(float *)(param_1 + 0x200) + (1.0 - fVar1) * fVar3 + -fVar4;
          local_2c = local_2c + 1;
          pfVar14 = pfVar14 + 1;
          local_24 = local_24 + 1;
          iVar15 = iVar15 + 1;
        } while (param_2 != iVar15);
      }
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))(*(int **)(param_1 + 0x118));
      return;
    }
  }
  return;
}

