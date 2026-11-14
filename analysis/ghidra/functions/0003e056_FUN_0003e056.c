/* 0003e056 FUN_0003e056 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003e056(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  longdouble lVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  
  piVar3 = *(int **)(param_1 + 0x1dc);
  *(int *)(param_1 + 0x794) = *piVar3;
  *(undefined4 *)(param_1 + 0x798) = **(undefined4 **)(param_1 + 0x1d4);
  fVar6 = **(float **)(param_1 + 0x1d8);
  *(float *)(param_1 + 0x79c) = fVar6;
  if (param_2 != *(float *)(param_1 + 0x1e4)) {
    dVar5 = (double)(*(float *)(param_1 + 0x1e4) - param_2);
    lVar4 = (longdouble)_pow(0,0x40000000,dVar5 + dVar5);
    fVar6 = fVar6 * (float)*(int *)(param_1 + 0x794) + *(float *)(param_1 + 0x798);
    if ((-1.0 <= fVar6) || (NAN(fVar6))) {
      fVar7 = 1.0;
      if (fVar6 <= 1.0) {
        fVar7 = fVar6;
      }
    }
    else {
      fVar7 = -1.0;
    }
    iVar2 = (int)((float)lVar4 * (float)*(int *)(param_1 + 0x794) + 0.5);
    iVar1 = 1;
    if (0 < iVar2) {
      iVar1 = iVar2;
    }
    *(int *)(param_1 + 0x794) = iVar1;
    *(float *)(param_1 + 0x79c) = (fVar7 - *(float *)(param_1 + 0x798)) / (float)iVar1;
    *(float *)(param_1 + 0x1e4) = param_2;
    *piVar3 = iVar1;
    **(undefined4 **)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x798);
    **(undefined4 **)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x79c);
    piVar3 = *(int **)(param_1 + 0x1dc);
  }
  *piVar3 = *(int *)(param_1 + 0x794);
  **(undefined4 **)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x798);
  **(undefined4 **)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x79c);
  return;
}

