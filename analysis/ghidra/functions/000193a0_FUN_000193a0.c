/* 000193a0 FUN_000193a0 */

void FUN_000193a0(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x92c4);
  if (iVar1 < 0x100) {
    *(undefined4 *)(param_1 + 0x8ac4 + iVar1 * 8) = param_2;
    *(undefined4 *)(param_1 + 0x8ac8 + *(int *)(param_1 + 0x92c4) * 8) = param_3;
    iVar1 = *(int *)(param_1 + 0x92c4) + 1;
    *(int *)(param_1 + 0x92c4) = iVar1;
  }
  if ((param_4 != '\0') && (iVar1 < 0x100)) {
    *(undefined4 *)(param_1 + 0x8ac4 + iVar1 * 8) = param_3;
    *(undefined4 *)(param_1 + 0x8ac8 + *(int *)(param_1 + 0x92c4) * 8) = param_2;
    *(int *)(param_1 + 0x92c4) = *(int *)(param_1 + 0x92c4) + 1;
  }
  return;
}

