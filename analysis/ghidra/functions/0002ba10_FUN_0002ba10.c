/* 0002ba10 FUN_0002ba10 */

undefined4 FUN_0002ba10(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 8) != 0) && (param_2 != (undefined4 *)0x0)) &&
     (*(char *)(param_2 + 1) != '\0')) {
    if (*(int *)(param_1 + 0xc) + 1U < *(uint *)(param_1 + 4)) {
      iVar2 = *(int *)(param_1 + 0xc) + 1;
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 != *(int *)(param_1 + 0x10)) {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 0x18);
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
      puVar1[2] = param_2[2];
      puVar1[3] = param_2[3];
      puVar1[4] = param_2[4];
      puVar1[5] = param_2[5];
      *(int *)(param_1 + 0xc) = iVar2;
      return 1;
    }
  }
  return 0;
}

