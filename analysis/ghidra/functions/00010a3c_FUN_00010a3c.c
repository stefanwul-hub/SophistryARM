/* 00010a3c FUN_00010a3c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_00010a3c(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  double dVar4;
  float fVar5;
  
  iVar2 = *(int *)(param_1 + 0x24);
  if (iVar2 < *(int *)(param_1 + 0x28)) {
    fVar5 = (float)(*(int *)(param_1 + 0x2c) - iVar2) / (float)(*(int *)(param_1 + 0x28) - iVar2);
  }
  else {
    fVar5 = 0.5;
  }
  fVar1 = *(float *)(param_1 + 0x38);
  dVar4 = (double)fVar1;
  if ((0.01 < dVar4) || ((dVar4 < -0.01 && (!NAN(dVar4))))) {
    lVar3 = (longdouble)_exp(dVar4);
    lVar3 = (longdouble)_log(((double)lVar3 * (double)fVar5 - (double)fVar5) + 1.0);
    fVar5 = (float)lVar3 / fVar1;
  }
  return (longdouble)fVar5;
}

