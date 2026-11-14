/* 00041f38 FUN_00041f38 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_00041f38(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  float fVar10;
  float fVar11;
  uint local_34;
  uint local_24;
  
  if (0 < (int)param_2) {
    local_34 = 0;
    do {
      uVar2 = local_34 & 7;
      local_34 = local_34 + 1;
      if (uVar2 == 0) {
        fVar11 = (float)param_1[0x81c] + (float)param_1[0x81d];
        param_1[0x81c] = (int)fVar11;
        iVar5 = param_1[0x822];
        param_1[0x822] = iVar5 + -1;
        if (iVar5 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x78);
          fVar11 = (float)param_1[0x81c];
        }
        dVar6 = ((double)((float)param_1[0x83d] - (fVar11 * 0.66666 + 1.0) * (float)param_1[0x825])
                - *(double *)(param_1 + 0x82b)) * 0.125;
        *(double *)(param_1 + 0x833) = dVar6;
        *(double *)(param_1 + 0x835) =
             ((double)((float)param_1[0x83d] - (float)param_1[0x825] * (fVar11 * -0.66666 + 1.0)) -
             *(double *)(param_1 + 0x82d)) * 0.125;
        dVar9 = 0.7937;
        dVar8 = dVar9;
        if (0.7937 <= dVar6) {
          dVar8 = (double)(~-(ulonglong)(dVar6 <= 1.26) & (ulonglong)1.26 |
                          (ulonglong)dVar6 & -(ulonglong)(dVar6 <= 1.26));
        }
        *(double *)(param_1 + 0x833) = dVar8;
        dVar8 = *(double *)(param_1 + 0x835);
        if ((0.7937 <= dVar8) && (dVar9 = 1.26, dVar8 <= 1.26)) {
          dVar9 = dVar8;
        }
        *(double *)(param_1 + 0x835) = dVar9;
        param_1[0x81e] = (int)((float)param_1[0x81e] + (float)param_1[0x81f]);
        param_1[0x820] = (int)((float)param_1[0x820] + (float)param_1[0x821]);
        iVar5 = param_1[0x823];
        param_1[0x823] = iVar5 + -1;
        if (iVar5 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x261);
        }
        iVar5 = param_1[0x824];
        param_1[0x824] = iVar5 + -1;
        if (iVar5 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x44a);
        }
        dVar8 = ((double)((float)param_1[0x83d] -
                         ((float)param_1[0x81e] * -0.75 + 1.0) * (float)param_1[0x826]) -
                *(double *)(param_1 + 0x82f)) * 0.125;
        *(double *)(param_1 + 0x837) = dVar8;
        *(double *)(param_1 + 0x839) =
             ((double)((float)param_1[0x83d] -
                      ((float)param_1[0x820] * 0.75 + 1.0) * (float)param_1[0x827]) -
             *(double *)(param_1 + 0x831)) * 0.125;
        dVar9 = 0.7937;
        dVar6 = dVar9;
        if (0.7937 <= dVar8) {
          dVar6 = (double)(~-(ulonglong)(dVar8 <= 1.26) & (ulonglong)1.26 |
                          (ulonglong)dVar8 & -(ulonglong)(dVar8 <= 1.26));
        }
        *(double *)(param_1 + 0x837) = dVar6;
        dVar8 = *(double *)(param_1 + 0x839);
        if ((0.7937 <= dVar8) && (dVar9 = 1.26, dVar8 <= 1.26)) {
          dVar9 = dVar8;
        }
        *(double *)(param_1 + 0x839) = dVar9;
      }
      uVar2 = param_1[0x83d];
      *(undefined4 *)(param_1[0x83e] + (uVar2 & param_1[0x83c]) * 4) = *(undefined4 *)param_1[0x83f]
      ;
      param_1[0x83d] = uVar2 + 1;
      dVar9 = *(double *)(param_1 + 0x82b);
      if (dVar9 <= 0.0) {
        dVar8 = 0.499999999999;
      }
      else {
        dVar8 = -0.499999999999;
      }
      local_24 = SUB84(dVar8 + dVar9 + *(double *)PTR_DAT_00103810,0);
      dVar6 = (double)(int)local_24;
      iVar5 = param_1[0x83e];
      uVar2 = param_1[0x83c];
      uVar4 = local_24 & uVar2;
      uVar1 = local_24 + 1;
      dVar8 = *(double *)(param_1 + 0x82f);
      if (dVar8 <= 0.0) {
        dVar7 = 0.499999999999;
      }
      else {
        dVar7 = -0.499999999999;
      }
      local_24 = SUB84(dVar7 + dVar8 + *(double *)PTR_DAT_00103810,0);
      fVar11 = (1.0 - (float)(dVar8 - (double)(int)local_24)) *
               *(float *)(iVar5 + (local_24 & uVar2) * 4) +
               (float)(dVar8 - (double)(int)local_24) *
               *(float *)(iVar5 + (local_24 + 1 & uVar2) * 4) +
               (1.0 - (float)(dVar9 - dVar6)) * *(float *)(iVar5 + uVar4 * 4) +
               (float)(dVar9 - dVar6) * *(float *)(iVar5 + (uVar1 & uVar2) * 4);
      dVar9 = *(double *)(param_1 + 0x82d);
      if (dVar9 <= 0.0) {
        dVar8 = 0.499999999999;
      }
      else {
        dVar8 = -0.499999999999;
      }
      local_24 = SUB84(dVar8 + dVar9 + *(double *)PTR_DAT_00103810,0);
      dVar6 = (double)(int)local_24;
      uVar4 = local_24 & uVar2;
      uVar1 = local_24 + 1;
      dVar8 = *(double *)(param_1 + 0x831);
      if (dVar8 <= 0.0) {
        dVar7 = 0.499999999999;
      }
      else {
        dVar7 = -0.499999999999;
      }
      local_24 = SUB84(dVar7 + dVar8 + *(double *)PTR_DAT_00103810,0);
      fVar10 = (1.0 - (float)(dVar8 - (double)(int)local_24)) *
               *(float *)(iVar5 + (local_24 & uVar2) * 4) +
               (float)(dVar8 - (double)(int)local_24) *
               *(float *)(iVar5 + (uVar2 & local_24 + 1) * 4) +
               (1.0 - (float)(dVar9 - dVar6)) * *(float *)(iVar5 + uVar4 * 4) +
               (float)(dVar9 - dVar6) * *(float *)(iVar5 + (uVar1 & uVar2) * 4);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x841,
                 (float)param_1[0x82a] * *(float *)param_1[0x83f] + fVar11 * (float)param_1[0x828] +
                 fVar10 * (float)param_1[0x829]);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x842,
                 (float)param_1[0x82a] * *(float *)param_1[0x83f] + fVar10 * (float)param_1[0x828] +
                 fVar11 * (float)param_1[0x829]);
      param_1[0x83f] = param_1[0x83f] + 4;
      *(double *)(param_1 + 0x82b) = *(double *)(param_1 + 0x82b) + *(double *)(param_1 + 0x833);
      *(double *)(param_1 + 0x82d) = *(double *)(param_1 + 0x82d) + *(double *)(param_1 + 0x835);
      *(double *)(param_1 + 0x82f) = *(double *)(param_1 + 0x82f) + *(double *)(param_1 + 0x837);
      *(double *)(param_1 + 0x831) = *(double *)(param_1 + 0x831) + *(double *)(param_1 + 0x839);
    } while (param_2 != local_34);
  }
  iVar5 = param_1[0x83d];
  iVar3 = iVar5;
  if (1000000 < iVar5) {
    dVar8 = (double)iVar5;
    iVar3 = iVar5 / param_1[0x83b];
    iVar5 = iVar5 % param_1[0x83b] + param_1[0x83b];
    param_1[0x83d] = iVar5;
    *(double *)(param_1 + 0x82b) = (double)iVar5 - (dVar8 - *(double *)(param_1 + 0x82b));
    dVar6 = (double)iVar5;
    *(double *)(param_1 + 0x82d) = dVar6 - (dVar8 - *(double *)(param_1 + 0x82d));
    dVar9 = *(double *)(param_1 + 0x82f);
    if (0.0001 < dVar9) {
      dVar9 = dVar6 - (dVar8 - *(double *)(param_1 + 0x82f));
      *(double *)(param_1 + 0x82f) = dVar9;
      *(double *)(param_1 + 0x831) = dVar6 - (dVar8 - *(double *)(param_1 + 0x831));
    }
    if (dVar9 < 0.0) {
      do {
        dVar9 = dVar9 + (double)param_1[0x83b];
      } while (dVar9 < 0.0);
      *(double *)(param_1 + 0x82f) = dVar9;
      dVar9 = *(double *)(param_1 + 0x831);
    }
    else {
      dVar9 = *(double *)(param_1 + 0x831);
    }
    if (dVar9 < 0.0) {
      do {
        dVar9 = dVar9 + (double)param_1[0x83b];
      } while (dVar9 < 0.0);
      *(double *)(param_1 + 0x831) = dVar9;
      return iVar3;
    }
  }
  return iVar3;
}

