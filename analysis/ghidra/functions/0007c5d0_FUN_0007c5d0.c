/* 0007c5d0 FUN_0007c5d0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0007c5d0(int param_1,int param_2)

{
  uint *puVar1;
  float fVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  longdouble lVar9;
  double dVar10;
  double dVar11;
  undefined8 uVar12;
  double dVar13;
  double dVar14;
  double in_XMM3_Qa;
  double dVar15;
  double local_34;
  float *local_24;
  float *local_20 [4];
  
  (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),local_20,0);
  (**(code **)(**(int **)(param_1 + 0x118) + 0x28))(*(int **)(param_1 + 0x118),&local_24,0);
  uVar4 = param_2 * *(int *)(param_1 + 0x478);
  if (0 < (int)uVar4) {
    uVar6 = 0;
    do {
      dVar14 = 1.0;
      uVar8 = uVar6 + 1;
      if ((uVar6 & *(uint *)(param_1 + 0x488)) == 0) {
        dVar15 = (double)**(float **)(param_1 + 0x46c);
        *(float **)(param_1 + 0x46c) = *(float **)(param_1 + 0x46c) + 1;
        fVar2 = **(float **)(param_1 + 0x470);
        *(float **)(param_1 + 0x470) = *(float **)(param_1 + 0x470) + 1;
        if ((-1.0 <= fVar2) || (NAN(fVar2))) {
          dVar10 = dVar14;
          if (fVar2 <= 1.0) {
            dVar10 = (double)fVar2;
          }
        }
        else {
          dVar10 = -1.0;
        }
        dVar10 = dVar10 * dVar10 * dVar10 * 0.05362607007876781 +
                 dVar10 * dVar10 * 0.2480732860777168 + dVar10 * 0.695218770961068 + 1.0;
        for (dVar10 = dVar10 * dVar10 * dVar10 * dVar10 * *(double *)(param_1 + 0x204) *
                      (*(double *)(param_1 + 0x480) + *(double *)(param_1 + 0x480)) *
                      (double)*(float *)(param_1 + 0x144);
            *(double *)(param_1 + 0x480) * 0.5 < dVar10; dVar10 = dVar10 * 0.5) {
        }
        if (*(double *)(param_1 + 0x250) <= 0.0 && *(double *)(param_1 + 0x250) != 0.0) {
          *(double *)(param_1 + 0x250) = -*(double *)(param_1 + 0x214) * ABS(dVar15) - 1e-05;
        }
        else {
          *(double *)(param_1 + 0x250) = ABS(dVar15) * *(double *)(param_1 + 0x214) + 1e-05;
        }
        *(float *)(param_1 + 0x24c) = (float)(-dVar15 * *(double *)(param_1 + 0x21c));
        if (*(float *)(param_1 + 0x25c) <= 0.0 && *(float *)(param_1 + 0x25c) != 0.0) {
          *(float *)(param_1 + 0x25c) = (float)(dVar15 * -*(double *)(param_1 + 0x224));
        }
        else {
          *(float *)(param_1 + 0x25c) = (float)(dVar15 * *(double *)(param_1 + 0x224));
        }
        dVar15 = (double)**(float **)(param_1 + 0x474) * 0.95 + *(double *)(param_1 + 0x20c);
        *(float **)(param_1 + 0x474) = *(float **)(param_1 + 0x474) + 1;
        if (1.0 < dVar15) {
          dVar15 = 2.0 - dVar15;
        }
        if (dVar15 < 0.05) {
          dVar15 = 0.1 - dVar15;
        }
        dVar11 = dVar10 + dVar10;
        dVar13 = 0.05;
        if ((0.05 <= dVar11) && (dVar13 = dVar14, dVar11 <= 1.0)) {
          dVar13 = dVar11;
        }
        if ((dVar13 <= dVar15) && (dVar13 = dVar14, dVar15 <= 1.0)) {
          dVar13 = dVar15;
        }
        if ((*(char *)(param_1 + 600) == '\0') ||
           (*(double *)(param_1 + 0x234) <= 2e-09 && *(double *)(param_1 + 0x234) != 2e-09)) {
          *(double *)(param_1 + 0x264) = dVar10 / dVar13;
          *(double *)(param_1 + 0x26c) = dVar10 * (0.5 / (dVar13 * -0.5 + 1.0));
        }
      }
      dVar14 = *(double *)(param_1 + 0x22c);
      if (dVar14 < 1.0) {
        in_XMM3_Qa = (double)*(float *)(param_1 + 0x24c) * (dVar14 + *(double *)(param_1 + 0x244)) +
                     *(double *)(param_1 + 0x250) + (double)*(float *)(param_1 + 0x25c);
      }
      else {
        dVar14 = dVar14 - 1.0;
        *(double *)(param_1 + 0x22c) = dVar14;
        *(double *)(param_1 + 0x244) = -1.0 - *(double *)(param_1 + 0x244);
        dVar15 = -*(double *)(param_1 + 0x250);
        *(double *)(param_1 + 0x250) = dVar15;
        if (1e-08 < *(double *)(param_1 + 0x234) || *(double *)(param_1 + 0x234) == 1e-08) {
          if (dVar14 <= 1.0) {
            if ((*(char *)(param_1 + 0x1d4) != '\0') && (0.0 < dVar15)) {
              iVar5 = (int)uVar6 / *(int *)(param_1 + 0x478);
              iVar7 = iVar5;
              if (iVar5 < 0) {
                iVar7 = iVar5 + 0x1f;
              }
              puVar1 = (uint *)(*(int *)(param_1 + 0x1f0) + (iVar7 >> 5) * 4);
              *puVar1 = *puVar1 | 1 << ((byte)iVar5 & 0x1f);
            }
            lVar9 = (longdouble)
                    FUN_000152c0((float)((*(double *)(param_1 + 0x22c) +
                                         *(double *)(param_1 + 0x22c)) -
                                        *(double *)(param_1 + 0x234)),
                                 (float)*(double *)(param_1 + 0x234));
            local_34 = (double)(float)lVar9;
            if (*(double *)(param_1 + 0x244) <= -0.5) {
              dVar14 = -local_34;
            }
            else {
              dVar14 = *(double *)(param_1 + 0x244) + *(double *)(param_1 + 0x22c);
            }
            in_XMM3_Qa = local_34 * *(double *)(param_1 + 0x250) +
                         dVar14 * (double)*(float *)(param_1 + 0x24c);
            bVar3 = *(byte *)(param_1 + 600);
            *(byte *)(param_1 + 600) = bVar3 ^ 1;
            if (bVar3 == 0) {
              dVar14 = *(double *)(param_1 + 0x26c);
              dVar15 = *(double *)(param_1 + 0x264);
            }
            else {
              dVar14 = *(double *)(param_1 + 0x264);
              dVar15 = *(double *)(param_1 + 0x26c);
            }
            *(double *)(param_1 + 0x234) =
                 (1.0 - *(double *)(param_1 + 0x22c)) /
                 (1.0 / dVar14 - *(double *)(param_1 + 0x22c) / dVar15);
          }
          else {
            *(double *)(param_1 + 0x22c) = dVar14 - 1.0;
          }
        }
        else {
          in_XMM3_Qa = (double)*(float *)(param_1 + 0x24c) * (dVar14 + *(double *)(param_1 + 0x244))
                       + dVar15;
          if (dVar14 < 1.0) {
            bVar3 = *(byte *)(param_1 + 600);
            *(byte *)(param_1 + 600) = bVar3 ^ 1;
            if (bVar3 == 0) {
              uVar12 = *(undefined8 *)(param_1 + 0x26c);
            }
            else {
              uVar12 = *(undefined8 *)(param_1 + 0x264);
            }
            *(undefined8 *)(param_1 + 0x234) = uVar12;
          }
          else {
            if (*(char *)(param_1 + 600) == '\0') {
              uVar12 = *(undefined8 *)(param_1 + 0x264);
            }
            else {
              uVar12 = *(undefined8 *)(param_1 + 0x26c);
            }
            *(undefined8 *)(param_1 + 0x234) = uVar12;
            *(double *)(param_1 + 0x22c) = *(double *)(param_1 + 0x22c) - 1.0;
          }
        }
        bVar3 = *(byte *)(param_1 + 0x260);
        *(byte *)(param_1 + 0x260) = bVar3 ^ 1;
        if (bVar3 == 0) {
          fVar2 = *(float *)(param_1 + 0x25c);
          *(float *)(param_1 + 0x25c) = -fVar2;
          in_XMM3_Qa = (double)((float)local_34 * -fVar2) + in_XMM3_Qa;
        }
        else {
          in_XMM3_Qa = (double)*(float *)(param_1 + 0x25c) + in_XMM3_Qa;
        }
      }
      fVar2 = *local_20[0];
      uVar6 = uVar8 & *(uint *)(param_1 + 0x47c);
      if (uVar6 == 0) {
        local_20[0] = local_20[0] + 1;
      }
      dVar14 = ((double)fVar2 * in_XMM3_Qa - *(double *)(param_1 + 0x424)) +
               *(double *)(param_1 + 0x3f4) * -0.85;
      *(double *)(param_1 + 0x3c4) = dVar14;
      dVar14 = dVar14 * 0.5 + *(double *)(param_1 + 0x3f4);
      *(double *)(param_1 + 0x3f4) = dVar14;
      in_XMM3_Qa = dVar14 * 0.5 + *(double *)(param_1 + 0x424);
      *(double *)(param_1 + 0x424) = in_XMM3_Qa;
      if (uVar6 == 0) {
        *local_24 = (float)((double)*local_24 + in_XMM3_Qa);
        local_24 = local_24 + 1;
      }
      *(double *)(param_1 + 0x22c) = *(double *)(param_1 + 0x22c) + *(double *)(param_1 + 0x234);
      uVar6 = uVar8;
    } while (uVar8 != uVar4);
  }
  (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
  return 0;
}

