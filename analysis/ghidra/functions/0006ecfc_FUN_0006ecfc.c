/* 0006ecfc FUN_0006ecfc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006ecfc(int *param_1,uint param_2,float param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  double dVar8;
  float fVar9;
  double dVar10;
  double dVar11;
  float fVar12;
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
        fVar7 = (float)param_1[0x284] - (float)iVar4;
        fVar7 = ((1.0 - fVar7) * (float)param_1[iVar4 + 0x82] +
                fVar7 * (float)param_1[(iVar4 + 1U & 0x1ff) + 0x82]) * (float)param_1[0x28d];
        fVar12 = (float)(param_1[0x81] + 8) - (fVar7 + 1.0) * (float)param_1[0x28a];
        fVar7 = (float)(param_1[0x81] + 8) - (float)param_1[0x28a] * (1.0 - fVar7);
        if ((char)param_1[0x80] != '\0') {
          *(double *)(param_1 + 0x78) = (double)fVar12 - 8.0;
          *(double *)(param_1 + 0x7a) = (double)fVar7 - 8.0;
          *(undefined1 *)(param_1 + 0x80) = 0;
        }
        dVar8 = (((double)fVar12 - *(double *)(param_1 + 0x78)) * 0.125 - 1.0) * 0.0015 + 1.0;
        dVar11 = 0.25;
        dVar10 = dVar11;
        if ((0.25 <= dVar8) && (dVar10 = 4.0, dVar8 <= 4.0)) {
          dVar10 = dVar8;
        }
        *(double *)(param_1 + 0x7c) = dVar10;
        dVar10 = (((double)fVar7 - *(double *)(param_1 + 0x7a)) * 0.125 - 1.0) * 0.0015 + 1.0;
        if ((0.25 <= dVar10) && (dVar11 = 4.0, dVar10 <= 4.0)) {
          dVar11 = dVar10;
        }
        *(double *)(param_1 + 0x7e) = dVar11;
        fVar7 = (float)param_1[0x284] + (float)param_1[0x28c];
        param_1[0x284] = (int)fVar7;
        if (iVar1 + -2 < 7) {
          iVar1 = 7 - (iVar1 + -2);
        }
        else {
          iVar1 = 0;
        }
        iVar1 = iVar1 + param_1[0x4f];
        param_1[0x4f] = iVar1;
        if (8 < iVar1) {
          fVar7 = fVar7 - (float)param_1[0x28c];
          param_1[0x284] = (int)fVar7;
          param_1[0x4f] = iVar1 + -8;
        }
        if (512.0 <= fVar7) {
          param_1[0x284] = (int)(fVar7 - 512.0);
        }
      }
      uVar5 = (uint)*(double *)(param_1 + 0x78);
      fVar12 = (float)(*(double *)(param_1 + 0x78) - (double)(int)uVar5);
      uVar6 = (uint)*(double *)(param_1 + 0x7a);
      fVar7 = (float)(*(double *)(param_1 + 0x7a) - (double)(int)uVar6);
      iVar1 = param_1[0x291];
      uVar3 = param_1[0x293];
      fVar9 = (1.0 - fVar12) * *(float *)(iVar1 + (uVar5 & uVar3) * 4) +
              fVar12 * *(float *)(iVar1 + (uVar5 + 1 & uVar3) * 4);
      fVar12 = fVar7 * *(float *)(iVar1 + (uVar3 & uVar6 + 1) * 4) +
               (1.0 - fVar7) * *(float *)(iVar1 + (uVar6 & uVar3) * 4);
      fVar7 = *(float *)param_1[0x287];
      param_1[0x287] = (int)((float *)param_1[0x287] + 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1 + 0x285,fVar9 * (float)param_1[0x28e] + fVar7);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1 + 0x286,fVar12 * (float)param_1[0x28e] + fVar7)
      ;
      fVar7 = ((fVar9 + fVar12) * (float)param_1[0x28f] + fVar7) - (float)param_1[0x283];
      param_1[0x283] = (int)((float)param_1[0x283] + fVar7 * 0.0001);
      fVar7 = (fVar7 - (float)param_1[0x282]) * param_3 + (float)param_1[0x282];
      param_1[0x282] = (int)fVar7;
      uVar3 = param_1[0x81];
      *(float *)(param_1[0x291] + (uVar3 & param_1[0x293]) * 4) = fVar7;
      param_1[0x81] = uVar3 + 1;
      *(double *)(param_1 + 0x78) = *(double *)(param_1 + 0x78) + *(double *)(param_1 + 0x7c);
      *(double *)(param_1 + 0x7a) = *(double *)(param_1 + 0x7a) + *(double *)(param_1 + 0x7e);
      iVar1 = iVar2;
    } while (local_24 != param_2);
  }
  return;
}

