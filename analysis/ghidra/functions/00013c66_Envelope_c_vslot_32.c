/* 00013c66 Envelope_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_32(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  *(undefined4 *)(param_1 + 0x124) = 0;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1f < param_2) {
    param_2 = 0x1f;
  }
  (**(code **)(*param_3 + 0x20))(param_3);
  if (*(int *)(param_1 + 0x120) != 0) {
    *(int *)(param_1 + 0x128) = param_2;
    *(char *)(param_1 + 0x130) = (char)param_3[1];
    *(int *)(param_1 + 0x134) = param_3[2];
    *(int *)(param_1 + 0x138) = param_3[3];
    *(float *)(param_1 + 0x160) = (float)(param_3[2] - *(int *)(param_1 + 0x158)) * 0.010416667;
    fVar4 = (float)param_3[3] * 0.031496 - 2.0;
    fVar4 = fVar4 * fVar4 * fVar4 * 0.00083790737 + fVar4 * fVar4 * 0.01550458 + fVar4 * 0.17380469
            + 1.0;
    *(float *)(param_1 + 0x164) = fVar4 * fVar4 * fVar4 * fVar4;
    uVar1 = FUN_00011b72(*(undefined4 *)(param_1 + 0x120),param_2);
    *(undefined4 *)(param_1 + 0x124) = uVar1;
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x18 + param_2 * 8);
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x1c + param_2 * 8);
    iVar3 = 0x10;
    iVar2 = param_1;
    do {
      *(undefined4 *)(iVar2 + 0x174) = 0;
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined1 *)(param_1 + 0x15d) = 1;
  }
  return;
}

