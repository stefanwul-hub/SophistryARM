/* 0000a0de FUN_0000a0de */

void FUN_0000a0de(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  
  uVar3 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = ~uVar3 - 2;
  if (-1 < iVar2) {
    param_2 = param_2 + iVar2;
    iVar5 = 0;
    iVar2 = ~uVar3 - 1;
    do {
      while (((cVar1 = *param_2, cVar1 == *(char *)(param_1 + 0x10) ||
              (cVar1 == *(char *)(param_1 + 0x11))) || (cVar1 == *(char *)(param_1 + 0x12)))) {
        *param_2 = *(char *)(param_1 + 0x11);
        iVar5 = iVar5 + 1;
        param_2 = param_2 + -1;
        if (iVar5 == iVar2) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
      param_2 = param_2 + -1;
    } while (iVar5 != iVar2);
  }
  return;
}

