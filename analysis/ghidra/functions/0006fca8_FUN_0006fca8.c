/* 0006fca8 FUN_0006fca8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006fca8(int param_1,int param_2)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  double dVar4;
  
  lVar2 = (longdouble)FUN_000137fe(param_1,*(undefined4 *)(*(int *)(param_1 + 0x124) + 0x158));
  dVar4 = (double)(float)lVar2;
  lVar3 = (longdouble)_fmod((double)param_2,dVar4);
  fVar1 = (float)lVar3;
  if ((double)fVar1 < dVar4 * 0.5) {
    *(float *)(param_1 + 0x89c) = -fVar1;
    return;
  }
  *(float *)(param_1 + 0x89c) = (float)lVar2 - fVar1;
  return;
}

