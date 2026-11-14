/* 00084996 FUN_00084996 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00084996(int param_1,undefined8 param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  LFOSimp_c_vslot_59(param_1 + 0x1fc,param_2);
  *(float *)(param_1 + 0xd34) = 1.0;
  *(undefined4 *)(param_1 + 0xd38) = 0;
  *(undefined4 *)(param_1 + 0xd30) = 0x7ffffbff;
  iVar2 = *(int *)(param_1 + 0xd24);
  if (0x7ffffbfe < iVar2) {
    iVar2 = 0x7ffffbff;
  }
  **(int **)(param_1 + 0x1dc) = iVar2;
  **(float **)(param_1 + 0x1d4) = *(float *)(param_1 + 0xd28) * *(float *)(param_1 + 0xd34);
  fVar5 = (float)**(int **)(param_1 + 0x1dc);
  fVar4 = fVar5 * *(float *)(param_1 + 0xd2c) + *(float *)(param_1 + 0xd28);
  fVar3 = fVar5 * *(float *)(param_1 + 0xd38) + *(float *)(param_1 + 0xd34);
  if ((-1.0 <= fVar4) || (NAN(fVar4))) {
    fVar1 = 1.0;
    if (fVar4 <= 1.0) {
      fVar1 = fVar4;
    }
  }
  else {
    fVar1 = -1.0;
  }
  if (0.0 <= fVar3) {
    fVar4 = 1.0;
    if (fVar3 <= 1.0) {
      fVar4 = fVar3;
    }
  }
  else {
    fVar4 = 0.0;
  }
  if (**(int **)(param_1 + 0x1dc) == 0) {
    **(undefined4 **)(param_1 + 0x1d8) = 0;
    *(undefined4 *)(param_1 + 0xd3c) = **(undefined4 **)(param_1 + 0x1dc);
    return;
  }
  **(float **)(param_1 + 0x1d8) = (fVar1 * fVar4 - **(float **)(param_1 + 0x1d4)) / fVar5;
  *(undefined4 *)(param_1 + 0xd3c) = **(undefined4 **)(param_1 + 0x1dc);
  return;
}

