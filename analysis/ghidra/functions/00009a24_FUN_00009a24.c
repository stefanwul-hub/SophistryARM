/* 00009a24 FUN_00009a24 */

void FUN_00009a24(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_2 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar3 - 2;
    if (-1 < iVar4) {
      param_2 = param_2 + iVar4;
      if (*param_2 != '.') {
        iVar2 = 0;
        do {
          param_2 = param_2 + -1;
          if (iVar2 == iVar4) {
            return;
          }
          iVar2 = iVar2 + 1;
        } while (*param_2 != '.');
      }
      *param_2 = '\0';
    }
  }
  return;
}

