/* 00074ba6 FilterFree_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FilterFree_c_vslot_56(int param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  longdouble lVar5;
  float fVar6;
  double dVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  
  if (*(char *)(param_1 + 0x15c) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
              (*(int **)(param_1 + 0x118),param_1 + 0x218,param_1 + 0x21c);
    piVar2 = *(int **)(param_1 + 0x10);
    if (*(char *)((int)piVar2 + 0x27) == '\0') {
      (**(code **)(*piVar2 + 0x34))(piVar2,param_1 + 0x210,0);
    }
    else {
      (**(code **)(*piVar2 + 0x38))(piVar2,param_1 + 0x210,param_1 + 0x214);
    }
    pfVar3 = *(float **)(param_1 + 0x1e8);
    *(float **)(param_1 + 0x1fc) = pfVar3;
    *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(param_1 + 0x1ec);
    *(undefined4 *)(param_1 + 0x204) = *(undefined4 *)(param_1 + 0x1f0);
    *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(param_1 + 500);
    *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x1f8);
    *(undefined4 *)(param_1 + 0x1e4) = 0;
    if (*(char *)(param_1 + 0x1e0) != '\0') {
      fVar6 = **(float **)(param_1 + 0x1f8);
      lVar5 = (longdouble)_fmod((double)(fVar6 + fVar6 + 10.0),0,0x40100000);
      fVar6 = (float)lVar5;
      if ((1.0 <= fVar6) || (*(float *)(param_1 + 0x23c) <= 3.0)) {
        if ((fVar6 <= 3.0) || (1.0 <= *(float *)(param_1 + 0x23c))) {
          *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + fVar6 * 0.01;
        }
        else {
          *(float *)(param_1 + 0x23c) = (*(float *)(param_1 + 0x23c) + 4.0) * 0.99 + fVar6 * 0.01;
        }
      }
      else {
        *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + (fVar6 + 4.0) * 0.01;
      }
      lVar5 = (longdouble)_fmod((double)*(float *)(param_1 + 0x23c),0,0x40100000);
      fVar6 = (float)lVar5;
      *(float *)(param_1 + 0x23c) = fVar6;
      if (fVar6 < 1.0) {
        *(float *)(param_1 + 0x240) = 1.0 - fVar6;
        *(float *)(param_1 + 0x248) = fVar6;
        *(undefined4 *)(param_1 + 0x244) = 0;
        *(undefined4 *)(param_1 + 0x24c) = 0;
      }
      else if (2.0 <= fVar6) {
        if (fVar6 < 3.0) {
          *(undefined4 *)(param_1 + 0x240) = 0;
          *(undefined4 *)(param_1 + 0x248) = 0;
          *(float *)(param_1 + 0x244) = 3.0 - *(float *)(param_1 + 0x23c);
          *(float *)(param_1 + 0x24c) = fVar6 - 2.0;
        }
        else {
          *(float *)(param_1 + 0x240) = fVar6 - 3.0;
          *(undefined4 *)(param_1 + 0x248) = 0;
          *(undefined4 *)(param_1 + 0x244) = 0;
          *(float *)(param_1 + 0x24c) = 4.0 - *(float *)(param_1 + 0x23c);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x240) = 0;
        *(float *)(param_1 + 0x248) = 2.0 - *(float *)(param_1 + 0x23c);
        *(float *)(param_1 + 0x244) = fVar6 - 1.0;
        *(undefined4 *)(param_1 + 0x24c) = 0;
      }
      fVar6 = *pfVar3;
      if (0.0 <= fVar6) {
        if (1.0 < fVar6) {
          dVar7 = 1.0;
        }
        else {
          dVar7 = (double)fVar6;
        }
      }
      else {
        dVar7 = 0.0;
      }
      dVar7 = dVar7 * 10.0 - 5.0;
      dVar7 = dVar7 * dVar7 * dVar7 * 0.00082312050791077 + dVar7 * dVar7 * 0.0157739370387826 +
              dVar7 * 0.174502948013078 + 1.0;
      *(float *)(param_1 + 0x22c) =
           (float)(dVar7 * dVar7 * dVar7 * dVar7 * 0.03125) * *(float *)(param_1 + 0x220);
      *(undefined1 *)(param_1 + 0x1e0) = 0;
    }
    if (*(char *)(param_1 + 0x2c8) == '\0') {
      if (*(char *)(*(int *)(param_1 + 0x10) + 0x27) == '\0') {
        if (0 < param_2) {
          iVar4 = 0;
          do {
            uVar10 = *(uint *)(param_1 + 0x1e4);
            *(uint *)(param_1 + 0x1e4) = uVar10 + 1;
            if ((uVar10 & 7) == 0) {
              fVar6 = **(float **)(param_1 + 0x1fc);
              *(float **)(param_1 + 0x1fc) = *(float **)(param_1 + 0x1fc) + 1;
              if (fVar6 < 0.0) {
                dVar7 = 0.0;
              }
              else if (fVar6 <= 1.0) {
                dVar7 = (double)fVar6;
              }
              else {
                dVar7 = 1.0;
              }
              dVar7 = dVar7 * 10.0 - 5.0;
              dVar7 = dVar7 * dVar7 * dVar7 * 0.00082312050791077 +
                      dVar7 * dVar7 * 0.0157739370387826 + dVar7 * 0.174502948013078 + 1.0;
              fVar6 = (float)(dVar7 * dVar7 * dVar7 * dVar7 * 0.03125) * *(float *)(param_1 + 0x220)
                      * 0.1 + *(float *)(param_1 + 0x22c) * 0.9;
              *(float *)(param_1 + 0x22c) = fVar6;
              dVar7 = (double)fVar6;
              *(double *)(param_1 + 0x250) = dVar7 * (2.0 - dVar7);
              fVar6 = **(float **)(param_1 + 0x200) * 0.9;
              *(float *)(param_1 + 0x230) = fVar6;
              *(float **)(param_1 + 0x200) = *(float **)(param_1 + 0x200) + 1;
              if (0.0 <= fVar6) {
                uVar10 = ~-(uint)(fVar6 <= 0.9) & (uint)0.9 | (uint)fVar6 & -(uint)(fVar6 <= 0.9);
              }
              else {
                uVar10 = 0;
              }
              *(uint *)(param_1 + 0x230) = uVar10;
              *(float *)(param_1 + 0x230) =
                   *(float *)(param_1 + 0x230) * (2.0 - *(float *)(param_1 + 0x230));
              fVar6 = **(float **)(param_1 + 0x204);
              *(float *)(param_1 + 0x224) = fVar6;
              *(float **)(param_1 + 0x204) = *(float **)(param_1 + 0x204) + 1;
              *(float *)(param_1 + 0x228) = (fVar6 - *(float *)(param_1 + 0x234)) * 0.125;
              fVar6 = *(float *)(param_1 + 0x238) * 0.75 +
                      (**(float **)(param_1 + 0x208) + 1.0) * 0.25;
              *(float *)(param_1 + 0x238) = fVar6;
              *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
              if ((1e-05 <= fVar6) || (NAN(fVar6))) {
                fVar6 = (float)(~-(uint)(fVar6 <= 1.99999) & (uint)1.99999 |
                               (uint)fVar6 & -(uint)(fVar6 <= 1.99999));
              }
              else {
                fVar6 = 1e-05;
              }
              *(float *)(param_1 + 0x238) = fVar6;
              fVar6 = **(float **)(param_1 + 0x20c);
              *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
              lVar5 = (longdouble)_fmod((double)(fVar6 + fVar6 + 10.0),0,0x40100000);
              fVar6 = (float)lVar5;
              if ((1.0 <= fVar6) || (*(float *)(param_1 + 0x23c) <= 3.0)) {
                if ((fVar6 <= 3.0) || (1.0 <= *(float *)(param_1 + 0x23c))) {
                  *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + fVar6 * 0.01;
                }
                else {
                  *(float *)(param_1 + 0x23c) =
                       (*(float *)(param_1 + 0x23c) + 4.0) * 0.99 + fVar6 * 0.01;
                }
              }
              else {
                *(float *)(param_1 + 0x23c) =
                     *(float *)(param_1 + 0x23c) * 0.99 + (fVar6 + 4.0) * 0.01;
              }
              lVar5 = (longdouble)_fmod((double)*(float *)(param_1 + 0x23c),0,0x40100000);
              fVar6 = (float)lVar5;
              *(float *)(param_1 + 0x23c) = fVar6;
              if (fVar6 < 1.0) {
                *(float *)(param_1 + 0x240) = 1.0 - fVar6;
                *(float *)(param_1 + 0x248) = fVar6;
                *(undefined4 *)(param_1 + 0x244) = 0;
                *(undefined4 *)(param_1 + 0x24c) = 0;
              }
              else if (2.0 <= fVar6) {
                if (3.0 <= fVar6) {
                  *(float *)(param_1 + 0x240) = fVar6 - 3.0;
                  *(undefined4 *)(param_1 + 0x248) = 0;
                  *(undefined4 *)(param_1 + 0x244) = 0;
                  *(float *)(param_1 + 0x24c) = 4.0 - *(float *)(param_1 + 0x23c);
                }
                else {
                  *(undefined4 *)(param_1 + 0x240) = 0;
                  *(undefined4 *)(param_1 + 0x248) = 0;
                  *(float *)(param_1 + 0x244) = 3.0 - *(float *)(param_1 + 0x23c);
                  *(float *)(param_1 + 0x24c) = fVar6 - 2.0;
                }
              }
              else {
                *(undefined4 *)(param_1 + 0x240) = 0;
                *(float *)(param_1 + 0x248) = 2.0 - *(float *)(param_1 + 0x23c);
                *(float *)(param_1 + 0x244) = fVar6 - 1.0;
                *(undefined4 *)(param_1 + 0x24c) = 0;
              }
            }
            *(float *)(param_1 + 0x234) = *(float *)(param_1 + 0x234) + *(float *)(param_1 + 0x228);
            fVar6 = **(float **)(param_1 + 0x210);
            *(float **)(param_1 + 0x210) = *(float **)(param_1 + 0x210) + 1;
            dVar7 = (double)(fVar6 - *(float *)(param_1 + 0x2c0));
            *(float *)(param_1 + 0x2c0) =
                 (float)((double)*(float *)(param_1 + 0x2c0) + dVar7 * 0.0003);
            dVar11 = (dVar7 - *(double *)(param_1 + 600)) -
                     (1.0 - (double)*(float *)(param_1 + 0x230)) * *(double *)(param_1 + 0x268);
            *(double *)(param_1 + 0x260) = dVar11;
            dVar7 = dVar11 * *(double *)(param_1 + 0x250) + *(double *)(param_1 + 0x268);
            *(double *)(param_1 + 0x268) = dVar7;
            dVar7 = dVar7 * *(double *)(param_1 + 0x250) + *(double *)(param_1 + 600);
            *(double *)(param_1 + 600) = dVar7;
            fVar6 = (float)((double)*(float *)(param_1 + 0x24c) * (dVar7 + dVar11) +
                            dVar7 * (double)*(float *)(param_1 + 0x240) +
                            dVar11 * (double)*(float *)(param_1 + 0x244) +
                           (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x268));
            *(float *)(param_1 + 0x2b8) = fVar6;
            pfVar3 = *(float **)(param_1 + 0x218);
            *pfVar3 = *pfVar3 + fVar6 * *(float *)(param_1 + 0x234) *
                                (2.0 - *(float *)(param_1 + 0x238));
            *(float **)(param_1 + 0x218) = pfVar3 + 1;
            pfVar3 = *(float **)(param_1 + 0x21c);
            *pfVar3 = *(float *)(param_1 + 0x2b8) * *(float *)(param_1 + 0x234) *
                      *(float *)(param_1 + 0x238) + *pfVar3;
            *(float **)(param_1 + 0x21c) = pfVar3 + 1;
            iVar4 = iVar4 + 1;
          } while (param_2 != iVar4);
        }
      }
      else if (0 < param_2) {
        iVar4 = 0;
        do {
          uVar10 = *(uint *)(param_1 + 0x1e4);
          *(uint *)(param_1 + 0x1e4) = uVar10 + 1;
          if ((uVar10 & 7) == 0) {
            fVar6 = **(float **)(param_1 + 0x1fc);
            *(float **)(param_1 + 0x1fc) = *(float **)(param_1 + 0x1fc) + 1;
            if (fVar6 < 0.0) {
              dVar7 = 0.0;
            }
            else if (fVar6 <= 1.0) {
              dVar7 = (double)fVar6;
            }
            else {
              dVar7 = 1.0;
            }
            dVar7 = dVar7 * 10.0 - 5.0;
            dVar7 = dVar7 * dVar7 * dVar7 * 0.00082312050791077 + dVar7 * dVar7 * 0.0157739370387826
                    + dVar7 * 0.174502948013078 + 1.0;
            fVar6 = (float)(dVar7 * dVar7 * dVar7 * dVar7 * 0.03125) * *(float *)(param_1 + 0x220) *
                    0.1 + *(float *)(param_1 + 0x22c) * 0.9;
            *(float *)(param_1 + 0x22c) = fVar6;
            dVar7 = (double)fVar6;
            *(double *)(param_1 + 0x250) = dVar7 * (2.0 - dVar7);
            fVar6 = **(float **)(param_1 + 0x200) * 0.9;
            *(float *)(param_1 + 0x230) = fVar6;
            *(float **)(param_1 + 0x200) = *(float **)(param_1 + 0x200) + 1;
            if (0.0 <= fVar6) {
              uVar10 = ~-(uint)(fVar6 <= 0.9) & (uint)0.9 | (uint)fVar6 & -(uint)(fVar6 <= 0.9);
            }
            else {
              uVar10 = 0;
            }
            *(uint *)(param_1 + 0x230) = uVar10;
            *(float *)(param_1 + 0x230) =
                 *(float *)(param_1 + 0x230) * (2.0 - *(float *)(param_1 + 0x230));
            fVar6 = **(float **)(param_1 + 0x204);
            *(float *)(param_1 + 0x224) = fVar6;
            *(float **)(param_1 + 0x204) = *(float **)(param_1 + 0x204) + 1;
            *(float *)(param_1 + 0x228) = (fVar6 - *(float *)(param_1 + 0x234)) * 0.125;
            fVar6 = *(float *)(param_1 + 0x238) * 0.75 +
                    (**(float **)(param_1 + 0x208) + 1.0) * 0.25;
            *(float *)(param_1 + 0x238) = fVar6;
            *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
            if ((1e-05 <= fVar6) || (NAN(fVar6))) {
              fVar6 = (float)(~-(uint)(fVar6 <= 1.99999) & (uint)1.99999 |
                             (uint)fVar6 & -(uint)(fVar6 <= 1.99999));
            }
            else {
              fVar6 = 1e-05;
            }
            *(float *)(param_1 + 0x238) = fVar6;
            fVar6 = **(float **)(param_1 + 0x20c);
            *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
            lVar5 = (longdouble)_fmod((double)(fVar6 + fVar6 + 10.0),0,0x40100000);
            fVar6 = (float)lVar5;
            if ((1.0 <= fVar6) || (*(float *)(param_1 + 0x23c) <= 3.0)) {
              if ((fVar6 <= 3.0) || (1.0 <= *(float *)(param_1 + 0x23c))) {
                *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + fVar6 * 0.01;
              }
              else {
                *(float *)(param_1 + 0x23c) =
                     (*(float *)(param_1 + 0x23c) + 4.0) * 0.99 + fVar6 * 0.01;
              }
            }
            else {
              *(float *)(param_1 + 0x23c) =
                   *(float *)(param_1 + 0x23c) * 0.99 + (fVar6 + 4.0) * 0.01;
            }
            lVar5 = (longdouble)_fmod((double)*(float *)(param_1 + 0x23c),0,0x40100000);
            fVar6 = (float)lVar5;
            *(float *)(param_1 + 0x23c) = fVar6;
            if (fVar6 < 1.0) {
              *(float *)(param_1 + 0x240) = 1.0 - fVar6;
              *(float *)(param_1 + 0x248) = fVar6;
              *(undefined4 *)(param_1 + 0x244) = 0;
              *(undefined4 *)(param_1 + 0x24c) = 0;
            }
            else if (2.0 <= fVar6) {
              if (3.0 <= fVar6) {
                *(float *)(param_1 + 0x240) = fVar6 - 3.0;
                *(undefined4 *)(param_1 + 0x248) = 0;
                *(undefined4 *)(param_1 + 0x244) = 0;
                *(float *)(param_1 + 0x24c) = 4.0 - *(float *)(param_1 + 0x23c);
              }
              else {
                *(undefined4 *)(param_1 + 0x240) = 0;
                *(undefined4 *)(param_1 + 0x248) = 0;
                *(float *)(param_1 + 0x244) = 3.0 - *(float *)(param_1 + 0x23c);
                *(float *)(param_1 + 0x24c) = fVar6 - 2.0;
              }
            }
            else {
              *(undefined4 *)(param_1 + 0x240) = 0;
              *(float *)(param_1 + 0x248) = 2.0 - *(float *)(param_1 + 0x23c);
              *(float *)(param_1 + 0x244) = fVar6 - 1.0;
              *(undefined4 *)(param_1 + 0x24c) = 0;
            }
          }
          *(float *)(param_1 + 0x234) = *(float *)(param_1 + 0x234) + *(float *)(param_1 + 0x228);
          fVar6 = **(float **)(param_1 + 0x210);
          *(float **)(param_1 + 0x210) = *(float **)(param_1 + 0x210) + 1;
          fVar1 = **(float **)(param_1 + 0x214);
          *(float **)(param_1 + 0x214) = *(float **)(param_1 + 0x214) + 1;
          dVar11 = (double)(fVar6 - *(float *)(param_1 + 0x2c0));
          *(float *)(param_1 + 0x2c0) =
               (float)((double)*(float *)(param_1 + 0x2c0) + dVar11 * 0.0003);
          dVar13 = (double)(fVar1 - *(float *)(param_1 + 0x2c4));
          *(float *)(param_1 + 0x2c4) =
               (float)((double)*(float *)(param_1 + 0x2c4) + dVar13 * 0.0003);
          dVar7 = 1.0 - (double)*(float *)(param_1 + 0x230);
          dVar12 = (dVar11 - *(double *)(param_1 + 600)) - dVar7 * *(double *)(param_1 + 0x268);
          *(double *)(param_1 + 0x260) = dVar12;
          dVar14 = (dVar13 - *(double *)(param_1 + 0x288)) - dVar7 * *(double *)(param_1 + 0x298);
          *(double *)(param_1 + 0x290) = dVar14;
          dVar7 = *(double *)(param_1 + 0x250);
          *(double *)(param_1 + 0x268) = dVar7 * dVar12 + *(double *)(param_1 + 0x268);
          dVar13 = dVar7 * dVar14 + *(double *)(param_1 + 0x298);
          *(double *)(param_1 + 0x298) = dVar13;
          dVar11 = dVar7 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 600);
          *(double *)(param_1 + 600) = dVar11;
          dVar7 = dVar7 * dVar13 + *(double *)(param_1 + 0x288);
          *(double *)(param_1 + 0x288) = dVar7;
          fVar6 = (float)((dVar11 + dVar12) * (double)*(float *)(param_1 + 0x24c) +
                          dVar11 * (double)*(float *)(param_1 + 0x240) +
                          dVar12 * (double)*(float *)(param_1 + 0x244) +
                         (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x268));
          *(float *)(param_1 + 0x2b8) = fVar6;
          *(float *)(param_1 + 700) =
               (float)((double)*(float *)(param_1 + 0x24c) * (dVar7 + dVar14) +
                       dVar7 * (double)*(float *)(param_1 + 0x240) +
                       dVar14 * (double)*(float *)(param_1 + 0x244) +
                      (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x298));
          pfVar3 = *(float **)(param_1 + 0x218);
          *pfVar3 = *pfVar3 + fVar6 * *(float *)(param_1 + 0x234) *
                              (2.0 - *(float *)(param_1 + 0x238));
          *(float **)(param_1 + 0x218) = pfVar3 + 1;
          pfVar3 = *(float **)(param_1 + 0x21c);
          *pfVar3 = *(float *)(param_1 + 700) * *(float *)(param_1 + 0x234) *
                    *(float *)(param_1 + 0x238) + *pfVar3;
          *(float **)(param_1 + 0x21c) = pfVar3 + 1;
          iVar4 = iVar4 + 1;
        } while (param_2 != iVar4);
      }
    }
    else if (*(char *)(*(int *)(param_1 + 0x10) + 0x27) == '\0') {
      if (0 < param_2) {
        iVar4 = 0;
        do {
          uVar10 = *(uint *)(param_1 + 0x1e4);
          *(uint *)(param_1 + 0x1e4) = uVar10 + 1;
          if ((uVar10 & 7) == 0) {
            fVar6 = **(float **)(param_1 + 0x1fc);
            *(float **)(param_1 + 0x1fc) = *(float **)(param_1 + 0x1fc) + 1;
            if (0.0 <= fVar6) {
              if (fVar6 <= 1.0) {
                dVar7 = (double)fVar6;
              }
              else {
                dVar7 = 1.0;
              }
            }
            else {
              dVar7 = 0.0;
            }
            dVar7 = dVar7 * 10.0 - 5.0;
            dVar7 = dVar7 * dVar7 * dVar7 * 0.00082312050791077 + dVar7 * dVar7 * 0.0157739370387826
                    + dVar7 * 0.174502948013078 + 1.0;
            fVar6 = (float)(dVar7 * dVar7 * dVar7 * dVar7 * 0.03125) * *(float *)(param_1 + 0x220) *
                    0.1 + *(float *)(param_1 + 0x22c) * 0.9;
            *(float *)(param_1 + 0x22c) = fVar6;
            dVar7 = (double)fVar6;
            *(double *)(param_1 + 0x250) = dVar7 * (2.0 - dVar7);
            fVar6 = **(float **)(param_1 + 0x200) * 0.9;
            *(float *)(param_1 + 0x230) = fVar6;
            *(float **)(param_1 + 0x200) = *(float **)(param_1 + 0x200) + 1;
            if (0.0 <= fVar6) {
              uVar10 = ~-(uint)(fVar6 <= 0.9) & (uint)0.9 | (uint)fVar6 & -(uint)(fVar6 <= 0.9);
            }
            else {
              uVar10 = 0;
            }
            *(uint *)(param_1 + 0x230) = uVar10;
            *(float *)(param_1 + 0x230) =
                 *(float *)(param_1 + 0x230) * (2.0 - *(float *)(param_1 + 0x230));
            fVar6 = **(float **)(param_1 + 0x204);
            *(float *)(param_1 + 0x224) = fVar6;
            *(float **)(param_1 + 0x204) = *(float **)(param_1 + 0x204) + 1;
            *(float *)(param_1 + 0x228) = (fVar6 - *(float *)(param_1 + 0x234)) * 0.125;
            fVar6 = *(float *)(param_1 + 0x238) * 0.75 +
                    (**(float **)(param_1 + 0x208) + 1.0) * 0.25;
            *(float *)(param_1 + 0x238) = fVar6;
            *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
            if ((1e-05 <= fVar6) || (NAN(fVar6))) {
              fVar6 = (float)(~-(uint)(fVar6 <= 1.99999) & (uint)1.99999 |
                             (uint)fVar6 & -(uint)(fVar6 <= 1.99999));
            }
            else {
              fVar6 = 1e-05;
            }
            *(float *)(param_1 + 0x238) = fVar6;
            fVar6 = **(float **)(param_1 + 0x20c);
            *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
            lVar5 = (longdouble)_fmod((double)(fVar6 + fVar6 + 10.0),0,0x40100000);
            fVar6 = (float)lVar5;
            if ((1.0 <= fVar6) || (*(float *)(param_1 + 0x23c) <= 3.0)) {
              if ((fVar6 <= 3.0) || (1.0 <= *(float *)(param_1 + 0x23c))) {
                *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + fVar6 * 0.01;
              }
              else {
                *(float *)(param_1 + 0x23c) =
                     (*(float *)(param_1 + 0x23c) + 4.0) * 0.99 + fVar6 * 0.01;
              }
            }
            else {
              *(float *)(param_1 + 0x23c) =
                   *(float *)(param_1 + 0x23c) * 0.99 + (fVar6 + 4.0) * 0.01;
            }
            lVar5 = (longdouble)_fmod((double)*(float *)(param_1 + 0x23c),0,0x40100000);
            fVar6 = (float)lVar5;
            *(float *)(param_1 + 0x23c) = fVar6;
            if (fVar6 < 1.0) {
              *(float *)(param_1 + 0x240) = 1.0 - fVar6;
              *(float *)(param_1 + 0x248) = fVar6;
              *(undefined4 *)(param_1 + 0x244) = 0;
              *(undefined4 *)(param_1 + 0x24c) = 0;
            }
            else if (2.0 <= fVar6) {
              if (3.0 <= fVar6) {
                *(float *)(param_1 + 0x240) = fVar6 - 3.0;
                *(undefined4 *)(param_1 + 0x248) = 0;
                *(undefined4 *)(param_1 + 0x244) = 0;
                *(float *)(param_1 + 0x24c) = 4.0 - *(float *)(param_1 + 0x23c);
              }
              else {
                *(undefined4 *)(param_1 + 0x240) = 0;
                *(undefined4 *)(param_1 + 0x248) = 0;
                *(float *)(param_1 + 0x244) = 3.0 - *(float *)(param_1 + 0x23c);
                *(float *)(param_1 + 0x24c) = fVar6 - 2.0;
              }
            }
            else {
              *(undefined4 *)(param_1 + 0x240) = 0;
              *(float *)(param_1 + 0x248) = 2.0 - *(float *)(param_1 + 0x23c);
              *(float *)(param_1 + 0x244) = fVar6 - 1.0;
              *(undefined4 *)(param_1 + 0x24c) = 0;
            }
          }
          *(float *)(param_1 + 0x234) = *(float *)(param_1 + 0x234) + *(float *)(param_1 + 0x228);
          fVar6 = **(float **)(param_1 + 0x210);
          *(float **)(param_1 + 0x210) = *(float **)(param_1 + 0x210) + 1;
          dVar7 = (double)(fVar6 - *(float *)(param_1 + 0x2c0));
          *(float *)(param_1 + 0x2c0) =
               (float)((double)*(float *)(param_1 + 0x2c0) + dVar7 * 0.0003);
          dVar11 = (dVar7 - *(double *)(param_1 + 600)) -
                   (1.0 - (double)*(float *)(param_1 + 0x230)) * *(double *)(param_1 + 0x268);
          *(double *)(param_1 + 0x260) = dVar11;
          dVar7 = dVar11 * *(double *)(param_1 + 0x250) + *(double *)(param_1 + 0x268);
          *(double *)(param_1 + 0x268) = dVar7;
          dVar7 = dVar7 * *(double *)(param_1 + 0x250) + *(double *)(param_1 + 600);
          *(double *)(param_1 + 600) = dVar7;
          dVar7 = ((double)(float)((double)*(float *)(param_1 + 0x24c) * (dVar7 + dVar11) +
                                   dVar7 * (double)*(float *)(param_1 + 0x240) +
                                   dVar11 * (double)*(float *)(param_1 + 0x244) +
                                  (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x268)
                                  ) - *(double *)(param_1 + 0x270)) - *(double *)(param_1 + 0x280);
          *(double *)(param_1 + 0x278) = dVar7;
          dVar7 = dVar7 * *(double *)(param_1 + 0x250) + *(double *)(param_1 + 0x280);
          *(double *)(param_1 + 0x280) = dVar7;
          dVar11 = dVar7 * *(double *)(param_1 + 0x250) + *(double *)(param_1 + 0x270);
          *(double *)(param_1 + 0x270) = dVar11;
          dVar7 = -1.0;
          if (-1.0 <= dVar11) {
            dVar7 = (double)(~-(ulonglong)(dVar11 <= 1.0) & (ulonglong)1.0 |
                            (ulonglong)dVar11 & -(ulonglong)(dVar11 <= 1.0));
          }
          *(double *)(param_1 + 0x270) = dVar7;
          fVar6 = (float)((double)*(float *)(param_1 + 0x24c) *
                          (*(double *)(param_1 + 0x270) + *(double *)(param_1 + 0x278)) +
                          *(double *)(param_1 + 0x270) * (double)*(float *)(param_1 + 0x240) +
                          *(double *)(param_1 + 0x278) * (double)*(float *)(param_1 + 0x244) +
                         (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x280));
          *(float *)(param_1 + 0x2b8) = fVar6;
          pfVar3 = *(float **)(param_1 + 0x218);
          *pfVar3 = *pfVar3 + fVar6 * *(float *)(param_1 + 0x234) *
                              (2.0 - *(float *)(param_1 + 0x238));
          *(float **)(param_1 + 0x218) = pfVar3 + 1;
          pfVar3 = *(float **)(param_1 + 0x21c);
          *pfVar3 = *(float *)(param_1 + 0x2b8) * *(float *)(param_1 + 0x234) *
                    *(float *)(param_1 + 0x238) + *pfVar3;
          *(float **)(param_1 + 0x21c) = pfVar3 + 1;
          iVar4 = iVar4 + 1;
        } while (param_2 != iVar4);
      }
    }
    else if (0 < param_2) {
      iVar4 = 0;
      do {
        uVar10 = *(uint *)(param_1 + 0x1e4);
        *(uint *)(param_1 + 0x1e4) = uVar10 + 1;
        if ((uVar10 & 7) == 0) {
          fVar6 = **(float **)(param_1 + 0x1fc);
          *(float **)(param_1 + 0x1fc) = *(float **)(param_1 + 0x1fc) + 1;
          if (0.0 <= fVar6) {
            if (fVar6 <= 1.0) {
              dVar7 = (double)fVar6;
            }
            else {
              dVar7 = 1.0;
            }
          }
          else {
            dVar7 = 0.0;
          }
          dVar7 = dVar7 * 10.0 - 5.0;
          dVar7 = dVar7 * dVar7 * dVar7 * 0.00082312050791077 + dVar7 * dVar7 * 0.0157739370387826 +
                  dVar7 * 0.174502948013078 + 1.0;
          fVar6 = (float)(dVar7 * dVar7 * dVar7 * dVar7 * 0.03125) * *(float *)(param_1 + 0x220) *
                  0.1 + *(float *)(param_1 + 0x22c) * 0.9;
          *(float *)(param_1 + 0x22c) = fVar6;
          dVar7 = (double)fVar6;
          *(double *)(param_1 + 0x250) = dVar7 * (2.0 - dVar7);
          fVar6 = **(float **)(param_1 + 0x200) * 0.9;
          *(float *)(param_1 + 0x230) = fVar6;
          *(float **)(param_1 + 0x200) = *(float **)(param_1 + 0x200) + 1;
          if (0.0 <= fVar6) {
            uVar10 = ~-(uint)(fVar6 <= 0.9) & (uint)0.9 | (uint)fVar6 & -(uint)(fVar6 <= 0.9);
          }
          else {
            uVar10 = 0;
          }
          *(uint *)(param_1 + 0x230) = uVar10;
          *(float *)(param_1 + 0x230) =
               *(float *)(param_1 + 0x230) * (2.0 - *(float *)(param_1 + 0x230));
          fVar6 = **(float **)(param_1 + 0x204);
          *(float *)(param_1 + 0x224) = fVar6;
          *(float **)(param_1 + 0x204) = *(float **)(param_1 + 0x204) + 1;
          *(float *)(param_1 + 0x228) = (fVar6 - *(float *)(param_1 + 0x234)) * 0.125;
          fVar6 = *(float *)(param_1 + 0x238) * 0.75 + (**(float **)(param_1 + 0x208) + 1.0) * 0.25;
          *(float *)(param_1 + 0x238) = fVar6;
          *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
          if ((1e-05 <= fVar6) || (NAN(fVar6))) {
            fVar6 = (float)(~-(uint)(fVar6 <= 1.99999) & (uint)1.99999 |
                           (uint)fVar6 & -(uint)(fVar6 <= 1.99999));
          }
          else {
            fVar6 = 1e-05;
          }
          *(float *)(param_1 + 0x238) = fVar6;
          fVar6 = **(float **)(param_1 + 0x20c);
          *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
          lVar5 = (longdouble)_fmod((double)(fVar6 + fVar6 + 10.0),0,0x40100000);
          fVar6 = (float)lVar5;
          if ((1.0 <= fVar6) || (*(float *)(param_1 + 0x23c) <= 3.0)) {
            if ((fVar6 <= 3.0) || (1.0 <= *(float *)(param_1 + 0x23c))) {
              *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + fVar6 * 0.01;
            }
            else {
              *(float *)(param_1 + 0x23c) =
                   (*(float *)(param_1 + 0x23c) + 4.0) * 0.99 + fVar6 * 0.01;
            }
          }
          else {
            *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x23c) * 0.99 + (fVar6 + 4.0) * 0.01;
          }
          lVar5 = (longdouble)_fmod((double)*(float *)(param_1 + 0x23c),0,0x40100000);
          fVar6 = (float)lVar5;
          *(float *)(param_1 + 0x23c) = fVar6;
          if (fVar6 < 1.0) {
            *(float *)(param_1 + 0x240) = 1.0 - fVar6;
            *(float *)(param_1 + 0x248) = fVar6;
            *(undefined4 *)(param_1 + 0x244) = 0;
            *(undefined4 *)(param_1 + 0x24c) = 0;
          }
          else if (2.0 <= fVar6) {
            if (3.0 <= fVar6) {
              *(float *)(param_1 + 0x240) = fVar6 - 3.0;
              *(undefined4 *)(param_1 + 0x248) = 0;
              *(undefined4 *)(param_1 + 0x244) = 0;
              *(float *)(param_1 + 0x24c) = 4.0 - *(float *)(param_1 + 0x23c);
            }
            else {
              *(undefined4 *)(param_1 + 0x240) = 0;
              *(undefined4 *)(param_1 + 0x248) = 0;
              *(float *)(param_1 + 0x244) = 3.0 - *(float *)(param_1 + 0x23c);
              *(float *)(param_1 + 0x24c) = fVar6 - 2.0;
            }
          }
          else {
            *(undefined4 *)(param_1 + 0x240) = 0;
            *(float *)(param_1 + 0x248) = 2.0 - *(float *)(param_1 + 0x23c);
            *(float *)(param_1 + 0x244) = fVar6 - 1.0;
            *(undefined4 *)(param_1 + 0x24c) = 0;
          }
        }
        *(float *)(param_1 + 0x234) = *(float *)(param_1 + 0x234) + *(float *)(param_1 + 0x228);
        fVar6 = **(float **)(param_1 + 0x210);
        *(float **)(param_1 + 0x210) = *(float **)(param_1 + 0x210) + 1;
        fVar1 = **(float **)(param_1 + 0x214);
        *(float **)(param_1 + 0x214) = *(float **)(param_1 + 0x214) + 1;
        dVar13 = (double)(fVar6 - *(float *)(param_1 + 0x2c0));
        *(float *)(param_1 + 0x2c0) = (float)((double)*(float *)(param_1 + 0x2c0) + dVar13 * 0.0003)
        ;
        dVar11 = (double)(fVar1 - *(float *)(param_1 + 0x2c4));
        *(float *)(param_1 + 0x2c4) = (float)((double)*(float *)(param_1 + 0x2c4) + dVar11 * 0.0003)
        ;
        dVar7 = 1.0 - (double)*(float *)(param_1 + 0x230);
        dVar14 = (dVar13 - *(double *)(param_1 + 600)) - dVar7 * *(double *)(param_1 + 0x268);
        *(double *)(param_1 + 0x260) = dVar14;
        dVar12 = (dVar11 - *(double *)(param_1 + 0x288)) - dVar7 * *(double *)(param_1 + 0x298);
        *(double *)(param_1 + 0x290) = dVar12;
        dVar7 = *(double *)(param_1 + 0x250);
        *(double *)(param_1 + 0x268) = dVar7 * dVar14 + *(double *)(param_1 + 0x268);
        *(double *)(param_1 + 0x298) = dVar7 * dVar12 + *(double *)(param_1 + 0x298);
        dVar13 = dVar7 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 600);
        *(double *)(param_1 + 600) = dVar13;
        dVar11 = dVar7 * *(double *)(param_1 + 0x298) + *(double *)(param_1 + 0x288);
        *(double *)(param_1 + 0x288) = dVar11;
        *(double *)(param_1 + 0x278) =
             ((double)(float)((double)*(float *)(param_1 + 0x24c) * (dVar13 + dVar14) +
                              (double)*(float *)(param_1 + 0x240) * dVar13 +
                              (double)*(float *)(param_1 + 0x244) * dVar14 +
                             (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x268)) -
             *(double *)(param_1 + 0x270)) - *(double *)(param_1 + 0x280);
        dVar11 = ((double)(float)((dVar11 + dVar12) * (double)*(float *)(param_1 + 0x24c) +
                                  dVar11 * (double)*(float *)(param_1 + 0x240) +
                                  dVar12 * (double)*(float *)(param_1 + 0x244) +
                                 (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x298))
                 - *(double *)(param_1 + 0x2a0)) - *(double *)(param_1 + 0x2b0);
        *(double *)(param_1 + 0x2a8) = dVar11;
        *(double *)(param_1 + 0x280) =
             dVar7 * *(double *)(param_1 + 0x278) + *(double *)(param_1 + 0x280);
        *(double *)(param_1 + 0x2b0) = dVar7 * dVar11 + *(double *)(param_1 + 0x2b0);
        dVar11 = dVar7 * *(double *)(param_1 + 0x280) + *(double *)(param_1 + 0x270);
        *(double *)(param_1 + 0x270) = dVar11;
        *(double *)(param_1 + 0x2a0) =
             dVar7 * *(double *)(param_1 + 0x2b0) + *(double *)(param_1 + 0x2a0);
        dVar7 = -1.0;
        if (-1.0 <= dVar11) {
          dVar7 = (double)(~-(ulonglong)(dVar11 <= 1.0) & (ulonglong)1.0 |
                          (ulonglong)dVar11 & -(ulonglong)(dVar11 <= 1.0));
        }
        *(double *)(param_1 + 0x270) = dVar7;
        dVar7 = *(double *)(param_1 + 0x2a0);
        uVar8 = 0;
        uVar9 = 0xbff00000;
        if (-1.0 <= dVar7) {
          uVar8 = 0;
          uVar9 = 0x3ff00000;
          if (dVar7 <= 1.0) {
            uVar8 = SUB84(dVar7,0);
            uVar9 = (undefined4)((ulonglong)dVar7 >> 0x20);
          }
        }
        *(ulonglong *)(param_1 + 0x2a0) = CONCAT44(uVar9,uVar8);
        fVar6 = (float)((*(double *)(param_1 + 0x270) + *(double *)(param_1 + 0x278)) *
                        (double)*(float *)(param_1 + 0x24c) +
                        *(double *)(param_1 + 0x270) * (double)*(float *)(param_1 + 0x240) +
                        *(double *)(param_1 + 0x278) * (double)*(float *)(param_1 + 0x244) +
                       (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x280));
        *(float *)(param_1 + 0x2b8) = fVar6;
        *(float *)(param_1 + 700) =
             (float)((double)*(float *)(param_1 + 0x24c) *
                     (*(double *)(param_1 + 0x2a0) + *(double *)(param_1 + 0x2a8)) +
                     *(double *)(param_1 + 0x2a0) * (double)*(float *)(param_1 + 0x240) +
                     *(double *)(param_1 + 0x2a8) * (double)*(float *)(param_1 + 0x244) +
                    (double)*(float *)(param_1 + 0x248) * *(double *)(param_1 + 0x2b0));
        pfVar3 = *(float **)(param_1 + 0x218);
        *pfVar3 = *pfVar3 + fVar6 * *(float *)(param_1 + 0x234) *
                            (2.0 - *(float *)(param_1 + 0x238));
        *(float **)(param_1 + 0x218) = pfVar3 + 1;
        pfVar3 = *(float **)(param_1 + 0x21c);
        *pfVar3 = *(float *)(param_1 + 700) * *(float *)(param_1 + 0x234) *
                  *(float *)(param_1 + 0x238) + *pfVar3;
        *(float **)(param_1 + 0x21c) = pfVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (param_2 != iVar4);
    }
                    /* WARNING: Could not recover jumptable at 0x000765a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
    return;
  }
  return;
}

