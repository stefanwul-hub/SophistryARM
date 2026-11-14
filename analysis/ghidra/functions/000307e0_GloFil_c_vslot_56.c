/* 000307e0 GloFil_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void GloFil_c_vslot_56(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  if ((char)param_1[0x57] != '\0') {
    piVar1 = param_1 + 0x265;
    piVar2 = param_1 + 0x264;
    (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],piVar2,piVar1);
    (**(code **)(*(int *)param_1[4] + 0x38))((int *)param_1[4],param_1 + 0x266,param_1 + 0x267);
    iVar7 = *(int *)(param_1[0x49] + 0x158);
    if (iVar7 == 1) {
      if (0 < (int)param_2) {
        local_38 = 0;
        iVar7 = param_2 + 1;
        do {
          iVar5 = param_2 - local_38;
          uVar6 = local_38 & 7;
          local_38 = local_38 + 1;
          if (uVar6 == 0) {
            param_1[0x261] = (int)((float)param_1[0x261] + (float)param_1[0x262]);
            param_1[0x263] = param_1[0x263] + -1;
            iVar4 = 0;
            if (iVar7 + -2 < 7) {
              iVar4 = 7 - (iVar7 + -2);
            }
            iVar4 = iVar4 + param_1[0x4f];
            param_1[0x4f] = iVar4;
            if (8 < iVar4) {
              param_1[0x261] = (int)((float)param_1[0x261] - (float)param_1[0x262]);
              param_1[0x263] = param_1[0x263] + 1;
              param_1[0x4f] = iVar4 + -8;
            }
            if (param_1[0x263] < 1) {
              LFOSimp_c_vslot_57(param_1 + 0x78);
            }
            dVar9 = (double)((float)param_1[0x280] * (float)param_1[0x261]) * 3.0;
            dVar9 = dVar9 * dVar9 * dVar9 * 0.00082312050791077 + dVar9 * dVar9 * 0.0157739370387826
                    + dVar9 * 0.174502948013078 + 1.0;
            dVar9 = (double)(float)param_1[0x27f] * dVar9 * dVar9 * dVar9 * dVar9 *
                    (double)(float)param_1[0x52];
            *(double *)(param_1 + 0x268) = dVar9;
            if ((0.001 <= dVar9) || (NAN(dVar9))) {
              dVar9 = (double)(~-(ulonglong)(dVar9 <= 1.0) & (ulonglong)1.0 |
                              (ulonglong)dVar9 & -(ulonglong)(dVar9 <= 1.0));
            }
            else {
              dVar9 = 0.001;
            }
            *(double *)(param_1 + 0x268) = dVar9;
          }
          fVar3 = *(float *)param_1[0x266];
          param_1[0x266] = (int)((float *)param_1[0x266] + 1);
          dVar8 = (double)(float)param_1[0x27e];
          dVar9 = *(double *)(param_1 + 0x270);
          dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
          *(double *)(param_1 + 0x270) = dVar9;
          dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                   dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                  *(double *)(param_1 + 0x26c)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
          *(double *)(param_1 + 0x26e) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x270);
          *(double *)(param_1 + 0x270) = dVar9;
          *(double *)(param_1 + 0x26c) =
               dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x26c);
          (**(code **)(*param_1 + 0xcc))
                    (param_1,piVar2,
                     (float)((double)(float)param_1[0x27c] * *(double *)(param_1 + 0x26e) +
                            (double)(fVar3 * (float)param_1[0x27d])));
          fVar3 = *(float *)param_1[0x267];
          param_1[0x267] = (int)((float *)param_1[0x267] + 1);
          dVar8 = (double)(float)param_1[0x27e];
          dVar9 = *(double *)(param_1 + 0x278);
          dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
          *(double *)(param_1 + 0x278) = dVar9;
          dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                   dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                  *(double *)(param_1 + 0x274)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
          *(double *)(param_1 + 0x276) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x278);
          *(double *)(param_1 + 0x278) = dVar9;
          *(double *)(param_1 + 0x274) =
               dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x274);
          (**(code **)(*param_1 + 0xcc))
                    (param_1,piVar1,
                     (float)((double)(float)param_1[0x27c] * *(double *)(param_1 + 0x276) +
                            (double)(fVar3 * (float)param_1[0x27d])));
          iVar7 = iVar5;
        } while (param_2 != local_38);
      }
    }
    else if (iVar7 < 2) {
      if ((iVar7 == 0) && (0 < (int)param_2)) {
        local_3c = 0;
        iVar7 = param_2 + 1;
        do {
          iVar5 = param_2 - local_3c;
          uVar6 = local_3c & 7;
          local_3c = local_3c + 1;
          if (uVar6 == 0) {
            param_1[0x261] = (int)((float)param_1[0x261] + (float)param_1[0x262]);
            param_1[0x263] = param_1[0x263] + -1;
            iVar4 = 0;
            if (iVar7 + -2 < 7) {
              iVar4 = 7 - (iVar7 + -2);
            }
            iVar4 = iVar4 + param_1[0x4f];
            param_1[0x4f] = iVar4;
            if (8 < iVar4) {
              param_1[0x261] = (int)((float)param_1[0x261] - (float)param_1[0x262]);
              param_1[0x263] = param_1[0x263] + 1;
              param_1[0x4f] = iVar4 + -8;
            }
            if (param_1[0x263] < 1) {
              LFOSimp_c_vslot_57(param_1 + 0x78);
            }
            dVar9 = (double)((float)param_1[0x280] * (float)param_1[0x261]) * 3.0;
            dVar9 = dVar9 * dVar9 * dVar9 * 0.00082312050791077 + dVar9 * dVar9 * 0.0157739370387826
                    + dVar9 * 0.174502948013078 + 1.0;
            dVar9 = (double)(float)param_1[0x27f] * dVar9 * dVar9 * dVar9 * dVar9 *
                    (double)(float)param_1[0x52];
            *(double *)(param_1 + 0x268) = dVar9;
            if ((0.001 <= dVar9) || (NAN(dVar9))) {
              dVar9 = (double)(~-(ulonglong)(dVar9 <= 1.0) & (ulonglong)1.0 |
                              (ulonglong)dVar9 & -(ulonglong)(dVar9 <= 1.0));
            }
            else {
              dVar9 = 0.001;
            }
            *(double *)(param_1 + 0x268) = dVar9;
          }
          fVar3 = *(float *)param_1[0x266];
          param_1[0x266] = (int)((float *)param_1[0x266] + 1);
          dVar8 = (double)(float)param_1[0x27e];
          dVar9 = *(double *)(param_1 + 0x270);
          dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
          *(double *)(param_1 + 0x270) = dVar9;
          dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                   dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                  *(double *)(param_1 + 0x26c)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
          *(double *)(param_1 + 0x26e) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x270);
          *(double *)(param_1 + 0x270) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x26c);
          *(double *)(param_1 + 0x26c) = dVar9;
          (**(code **)(*param_1 + 0xcc))
                    (param_1,piVar2,
                     (float)(dVar9 * (double)(float)param_1[0x27c] +
                            (double)(fVar3 * (float)param_1[0x27d])));
          fVar3 = *(float *)param_1[0x267];
          param_1[0x267] = (int)((float *)param_1[0x267] + 1);
          dVar8 = (double)(float)param_1[0x27e];
          dVar9 = *(double *)(param_1 + 0x278);
          dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
          *(double *)(param_1 + 0x278) = dVar9;
          dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                   dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                  *(double *)(param_1 + 0x274)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
          *(double *)(param_1 + 0x276) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x278);
          *(double *)(param_1 + 0x278) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x274);
          *(double *)(param_1 + 0x274) = dVar9;
          (**(code **)(*param_1 + 0xcc))
                    (param_1,piVar1,
                     (float)(dVar9 * (double)(float)param_1[0x27c] +
                            (double)(fVar3 * (float)param_1[0x27d])));
          iVar7 = iVar5;
        } while (param_2 != local_3c);
      }
    }
    else if (iVar7 == 2) {
      if (0 < (int)param_2) {
        local_34 = 0;
        iVar7 = param_2 + 1;
        do {
          iVar5 = param_2 - local_34;
          uVar6 = local_34 & 7;
          local_34 = local_34 + 1;
          if (uVar6 == 0) {
            param_1[0x261] = (int)((float)param_1[0x261] + (float)param_1[0x262]);
            param_1[0x263] = param_1[0x263] + -1;
            iVar4 = 0;
            if (iVar7 + -2 < 7) {
              iVar4 = 7 - (iVar7 + -2);
            }
            iVar4 = iVar4 + param_1[0x4f];
            param_1[0x4f] = iVar4;
            if (8 < iVar4) {
              param_1[0x261] = (int)((float)param_1[0x261] - (float)param_1[0x262]);
              param_1[0x263] = param_1[0x263] + 1;
              param_1[0x4f] = iVar4 + -8;
            }
            if (param_1[0x263] < 1) {
              LFOSimp_c_vslot_57(param_1 + 0x78);
            }
            dVar9 = (double)((float)param_1[0x280] * (float)param_1[0x261]) * 3.0;
            dVar9 = dVar9 * dVar9 * dVar9 * 0.00082312050791077 + dVar9 * dVar9 * 0.0157739370387826
                    + dVar9 * 0.174502948013078 + 1.0;
            dVar9 = (double)(float)param_1[0x27f] * dVar9 * dVar9 * dVar9 * dVar9 *
                    (double)(float)param_1[0x52];
            *(double *)(param_1 + 0x268) = dVar9;
            if ((0.001 <= dVar9) || (NAN(dVar9))) {
              dVar9 = (double)(~-(ulonglong)(dVar9 <= 1.0) & (ulonglong)1.0 |
                              (ulonglong)dVar9 & -(ulonglong)(dVar9 <= 1.0));
            }
            else {
              dVar9 = 0.001;
            }
            *(double *)(param_1 + 0x268) = dVar9;
          }
          fVar3 = *(float *)param_1[0x266];
          param_1[0x266] = (int)((float *)param_1[0x266] + 1);
          dVar8 = (double)(float)param_1[0x27e];
          dVar9 = *(double *)(param_1 + 0x270);
          dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
          *(double *)(param_1 + 0x270) = dVar9;
          dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                   dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                  *(double *)(param_1 + 0x26c)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
          *(double *)(param_1 + 0x26e) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x270);
          *(double *)(param_1 + 0x270) = dVar9;
          *(double *)(param_1 + 0x26c) =
               dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x26c);
          (**(code **)(*param_1 + 0xcc))
                    (param_1,piVar2,
                     (float)((double)(float)param_1[0x27c] * *(double *)(param_1 + 0x270) +
                            (double)(fVar3 * (float)param_1[0x27d])));
          fVar3 = *(float *)param_1[0x267];
          param_1[0x267] = (int)((float *)param_1[0x267] + 1);
          dVar8 = (double)(float)param_1[0x27e];
          dVar9 = *(double *)(param_1 + 0x278);
          dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
          *(double *)(param_1 + 0x278) = dVar9;
          dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                   dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                  *(double *)(param_1 + 0x274)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
          *(double *)(param_1 + 0x276) = dVar9;
          dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x278);
          *(double *)(param_1 + 0x278) = dVar9;
          *(double *)(param_1 + 0x274) =
               dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x274);
          (**(code **)(*param_1 + 0xcc))
                    (param_1,piVar1,
                     (float)((double)(float)param_1[0x27c] * *(double *)(param_1 + 0x278) +
                            (double)(fVar3 * (float)param_1[0x27d])));
          iVar7 = iVar5;
        } while (param_2 != local_34);
      }
    }
    else if ((iVar7 == 3) && (0 < (int)param_2)) {
      local_30 = 0;
      iVar7 = param_2 + 1;
      do {
        iVar5 = param_2 - local_30;
        uVar6 = local_30 & 7;
        local_30 = local_30 + 1;
        if (uVar6 == 0) {
          param_1[0x261] = (int)((float)param_1[0x261] + (float)param_1[0x262]);
          param_1[0x263] = param_1[0x263] + -1;
          iVar4 = 0;
          if (iVar7 + -2 < 7) {
            iVar4 = 7 - (iVar7 + -2);
          }
          iVar4 = iVar4 + param_1[0x4f];
          param_1[0x4f] = iVar4;
          if (8 < iVar4) {
            param_1[0x261] = (int)((float)param_1[0x261] - (float)param_1[0x262]);
            param_1[0x263] = param_1[0x263] + 1;
            param_1[0x4f] = iVar4 + -8;
          }
          if (param_1[0x263] < 1) {
            LFOSimp_c_vslot_57(param_1 + 0x78);
          }
          dVar9 = (double)((float)param_1[0x280] * (float)param_1[0x261]) * 3.0;
          dVar9 = dVar9 * dVar9 * dVar9 * 0.00082312050791077 + dVar9 * dVar9 * 0.0157739370387826 +
                  dVar9 * 0.174502948013078 + 1.0;
          dVar9 = (double)(float)param_1[0x27f] * dVar9 * dVar9 * dVar9 * dVar9 *
                  (double)(float)param_1[0x52];
          *(double *)(param_1 + 0x268) = dVar9;
          if ((0.001 <= dVar9) || (NAN(dVar9))) {
            dVar9 = (double)(~-(ulonglong)(dVar9 <= 1.0) & (ulonglong)1.0 |
                            (ulonglong)dVar9 & -(ulonglong)(dVar9 <= 1.0));
          }
          else {
            dVar9 = 0.001;
          }
          *(double *)(param_1 + 0x268) = dVar9;
        }
        fVar3 = *(float *)param_1[0x266];
        param_1[0x266] = (int)((float *)param_1[0x266] + 1);
        dVar8 = (double)(float)param_1[0x27e];
        dVar9 = *(double *)(param_1 + 0x270);
        dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
        *(double *)(param_1 + 0x270) = dVar9;
        dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                 dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                *(double *)(param_1 + 0x26c)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
        *(double *)(param_1 + 0x26e) = dVar9;
        dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x270);
        *(double *)(param_1 + 0x270) = dVar9;
        dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x26c);
        *(double *)(param_1 + 0x26c) = dVar9;
        (**(code **)(*param_1 + 0xcc))
                  (param_1,piVar2,
                   (float)((dVar9 + *(double *)(param_1 + 0x26e)) * (double)(float)param_1[0x27c] +
                          (double)(fVar3 * (float)param_1[0x27d])));
        fVar3 = *(float *)param_1[0x267];
        param_1[0x267] = (int)((float *)param_1[0x267] + 1);
        dVar8 = (double)(float)param_1[0x27e];
        dVar9 = *(double *)(param_1 + 0x278);
        dVar9 = dVar9 * dVar9 * dVar9 * -0.02 + dVar9;
        *(double *)(param_1 + 0x278) = dVar9;
        dVar9 = (((1.0 - dVar8) * (double)fVar3 +
                 dVar8 * 0.35 * ((double)fVar3 / ((1.001 - dVar8) + (double)ABS(fVar3)))) -
                *(double *)(param_1 + 0x274)) - dVar9 * (1.0 - *(double *)(param_1 + 0x26a));
        *(double *)(param_1 + 0x276) = dVar9;
        dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x278);
        *(double *)(param_1 + 0x278) = dVar9;
        dVar9 = dVar9 * *(double *)(param_1 + 0x268) + *(double *)(param_1 + 0x274);
        *(double *)(param_1 + 0x274) = dVar9;
        (**(code **)(*param_1 + 0xcc))
                  (param_1,piVar1,
                   (float)((dVar9 + *(double *)(param_1 + 0x276)) * (double)(float)param_1[0x27c] +
                          (double)(fVar3 * (float)param_1[0x27d])));
        iVar7 = iVar5;
      } while (local_30 != param_2);
    }
                    /* WARNING: Could not recover jumptable at 0x00030890. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[0x46] + 0x44))();
    return;
  }
  return;
}

