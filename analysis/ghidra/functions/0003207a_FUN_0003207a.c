/* 0003207a FUN_0003207a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003207a(undefined4 param_1,float *param_2,int param_3,double param_4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  float fVar6;
  float fVar7;
  int local_20;
  
  if (param_3 < 0x400) {
    if (param_3 < 0x100) {
      if (param_3 < 0x80) {
        fVar6 = 0.25;
      }
      else {
        fVar6 = 0.2;
      }
    }
    else {
      fVar6 = 0.1;
    }
  }
  else {
    fVar6 = 0.05;
  }
  if ((param_2 != (float *)0x0) && (0x28 < param_3)) {
    iVar4 = (int)(fVar6 * (float)param_3 + 0.5);
    if (iVar4 < 1) {
      iVar4 = 1;
      local_20 = 0;
    }
    else {
      local_20 = iVar4 + -1;
    }
    iVar2 = param_3 - iVar4;
    fVar7 = (float)(param_4 / (double)iVar2);
    lVar5 = (longdouble)FUN_000152c0(1.0,ABS(fVar7) + 1.0);
    fVar6 = (float)lVar5;
    if (iVar4 < 1) {
      iVar4 = 0;
    }
    else {
      iVar3 = 0;
      pfVar1 = param_2;
      do {
        *pfVar1 = (*pfVar1 - (float)iVar3 * (1.0 / (float)local_20) * fVar7) * fVar6;
        iVar3 = iVar3 + 1;
        pfVar1 = pfVar1 + 1;
      } while (iVar4 != iVar3);
    }
    if (iVar4 < iVar2) {
      pfVar1 = param_2 + iVar4;
      iVar3 = 0;
      do {
        *pfVar1 = (*pfVar1 - fVar7) * fVar6;
        iVar3 = iVar3 + 1;
        pfVar1 = pfVar1 + 1;
      } while (iVar3 != iVar2 - iVar4);
      iVar4 = iVar4 + iVar3;
    }
    if (iVar4 < param_3) {
      iVar2 = iVar4 - iVar2;
      param_2 = param_2 + iVar4;
      iVar3 = 0;
      do {
        *param_2 = (*param_2 - (1.0 - (float)iVar2 * (1.0 / (float)local_20)) * fVar7) * fVar6;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 1;
      } while (iVar3 != param_3 - iVar4);
    }
  }
  return;
}

