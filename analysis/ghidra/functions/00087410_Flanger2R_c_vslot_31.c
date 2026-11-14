/* 00087410 Flanger2R_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Flanger2R_c_vslot_31(int param_1)

{
  int iVar1;
  uint uVar2;
  longdouble lVar3;
  float fVar4;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if ((iVar1 != 0) && (*(char *)(param_1 + 0x15c) != '\0')) {
    uVar2 = *(uint *)(iVar1 + 0xec);
    *(uint *)(param_1 + 0x220) = uVar2;
    if (*(char *)(iVar1 + 0x16c) != '\0') {
      *(uint *)(param_1 + 0x220) = uVar2 ^ 0x80000000;
    }
    *(float *)(param_1 + 0x224) = *(float *)(iVar1 + 0x1cc) * 0.001;
    fVar4 = *(float *)(iVar1 + 0x23c);
    *(float *)(param_1 + 0x228) = fVar4;
    if (*(char *)(iVar1 + 700) == '\0') {
      *(float *)(param_1 + 0x228) = fVar4 * 0.975;
    }
    else {
      *(float *)(param_1 + 0x228) = -fVar4;
    }
    *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(iVar1 + 0x31c);
    *(undefined4 *)(param_1 + 0x230) = *(undefined4 *)(iVar1 + 0x46c);
    *(undefined4 *)(param_1 + 0x234) = *(undefined4 *)(iVar1 + 0x4dc);
    *(float *)(param_1 + 0x238) = *(float *)(param_1 + 0x224) * *(float *)(param_1 + 0x140);
    if (*(int *)(iVar1 + 0x414) < *(int *)(iVar1 + 0x3f8)) {
      lVar3 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar1 + 0x3f8));
      fVar4 = (float)lVar3;
    }
    else {
      fVar4 = *(float *)(iVar1 + 0x38c);
    }
    *(float *)(param_1 + 0x218) = fVar4 * *(float *)(param_1 + 0x144) * 8.0;
  }
  return;
}

