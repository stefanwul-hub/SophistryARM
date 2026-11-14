/* 00012888 FUN_00012888 */

undefined4 FUN_00012888(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    uVar1 = FUN_00011b72();
    return uVar1;
  }
  return 0;
}

