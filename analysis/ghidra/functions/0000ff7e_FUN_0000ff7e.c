/* 0000ff7e FUN_0000ff7e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000ff7e(int param_1)

{
  float fVar1;
  int iVar2;
  char cVar3;
  longdouble lVar4;
  double dVar5;
  float fVar6;
  float local_40;
  
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x44) < *(int *)(param_1 + 0x48)) {
    fVar6 = (float)*(int *)(param_1 + 0x44);
    local_40 = (float)*(int *)(param_1 + 0x5c);
    *(float *)(param_1 + 0x14) = (local_40 - fVar6) / ((float)*(int *)(param_1 + 0x48) - fVar6);
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    local_40 = (float)*(int *)(param_1 + 0x5c);
  }
  fVar6 = *(float *)(param_1 + 0x38);
  dVar5 = (double)fVar6;
  if ((0.01 < dVar5) || ((dVar5 < -0.01 && (!NAN(dVar5))))) {
    fVar1 = *(float *)(param_1 + 0x14);
    lVar4 = (longdouble)_exp(dVar5);
    lVar4 = (longdouble)_log(((double)lVar4 * (double)fVar1 - (double)fVar1) + 1.0);
    *(float *)(param_1 + 0x14) = (float)lVar4 / fVar6;
  }
  lVar4 = (longdouble)FUN_000152c0(local_40,(float)*(int *)(param_1 + 100));
  fVar6 = (float)lVar4;
  *(float *)(param_1 + 0xc) = fVar6;
  if ((1024.0 <= fVar6) || (NAN(fVar6))) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    iVar2 = *(int *)(param_1 + 4);
  }
  else {
    lVar4 = (longdouble)_pow(0xa0000000,0x3ff0f38f,(double)fVar6);
    *(float *)(param_1 + 0x10) = (float)lVar4;
    iVar2 = *(int *)(param_1 + 4);
  }
  if ((iVar2 == 5) &&
     ((*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x44) ||
      (cVar3 = FUN_0002d6ea(param_1 + 0x68,1), cVar3 == '\0')))) {
    lVar4 = (longdouble)_pow(0x40000000,0x3ff05fbd,(double)*(int *)(param_1 + 0x5c));
    *(float *)(param_1 + 0x18) = (float)lVar4;
    *(bool *)(param_1 + 0x1c) = *(int *)(param_1 + 0x5c) != 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(bool *)(param_1 + 0x1c) = *(int *)(param_1 + 0x5c) != 0;
  return;
}

