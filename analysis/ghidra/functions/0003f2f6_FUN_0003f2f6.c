/* 0003f2f6 FUN_0003f2f6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003f2f6(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint local_28;
  int local_24;
  
  local_24 = param_2 + 1;
  local_28 = 0;
  do {
    local_24 = local_24 + -1;
    if (local_24 < 1) {
      return;
    }
    while( true ) {
      uVar3 = local_28 & 7;
      local_28 = local_28 + 1;
      if (uVar3 == 0) {
        iVar4 = param_1[0x49];
        if ((iVar4 == 0) || (param_1[0x8a] < 0x11)) {
          fVar10 = 0.0;
        }
        else {
          fVar10 = *(float *)(iVar4 + 0xec) * 0.001;
          if (*(int *)(iVar4 + 0x174) < *(int *)(iVar4 + 0x158)) {
            lVar5 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar4 + 0x158));
            fVar10 = (float)lVar5;
            iVar4 = param_1[0x49];
          }
          for (; (float)(param_1[0x8a] + -0x10) <= fVar10 * (float)param_1[0x50];
              fVar10 = fVar10 * 0.5) {
          }
        }
        fVar1 = (float)param_1[0x50];
        if ((iVar4 == 0) || (param_1[0x8a] < 0x11)) {
          fVar11 = 0.0;
        }
        else {
          fVar11 = *(float *)(iVar4 + 0x1cc) * 0.001;
          if (*(int *)(iVar4 + 0x254) < *(int *)(iVar4 + 0x238)) {
            lVar5 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar4 + 0x238));
            fVar11 = (float)lVar5;
          }
          for (; (float)(param_1[0x8a] + -0x10) <= (float)param_1[0x50] * fVar11;
              fVar11 = fVar11 * 0.5) {
          }
        }
        dVar7 = (((double)((float)(param_1[0x78] + 8) - fVar10 * fVar1) -
                 *(double *)(param_1 + 0x79)) * 0.125 - 1.0) * 0.0015 + 1.0;
        dVar9 = 0.25;
        dVar8 = dVar9;
        if ((0.25 <= dVar7) && (dVar8 = 4.0, dVar7 <= 4.0)) {
          dVar8 = dVar7;
        }
        *(double *)(param_1 + 0x7d) = dVar8;
        dVar8 = (((double)((float)(param_1[0x78] + 8) - fVar11 * (float)param_1[0x50]) -
                 *(double *)(param_1 + 0x7b)) * 0.125 - 1.0) * 0.0015 + 1.0;
        *(double *)(param_1 + 0x7f) = dVar8;
        if ((0.25 <= dVar8) && (dVar9 = 4.0, dVar8 <= 4.0)) {
          dVar9 = dVar8;
        }
        *(double *)(param_1 + 0x7f) = dVar9;
      }
      fVar10 = *(float *)param_1[0x91];
      param_1[0x91] = (int)((float *)param_1[0x91] + 1);
      fVar1 = *(float *)param_1[0x92];
      param_1[0x92] = (int)((float *)param_1[0x92] + 1);
      uVar3 = param_1[0x83];
      fVar11 = *(float *)(param_1[0x88] + ((int)*(double *)(param_1 + 0x79) & uVar3) * 4);
      fVar2 = *(float *)(param_1[0x89] + ((int)*(double *)(param_1 + 0x7b) & uVar3) * 4);
      fVar6 = (float)param_1[0x99];
      *(float *)(param_1[0x88] + (uVar3 & param_1[0x78]) * 4) =
           fVar11 * (float)param_1[0x98] + fVar10;
      *(float *)(param_1[0x89] + (param_1[0x78] & param_1[0x83]) * 4) = fVar2 * fVar6 + fVar1;
      param_1[0x8d] =
           (int)((float)param_1[0x8d] + (fVar11 - (float)param_1[0x8d]) * (float)param_1[0x9a]);
      fVar6 = (fVar2 - (float)param_1[0x8e]) * (float)param_1[0x9a] + (float)param_1[0x8e];
      param_1[0x8e] = (int)fVar6;
      fVar12 = ((fVar11 - (float)param_1[0x8d]) - (float)param_1[0x8b]) * (float)param_1[0x9b] +
               (float)param_1[0x8b];
      param_1[0x8b] = (int)fVar12;
      fVar6 = ((fVar2 - fVar6) - (float)param_1[0x8c]) * (float)param_1[0x9b] + (float)param_1[0x8c]
      ;
      param_1[0x8c] = (int)fVar6;
      fVar11 = (float)param_1[0x96];
      fVar2 = (float)param_1[0x97];
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x8f,
                 fVar10 + (fVar11 * fVar12 + fVar2 * fVar6) * (float)param_1[0x95]);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x90,
                 fVar1 + (fVar6 * fVar11 + fVar12 * fVar2) * (float)param_1[0x95]);
      iVar4 = param_1[0x78] + 1;
      param_1[0x78] = iVar4;
      dVar9 = *(double *)(param_1 + 0x79);
      *(double *)(param_1 + 0x79) = dVar9 + *(double *)(param_1 + 0x7d);
      dVar8 = *(double *)(param_1 + 0x7b);
      *(double *)(param_1 + 0x7b) = dVar8 + *(double *)(param_1 + 0x7f);
      if (iVar4 < param_1[0x84]) break;
      param_1[0x78] = iVar4 - param_1[0x85];
      *(double *)(param_1 + 0x79) =
           (dVar9 + *(double *)(param_1 + 0x7d)) - *(double *)(param_1 + 0x86);
      *(double *)(param_1 + 0x7b) =
           (dVar8 + *(double *)(param_1 + 0x7f)) - *(double *)(param_1 + 0x86);
      local_24 = local_24 + -1;
      if (local_24 < 1) {
        return;
      }
    }
  } while( true );
}

