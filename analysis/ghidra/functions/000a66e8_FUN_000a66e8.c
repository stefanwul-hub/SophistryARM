/* 000a66e8 FUN_000a66e8 */

undefined4 FUN_000a66e8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((((*(int *)(param_2 + 8) == 0x6c70636d) && (*(int *)(param_2 + 0x14) == 1)) &&
      (*(int *)(param_2 + 0x10) == *(int *)(param_2 + 0x18))) &&
     (((uVar1 = *(uint *)(param_2 + 0xc), (uVar1 & 1) != 0 &&
       (((uVar1 >> 5 ^ 1) & 1) == (uint)(*(char *)(param_1 + 0xe) == '\x01'))) &&
      (((uVar1 & 2) == 0 && (*(int *)(param_2 + 0x20) == 0x20)))))) {
    if ((uVar1 >> 5 & 1) == 0) {
      iVar2 = *(int *)(param_2 + 0x1c) << 2;
    }
    else {
      iVar2 = 4;
    }
    if (*(int *)(param_2 + 0x10) == iVar2) {
      return 1;
    }
  }
  return 0;
}

