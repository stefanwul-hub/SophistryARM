/* 00079c72 FUN_00079c72 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00079c72(int *param_1,int param_2,float *param_3)

{
  float *pfVar1;
  uint uVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  int local_20;
  
  if (((char)param_1[0x57] != '\0') && (param_1[0x79] = 0, 0 < param_2)) {
    local_20 = 0;
    pfVar1 = (float *)(param_1 + 0x10c3);
    do {
      uVar2 = param_1[0x79];
      param_1[0x79] = uVar2 + 1;
      if ((uVar2 & 7) == 0) {
        fVar4 = *(float *)param_1[0x10bf];
        param_1[0x10c3] = (int)fVar4;
        param_1[0x10bf] = (int)((float *)param_1[0x10bf] + 1);
        fVar6 = 1e-06;
        fVar5 = fVar6;
        if (1e-06 <= fVar4) {
          fVar5 = (float)(~-(uint)(fVar4 <= 1.0) & (uint)1.0 | (uint)fVar4 & -(uint)(fVar4 <= 1.0));
        }
        *pfVar1 = fVar5;
        fVar4 = ((float)param_1[0x10c3] + (float)param_1[0x10c3]) - 1.0;
        fVar4 = fVar4 * fVar4 * fVar4 * 0.05362607 + fVar4 * fVar4 * 0.24807328 + fVar4 * 0.69521874
                + 1.0;
        param_1[0x10c3] = (int)(fVar4 * fVar4 * fVar4 * fVar4 * 0.0625 * (float)param_1[0x10c9]);
        fVar4 = *pfVar1;
        if ((0.0004 <= fVar4) || (NAN(fVar4))) {
          fVar5 = 1.0;
          if (fVar4 <= 1.0) {
            fVar5 = fVar4;
          }
        }
        else {
          fVar5 = 0.0004;
        }
        *pfVar1 = fVar5;
        fVar4 = *(float *)param_1[0x10c0];
        param_1[0x10c5] = (int)fVar4;
        param_1[0x10c0] = (int)((float *)param_1[0x10c0] + 1);
        if (1e-06 <= fVar4) {
          fVar6 = (float)(~-(uint)(fVar4 <= 0.96) & (uint)0.96 |
                         (uint)fVar4 & -(uint)(fVar4 <= 0.96));
        }
        param_1[0x10c5] = (int)fVar6;
        fVar6 = *(float *)param_1[0x10c1] * 8.0;
        param_1[0x10cc] = (int)fVar6;
        param_1[0x10c1] = (int)((float *)param_1[0x10c1] + 1);
        param_1[0x10cd] = (int)((fVar6 - (float)param_1[0x10c6]) * 0.125);
        fVar6 = (float)param_1[0x10c7] * 0.75 + (*(float *)param_1[0x10c2] + 1.0) * 0.25;
        param_1[0x10c7] = (int)fVar6;
        param_1[0x10c2] = (int)((float *)param_1[0x10c2] + 1);
        if ((1e-05 <= fVar6) || (NAN(fVar6))) {
          fVar6 = (float)(~-(uint)(fVar6 <= 1.99999) & (uint)1.99999 |
                         (uint)fVar6 & -(uint)(fVar6 <= 1.99999));
        }
        else {
          fVar6 = 1e-05;
        }
        param_1[0x10c7] = (int)fVar6;
        dVar7 = (double)(float)param_1[0x10c3];
        dVar7 = (dVar7 * 3.6 + dVar7 * dVar7 * -1.6) - 1.0;
        *(double *)(param_1 + 0xb2) = dVar7;
        *(double *)(param_1 + 0xb4) = (dVar7 + 1.0) * 0.5;
        lVar3 = (longdouble)_log10((double)((float)param_1[0x10c3] * (float)param_1[0x10c3]));
        *(double *)(param_1 + 0xb6) = 0.75 - (double)lVar3;
        *(double *)(param_1 + 0xb8) = (0.75 - (double)lVar3) * (double)(float)param_1[0x10c5];
      }
      param_1[0x10c6] = (int)((float)param_1[0x10c6] + (float)param_1[0x10cd]);
      fVar6 = *param_3;
      param_3 = param_3 + 1;
      dVar9 = ((double)fVar6 * 0.125 - *(double *)(param_1 + 0xb8) * *(double *)(param_1 + 0x98)) -
              (double)(float)param_1[0x10bd];
      param_1[0x10bd] = (int)(float)((double)(float)param_1[0x10bd] + dVar9 * 0.0003);
      dVar7 = *(double *)(param_1 + 0xb2);
      dVar8 = (dVar9 + *(double *)(param_1 + 0x9a)) * *(double *)(param_1 + 0xb4) -
              dVar7 * *(double *)(param_1 + 0x92);
      *(double *)(param_1 + 0x92) = dVar8;
      dVar8 = (dVar8 + *(double *)(param_1 + 0x9c)) * *(double *)(param_1 + 0xb4) -
              dVar7 * *(double *)(param_1 + 0x94);
      *(double *)(param_1 + 0x94) = dVar8;
      dVar8 = (dVar8 + *(double *)(param_1 + 0x9e)) * *(double *)(param_1 + 0xb4) -
              dVar7 * *(double *)(param_1 + 0x96);
      *(double *)(param_1 + 0x96) = dVar8;
      dVar7 = (dVar8 + *(double *)(param_1 + 0xa0)) * *(double *)(param_1 + 0xb4) -
              dVar7 * *(double *)(param_1 + 0x98);
      *(double *)(param_1 + 0x98) = dVar7 + dVar7 * dVar7 * dVar7 * -0.166666;
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x80,
                 (float)((double)(float)param_1[0x10c6] * *(double *)(param_1 + 0x94) *
                        (2.0 - (double)(float)param_1[0x10c7])));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x81,
                 (float)((double)(float)param_1[0x10c6] * *(double *)(param_1 + 0x94) *
                        (double)(float)param_1[0x10c7]));
      *(double *)(param_1 + 0x9a) = dVar9;
      *(undefined8 *)(param_1 + 0x9c) = *(undefined8 *)(param_1 + 0x92);
      *(undefined8 *)(param_1 + 0x9e) = *(undefined8 *)(param_1 + 0x94);
      *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(param_1 + 0x96);
      local_20 = local_20 + 1;
    } while (local_20 != param_2);
  }
  return;
}

