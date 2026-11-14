/* 0006df90 FUN_0006df90 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006df90(int *param_1,uint param_2,float param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
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
    iVar4 = param_2 + 1;
    do {
      iVar1 = param_2 - local_24;
      uVar2 = local_24 & 7;
      local_24 = local_24 + 1;
      if (uVar2 == 0) {
        iVar3 = (int)(float)param_1[0x284];
        fVar7 = (float)param_1[0x284] - (float)iVar3;
        fVar7 = ((1.0 - fVar7) * (float)param_1[iVar3 + 0x82] +
                fVar7 * (float)param_1[(iVar3 + 1U & 0x1ff) + 0x82]) * (float)param_1[0x28d];
        fVar13 = (float)(param_1[0x81] + 8) - (fVar7 + 1.0) * (float)param_1[0x28a];
        fVar7 = (float)(param_1[0x81] + 8) - (float)param_1[0x28a] * (1.0 - fVar7);
        if ((char)param_1[0x80] != '\0') {
          *(double *)(param_1 + 0x78) = (double)fVar13 - 8.0;
          *(double *)(param_1 + 0x7a) = (double)fVar7 - 8.0;
          *(undefined1 *)(param_1 + 0x80) = 0;
        }
        dVar9 = (((double)fVar13 - *(double *)(param_1 + 0x78)) * 0.125 - 1.0) * 0.0015 + 1.0;
        dVar12 = 0.25;
        dVar11 = dVar12;
        if ((0.25 <= dVar9) && (dVar11 = 4.0, dVar9 <= 4.0)) {
          dVar11 = dVar9;
        }
        *(double *)(param_1 + 0x7c) = dVar11;
        dVar11 = (((double)fVar7 - *(double *)(param_1 + 0x7a)) * 0.125 - 1.0) * 0.0015 + 1.0;
        if ((0.25 <= dVar11) && (dVar12 = 4.0, dVar11 <= 4.0)) {
          dVar12 = dVar11;
        }
        *(double *)(param_1 + 0x7e) = dVar12;
        fVar7 = (float)param_1[0x284] + (float)param_1[0x28c];
        param_1[0x284] = (int)fVar7;
        if (iVar4 + -2 < 7) {
          iVar4 = 7 - (iVar4 + -2);
        }
        else {
          iVar4 = 0;
        }
        iVar4 = iVar4 + param_1[0x4f];
        param_1[0x4f] = iVar4;
        if (8 < iVar4) {
          fVar7 = fVar7 - (float)param_1[0x28c];
          param_1[0x284] = (int)fVar7;
          param_1[0x4f] = iVar4 + -8;
        }
        if (512.0 <= fVar7) {
          param_1[0x284] = (int)(fVar7 - 512.0);
        }
      }
      uVar5 = (uint)*(double *)(param_1 + 0x78);
      fVar13 = (float)(*(double *)(param_1 + 0x78) - (double)(int)uVar5);
      uVar6 = (uint)*(double *)(param_1 + 0x7a);
      fVar7 = (float)(*(double *)(param_1 + 0x7a) - (double)(int)uVar6);
      iVar4 = param_1[0x291];
      uVar2 = param_1[0x293];
      fVar10 = (1.0 - fVar13) * *(float *)(iVar4 + (uVar5 & uVar2) * 4) +
               fVar13 * *(float *)(iVar4 + (uVar5 + 1 & uVar2) * 4);
      fVar8 = (1.0 - fVar7) * *(float *)(iVar4 + (uVar6 & uVar2) * 4) +
              fVar7 * *(float *)(iVar4 + (uVar2 & uVar6 + 1) * 4);
      fVar7 = *(float *)param_1[0x287];
      param_1[0x287] = (int)((float *)param_1[0x287] + 1);
      fVar13 = *(float *)param_1[0x288];
      param_1[0x288] = (int)((float *)param_1[0x288] + 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1 + 0x285,fVar10 * (float)param_1[0x28e] + fVar7)
      ;
      (**(code **)(*param_1 + 0xcc))(param_1,param_1 + 0x286,fVar8 * (float)param_1[0x28e] + fVar13)
      ;
      fVar7 = ((fVar7 + fVar13) * 0.5 + (fVar10 + fVar8) * (float)param_1[0x28f]) -
              (float)param_1[0x283];
      param_1[0x283] = (int)((float)param_1[0x283] + param_3 * fVar7);
      if ((-1.0 <= fVar7) || (NAN(fVar7))) {
        fVar13 = 1.0;
        if (fVar7 <= 1.0) {
          fVar13 = fVar7;
        }
      }
      else {
        fVar13 = -1.0;
      }
      uVar2 = param_1[0x81];
      *(float *)(param_1[0x291] + (uVar2 & param_1[0x293]) * 4) = fVar13;
      param_1[0x81] = uVar2 + 1;
      *(double *)(param_1 + 0x78) = *(double *)(param_1 + 0x78) + *(double *)(param_1 + 0x7c);
      *(double *)(param_1 + 0x7a) = *(double *)(param_1 + 0x7a) + *(double *)(param_1 + 0x7e);
      iVar4 = iVar1;
    } while (local_24 != param_2);
  }
  return;
}

