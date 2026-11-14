/* 000108b4 FUN_000108b4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000108b4(int param_1,float param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  float fVar4;
  double dVar5;
  
  if ((0.0 <= param_2) || (NAN(param_2))) {
    fVar4 = 1.0;
    if (param_2 <= 1.0) {
      fVar4 = param_2;
    }
  }
  else {
    fVar4 = 0.0;
  }
  dVar5 = (double)*(float *)(param_1 + 0x38);
  if ((0.01 < dVar5) || (dVar5 < -0.01)) {
    lVar2 = (longdouble)_exp((double)fVar4 * dVar5);
    lVar3 = (longdouble)_exp(dVar5);
    fVar4 = (float)(((double)lVar2 - 1.0) / ((double)lVar3 - 1.0));
  }
  iVar1 = *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x5c) = iVar1;
  if (iVar1 < *(int *)(param_1 + 0x48)) {
    fVar4 = ((float)*(int *)(param_1 + 0x48) - (float)iVar1) * fVar4 + 0.1 + (float)iVar1;
    if (fVar4 < 0.0) {
      fVar4 = fVar4 - 0.2;
    }
    *(int *)(param_1 + 0x5c) = (int)fVar4;
  }
  FUN_0000ff7e();
  return;
}

