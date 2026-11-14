/* 0000aa76 FUN_0000aa76 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

char * FUN_0000aa76(int param_1,char *param_2,int param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char acStack_15e [334];
  
  if (((param_2 == (char *)0x0) || (param_3 == 0)) || (param_4 == 0)) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar1 = acStack_15e + 2;
    _strcpy(pcVar1,param_2);
    uVar3 = 0xffffffff;
    pcVar5 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    iVar4 = ~uVar3 - 2;
    if (-1 < iVar4) {
      param_2 = param_2 + iVar4;
      cVar2 = *param_2;
      if (((*(char *)(param_1 + 0x10) != cVar2) && (cVar2 != *(char *)(param_1 + 0x11))) &&
         (cVar2 != *(char *)(param_1 + 0x12))) {
        iVar6 = 0;
        do {
          param_2 = param_2 + -1;
          if (iVar4 == iVar6) goto LAB_0000ab50;
          cVar2 = *param_2;
        } while (((*(char *)(param_1 + 0x10) != cVar2) && (cVar2 != *(char *)(param_1 + 0x11))) &&
                (iVar6 = iVar6 + 1, cVar2 != *(char *)(param_1 + 0x12)));
      }
      _strcpy(pcVar1,param_2 + 1);
    }
LAB_0000ab50:
    uVar3 = 0xffffffff;
    pcVar5 = pcVar1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    iVar4 = ~uVar3 - 2;
    if (-1 < iVar4) {
      pcVar5 = pcVar1 + iVar4;
      if (*pcVar5 != '.') {
        iVar6 = 0;
        do {
          pcVar5 = pcVar5 + -1;
          if (iVar6 == iVar4) goto LAB_0000ab8d;
          iVar6 = iVar6 + 1;
        } while (*pcVar5 != '.');
      }
      *pcVar5 = '\0';
    }
LAB_0000ab8d:
    pcVar5 = (char *)(param_1 + 0x153);
    _sprintf(pcVar5,"%s%c%s.%s",param_3,(int)*(char *)(param_1 + 0x11),pcVar1,param_4);
  }
  return pcVar5;
}

