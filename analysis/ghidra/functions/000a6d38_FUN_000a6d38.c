/* 000a6d38 FUN_000a6d38 */

undefined4 FUN_000a6d38(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((((*(int *)(param_4 + 8) == 0x6c70636d) && (*(int *)(param_4 + 0x14) == 1)) &&
      (*(int *)(param_4 + 0x10) == *(int *)(param_4 + 0x18))) &&
     (((uVar1 = *(uint *)(param_4 + 0xc), (uVar1 & 1) != 0 &&
       (((uVar1 >> 5 ^ 1) & 1) == (uint)(*(char *)(param_1 + 0xe) == '\x01'))) &&
      (((uVar1 & 2) == 0 && (*(int *)(param_4 + 0x20) == 0x20)))))) {
    if ((uVar1 >> 5 & 1) == 0) {
      iVar2 = *(int *)(param_4 + 0x1c) << 2;
    }
    else {
      iVar2 = 4;
    }
    if (*(int *)(param_4 + 0x10) == iVar2) {
      return 1;
    }
  }
  return 0;
}

