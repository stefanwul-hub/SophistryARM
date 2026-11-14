/* 00009996 FUN_00009996 */

void FUN_00009996(int param_1,char *param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != (char *)0x0) {
    _strcpy(param_3,param_2);
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    iVar3 = ~uVar2 - 2;
    if (-1 < iVar3) {
      param_3 = param_3 + iVar3;
      cVar1 = *param_3;
      if (((cVar1 != *(char *)(param_1 + 0x10)) && (cVar1 != *(char *)(param_1 + 0x11))) &&
         (cVar1 != *(char *)(param_1 + 0x12))) {
        iVar4 = 0;
        do {
          param_3 = param_3 + -1;
          if (iVar4 == iVar3) {
            return;
          }
          cVar1 = *param_3;
        } while (((cVar1 != *(char *)(param_1 + 0x10)) && (cVar1 != *(char *)(param_1 + 0x11))) &&
                (iVar4 = iVar4 + 1, cVar1 != *(char *)(param_1 + 0x12)));
      }
      *param_3 = '\0';
    }
  }
  return;
}

