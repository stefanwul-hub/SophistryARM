/* 000b6206 FUN_000b6206 */

void FUN_000b6206(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = FUN_000b60a8(param_1);
  if (cVar1 != '\0') {
    iVar4 = 0;
    iVar3 = param_1 + 0x404;
    do {
      if ((*(int *)(iVar3 + -0x21c) != 0) && (0 < *(int *)(iVar3 + -0x218))) {
        iVar2 = 0;
        do {
          *(undefined4 *)(*(int *)(iVar3 + -0x21c) + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar3 + -0x218));
      }
      if ((*(int *)(iVar3 + 4) != 0) && (0 < *(int *)(iVar3 + 8))) {
        iVar2 = 0;
        do {
          *(undefined4 *)(*(int *)(iVar3 + 4) + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar3 + 8));
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x44;
    } while (iVar4 != 8);
    iVar4 = 0;
    iVar3 = param_1 + 0x6b4;
    do {
      if ((*(int *)(iVar3 + -0x8c) != 0) && (0 < *(int *)(iVar3 + -0x88))) {
        iVar2 = 0;
        do {
          *(undefined4 *)(*(int *)(iVar3 + -0x8c) + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar3 + -0x88));
      }
      if ((*(int *)(iVar3 + 4) != 0) && (0 < *(int *)(iVar3 + 8))) {
        iVar2 = 0;
        do {
          *(undefined4 *)(*(int *)(iVar3 + 4) + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar3 + 8));
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x18;
    } while (iVar4 != 6);
    if ((*(int *)(param_1 + 0x748) != 0) && (0 < *(int *)(param_1 + 0x74c))) {
      iVar3 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x748) + iVar3 * 4) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x74c));
    }
  }
  return;
}

