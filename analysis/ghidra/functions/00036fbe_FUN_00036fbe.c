/* 00036fbe FUN_00036fbe */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4
FUN_00036fbe(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  longdouble lVar10;
  longdouble lVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float local_28;
  float local_24;
  
  if (*(int *)(param_1 + 0x124) == 0) {
    return 0;
  }
  lVar10 = (longdouble)FUN_0001421a(param_1,param_3,*(undefined8 *)(param_1 + 0x330));
  lVar11 = (longdouble)FUN_0001421a(param_1,param_4,*(undefined8 *)(param_1 + 0x330));
  dVar14 = *(double *)(param_1 + 0x428);
  bVar9 = dVar14 != *(double *)(param_1 + 0x328);
  bVar7 = *(double *)(param_1 + 0x328) <= dVar14;
  bVar8 = bVar7 && bVar9;
  if (0 < *param_2) {
    if (!bVar7 || !bVar9) goto LAB_000372a9;
    local_28 = (float)lVar10;
    local_24 = (float)lVar11;
    do {
      uVar3 = *(uint *)(param_1 + 0x430);
      *(uint *)(param_1 + 0x430) = uVar3 + 1;
      if ((uVar3 & 7) == 0) {
        *(float *)(param_1 + 0x218) = param_5 * **(float **)(param_1 + 0x208);
        *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
        fVar1 = **(float **)(param_1 + 0x20c);
        *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
        if ((-1.0 <= fVar1) || (NAN(fVar1))) {
          if (fVar1 <= 1.0) {
            dVar14 = (double)fVar1;
          }
          else {
            dVar14 = 1.0;
          }
        }
        else {
          dVar14 = -1.0;
        }
        dVar14 = dVar14 * dVar14 * dVar14 * 0.05362607007876781 +
                 dVar14 * dVar14 * 0.2480732860777168 + dVar14 * 0.695218770961068 + 1.0;
        dVar14 = dVar14 * dVar14 * dVar14 * dVar14 * *(double *)(param_1 + 0x418);
        *(double *)(param_1 + 0x420) = dVar14;
        *(float *)(param_1 + 0x218) = (float)((double)*(float *)(param_1 + 0x218) / dVar14);
        if ((((*(char *)(param_1 + 0x458) == '\0') || (*(char *)(param_1 + 0x459) == '\0')) ||
            (uVar3 = *(uint *)(param_1 + 0x454), *(uint *)(param_1 + 0x454) = uVar3 + 1,
            (uVar3 & 0xf) != 0)) ||
           ((*(char *)(param_1 + 0x15d) == '\0' && (*(char *)(param_1 + 0x45c) == '\0'))))
        goto LAB_00037152;
        fVar1 = **(float **)(param_1 + 0x214);
        fVar2 = *(float *)(*(int *)(param_1 + 0x124) + 0x2ac);
        dVar12 = (double)**(float **)(param_1 + 0x210) * *(double *)(param_1 + 0x444) +
                 *(double *)(param_1 + 0x434);
        dVar14 = 1.0;
        if (1.0 <= dVar12) {
          dVar14 = dVar12;
        }
        dVar12 = *(double *)(param_1 + 0x428) - (*(double *)(param_1 + 0x44c) + 1.0);
        if (dVar14 <= dVar12) {
          dVar12 = dVar14;
        }
        *(double *)(param_1 + 0x3f8) = dVar12;
        dVar14 = (double)fVar1 * *(double *)(param_1 + 0x444) + *(double *)(param_1 + 0x43c);
        dVar12 = dVar12 + *(double *)(param_1 + 0x44c);
        if (dVar12 <= dVar14) {
          dVar12 = dVar14;
        }
        *(double *)(param_1 + 0x400) = dVar12;
        if ((*(char *)(param_1 + 0x15d) != '\0') || (*(char *)(param_1 + 0x45c) != '\0')) {
          dVar14 = *(double *)(param_1 + 0x328) + 1.0;
          if (dVar14 <= dVar12) {
            dVar14 = dVar12;
          }
          *(double *)(param_1 + 0x400) = dVar14;
        }
        dVar12 = *(double *)(param_1 + 0x428) - 1.0;
        dVar14 = *(double *)(param_1 + 0x400);
        if (dVar14 <= dVar12) {
          dVar12 = dVar14;
        }
        *(double *)(param_1 + 0x400) = dVar12;
        dVar14 = *(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x3f8);
        *(double *)(param_1 + 0x410) = dVar14;
        dVar12 = (double)(fVar2 * -0.01 + 1.0) * dVar14 + *(double *)(param_1 + 0x3f8);
        *(double *)(param_1 + 0x408) = dVar12;
        if ((*(char *)(param_1 + 0x15d) == '\0') && (*(char *)(param_1 + 0x45c) == '\0')) {
          dVar14 = *(double *)(param_1 + 0x328);
        }
        else {
          dVar14 = *(double *)(param_1 + 0x328);
          dVar13 = dVar14;
          if (dVar14 <= dVar12) {
            dVar13 = dVar12;
          }
          *(double *)(param_1 + 0x408) = dVar13;
        }
        dVar12 = *(double *)(param_1 + 0x410);
        if (*(double *)(param_1 + 0x410) <= *(double *)(param_1 + 0x408)) {
          dVar12 = *(double *)(param_1 + 0x408);
        }
        *(double *)(param_1 + 0x408) = dVar12;
        *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 0x40;
        *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 0x40;
      }
      else {
LAB_00037152:
        dVar14 = *(double *)(param_1 + 0x328);
      }
      lVar10 = (longdouble)FUN_00013b34(param_1,param_4,dVar14);
      pfVar4 = *(float **)(param_1 + 0x234);
      *pfVar4 = ((float)lVar10 - local_24) * *(float *)(param_1 + 0x218) *
                **(float **)(param_1 + 0x22c) + *pfVar4;
      *(float **)(param_1 + 0x234) = pfVar4 + 1;
      lVar11 = (longdouble)FUN_00013b34(param_1,param_3,*(undefined8 *)(param_1 + 0x328));
      pfVar4 = *(float **)(param_1 + 0x230);
      pfVar5 = *(float **)(param_1 + 0x22c);
      *pfVar4 = ((float)lVar11 - local_28) * *(float *)(param_1 + 0x218) * *pfVar5 + *pfVar4;
      *(float **)(param_1 + 0x230) = pfVar4 + 1;
      *(float **)(param_1 + 0x22c) = pfVar5 + 1;
      *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(param_1 + 0x328);
      dVar14 = (double)**(float **)(param_1 + 0x228) * *(double *)(param_1 + 0x420) +
               *(double *)(param_1 + 0x328);
      *(double *)(param_1 + 0x328) = dVar14;
      bVar8 = dVar14 < *(double *)(param_1 + 0x428);
      *(float **)(param_1 + 0x228) = *(float **)(param_1 + 0x228) + 1;
      bVar9 = bVar8;
      if ((*(char *)(param_1 + 0x458) != '\0') &&
         (((*(char *)(param_1 + 0x15d) != '\0' || (*(char *)(param_1 + 0x45c) != '\0')) &&
          (*(double *)(param_1 + 0x408) <= *(double *)(param_1 + 0x328) &&
           *(double *)(param_1 + 0x328) != *(double *)(param_1 + 0x408))))) {
        bVar9 = false;
      }
      iVar6 = *param_2;
      *param_2 = iVar6 + -1;
      local_28 = (float)lVar11;
      local_24 = (float)lVar10;
    } while ((bool)(0 < iVar6 + -1 & bVar9));
  }
  if (bVar8) {
    return 1;
  }
LAB_000372a9:
  if (((*(char *)(param_1 + 0x458) != '\0') &&
      ((*(char *)(param_1 + 0x15d) != '\0' || (*(char *)(param_1 + 0x45c) != '\0')))) &&
     (*(double *)(param_1 + 0x330) <= *(double *)(param_1 + 0x408) &&
      *(double *)(param_1 + 0x408) != *(double *)(param_1 + 0x330))) {
    return 1;
  }
  return 0;
}

