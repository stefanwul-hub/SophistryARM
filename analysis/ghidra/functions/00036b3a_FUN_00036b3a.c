/* 00036b3a FUN_00036b3a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_00036b3a(int param_1,int *param_2,undefined4 param_3,float param_4)

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
  double dVar11;
  double dVar12;
  double dVar13;
  float local_20;
  
  if (*(int *)(param_1 + 0x124) == 0) {
    return 0;
  }
  lVar10 = (longdouble)FUN_0001421a(param_1,param_3,*(undefined8 *)(param_1 + 0x330));
  dVar13 = *(double *)(param_1 + 0x428);
  bVar9 = dVar13 != *(double *)(param_1 + 0x328);
  bVar7 = *(double *)(param_1 + 0x328) <= dVar13;
  bVar8 = bVar7 && bVar9;
  if (0 < *param_2) {
    if (!bVar7 || !bVar9) goto LAB_00036dac;
    local_20 = (float)lVar10;
    do {
      uVar3 = *(uint *)(param_1 + 0x430);
      *(uint *)(param_1 + 0x430) = uVar3 + 1;
      if ((uVar3 & 7) == 0) {
        *(float *)(param_1 + 0x218) = param_4 * **(float **)(param_1 + 0x208);
        *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
        fVar1 = **(float **)(param_1 + 0x20c);
        *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
        if ((-1.0 <= fVar1) || (NAN(fVar1))) {
          if (fVar1 <= 1.0) {
            dVar13 = (double)fVar1;
          }
          else {
            dVar13 = 1.0;
          }
        }
        else {
          dVar13 = -1.0;
        }
        dVar13 = dVar13 * dVar13 * dVar13 * 0.05362607007876781 +
                 dVar13 * dVar13 * 0.2480732860777168 + dVar13 * 0.695218770961068 + 1.0;
        dVar13 = dVar13 * dVar13 * dVar13 * dVar13 * *(double *)(param_1 + 0x418);
        *(double *)(param_1 + 0x420) = dVar13;
        *(float *)(param_1 + 0x218) = (float)((double)*(float *)(param_1 + 0x218) / dVar13);
        if ((((*(char *)(param_1 + 0x458) == '\0') || (*(char *)(param_1 + 0x459) == '\0')) ||
            (uVar3 = *(uint *)(param_1 + 0x454), *(uint *)(param_1 + 0x454) = uVar3 + 1,
            (uVar3 & 0xf) != 0)) ||
           ((*(char *)(param_1 + 0x15d) == '\0' && (*(char *)(param_1 + 0x45c) == '\0'))))
        goto LAB_00036cae;
        fVar1 = **(float **)(param_1 + 0x214);
        fVar2 = *(float *)(*(int *)(param_1 + 0x124) + 0x2ac);
        dVar11 = (double)**(float **)(param_1 + 0x210) * *(double *)(param_1 + 0x444) +
                 *(double *)(param_1 + 0x434);
        dVar13 = 1.0;
        if (1.0 <= dVar11) {
          dVar13 = dVar11;
        }
        dVar11 = *(double *)(param_1 + 0x428) - (*(double *)(param_1 + 0x44c) + 1.0);
        if (dVar13 <= dVar11) {
          dVar11 = dVar13;
        }
        *(double *)(param_1 + 0x3f8) = dVar11;
        dVar13 = (double)fVar1 * *(double *)(param_1 + 0x444) + *(double *)(param_1 + 0x43c);
        dVar11 = dVar11 + *(double *)(param_1 + 0x44c);
        if (dVar11 <= dVar13) {
          dVar11 = dVar13;
        }
        *(double *)(param_1 + 0x400) = dVar11;
        if ((*(char *)(param_1 + 0x15d) != '\0') || (*(char *)(param_1 + 0x45c) != '\0')) {
          dVar13 = *(double *)(param_1 + 0x328) + 1.0;
          if (dVar13 <= dVar11) {
            dVar13 = dVar11;
          }
          *(double *)(param_1 + 0x400) = dVar13;
        }
        dVar11 = *(double *)(param_1 + 0x428) - 1.0;
        dVar13 = *(double *)(param_1 + 0x400);
        if (dVar13 <= dVar11) {
          dVar11 = dVar13;
        }
        *(double *)(param_1 + 0x400) = dVar11;
        dVar13 = *(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x3f8);
        *(double *)(param_1 + 0x410) = dVar13;
        dVar11 = (double)(fVar2 * -0.01 + 1.0) * dVar13 + *(double *)(param_1 + 0x3f8);
        *(double *)(param_1 + 0x408) = dVar11;
        if ((*(char *)(param_1 + 0x15d) == '\0') && (*(char *)(param_1 + 0x45c) == '\0')) {
          dVar13 = *(double *)(param_1 + 0x328);
        }
        else {
          dVar13 = *(double *)(param_1 + 0x328);
          dVar12 = dVar13;
          if (dVar13 <= dVar11) {
            dVar12 = dVar11;
          }
          *(double *)(param_1 + 0x408) = dVar12;
        }
        dVar11 = *(double *)(param_1 + 0x410);
        if (*(double *)(param_1 + 0x410) <= *(double *)(param_1 + 0x408)) {
          dVar11 = *(double *)(param_1 + 0x408);
        }
        *(double *)(param_1 + 0x408) = dVar11;
        *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 0x40;
        *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 0x40;
      }
      else {
LAB_00036cae:
        dVar13 = *(double *)(param_1 + 0x328);
      }
      lVar10 = (longdouble)FUN_00013b34(param_1,param_3,dVar13);
      pfVar4 = *(float **)(param_1 + 0x230);
      pfVar5 = *(float **)(param_1 + 0x22c);
      *pfVar4 = ((float)lVar10 - local_20) * *(float *)(param_1 + 0x218) * *pfVar5 + *pfVar4;
      *(float **)(param_1 + 0x230) = pfVar4 + 1;
      *(float **)(param_1 + 0x22c) = pfVar5 + 1;
      *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(param_1 + 0x328);
      dVar13 = (double)**(float **)(param_1 + 0x228) * *(double *)(param_1 + 0x420) +
               *(double *)(param_1 + 0x328);
      *(double *)(param_1 + 0x328) = dVar13;
      bVar8 = dVar13 < *(double *)(param_1 + 0x428);
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
      local_20 = (float)lVar10;
    } while ((bool)(0 < iVar6 + -1 & bVar9));
  }
  if (bVar8) {
    return 1;
  }
LAB_00036dac:
  if (((*(char *)(param_1 + 0x458) != '\0') &&
      ((*(char *)(param_1 + 0x15d) != '\0' || (*(char *)(param_1 + 0x45c) != '\0')))) &&
     (*(double *)(param_1 + 0x330) <= *(double *)(param_1 + 0x408) &&
      *(double *)(param_1 + 0x408) != *(double *)(param_1 + 0x330))) {
    return 1;
  }
  return 0;
}

