/* 0002bb04 FUN_0002bb04 */

void FUN_0002bb04(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar2 != *(int *)(param_1 + 0xc)) {
    iVar1 = *(int *)(param_1 + 8) + iVar2 * 0x18;
    if (*(char *)(iVar1 + 4) == 'Q') {
      *(undefined1 *)(iVar1 + 4) = 0;
    }
    iVar2 = iVar2 + 1;
    if (*(int *)(param_1 + 4) <= iVar2) {
      iVar2 = 0;
    }
  }
  return;
}

