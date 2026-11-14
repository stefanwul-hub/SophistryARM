/* 000a6a2a FUN_000a6a2a */

void FUN_000a6a2a(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    iVar1 = param_1 + 8;
    *(int *)(param_1 + 0x34) = iVar1;
    *(undefined4 *)(param_1 + 0x38) = 1;
    FUN_000abf88(param_1 + 0x34,*(undefined4 *)(param_1 + 0x10));
    *(int *)(param_1 + 0x48) = iVar1;
    *(undefined4 *)(param_1 + 0x4c) = 2;
    FUN_000abf88(param_1 + 0x48,*(undefined4 *)(param_1 + 0x14));
    *(int *)(param_1 + 0x5c) = iVar1;
    *(undefined4 *)(param_1 + 0x60) = 3;
    FUN_000abf88(param_1 + 0x5c,*(undefined4 *)(param_1 + 0x18));
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(param_1 + 0x74) = 4;
    FUN_000abf88(param_1 + 0x70,*(undefined4 *)(param_1 + 0x1c));
    *(undefined1 *)(param_1 + 0xc) = 1;
  }
  return;
}

