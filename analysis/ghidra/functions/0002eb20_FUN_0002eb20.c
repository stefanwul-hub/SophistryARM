/* 0002eb20 FUN_0002eb20 */

void FUN_0002eb20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    if (0 < *(int *)(param_1 + 0xc)) {
      iVar4 = 0;
      iVar3 = 0;
      do {
        while( true ) {
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 4 + iVar3) = 0xffffffff;
          *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x18 + iVar3) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc + iVar3) = 0xffffffff;
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x1c + iVar3) = 0xffffffff;
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x20 + iVar3) = 0xffffffff;
          *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar3) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10 + iVar3) = 0xffffffff;
          if (*(char *)(param_1 + 0x1c) != '\0') break;
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 8 + iVar3) = 0;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x24;
          if (*(int *)(param_1 + 0xc) <= iVar4) goto LAB_0002ebe9;
        }
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = *(int *)(iVar3 + 8 + iVar2);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x154) = 0;
          *(undefined4 *)(*(int *)(iVar3 + 8 + *(int *)(param_1 + 0x10)) + 0x14c) = 0;
          iVar2 = *(int *)(param_1 + 0x10);
        }
        *(undefined4 *)(iVar2 + 8 + iVar3) = 0;
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x24;
      } while (iVar4 < *(int *)(param_1 + 0xc));
    }
LAB_0002ebe9:
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}

