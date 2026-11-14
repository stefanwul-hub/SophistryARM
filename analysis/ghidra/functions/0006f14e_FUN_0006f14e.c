/* 0006f14e FUN_0006f14e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006f14e(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  float fVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  uint local_24;
  
  if (0 < (int)param_2) {
    local_24 = 0;
    iVar1 = param_2 + 1;
    do {
      iVar2 = param_2 - local_24;
      uVar3 = local_24 & 7;
      local_24 = local_24 + 1;
      if (uVar3 == 0) {
        iVar4 = (int)(float)param_1[0x284];
        fVar8 = (float)param_1[0x284] - (float)iVar4;
        fVar8 = ((1.0 - fVar8) * (float)param_1[iVar4 + 0x82] +
                fVar8 * (float)param_1[(iVar4 + 1U & 0x1ff) + 0x82]) * (float)param_1[0x28d];
        fVar13 = (float)(param_1[0x81] + 8) - (fVar8 + 1.0) * (float)param_1[0x28a];
        fVar8 = (float)(param_1[0x81] + 8) - (float)param_1[0x28a] * (1.0 - fVar8);
        if ((char)param_1[0x80] != '\0') {
          *(double *)(param_1 + 0x78) = (double)fVar13 - 8.0;
          *(double *)(param_1 + 0x7a) = (double)fVar8 - 8.0;
          *(undefined1 *)(param_1 + 0x80) = 0;
        }
        dVar9 = (((double)fVar13 - *(double *)(param_1 + 0x78)) * 0.125 - 1.0) * 0.0015 + 1.0;
        dVar12 = 0.25;
        dVar11 = dVar12;
        if ((0.25 <= dVar9) && (dVar11 = 4.0, dVar9 <= 4.0)) {
          dVar11 = dVar9;
        }
        *(double *)(param_1 + 0x7c) = dVar11;
        dVar11 = (((double)fVar8 - *(double *)(param_1 + 0x7a)) * 0.125 - 1.0) * 0.0015 + 1.0;
        if ((0.25 <= dVar11) && (dVar12 = 4.0, dVar11 <= 4.0)) {
          dVar12 = dVar11;
        }
        *(double *)(param_1 + 0x7e) = dVar12;
        fVar8 = (float)param_1[0x284] + (float)param_1[0x28c];
        param_1[0x284] = (int)fVar8;
        if (iVar1 + -2 < 7) {
          iVar1 = 7 - (iVar1 + -2);
        }
        else {
          iVar1 = 0;
        }
        iVar1 = iVar1 + param_1[0x4f];
        param_1[0x4f] = iVar1;
        if (8 < iVar1) {
          fVar8 = fVar8 - (float)param_1[0x28c];
          param_1[0x284] = (int)fVar8;
          param_1[0x4f] = iVar1 + -8;
        }
        if (512.0 <= fVar8) {
          param_1[0x284] = (int)(fVar8 - 512.0);
        }
      }
      uVar5 = (uint)*(double *)(param_1 + 0x78);
      fVar13 = (float)(*(double *)(param_1 + 0x78) - (double)(int)uVar5);
      uVar6 = (uint)*(double *)(param_1 + 0x7a);
      fVar8 = (float)(*(double *)(param_1 + 0x7a) - (double)(int)uVar6);
      iVar1 = param_1[0x291];
      uVar3 = param_1[0x293];
      fVar10 = (1.0 - fVar13) * *(float *)(iVar1 + (uVar5 & uVar3) * 4) +
               fVar13 * *(float *)(iVar1 + (uVar5 + 1 & uVar3) * 4);
      fVar7 = fVar8 * *(float *)(iVar1 + (uVar3 & uVar6 + 1) * 4) +
              (1.0 - fVar8) * *(float *)(iVar1 + (uVar6 & uVar3) * 4);
      fVar8 = *(float *)param_1[0x287];
      param_1[0x287] = (int)((float *)param_1[0x287] + 1);
      fVar13 = *(float *)param_1[0x288];
      param_1[0x288] = (int)((float *)param_1[0x288] + 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1 + 0x285,fVar10 * (float)param_1[0x28e] + fVar8)
      ;
      (**(code **)(*param_1 + 0xcc))(param_1,param_1 + 0x286,fVar7 * (float)param_1[0x28e] + fVar13)
      ;
      uVar3 = param_1[0x81];
      *(float *)(param_1[0x291] + (uVar3 & param_1[0x293]) * 4) =
           (fVar8 + fVar13) * 0.5 + (fVar10 + fVar7) * (float)param_1[0x28f];
      param_1[0x81] = uVar3 + 1;
      *(double *)(param_1 + 0x78) = *(double *)(param_1 + 0x78) + *(double *)(param_1 + 0x7c);
      *(double *)(param_1 + 0x7a) = *(double *)(param_1 + 0x7a) + *(double *)(param_1 + 0x7e);
      iVar1 = iVar2;
    } while (local_24 != param_2);
  }
  return;
}

