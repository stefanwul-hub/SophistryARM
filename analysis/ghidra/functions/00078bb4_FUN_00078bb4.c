/* 00078bb4 FUN_00078bb4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00078bb4(int *param_1,int param_2,float *param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  int local_20;
  
  if ((char)param_1[0x57] != '\0') {
    param_1[0x10ce] = (int)0.5;
    param_1[0x79] = 0;
    if (0 < param_2) {
      local_20 = 0;
      pfVar1 = (float *)(param_1 + 0x10c3);
      do {
        uVar4 = param_1[0x79];
        param_1[0x79] = uVar4 + 1;
        if ((uVar4 & 7) == 0) {
          fVar5 = *(float *)param_1[0x10bf];
          param_1[0x10c3] = (int)fVar5;
          param_1[0x10bf] = (int)((float *)param_1[0x10bf] + 1);
          fVar6 = 1e-06;
          fVar3 = fVar6;
          if (1e-06 <= fVar5) {
            fVar3 = (float)(~-(uint)(fVar5 <= 1.0) & (uint)1.0 | (uint)fVar5 & -(uint)(fVar5 <= 1.0)
                           );
          }
          *pfVar1 = fVar3;
          fVar5 = (float)param_1[0x10c3] * 10.0 - 5.0;
          fVar5 = fVar5 * fVar5 * fVar5 * 0.0008231205 + fVar5 * fVar5 * 0.015773937 +
                  fVar5 * 0.17450295 + 1.0;
          param_1[0x10c3] = (int)(fVar5 * fVar5 * fVar5 * fVar5 * 0.03125);
          fVar5 = *(float *)param_1[0x10c0];
          param_1[0x10c5] = (int)fVar5;
          param_1[0x10c0] = (int)((float *)param_1[0x10c0] + 1);
          if (1e-06 <= fVar5) {
            fVar6 = (float)(~-(uint)(fVar5 <= 1.0) & (uint)1.0 | (uint)fVar5 & -(uint)(fVar5 <= 1.0)
                           );
          }
          param_1[0x10c5] = (int)fVar6;
          param_1[0x10c3] = (int)((float)param_1[0x10c3] * (float)param_1[0x10c9]);
          fVar6 = *pfVar1;
          if ((0.002 <= fVar6) || (NAN(fVar6))) {
            fVar5 = 1.0;
            if (fVar6 <= 1.0) {
              fVar5 = fVar6;
            }
          }
          else {
            fVar5 = 0.002;
          }
          *pfVar1 = fVar5;
          for (fVar6 = (float)param_1[0x78] / (float)param_1[0x10c3] + 1.55; 2047.0 < fVar6;
              fVar6 = fVar6 * 0.5) {
          }
          param_1[0x10c8] = (int)(fVar6 - (float)(int)fVar6);
          uVar4 = param_1[0x10ba] - (int)fVar6;
          param_1[0x10bb] = uVar4 & 0x7ff;
          param_1[0x10bc] = uVar4 + 0xfff & 0x7ff;
          fVar6 = *(float *)param_1[0x10c1] * (float)param_1[0x10ce];
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
        }
        param_1[0x10c6] = (int)((float)param_1[0x10c6] + (float)param_1[0x10cd]);
        fVar6 = *param_3;
        param_3 = param_3 + 1;
        fVar6 = (((1.0 - (float)param_1[0x10c8]) * (float)param_1[param_1[0x10bb] + 0xba] +
                 (float)param_1[0x10c8] * (float)param_1[param_1[0x10bc] + 0xba]) *
                 (float)param_1[0x10c5] + fVar6) - (float)param_1[0x86];
        param_1[0x86] = (int)((float)param_1[0x86] + fVar6 * (float)param_1[0x10c3]);
        fVar6 = fVar6 - (float)param_1[0x87];
        param_1[0x87] = (int)((float)param_1[0x87] + fVar6 * (float)param_1[0x10c3]);
        (**(code **)(*param_1 + 0xcc))
                  (param_1,param_1 + 0x80,
                   fVar6 * (float)param_1[0x10c6] * (2.0 - (float)param_1[0x10c7]));
        (**(code **)(*param_1 + 0xcc))
                  (param_1,param_1 + 0x81,fVar6 * (float)param_1[0x10c6] * (float)param_1[0x10c7]);
        iVar2 = param_1[0x10ba];
        param_1[iVar2 + 0xba] = (int)(fVar6 / (fVar6 * fVar6 * 0.25 + 1.0));
        param_1[0x10bc] = param_1[0x10bc] + 1U & 0x7ff;
        param_1[0x10ba] = iVar2 + 1U & 0x7ff;
        param_1[0x10bb] = param_1[0x10bb] + 1U & 0x7ff;
        local_20 = local_20 + 1;
      } while (param_2 != local_20);
    }
  }
  return;
}

