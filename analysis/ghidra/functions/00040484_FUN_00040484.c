/* 00040484 FUN_00040484 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00040484(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  longdouble lVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint local_30;
  int local_2c;
  
  local_2c = param_2 + 1;
  local_30 = 0;
  do {
    local_2c = local_2c + -1;
    if (local_2c < 1) {
      return;
    }
    while( true ) {
      uVar4 = local_30 & 7;
      local_30 = local_30 + 1;
      if (uVar4 == 0) {
        iVar5 = param_1[0x49];
        if ((iVar5 == 0) || (param_1[0x8a] < 0x11)) {
          fVar11 = 0.0;
        }
        else {
          fVar11 = *(float *)(iVar5 + 0xec) * 0.001;
          if (*(int *)(iVar5 + 0x174) < *(int *)(iVar5 + 0x158)) {
            lVar6 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar5 + 0x158));
            fVar11 = (float)lVar6;
            iVar5 = param_1[0x49];
          }
          for (; (float)(param_1[0x8a] + -0x10) <= fVar11 * (float)param_1[0x50];
              fVar11 = fVar11 * 0.5) {
          }
        }
        fVar1 = (float)param_1[0x50];
        if ((iVar5 == 0) || (param_1[0x8a] < 0x11)) {
          fVar12 = 0.0;
        }
        else {
          fVar12 = *(float *)(iVar5 + 0x1cc) * 0.001;
          if (*(int *)(iVar5 + 0x254) < *(int *)(iVar5 + 0x238)) {
            lVar6 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar5 + 0x238));
            fVar12 = (float)lVar6;
          }
          for (; (float)(param_1[0x8a] + -0x10) <= (float)param_1[0x50] * fVar12;
              fVar12 = fVar12 * 0.5) {
          }
        }
        dVar8 = (((double)((float)(param_1[0x78] + 8) - fVar11 * fVar1) -
                 *(double *)(param_1 + 0x79)) * 0.125 - 1.0) * 0.0015 + 1.0;
        dVar10 = 0.25;
        dVar9 = dVar10;
        if ((0.25 <= dVar8) && (dVar9 = 4.0, dVar8 <= 4.0)) {
          dVar9 = dVar8;
        }
        *(double *)(param_1 + 0x7d) = dVar9;
        dVar9 = (((double)((float)(param_1[0x78] + 8) - fVar12 * (float)param_1[0x50]) -
                 *(double *)(param_1 + 0x7b)) * 0.125 - 1.0) * 0.0015 + 1.0;
        *(double *)(param_1 + 0x7f) = dVar9;
        if ((0.25 <= dVar9) && (dVar10 = 4.0, dVar9 <= 4.0)) {
          dVar10 = dVar9;
        }
        *(double *)(param_1 + 0x7f) = dVar10;
      }
      fVar11 = *(float *)param_1[0x91];
      param_1[0x91] = (int)((float *)param_1[0x91] + 1);
      fVar1 = *(float *)param_1[0x92];
      param_1[0x92] = (int)((float *)param_1[0x92] + 1);
      uVar4 = param_1[0x83];
      fVar12 = *(float *)(param_1[0x88] + ((int)*(double *)(param_1 + 0x79) & uVar4) * 4);
      fVar2 = *(float *)(param_1[0x89] + ((int)*(double *)(param_1 + 0x7b) & uVar4) * 4);
      fVar7 = (float)param_1[0x96];
      fVar13 = (float)param_1[0x97];
      fVar3 = (float)param_1[0x99];
      *(float *)(param_1[0x88] + (uVar4 & param_1[0x78]) * 4) =
           (fVar7 * fVar12 + fVar13 * fVar2) * (float)param_1[0x98] + fVar11;
      *(float *)(param_1[0x89] + (param_1[0x78] & param_1[0x83]) * 4) =
           (fVar2 * fVar7 + fVar12 * fVar13) * fVar3 + fVar1;
      param_1[0x8d] =
           (int)((float)param_1[0x8d] + (fVar12 - (float)param_1[0x8d]) * (float)param_1[0x9a]);
      fVar7 = (fVar2 - (float)param_1[0x8e]) * (float)param_1[0x9a] + (float)param_1[0x8e];
      param_1[0x8e] = (int)fVar7;
      fVar13 = ((fVar12 - (float)param_1[0x8d]) - (float)param_1[0x8b]) * (float)param_1[0x9b] +
               (float)param_1[0x8b];
      param_1[0x8b] = (int)fVar13;
      fVar7 = ((fVar2 - fVar7) - (float)param_1[0x8c]) * (float)param_1[0x9b] + (float)param_1[0x8c]
      ;
      param_1[0x8c] = (int)fVar7;
      fVar12 = (float)param_1[0x96];
      fVar2 = (float)param_1[0x97];
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x8f,
                 fVar11 + (fVar12 * fVar13 + fVar2 * fVar7) * (float)param_1[0x95]);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x90,
                 fVar1 + (fVar7 * fVar12 + fVar13 * fVar2) * (float)param_1[0x95]);
      iVar5 = param_1[0x78] + 1;
      param_1[0x78] = iVar5;
      dVar10 = *(double *)(param_1 + 0x79);
      *(double *)(param_1 + 0x79) = dVar10 + *(double *)(param_1 + 0x7d);
      dVar9 = *(double *)(param_1 + 0x7b);
      *(double *)(param_1 + 0x7b) = dVar9 + *(double *)(param_1 + 0x7f);
      if (iVar5 < param_1[0x84]) break;
      param_1[0x78] = iVar5 - param_1[0x85];
      *(double *)(param_1 + 0x79) =
           (dVar10 + *(double *)(param_1 + 0x7d)) - *(double *)(param_1 + 0x86);
      *(double *)(param_1 + 0x7b) =
           (dVar9 + *(double *)(param_1 + 0x7f)) - *(double *)(param_1 + 0x86);
      local_2c = local_2c + -1;
      if (local_2c < 1) {
        return;
      }
    }
  } while( true );
}

