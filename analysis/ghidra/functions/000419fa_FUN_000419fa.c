/* 000419fa FUN_000419fa */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int * FUN_000419fa(int *param_1,uint param_2)

{
  float fVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  float fVar10;
  uint local_34;
  uint local_24;
  
  if (0 < (int)param_2) {
    local_34 = 0;
    do {
      uVar3 = local_34 & 7;
      local_34 = local_34 + 1;
      if (uVar3 == 0) {
        fVar10 = (float)param_1[0x81c] + (float)param_1[0x81d];
        param_1[0x81c] = (int)fVar10;
        iVar5 = param_1[0x822];
        param_1[0x822] = iVar5 + -1;
        if (iVar5 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x78);
          fVar10 = (float)param_1[0x81c];
        }
        dVar8 = ((double)((float)param_1[0x83d] - (fVar10 * 0.66666 + 1.0) * (float)param_1[0x825])
                - *(double *)(param_1 + 0x82b)) * 0.125;
        *(double *)(param_1 + 0x833) = dVar8;
        *(double *)(param_1 + 0x835) =
             ((double)((float)param_1[0x83d] - (float)param_1[0x825] * (fVar10 * -0.66666 + 1.0)) -
             *(double *)(param_1 + 0x82d)) * 0.125;
        dVar7 = 0.7937;
        dVar6 = dVar7;
        if (0.7937 <= dVar8) {
          dVar6 = (double)(~-(ulonglong)(dVar8 <= 1.26) & (ulonglong)1.26 |
                          (ulonglong)dVar8 & -(ulonglong)(dVar8 <= 1.26));
        }
        *(double *)(param_1 + 0x833) = dVar6;
        dVar6 = *(double *)(param_1 + 0x835);
        if ((0.7937 <= dVar6) && (dVar7 = 1.26, dVar6 <= 1.26)) {
          dVar7 = dVar6;
        }
        *(double *)(param_1 + 0x835) = dVar7;
      }
      uVar3 = param_1[0x83d];
      *(float *)(param_1[0x83e] + (uVar3 & param_1[0x83c]) * 4) =
           (*(float *)param_1[0x83f] + *(float *)param_1[0x840]) * 0.5;
      param_1[0x83d] = uVar3 + 1;
      dVar7 = *(double *)(param_1 + 0x82b);
      if (dVar7 <= 0.0) {
        dVar6 = 0.499999999999;
      }
      else {
        dVar6 = -0.499999999999;
      }
      local_24 = SUB84(dVar6 + dVar7 + *(double *)PTR_DAT_00103810,0);
      iVar5 = param_1[0x83e];
      uVar3 = param_1[0x83c];
      fVar10 = (1.0 - (float)(dVar7 - (double)(int)local_24)) *
               *(float *)(iVar5 + (local_24 & uVar3) * 4) +
               (float)(dVar7 - (double)(int)local_24) *
               *(float *)(iVar5 + (local_24 + 1 & uVar3) * 4);
      dVar7 = *(double *)(param_1 + 0x82d);
      if (dVar7 <= 0.0) {
        dVar6 = 0.499999999999;
      }
      else {
        dVar6 = -0.499999999999;
      }
      local_24 = SUB84(*(double *)PTR_DAT_00103810 + dVar6 + dVar7,0);
      fVar9 = (1.0 - (float)(dVar7 - (double)(int)local_24)) *
              *(float *)(iVar5 + (local_24 & uVar3) * 4) +
              (float)(dVar7 - (double)(int)local_24) *
              *(float *)(iVar5 + (uVar3 & local_24 + 1) * 4);
      pcVar2 = *(code **)(*param_1 + 0xcc);
      fVar1 = *(float *)param_1[0x83f];
      param_1[0x83f] = (int)((float *)param_1[0x83f] + 1);
      (*pcVar2)(param_1,param_1 + 0x841,
                (float)param_1[0x82a] * fVar1 + fVar10 * (float)param_1[0x828] +
                fVar9 * (float)param_1[0x829]);
      pcVar2 = *(code **)(*param_1 + 0xcc);
      fVar1 = *(float *)param_1[0x840];
      param_1[0x840] = (int)((float *)param_1[0x840] + 1);
      (*pcVar2)(param_1,param_1 + 0x842,
                (float)param_1[0x82a] * fVar1 + fVar9 * (float)param_1[0x828] +
                fVar10 * (float)param_1[0x829]);
      *(double *)(param_1 + 0x82b) = *(double *)(param_1 + 0x82b) + *(double *)(param_1 + 0x833);
      *(double *)(param_1 + 0x82d) = *(double *)(param_1 + 0x82d) + *(double *)(param_1 + 0x835);
    } while (local_34 != param_2);
  }
  piVar4 = (int *)param_1[0x83d];
  if (1000000 < (int)piVar4) {
    dVar6 = (double)(int)piVar4;
    iVar5 = (int)piVar4 % param_1[0x83b] + param_1[0x83b];
    param_1[0x83d] = iVar5;
    *(double *)(param_1 + 0x82b) = (double)iVar5 - (dVar6 - *(double *)(param_1 + 0x82b));
    dVar8 = (double)iVar5;
    *(double *)(param_1 + 0x82d) = dVar8 - (dVar6 - *(double *)(param_1 + 0x82d));
    dVar7 = *(double *)(param_1 + 0x82f);
    if (0.0001 < dVar7) {
      dVar7 = dVar8 - (dVar6 - *(double *)(param_1 + 0x82f));
      *(double *)(param_1 + 0x82f) = dVar7;
      *(double *)(param_1 + 0x831) = dVar8 - (dVar6 - *(double *)(param_1 + 0x831));
    }
    if (dVar7 < 0.0) {
      do {
        dVar7 = dVar7 + (double)param_1[0x83b];
      } while (dVar7 < 0.0);
      *(double *)(param_1 + 0x82f) = dVar7;
      dVar7 = *(double *)(param_1 + 0x831);
      piVar4 = param_1;
    }
    else {
      dVar7 = *(double *)(param_1 + 0x831);
      piVar4 = (int *)((int)piVar4 / param_1[0x83b]);
    }
    if (dVar7 < 0.0) {
      do {
        dVar7 = dVar7 + (double)param_1[0x83b];
      } while (dVar7 < 0.0);
      *(double *)(param_1 + 0x831) = dVar7;
      return param_1;
    }
  }
  return piVar4;
}

