/* 000426a4 FUN_000426a4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_000426a4(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  uint local_34;
  uint local_24;
  
  if (0 < (int)param_2) {
    local_34 = 0;
    do {
      uVar1 = local_34 & 7;
      local_34 = local_34 + 1;
      if (uVar1 == 0) {
        fVar8 = (float)param_1[0x81c] + (float)param_1[0x81d];
        param_1[0x81c] = (int)fVar8;
        iVar3 = param_1[0x822];
        param_1[0x822] = iVar3 + -1;
        if (iVar3 + -1 < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x78);
          fVar8 = (float)param_1[0x81c];
        }
        dVar6 = ((double)((float)param_1[0x83d] - (fVar8 * 0.66666 + 1.0) * (float)param_1[0x825]) -
                *(double *)(param_1 + 0x82b)) * 0.125;
        *(double *)(param_1 + 0x833) = dVar6;
        *(double *)(param_1 + 0x835) =
             ((double)((float)param_1[0x83d] - (float)param_1[0x825] * (fVar8 * -0.66666 + 1.0)) -
             *(double *)(param_1 + 0x82d)) * 0.125;
        dVar5 = 0.7937;
        dVar4 = dVar5;
        if (0.7937 <= dVar6) {
          dVar4 = (double)(~-(ulonglong)(dVar6 <= 1.26) & (ulonglong)1.26 |
                          (ulonglong)dVar6 & -(ulonglong)(dVar6 <= 1.26));
        }
        *(double *)(param_1 + 0x833) = dVar4;
        dVar4 = *(double *)(param_1 + 0x835);
        if ((0.7937 <= dVar4) && (dVar5 = 1.26, dVar4 <= 1.26)) {
          dVar5 = dVar4;
        }
        *(double *)(param_1 + 0x835) = dVar5;
      }
      uVar1 = param_1[0x83d];
      *(undefined4 *)(param_1[0x83e] + (uVar1 & param_1[0x83c]) * 4) = *(undefined4 *)param_1[0x83f]
      ;
      param_1[0x83d] = uVar1 + 1;
      dVar5 = *(double *)(param_1 + 0x82b);
      if (dVar5 <= 0.0) {
        dVar4 = 0.499999999999;
      }
      else {
        dVar4 = -0.499999999999;
      }
      local_24 = SUB84(dVar4 + dVar5 + *(double *)PTR_DAT_00103810,0);
      iVar3 = param_1[0x83e];
      uVar1 = param_1[0x83c];
      fVar8 = (1.0 - (float)(dVar5 - (double)(int)local_24)) *
              *(float *)(iVar3 + (local_24 & uVar1) * 4) +
              (float)(dVar5 - (double)(int)local_24) *
              *(float *)(iVar3 + (local_24 + 1 & uVar1) * 4);
      dVar5 = *(double *)(param_1 + 0x82d);
      if (dVar5 <= 0.0) {
        dVar4 = 0.499999999999;
      }
      else {
        dVar4 = -0.499999999999;
      }
      local_24 = SUB84(*(double *)PTR_DAT_00103810 + dVar4 + dVar5,0);
      fVar7 = (1.0 - (float)(dVar5 - (double)(int)local_24)) *
              *(float *)(iVar3 + (local_24 & uVar1) * 4) +
              (float)(dVar5 - (double)(int)local_24) *
              *(float *)(iVar3 + (uVar1 & local_24 + 1) * 4);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x841,
                 (float)param_1[0x82a] * *(float *)param_1[0x83f] + fVar8 * (float)param_1[0x828] +
                 fVar7 * (float)param_1[0x829]);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x842,
                 (float)param_1[0x82a] * *(float *)param_1[0x83f] + fVar7 * (float)param_1[0x828] +
                 fVar8 * (float)param_1[0x829]);
      param_1[0x83f] = param_1[0x83f] + 4;
      *(double *)(param_1 + 0x82b) = *(double *)(param_1 + 0x82b) + *(double *)(param_1 + 0x833);
      *(double *)(param_1 + 0x82d) = *(double *)(param_1 + 0x82d) + *(double *)(param_1 + 0x835);
    } while (local_34 != param_2);
  }
  iVar3 = param_1[0x83d];
  iVar2 = iVar3;
  if (1000000 < iVar3) {
    dVar4 = (double)iVar3;
    iVar2 = iVar3 / param_1[0x83b];
    iVar3 = iVar3 % param_1[0x83b] + param_1[0x83b];
    param_1[0x83d] = iVar3;
    *(double *)(param_1 + 0x82b) = (double)iVar3 - (dVar4 - *(double *)(param_1 + 0x82b));
    dVar6 = (double)iVar3;
    *(double *)(param_1 + 0x82d) = dVar6 - (dVar4 - *(double *)(param_1 + 0x82d));
    dVar5 = *(double *)(param_1 + 0x82f);
    if (0.0001 < dVar5) {
      dVar5 = dVar6 - (dVar4 - *(double *)(param_1 + 0x82f));
      *(double *)(param_1 + 0x82f) = dVar5;
      *(double *)(param_1 + 0x831) = dVar6 - (dVar4 - *(double *)(param_1 + 0x831));
    }
    if (dVar5 < 0.0) {
      do {
        dVar5 = dVar5 + (double)param_1[0x83b];
      } while (dVar5 < 0.0);
      *(double *)(param_1 + 0x82f) = dVar5;
      dVar5 = *(double *)(param_1 + 0x831);
    }
    else {
      dVar5 = *(double *)(param_1 + 0x831);
    }
    if (dVar5 < 0.0) {
      do {
        dVar5 = dVar5 + (double)param_1[0x83b];
      } while (dVar5 < 0.0);
      *(double *)(param_1 + 0x831) = dVar5;
      return iVar2;
    }
  }
  return iVar2;
}

