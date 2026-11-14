/* 0008f9a8 Phaser1SR_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Phaser1SR_c_vslot_31(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x124);
  if ((iVar2 != 0) && (*(char *)(param_1 + 0x15c) != '\0')) {
    *(undefined4 *)(param_1 + 0xa08) = *(undefined4 *)(iVar2 + 0x388);
    *(undefined4 *)(param_1 + 0xa0c) = *(undefined4 *)(iVar2 + 0x3fc);
    fVar1 = *(float *)(iVar2 + 0xec);
    *(float *)(param_1 + 0xa10) = fVar1;
    *(float *)(param_1 + 0xa14) = (2.0 - fVar1) * DAT_000fd450;
    *(undefined4 *)(param_1 + 0xa18) = *(undefined4 *)(iVar2 + 0x23c);
    *(undefined4 *)(param_1 + 0xa1c) = *(undefined4 *)(iVar2 + 0x1cc);
    fVar1 = 1.0 - *(float *)(iVar2 + 0x2ac);
    *(float *)(param_1 + 0xa20) = 1.0 - fVar1 * fVar1;
    if (*(char *)(iVar2 + 0x32c) == '\0') {
      uVar3 = 0x3f7f7cee;
    }
    else {
      uVar3 = 0xbf7f7cee;
    }
    *(undefined4 *)(param_1 + 0xa24) = uVar3;
  }
  return;
}

