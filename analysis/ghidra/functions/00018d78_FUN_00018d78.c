/* 00018d78 FUN_00018d78 */

void FUN_00018d78(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0002f86e(param_1 + 0xe33,param_2);
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    if (*(int *)(iVar2 + 8) != 0) {
      Envelope_c_vslot_9(param_1 + 0x169,iVar1,6,*(undefined4 *)(*(int *)(iVar2 + 8) + 0x14c));
      if ((-1 < param_1[0xed5]) && (-1 < param_1[0xed9])) {
        (**(code **)(*param_1 + 0x34c))(param_1,param_1[0xed5] + iVar1 * param_1[0xed9],0);
      }
    }
  }
  return;
}

