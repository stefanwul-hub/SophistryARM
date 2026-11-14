/* 0000a65c FUN_0000a65c */

void FUN_0000a65c(int param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    if (param_3 == (char *)0x0) {
      return;
    }
  }
  else {
    if (param_3 == (char *)0x0) {
      return;
    }
    _strcpy(param_3,param_2);
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
      cVar1 = *param_2;
      if (((cVar1 != *(char *)(param_1 + 0x10)) && (cVar1 != *(char *)(param_1 + 0x11))) &&
         (cVar1 != *(char *)(param_1 + 0x12))) {
        iVar2 = 0;
        do {
          param_2 = param_2 + -1;
          if (iVar4 == iVar2) goto LAB_0000a701;
          cVar1 = *param_2;
        } while (((cVar1 != *(char *)(param_1 + 0x10)) && (cVar1 != *(char *)(param_1 + 0x11))) &&
                (iVar2 = iVar2 + 1, cVar1 != *(char *)(param_1 + 0x12)));
      }
      _strcpy(param_3,param_2 + 1);
    }
  }
LAB_0000a701:
  uVar3 = 0xffffffff;
  pcVar5 = param_3;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 2;
  if (-1 < iVar4) {
    param_3 = param_3 + iVar4;
    if (*param_3 != '.') {
      iVar2 = 0;
      do {
        param_3 = param_3 + -1;
        if (iVar2 == iVar4) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (*param_3 != '.');
    }
    *param_3 = '\0';
  }
  return;
}

