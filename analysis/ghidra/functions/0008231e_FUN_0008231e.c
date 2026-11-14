/* 0008231e FUN_0008231e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008231e(int param_1,undefined4 param_2,undefined4 *param_3,float param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  longdouble lVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int local_74;
  float *local_70;
  int *local_44;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((*(int **)(param_1 + 200) != (int *)0x0) && (**(int **)(param_1 + 200) != 0)) {
    fVar13 = param_4 * *(float *)(param_1 + 0xdc);
    fVar15 = (float)*(int *)(param_1 + 0xe0) - 1.0;
    lVar10 = (longdouble)FUN_000152c0(param_5,(float)*(int *)(param_1 + 0xb0));
    local_44 = *(int **)(param_1 + 200);
    iVar4 = *(int *)(*local_44 + 0x210);
    if ((0 < *(int *)(param_1 + 0xb0)) && (fVar13 < fVar15)) {
      iVar9 = 0;
      local_30 = 0;
      do {
        fVar14 = (float)iVar4 * (float)lVar10 + fVar13;
        fVar11 = fVar15;
        if (fVar14 <= fVar15) {
          fVar11 = fVar14;
        }
        iVar6 = (int)(fVar13 + 0.5);
        iVar8 = (int)(fVar11 + 0.5);
        if (*(char *)(param_1 + 0xd8) == '\0') {
          pfVar7 = (float *)(local_30 + *(int *)(param_1 + 0xd4));
          pfVar5 = (float *)(local_30 + *(int *)(param_1 + 0xd0));
          iVar1 = *(int *)(*local_44 + 0x21c);
          iVar6 = iVar6 + 1;
          if (iVar8 < iVar6) {
            iVar8 = iVar6;
          }
          *pfVar5 = -1.0;
          *pfVar7 = 1.0;
          if (iVar6 <= iVar8) {
            pfVar3 = (float *)(iVar1 + iVar6 * 4);
            do {
              fVar13 = *pfVar3;
              if (*pfVar5 <= fVar13 && fVar13 != *pfVar5) {
                *pfVar5 = fVar13;
              }
              if (fVar13 < *pfVar7) {
                *pfVar7 = fVar13;
              }
              iVar6 = iVar6 + 1;
              pfVar3 = pfVar3 + 1;
            } while (iVar6 <= iVar8);
          }
        }
        else {
          pfVar5 = (float *)(local_30 + *(int *)(param_1 + 0xd4));
          pfVar7 = (float *)(local_30 + *(int *)(param_1 + 0xd0));
          iVar1 = *(int *)(*local_44 + 0x21c);
          local_74 = iVar6 + 1;
          iVar2 = local_74;
          if (local_74 <= iVar8) {
            iVar2 = iVar8;
          }
          fVar13 = *(float *)(iVar1 + iVar6 * 4);
          *pfVar7 = -1.0;
          *pfVar5 = 1.0;
          if (local_74 <= iVar2) {
            local_70 = (float *)(iVar1 + local_74 * 4);
            do {
              fVar11 = *local_70;
              fVar13 = fVar11 - fVar13;
              if (*pfVar7 <= fVar13 && fVar13 != *pfVar7) {
                *pfVar7 = fVar13;
              }
              if (fVar13 < *pfVar5) {
                *pfVar5 = fVar13;
              }
              if (*pfVar7 <= -1.0 && *pfVar7 != -1.0) {
                *pfVar7 = -1.0;
                fVar13 = -1.0;
              }
              else {
                fVar13 = *pfVar7;
              }
              if (1.1 < fVar13) {
                *pfVar7 = 1.1;
              }
              if (*pfVar5 <= -1.1 && *pfVar5 != -1.1) {
                *pfVar5 = -1.1;
              }
              fVar13 = *pfVar5;
              if (1.0 < *pfVar5) {
                *pfVar5 = 1.0;
                fVar13 = 1.0;
              }
              if (-1.0 <= fVar13) {
                *pfVar5 = (float)(~-(uint)(fVar13 <= 1.0) & (uint)1.0 |
                                 (uint)fVar13 & -(uint)(fVar13 <= 1.0));
                fVar13 = *pfVar7;
                if (-1.0 <= fVar13) goto LAB_00082550;
LAB_000825f9:
                *pfVar7 = -1.0;
              }
              else {
                *pfVar5 = -1.0;
                fVar13 = *pfVar7;
                if (fVar13 < -1.0) goto LAB_000825f9;
LAB_00082550:
                fVar12 = 1.0;
                if (fVar13 <= 1.0) {
                  fVar12 = fVar13;
                }
                *pfVar7 = fVar12;
              }
              if (iVar2 < local_74 + 1) break;
              local_70 = local_70 + 1;
              local_74 = local_74 + 1;
              fVar13 = fVar11;
            } while( true );
          }
        }
        iVar9 = iVar9 + 1;
        if ((*(int *)(param_1 + 0xb0) <= iVar9) || (local_30 = local_30 + 4, fVar15 <= fVar14))
        goto LAB_000823d1;
        local_44 = *(int **)(param_1 + 200);
        fVar13 = fVar14;
      } while( true );
    }
    iVar9 = 0;
LAB_000823d1:
    if (iVar9 < *(int *)(param_1 + 0xb0)) {
      iVar4 = iVar9 * 4;
      do {
        iVar8 = *(int *)(param_1 + 0xd0);
        *(undefined4 *)(*(int *)(param_1 + 0xd4) + iVar4) = 0;
        *(undefined4 *)(iVar4 + iVar8) = 0;
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar9 < *(int *)(param_1 + 0xb0));
    }
    local_2c = *param_3;
    local_28 = param_3[1];
    local_24 = param_3[2];
    local_20 = param_3[3];
    FUN_000819e2(param_1,param_2,&local_2c,param_4,param_5);
  }
  return;
}

