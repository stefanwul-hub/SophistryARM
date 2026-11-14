/* 000795d2 FUN_000795d2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000795d2(int *param_1,int param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  uint uVar2;
  double dVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  float *local_24;
  int local_20;
  
  if (((char)param_1[0x57] != '\0') && (param_1[0x79] = 0, 0 < param_2)) {
    local_24 = param_3;
    local_20 = 0;
    pfVar1 = (float *)(param_1 + 0x10c3);
    do {
      uVar2 = param_1[0x79];
      param_1[0x79] = uVar2 + 1;
      if ((uVar2 & 7) == 0) {
        fVar5 = *(float *)param_1[0x10bf];
        param_1[0x10c3] = (int)fVar5;
        param_1[0x10bf] = (int)((float *)param_1[0x10bf] + 1);
        fVar7 = 1e-06;
        fVar6 = fVar7;
        if (1e-06 <= fVar5) {
          fVar6 = (float)(~-(uint)(fVar5 <= 1.0) & (uint)1.0 | (uint)fVar5 & -(uint)(fVar5 <= 1.0));
        }
        *pfVar1 = fVar6;
        fVar5 = ((float)param_1[0x10c3] + (float)param_1[0x10c3]) - 1.0;
        fVar5 = fVar5 * fVar5 * fVar5 * 0.05362607 + fVar5 * fVar5 * 0.24807328 + fVar5 * 0.69521874
                + 1.0;
        param_1[0x10c3] = (int)(fVar5 * fVar5 * fVar5 * fVar5 * 0.0625 * (float)param_1[0x10c9]);
        fVar5 = *pfVar1;
        if ((0.0004 <= fVar5) || (NAN(fVar5))) {
          fVar6 = 1.0;
          if (fVar5 <= 1.0) {
            fVar6 = fVar5;
          }
        }
        else {
          fVar6 = 0.0004;
        }
        *pfVar1 = fVar6;
        fVar5 = *(float *)param_1[0x10c0];
        param_1[0x10c5] = (int)fVar5;
        param_1[0x10c0] = (int)((float *)param_1[0x10c0] + 1);
        if (1e-06 <= fVar5) {
          fVar7 = (float)(~-(uint)(fVar5 <= 0.96) & (uint)0.96 |
                         (uint)fVar5 & -(uint)(fVar5 <= 0.96));
        }
        param_1[0x10c5] = (int)fVar7;
        fVar7 = *(float *)param_1[0x10c1] * 8.0;
        param_1[0x10cc] = (int)fVar7;
        param_1[0x10c1] = (int)((float *)param_1[0x10c1] + 1);
        param_1[0x10cd] = (int)((fVar7 - (float)param_1[0x10c6]) * 0.125);
        fVar7 = (float)param_1[0x10c7] * 0.75 + (*(float *)param_1[0x10c2] + 1.0) * 0.25;
        param_1[0x10c7] = (int)fVar7;
        param_1[0x10c2] = (int)((float *)param_1[0x10c2] + 1);
        if ((1e-05 <= fVar7) || (NAN(fVar7))) {
          fVar7 = (float)(~-(uint)(fVar7 <= 1.99999) & (uint)1.99999 |
                         (uint)fVar7 & -(uint)(fVar7 <= 1.99999));
        }
        else {
          fVar7 = 1e-05;
        }
        param_1[0x10c7] = (int)fVar7;
        dVar8 = (double)(float)param_1[0x10c3];
        dVar8 = (dVar8 * 3.6 + dVar8 * dVar8 * -1.6) - 1.0;
        *(double *)(param_1 + 0xb2) = dVar8;
        *(double *)(param_1 + 0xb4) = (dVar8 + 1.0) * 0.5;
        lVar4 = (longdouble)_log10((double)((float)param_1[0x10c3] * (float)param_1[0x10c3]));
        *(double *)(param_1 + 0xb6) = 0.75 - (double)lVar4;
        dVar8 = (0.75 - (double)lVar4) * (double)(float)param_1[0x10c5];
        *(double *)(param_1 + 0xb8) = dVar8;
      }
      else {
        dVar8 = *(double *)(param_1 + 0xb8);
      }
      param_1[0x10c6] = (int)((float)param_1[0x10c6] + (float)param_1[0x10cd]);
      fVar7 = *local_24;
      local_24 = local_24 + 1;
      fVar5 = *param_4;
      param_4 = param_4 + 1;
      dVar11 = ((double)fVar7 * 0.125 - dVar8 * *(double *)(param_1 + 0x98)) -
               (double)(float)param_1[0x10bd];
      param_1[0x10bd] = (int)(float)((double)(float)param_1[0x10bd] + dVar11 * 0.0003);
      dVar10 = ((double)fVar5 * 0.125 - dVar8 * *(double *)(param_1 + 0xa8)) -
               (double)(float)param_1[0x10be];
      param_1[0x10be] = (int)(float)((double)(float)param_1[0x10be] + dVar10 * 0.0003);
      dVar8 = *(double *)(param_1 + 0xb2);
      dVar9 = (dVar11 + *(double *)(param_1 + 0x9a)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0x92);
      *(double *)(param_1 + 0x92) = dVar9;
      dVar3 = (dVar10 + *(double *)(param_1 + 0xaa)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0xa2);
      *(double *)(param_1 + 0xa2) = dVar3;
      dVar9 = (dVar9 + *(double *)(param_1 + 0x9c)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0x94);
      *(double *)(param_1 + 0x94) = dVar9;
      dVar3 = (dVar3 + *(double *)(param_1 + 0xac)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0xa4);
      *(double *)(param_1 + 0xa4) = dVar3;
      dVar9 = (dVar9 + *(double *)(param_1 + 0x9e)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0x96);
      *(double *)(param_1 + 0x96) = dVar9;
      dVar3 = (dVar3 + *(double *)(param_1 + 0xae)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0xa6);
      *(double *)(param_1 + 0xa6) = dVar3;
      dVar9 = (dVar9 + *(double *)(param_1 + 0xa0)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0x98);
      *(double *)(param_1 + 0x98) = dVar9;
      dVar8 = (dVar3 + *(double *)(param_1 + 0xb0)) * *(double *)(param_1 + 0xb4) -
              dVar8 * *(double *)(param_1 + 0xa8);
      *(double *)(param_1 + 0xa8) = dVar8;
      *(double *)(param_1 + 0x98) = dVar9 + dVar9 * dVar9 * dVar9 * -0.166666;
      *(double *)(param_1 + 0xa8) = dVar8 + dVar8 * dVar8 * dVar8 * -0.166666;
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x80,
                 (float)((double)(float)param_1[0x10c6] * *(double *)(param_1 + 0x98) *
                        (2.0 - (double)(float)param_1[0x10c7])));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x81,
                 (float)((double)(float)param_1[0x10c6] * *(double *)(param_1 + 0xa8) *
                        (double)(float)param_1[0x10c7]));
      *(double *)(param_1 + 0x9a) = dVar11;
      *(double *)(param_1 + 0xaa) = dVar10;
      *(undefined8 *)(param_1 + 0x9c) = *(undefined8 *)(param_1 + 0x92);
      *(undefined8 *)(param_1 + 0xac) = *(undefined8 *)(param_1 + 0xa2);
      *(undefined8 *)(param_1 + 0x9e) = *(undefined8 *)(param_1 + 0x94);
      *(undefined8 *)(param_1 + 0xae) = *(undefined8 *)(param_1 + 0xa4);
      *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(param_1 + 0x96);
      *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0xa6);
      local_20 = local_20 + 1;
    } while (param_2 != local_20);
  }
  return;
}

