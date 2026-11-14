/* 0007e338 OscAnalog3_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 OscAnalog3_c_vslot_61(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  float fVar2;
  undefined8 uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  
  if ((char)param_1[0x75] == '\0') {
    iVar7 = param_3 << 2;
    iVar6 = param_1[0x7b];
  }
  else if (param_1[0x7b] == 0) {
    iVar7 = param_3 << 2;
    iVar6 = 0;
  }
  else {
    iVar7 = param_3 * 4;
    _memset(*(void **)(param_1[0x7b] + iVar7),0,(param_2 + -1 >> 3) + 1);
    iVar6 = param_1[0x7b];
  }
  param_1[0x11b] = param_1[0x7e];
  param_1[0x11c] = param_1[0x7f];
  param_1[0x11d] = param_1[0x80];
  param_1[0x7c] = *(int *)(iVar6 + iVar7);
  if (*(char *)((int)param_1 + 0x1d5) == '\0') {
    iVar6 = param_1[0x77];
    if (iVar6 == 1) {
      FUN_0007bec6(param_1,param_2,param_3);
      return 0;
    }
    if (iVar6 < 2) {
      if (iVar6 == 0) {
        (**(code **)(*param_1 + 0xf8))(param_1,param_2,param_3);
      }
    }
    else if (iVar6 == 2) {
      FUN_0007c5d0(param_1,param_2,param_3);
    }
    else if (((iVar6 == 3) && ((char)param_1[0x75] != '\0')) &&
            (iVar6 = param_1[0x11e], 0 < param_2 * iVar6)) {
      uVar8 = 0;
      dVar12 = *(double *)(param_1 + 0x8b);
      do {
        dVar11 = 1.0;
        if ((param_1[0x122] & uVar8) == 0) {
          dVar13 = (double)*(float *)param_1[0x11b];
          param_1[0x11b] = (int)((float *)param_1[0x11b] + 1);
          fVar2 = *(float *)param_1[0x11c];
          param_1[0x11c] = (int)((float *)param_1[0x11c] + 1);
          if ((-1.0 <= fVar2) || (NAN(fVar2))) {
            dVar9 = dVar11;
            if (fVar2 <= 1.0) {
              dVar9 = (double)fVar2;
            }
          }
          else {
            dVar9 = -1.0;
          }
          dVar9 = dVar9 * dVar9 * dVar9 * 0.05362607007876781 + dVar9 * dVar9 * 0.2480732860777168 +
                  dVar9 * 0.695218770961068 + 1.0;
          for (dVar9 = dVar9 * dVar9 * dVar9 * dVar9 * *(double *)(param_1 + 0x81) *
                       (*(double *)(param_1 + 0x120) + *(double *)(param_1 + 0x120)) *
                       (double)(float)param_1[0x51]; *(double *)(param_1 + 0x120) * 0.5 < dVar9;
              dVar9 = dVar9 * 0.5) {
          }
          if (*(double *)(param_1 + 0x94) <= 0.0 && *(double *)(param_1 + 0x94) != 0.0) {
            *(double *)(param_1 + 0x94) = -*(double *)(param_1 + 0x85) * ABS(dVar13) - 1e-05;
          }
          else {
            *(double *)(param_1 + 0x94) = ABS(dVar13) * *(double *)(param_1 + 0x85) + 1e-05;
          }
          param_1[0x93] = (int)(float)(-dVar13 * *(double *)(param_1 + 0x87));
          if ((float)param_1[0x97] <= 0.0 && (float)param_1[0x97] != 0.0) {
            param_1[0x97] = (int)(float)(dVar13 * -*(double *)(param_1 + 0x89));
          }
          else {
            param_1[0x97] = (int)(float)(dVar13 * *(double *)(param_1 + 0x89));
          }
          dVar13 = (double)*(float *)param_1[0x11d] * 0.95 + *(double *)(param_1 + 0x83);
          param_1[0x11d] = (int)((float *)param_1[0x11d] + 1);
          if (1.0 < dVar13) {
            dVar13 = 2.0 - dVar13;
          }
          if (dVar13 < 0.05) {
            dVar13 = 0.1 - dVar13;
          }
          dVar10 = dVar9 + dVar9;
          dVar14 = 0.05;
          if ((0.05 <= dVar10) && (dVar14 = dVar11, dVar10 <= 1.0)) {
            dVar14 = dVar10;
          }
          if ((dVar14 <= dVar13) && (dVar14 = dVar11, dVar13 <= 1.0)) {
            dVar14 = dVar13;
          }
          if (((char)param_1[0x96] == '\0') ||
             (*(double *)(param_1 + 0x8d) <= 2e-09 && *(double *)(param_1 + 0x8d) != 2e-09)) {
            *(double *)(param_1 + 0x99) = dVar9 / dVar14;
            *(double *)(param_1 + 0x9b) = dVar9 * (0.5 / (dVar14 * -0.5 + 1.0));
          }
        }
        if (1.0 <= dVar12) {
          dVar12 = dVar12 - 1.0;
          *(double *)(param_1 + 0x8b) = dVar12;
          *(double *)(param_1 + 0x91) = -1.0 - *(double *)(param_1 + 0x91);
          dVar11 = *(double *)(param_1 + 0x94);
          *(double *)(param_1 + 0x94) = -dVar11;
          if (1e-08 < *(double *)(param_1 + 0x8d) || *(double *)(param_1 + 0x8d) == 1e-08) {
            if (1.0 < dVar12) goto LAB_0007e712;
            if (((char)param_1[0x75] != '\0') && (0.0 < -dVar11)) {
              iVar5 = (int)uVar8 / param_1[0x11e];
              iVar7 = iVar5;
              if (iVar5 < 0) {
                iVar7 = iVar5 + 0x1f;
              }
              puVar1 = (uint *)(param_1[0x7c] + (iVar7 >> 5) * 4);
              *puVar1 = *puVar1 | 1 << ((byte)iVar5 & 0x1f);
            }
            FUN_000152c0((float)((*(double *)(param_1 + 0x8b) + *(double *)(param_1 + 0x8b)) -
                                *(double *)(param_1 + 0x8d)),(float)*(double *)(param_1 + 0x8d));
            bVar4 = *(byte *)(param_1 + 0x96);
            *(byte *)(param_1 + 0x96) = bVar4 ^ 1;
            if (bVar4 == 0) {
              dVar11 = *(double *)(param_1 + 0x9b);
              dVar13 = *(double *)(param_1 + 0x99);
            }
            else {
              dVar11 = *(double *)(param_1 + 0x99);
              dVar13 = *(double *)(param_1 + 0x9b);
            }
            dVar12 = *(double *)(param_1 + 0x8b);
            *(double *)(param_1 + 0x8d) = (1.0 - dVar12) / (1.0 / dVar11 - dVar12 / dVar13);
          }
          else if (dVar12 < 1.0) {
            bVar4 = *(byte *)(param_1 + 0x96);
            *(byte *)(param_1 + 0x96) = bVar4 ^ 1;
            if (bVar4 == 0) {
              uVar3 = *(undefined8 *)(param_1 + 0x9b);
            }
            else {
              uVar3 = *(undefined8 *)(param_1 + 0x99);
            }
            *(undefined8 *)(param_1 + 0x8d) = uVar3;
            dVar12 = *(double *)(param_1 + 0x8b);
          }
          else {
            if ((char)param_1[0x96] == '\0') {
              uVar3 = *(undefined8 *)(param_1 + 0x99);
            }
            else {
              uVar3 = *(undefined8 *)(param_1 + 0x9b);
            }
            *(undefined8 *)(param_1 + 0x8d) = uVar3;
            dVar12 = *(double *)(param_1 + 0x8b);
LAB_0007e712:
            dVar12 = dVar12 - 1.0;
            *(double *)(param_1 + 0x8b) = dVar12;
          }
          bVar4 = *(byte *)(param_1 + 0x98);
          *(byte *)(param_1 + 0x98) = bVar4 ^ 1;
          if (bVar4 == 0) {
            param_1[0x97] = param_1[0x97] ^ 0x80000000;
          }
        }
        dVar12 = dVar12 + *(double *)(param_1 + 0x8d);
        *(double *)(param_1 + 0x8b) = dVar12;
        uVar8 = uVar8 + 1;
      } while (param_2 * iVar6 != uVar8);
    }
  }
  else {
    iVar6 = param_1[0x77];
    if (iVar6 == 1) {
      FUN_0007d422(param_1,param_2,param_3);
      return 0;
    }
    if (iVar6 == 2) {
      FUN_0007dbac(param_1,param_2,param_3);
      return 0;
    }
    if (iVar6 == 0) {
      FUN_0007ccc4(param_1,param_2,param_3);
      return 0;
    }
  }
  return 0;
}

