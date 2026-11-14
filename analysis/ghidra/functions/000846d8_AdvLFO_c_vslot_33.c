/* 000846d8 AdvLFO_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AdvLFO_c_vslot_33(int param_1,undefined4 param_2,int param_3,undefined1 param_4,
                      undefined1 param_5)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined *local_4c;
  undefined1 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (**(int **)(param_1 + 0x1dc) <= *(int *)(param_1 + 0xd3c)) {
    iVar2 = *(int *)(param_1 + 0xd3c) - **(int **)(param_1 + 0x1dc);
    *(float *)(param_1 + 0xd28) =
         (float)iVar2 * *(float *)(param_1 + 0xd2c) + *(float *)(param_1 + 0xd28);
    *(float *)(param_1 + 0xd34) =
         (float)iVar2 * *(float *)(param_1 + 0xd38) + *(float *)(param_1 + 0xd34);
    *(int *)(param_1 + 0xd24) = *(int *)(param_1 + 0xd24) - iVar2;
    *(int *)(param_1 + 0xd30) = *(int *)(param_1 + 0xd30) - iVar2;
  }
  local_4c = PTR_DAT_00103808 + 8;
  local_48 = *(undefined1 *)(param_3 + 4);
  local_44 = *(undefined4 *)(param_3 + 8);
  local_40 = *(undefined4 *)(param_3 + 0xc);
  Modulator_c_vslot_33(param_1,param_2,&local_4c,param_4,param_5);
  local_2c = PTR_DAT_00103808 + 8;
  if (*(int *)(param_1 + 0x124) == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x3e0) = *(undefined4 *)(param_1 + 0x1e4);
  local_38 = *(undefined1 *)(param_3 + 4);
  local_34 = *(undefined4 *)(param_3 + 8);
  local_30 = *(undefined4 *)(param_3 + 0xc);
  local_4c = local_2c;
  local_3c = local_2c;
  LFOSimp_c_vslot_33(param_1 + 0x1fc,param_2,&local_3c,param_4,param_5);
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  local_3c = local_2c;
  EnvDAD_c_vslot_33(param_1 + 0x9a0,param_2,&local_2c,param_4,param_5);
  local_2c = PTR_DAT_00103808 + 8;
  if (1 < *(int *)(*(int *)(param_1 + 0x124) + 0xe8) - 4U) {
    LFOSimp_c_vslot_59(param_1 + 0x1fc,(double)*(float *)(*(int *)(param_1 + 0x124) + 0x4dc));
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
  }
  else {
    **(float **)(param_1 + 0x1d8) = (fVar1 * fVar3 - **(float **)(param_1 + 0x1d4)) / fVar5;
  }
  *(undefined4 *)(param_1 + 0xd3c) = **(undefined4 **)(param_1 + 0x1dc);
  return;
}

