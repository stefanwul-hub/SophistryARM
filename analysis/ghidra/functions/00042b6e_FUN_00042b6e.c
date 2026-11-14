/* 00042b6e FUN_00042b6e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int * FUN_00042b6e(int *param_1,uint param_2)

{
  float fVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  uint local_34;
  uint local_24;
  
  if (0 < (int)param_2) {
    local_34 = 0;
    do {
      uVar4 = local_34 & 7;
      local_34 = local_34 + 1;
      if (uVar4 == 0) {
        fVar13 = (float)param_1[0x81c] + (float)param_1[0x81d];
        param_1[0x81c] = (int)fVar13;
        iVar7 = param_1[0x822];
        param_1[0x822] = iVar7 + -1;
        if (iVar7 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x78);
          fVar13 = (float)param_1[0x81c];
        }
        dVar8 = ((double)((float)param_1[0x83d] - (fVar13 * 0.66666 + 1.0) * (float)param_1[0x825])
                - *(double *)(param_1 + 0x82b)) * 0.125;
        *(double *)(param_1 + 0x833) = dVar8;
        *(double *)(param_1 + 0x835) =
             ((double)((float)param_1[0x83d] - (float)param_1[0x825] * (fVar13 * -0.66666 + 1.0)) -
             *(double *)(param_1 + 0x82d)) * 0.125;
        dVar11 = 0.7937;
        dVar10 = dVar11;
        if (0.7937 <= dVar8) {
          dVar10 = (double)(~-(ulonglong)(dVar8 <= 1.26) & (ulonglong)1.26 |
                           (ulonglong)dVar8 & -(ulonglong)(dVar8 <= 1.26));
        }
        *(double *)(param_1 + 0x833) = dVar10;
        dVar10 = *(double *)(param_1 + 0x835);
        if ((0.7937 <= dVar10) && (dVar11 = 1.26, dVar10 <= 1.26)) {
          dVar11 = dVar10;
        }
        *(double *)(param_1 + 0x835) = dVar11;
        param_1[0x81e] = (int)((float)param_1[0x81e] + (float)param_1[0x81f]);
        param_1[0x820] = (int)((float)param_1[0x820] + (float)param_1[0x821]);
        iVar7 = param_1[0x823];
        param_1[0x823] = iVar7 + -1;
        if (iVar7 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x261);
        }
        iVar7 = param_1[0x824];
        param_1[0x824] = iVar7 + -1;
        if (iVar7 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x44a);
        }
        dVar10 = ((double)((float)param_1[0x83d] -
                          ((float)param_1[0x81e] * -0.75 + 1.0) * (float)param_1[0x826]) -
                 *(double *)(param_1 + 0x82f)) * 0.125;
        *(double *)(param_1 + 0x837) = dVar10;
        *(double *)(param_1 + 0x839) =
             ((double)((float)param_1[0x83d] -
                      ((float)param_1[0x820] * 0.75 + 1.0) * (float)param_1[0x827]) -
             *(double *)(param_1 + 0x831)) * 0.125;
        dVar11 = 0.7937;
        dVar8 = dVar11;
        if (0.7937 <= dVar10) {
          dVar8 = (double)(~-(ulonglong)(dVar10 <= 1.26) & (ulonglong)1.26 |
                          (ulonglong)dVar10 & -(ulonglong)(dVar10 <= 1.26));
        }
        *(double *)(param_1 + 0x837) = dVar8;
        dVar10 = *(double *)(param_1 + 0x839);
        if ((0.7937 <= dVar10) && (dVar11 = 1.26, dVar10 <= 1.26)) {
          dVar11 = dVar10;
        }
        *(double *)(param_1 + 0x839) = dVar11;
      }
      uVar4 = param_1[0x83d];
      *(float *)(param_1[0x83e] + (uVar4 & param_1[0x83c]) * 4) =
           (*(float *)param_1[0x83f] + *(float *)param_1[0x840]) * 0.5;
      param_1[0x83d] = uVar4 + 1;
      dVar11 = *(double *)(param_1 + 0x82b);
      if (dVar11 <= 0.0) {
        dVar10 = 0.499999999999;
      }
      else {
        dVar10 = -0.499999999999;
      }
      local_24 = SUB84(dVar10 + dVar11 + *(double *)PTR_DAT_00103810,0);
      dVar8 = (double)(int)local_24;
      iVar7 = param_1[0x83e];
      uVar4 = param_1[0x83c];
      uVar6 = local_24 & uVar4;
      uVar3 = local_24 + 1;
      dVar10 = *(double *)(param_1 + 0x82f);
      if (dVar10 <= 0.0) {
        dVar9 = 0.499999999999;
      }
      else {
        dVar9 = -0.499999999999;
      }
      local_24 = SUB84(dVar9 + dVar10 + *(double *)PTR_DAT_00103810,0);
      fVar13 = (1.0 - (float)(dVar10 - (double)(int)local_24)) *
               *(float *)(iVar7 + (local_24 & uVar4) * 4) +
               (float)(dVar10 - (double)(int)local_24) *
               *(float *)(iVar7 + (local_24 + 1 & uVar4) * 4) +
               (1.0 - (float)(dVar11 - dVar8)) * *(float *)(iVar7 + uVar6 * 4) +
               (float)(dVar11 - dVar8) * *(float *)(iVar7 + (uVar3 & uVar4) * 4);
      dVar11 = *(double *)(param_1 + 0x82d);
      if (dVar11 <= 0.0) {
        dVar10 = 0.499999999999;
      }
      else {
        dVar10 = -0.499999999999;
      }
      local_24 = SUB84(dVar10 + dVar11 + *(double *)PTR_DAT_00103810,0);
      dVar8 = (double)(int)local_24;
      uVar6 = local_24 & uVar4;
      uVar3 = local_24 + 1;
      dVar10 = *(double *)(param_1 + 0x831);
      if (dVar10 <= 0.0) {
        dVar9 = 0.499999999999;
      }
      else {
        dVar9 = -0.499999999999;
      }
      local_24 = SUB84(dVar9 + dVar10 + *(double *)PTR_DAT_00103810,0);
      fVar12 = (1.0 - (float)(dVar10 - (double)(int)local_24)) *
               *(float *)(iVar7 + (local_24 & uVar4) * 4) +
               (float)(dVar10 - (double)(int)local_24) *
               *(float *)(iVar7 + (uVar4 & local_24 + 1) * 4) +
               (1.0 - (float)(dVar11 - dVar8)) * *(float *)(iVar7 + uVar6 * 4) +
               (float)(dVar11 - dVar8) * *(float *)(iVar7 + (uVar3 & uVar4) * 4);
      pcVar2 = *(code **)(*param_1 + 0xcc);
      fVar1 = *(float *)param_1[0x83f];
      param_1[0x83f] = (int)((float *)param_1[0x83f] + 1);
      (*pcVar2)(param_1,param_1 + 0x841,
                (float)param_1[0x82a] * fVar1 + fVar13 * (float)param_1[0x828] +
                fVar12 * (float)param_1[0x829]);
      pcVar2 = *(code **)(*param_1 + 0xcc);
      fVar1 = *(float *)param_1[0x840];
      param_1[0x840] = (int)((float *)param_1[0x840] + 1);
      (*pcVar2)(param_1,param_1 + 0x842,
                (float)param_1[0x82a] * fVar1 + fVar12 * (float)param_1[0x828] +
                fVar13 * (float)param_1[0x829]);
      *(double *)(param_1 + 0x82b) = *(double *)(param_1 + 0x82b) + *(double *)(param_1 + 0x833);
      *(double *)(param_1 + 0x82d) = *(double *)(param_1 + 0x82d) + *(double *)(param_1 + 0x835);
      *(double *)(param_1 + 0x82f) = *(double *)(param_1 + 0x82f) + *(double *)(param_1 + 0x837);
      *(double *)(param_1 + 0x831) = *(double *)(param_1 + 0x831) + *(double *)(param_1 + 0x839);
    } while (param_2 != local_34);
  }
  piVar5 = (int *)param_1[0x83d];
  if (1000000 < (int)piVar5) {
    dVar10 = (double)(int)piVar5;
    iVar7 = (int)piVar5 % param_1[0x83b] + param_1[0x83b];
    param_1[0x83d] = iVar7;
    *(double *)(param_1 + 0x82b) = (double)iVar7 - (dVar10 - *(double *)(param_1 + 0x82b));
    dVar8 = (double)iVar7;
    *(double *)(param_1 + 0x82d) = dVar8 - (dVar10 - *(double *)(param_1 + 0x82d));
    dVar11 = *(double *)(param_1 + 0x82f);
    if (0.0001 < dVar11) {
      dVar11 = dVar8 - (dVar10 - *(double *)(param_1 + 0x82f));
      *(double *)(param_1 + 0x82f) = dVar11;
      *(double *)(param_1 + 0x831) = dVar8 - (dVar10 - *(double *)(param_1 + 0x831));
    }
    if (dVar11 < 0.0) {
      do {
        dVar11 = dVar11 + (double)param_1[0x83b];
      } while (dVar11 < 0.0);
      *(double *)(param_1 + 0x82f) = dVar11;
      dVar11 = *(double *)(param_1 + 0x831);
      piVar5 = param_1;
    }
    else {
      dVar11 = *(double *)(param_1 + 0x831);
      piVar5 = (int *)((int)piVar5 / param_1[0x83b]);
    }
    if (dVar11 < 0.0) {
      do {
        dVar11 = dVar11 + (double)param_1[0x83b];
      } while (dVar11 < 0.0);
      *(double *)(param_1 + 0x831) = dVar11;
      return param_1;
    }
  }
  return piVar5;
}

