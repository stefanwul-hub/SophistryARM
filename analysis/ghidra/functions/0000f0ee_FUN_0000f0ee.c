/* 0000f0ee FUN_0000f0ee */

undefined4 FUN_0000f0ee(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x37c) + 1;
  *(int *)(param_1 + 0x37c) = iVar1;
  if (iVar1 < *(int *)(param_1 + 0x380)) {
    *param_2 = *(undefined4 *)(param_1 + 0x200 + iVar1 * 0xc);
    *param_3 = *(undefined4 *)(param_1 + 0x204 + *(int *)(param_1 + 0x37c) * 0xc);
    return 1;
  }
  *param_2 = 0;
  *param_3 = 0;
  return 0;
}

