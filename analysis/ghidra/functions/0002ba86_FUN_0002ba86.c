/* 0002ba86 FUN_0002ba86 */

undefined4 FUN_0002ba86(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (((*(int *)(param_1 + 8) != 0) && (param_2 != (undefined4 *)0x0)) &&
     (*(int *)(param_1 + 0x10) != *(int *)(param_1 + 0xc))) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) * 0x18);
    *param_2 = *puVar1;
    param_2[1] = puVar1[1];
    param_2[2] = puVar1[2];
    param_2[3] = puVar1[3];
    param_2[4] = puVar1[4];
    param_2[5] = puVar1[5];
    if (*(int *)(param_1 + 0x10) + 1U < *(uint *)(param_1 + 4)) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 1;
  }
  return 0;
}

