/* 0003225a FUN_0003225a */

void FUN_0003225a(undefined4 param_1,int param_2,int param_3)

{
  float *pfVar1;
  int iVar2;
  double dVar3;
  
  if (-1 < param_3 + -1) {
    pfVar1 = (float *)(param_2 + (param_3 + -1) * 4);
    dVar3 = 0.0;
    iVar2 = 0;
    do {
      dVar3 = dVar3 + (double)*pfVar1;
      iVar2 = iVar2 + 1;
      pfVar1 = pfVar1 + -1;
    } while (iVar2 != param_3);
    FUN_0003207a(param_1,param_2,param_3,dVar3);
    return;
  }
  FUN_0003207a(param_1,param_2,param_3,0);
  return;
}

