/* 00010318 FUN_00010318 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010318(int param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(char **)(param_1 + 0x40) = "";
  *(undefined4 *)(param_1 + 4) = 8;
  *(undefined4 *)(param_1 + 0x20) = 8;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(int *)(param_1 + 0x54) = param_3;
  *(int *)(param_1 + 0x34) = param_3;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_0000ff7e(param_1);
  FUN_0002d6d6(param_1 + 0x68,8);
  if (*(undefined **)(param_1 + 0x60) != &DAT_000e2000) {
    _free(*(undefined **)(param_1 + 0x60));
  }
  pvVar1 = _malloc(param_3 * 4 + 4);
  *(void **)(param_1 + 0x60) = pvVar1;
  return;
}

