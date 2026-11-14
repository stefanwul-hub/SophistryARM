/* 0008de6a FUN_0008de6a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008de6a(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  int local_34;
  int local_30;
  
  iVar1 = param_1 + param_2 * 0x274 + 0x1d8;
  lVar6 = (longdouble)_pow(0,0x40000000,(double)param_3 / 12.0);
  lVar6 = (longdouble)
          FUN_000152c0((float)*(int *)(iVar1 + 0x210),(float)((double)lVar6 * 8.175798915643707));
  iVar2 = (param_5 - param_4) + 1;
  if (iVar2 < 0x400) {
    iVar2 = *(int *)(iVar1 + 0x22c);
    if (iVar2 < 0x400) {
      return;
    }
    param_5 = param_4 + 0x3ff;
    if (iVar2 <= param_5) {
      iVar2 = (param_5 - iVar2) + 1;
      param_5 = param_5 - iVar2;
      param_4 = param_4 - iVar2;
    }
    fVar7 = 1024.0;
    local_34 = param_4;
  }
  else {
    fVar7 = (float)iVar2;
    local_34 = param_4;
  }
  fVar8 = fVar7;
  if ((float)lVar6 <= fVar7) {
    fVar8 = (float)lVar6;
  }
  lVar6 = (longdouble)FUN_000152c0(fVar7,fVar8);
  param_5 = param_5 - (int)(fVar8 + 0.5);
  local_30 = 0;
  do {
    fVar7 = (float)local_30 * (float)((int)lVar6 + -1) * 0.015625;
    iVar3 = (int)fVar7;
    fVar7 = fVar7 - (float)iVar3;
    iVar2 = (int)((float)(iVar3 + 1) * fVar8) + local_34;
    if (param_5 < iVar2) {
      iVar2 = param_5;
    }
    iVar5 = local_30 * 0x200;
    FUN_0008d9dc(param_1,*(int *)(iVar1 + 0x21c) + ((int)((float)iVar3 * fVar8) + local_34) * 4,
                 (int)fVar8,1.0 - fVar7,*(int *)(iVar1 + 0x21c) + iVar2 * 4,(int)fVar8,fVar7,
                 *(int *)(param_1 + 0x1d4 + param_2 * 4) + iVar5,0x80);
    pfVar4 = (float *)(iVar5 + *(int *)(param_1 + 0x1d4 + param_2 * 4));
    *pfVar4 = *pfVar4 * 0.0;
    pfVar4[1] = pfVar4[1] * 0.15;
    pfVar4[2] = pfVar4[2] * 0.3;
    pfVar4[3] = pfVar4[3] * 0.43;
    pfVar4[4] = pfVar4[4] * 0.56;
    pfVar4[5] = pfVar4[5] * 0.68;
    pfVar4[6] = pfVar4[6] * 0.78;
    pfVar4[7] = pfVar4[7] * 0.87;
    pfVar4[8] = pfVar4[8] * 0.93;
    pfVar4[9] = pfVar4[9] * 0.98;
    pfVar4[0x7f] = pfVar4[0x7f] * 0.15;
    pfVar4[0x7e] = pfVar4[0x7e] * 0.3;
    pfVar4[0x7d] = pfVar4[0x7d] * 0.43;
    pfVar4[0x7c] = pfVar4[0x7c] * 0.56;
    pfVar4[0x7b] = pfVar4[0x7b] * 0.68;
    pfVar4[0x7a] = pfVar4[0x7a] * 0.78;
    pfVar4[0x79] = pfVar4[0x79] * 0.87;
    pfVar4[0x78] = pfVar4[0x78] * 0.93;
    pfVar4[0x77] = pfVar4[0x77] * 0.98;
    FUN_00032430(iVar1,iVar5 + *(int *)(param_1 + 0x1d4 + param_2 * 4));
    local_30 = local_30 + 1;
  } while (local_30 != 0x40);
  lVar6 = (longdouble)FUN_000152c0((float)*(int *)(iVar1 + 0x22c),(float)*(int *)(iVar1 + 0x210));
  *(float *)(param_1 + 0x44c + param_2 * 4) = (float)lVar6;
  return;
}

