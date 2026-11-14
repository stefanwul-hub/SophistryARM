/* 00084ad8 AdvLFO_c_vslot_57 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AdvLFO_c_vslot_57(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if (**(int **)(param_1 + 0x1dc) <= *(int *)(param_1 + 0xd3c)) {
    iVar2 = *(int *)(param_1 + 0xd3c) - **(int **)(param_1 + 0x1dc);
    *(float *)(param_1 + 0xd28) =
         (float)iVar2 * *(float *)(param_1 + 0xd2c) + *(float *)(param_1 + 0xd28);
    *(float *)(param_1 + 0xd34) =
         (float)iVar2 * *(float *)(param_1 + 0xd38) + *(float *)(param_1 + 0xd34);
    *(int *)(param_1 + 0xd24) = *(int *)(param_1 + 0xd24) - iVar2;
    *(int *)(param_1 + 0xd30) = *(int *)(param_1 + 0xd30) - iVar2;
  }
  if (*(int *)(param_1 + 0xd24) == 0) {
    *(undefined4 *)(param_1 + 0x3e0) = *(undefined4 *)(param_1 + 0x1e4);
    LFOSimp_c_vslot_57(param_1 + 0x1fc);
    iVar2 = *(int *)(param_1 + 0xd30);
  }
  else {
    iVar2 = *(int *)(param_1 + 0xd30);
  }
  if (iVar2 == 0) {
    EnvDAD_c_vslot_57(param_1 + 0x9a0);
  }
  iVar2 = *(int *)(param_1 + 0xd30);
  if (*(int *)(param_1 + 0xd24) < *(int *)(param_1 + 0xd30)) {
    iVar2 = *(int *)(param_1 + 0xd24);
  }
  **(int **)(param_1 + 0x1dc) = iVar2;
  **(float **)(param_1 + 0x1d4) = *(float *)(param_1 + 0xd28) * *(float *)(param_1 + 0xd34);
  fVar5 = (float)**(int **)(param_1 + 0x1dc);
  fVar3 = fVar5 * *(float *)(param_1 + 0xd2c) + *(float *)(param_1 + 0xd28);
  fVar4 = fVar5 * *(float *)(param_1 + 0xd38) + *(float *)(param_1 + 0xd34);
  if ((-1.0 <= fVar3) || (NAN(fVar3))) {
    fVar1 = 1.0;
    if (fVar3 <= 1.0) {
      fVar1 = fVar3;
    }
  }
  else {
    fVar1 = -1.0;
  }
  if ((0.0 <= fVar4) || (NAN(fVar4))) {
    fVar3 = 1.0;
    if (fVar4 <= 1.0) {
      fVar3 = fVar4;
    }
  }
  else {
    fVar3 = 0.0;
  }
  if (**(int **)(param_1 + 0x1dc) == 0) {
    **(undefined4 **)(param_1 + 0x1d8) = 0;
    *(undefined4 *)(param_1 + 0xd3c) = **(undefined4 **)(param_1 + 0x1dc);
    return;
  }
  **(float **)(param_1 + 0x1d8) = (fVar1 * fVar3 - **(float **)(param_1 + 0x1d4)) / fVar5;
  *(undefined4 *)(param_1 + 0xd3c) = **(undefined4 **)(param_1 + 0x1dc);
  return;
}

