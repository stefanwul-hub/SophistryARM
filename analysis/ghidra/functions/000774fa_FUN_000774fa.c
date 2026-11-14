/* 000774fa FUN_000774fa */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000774fa(int *param_1,int param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  float *local_24;
  int local_20;
  
  if ((char)param_1[0x57] != '\0') {
    param_1[0x10ce] = (int)0.5;
    param_1[0x79] = 0;
    if (0 < param_2) {
      local_24 = param_3;
      local_20 = 0;
      pfVar1 = (float *)(param_1 + 0x10c3);
      do {
        uVar6 = param_1[0x79];
        param_1[0x79] = uVar6 + 1;
        if ((uVar6 & 7) == 0) {
          fVar8 = *(float *)param_1[0x10bf];
          param_1[0x10c3] = (int)fVar8;
          param_1[0x10bf] = (int)((float *)param_1[0x10bf] + 1);
          fVar7 = 1e-06;
          fVar2 = fVar7;
          if (1e-06 <= fVar8) {
            fVar2 = (float)(~-(uint)(fVar8 <= 1.0) & (uint)1.0 | (uint)fVar8 & -(uint)(fVar8 <= 1.0)
                           );
          }
          *pfVar1 = fVar2;
          fVar8 = (float)param_1[0x10c3] * 10.0 - 5.0;
          fVar8 = fVar8 * fVar8 * fVar8 * 0.0008231205 + fVar8 * fVar8 * 0.015773937 +
                  fVar8 * 0.17450295 + 1.0;
          param_1[0x10c3] = (int)(fVar8 * fVar8 * fVar8 * fVar8 * 0.03125);
          fVar8 = *(float *)param_1[0x10c0];
          param_1[0x10c5] = (int)fVar8;
          param_1[0x10c0] = (int)((float *)param_1[0x10c0] + 1);
          if (1e-06 <= fVar8) {
            fVar7 = (float)(~-(uint)(fVar8 <= 1.0) & (uint)1.0 | (uint)fVar8 & -(uint)(fVar8 <= 1.0)
                           );
          }
          param_1[0x10c5] = (int)fVar7;
          param_1[0x10c3] = (int)((float)param_1[0x10c3] * (float)param_1[0x10c9]);
          fVar7 = *pfVar1;
          if ((0.002 <= fVar7) || (NAN(fVar7))) {
            fVar8 = 1.0;
            if (fVar7 <= 1.0) {
              fVar8 = fVar7;
            }
          }
          else {
            fVar8 = 0.002;
          }
          *pfVar1 = fVar8;
          for (fVar7 = (float)param_1[0x78] / (float)param_1[0x10c3] + 1.55; 2047.0 < fVar7;
              fVar7 = fVar7 * 0.5) {
          }
          param_1[0x10c8] = (int)(fVar7 - (float)(int)fVar7);
          uVar6 = param_1[0x10ba] - (int)fVar7;
          param_1[0x10bb] = uVar6 & 0x7ff;
          param_1[0x10bc] = uVar6 + 0xfff & 0x7ff;
          fVar7 = *(float *)param_1[0x10c1] * (float)param_1[0x10ce];
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
        }
        param_1[0x10c6] = (int)((float)param_1[0x10c6] + (float)param_1[0x10cd]);
        fVar7 = (float)param_1[0x10c8];
        fVar8 = *local_24;
        local_24 = local_24 + 1;
        fVar2 = (float)param_1[param_1[0x10bb] + 0x8ba];
        fVar3 = (float)param_1[param_1[0x10bc] + 0x8ba];
        fVar4 = *param_4;
        param_4 = param_4 + 1;
        fVar8 = (((1.0 - fVar7) * (float)param_1[param_1[0x10bb] + 0xba] +
                 fVar7 * (float)param_1[param_1[0x10bc] + 0xba]) * (float)param_1[0x10c5] + fVar8) -
                (float)param_1[0x86];
        param_1[0x86] = (int)((float)param_1[0x86] + fVar8 * (float)param_1[0x10c3]);
        fVar7 = (((1.0 - fVar7) * fVar2 + fVar7 * fVar3) * (float)param_1[0x10c5] + fVar4) -
                (float)param_1[0x8e];
        param_1[0x8e] = (int)((float)param_1[0x8e] + fVar7 * (float)param_1[0x10c3]);
        fVar8 = fVar8 - (float)param_1[0x87];
        param_1[0x87] = (int)((float)param_1[0x87] + fVar8 * (float)param_1[0x10c3]);
        fVar7 = fVar7 - (float)param_1[0x8f];
        param_1[0x8f] = (int)((float)param_1[0x8f] + fVar7 * (float)param_1[0x10c3]);
        (**(code **)(*param_1 + 0xcc))
                  (param_1,param_1 + 0x80,
                   fVar8 * (float)param_1[0x10c6] * (2.0 - (float)param_1[0x10c7]));
        (**(code **)(*param_1 + 0xcc))
                  (param_1,param_1 + 0x81,fVar7 * (float)param_1[0x10c6] * (float)param_1[0x10c7]);
        iVar5 = param_1[0x10ba];
        param_1[iVar5 + 0xba] = (int)(fVar8 / (fVar8 * fVar8 * 0.25 + 1.0));
        param_1[iVar5 + 0x8ba] = (int)(fVar7 / (fVar7 * fVar7 * 0.25 + 1.0));
        param_1[0x10bc] = param_1[0x10bc] + 1U & 0x7ff;
        param_1[0x10ba] = iVar5 + 1U & 0x7ff;
        param_1[0x10bb] = param_1[0x10bb] + 1U & 0x7ff;
        local_20 = local_20 + 1;
      } while (param_2 != local_20);
    }
  }
  return;
}

