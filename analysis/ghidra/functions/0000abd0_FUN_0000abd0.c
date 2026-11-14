/* 0000abd0 FUN_0000abd0 */

bool FUN_0000abd0(int param_1,char param_2,char *param_3,char *param_4,int *param_5)

{
  char *pcVar1;
  char cVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *local_2b8;
  int local_2b4;
  char local_290 [318];
  char local_152 [322];
  int local_10;
  
  if (((((param_3 == (char *)0x0) || (*param_3 == '\0')) || (param_4 == (char *)0x0)) ||
      ((*param_4 = '\0', param_5 == (int *)0x0 || (*param_5 == 0)))) ||
     (pvVar3 = _malloc(0xa0000), pvVar3 == (void *)0x0)) {
    return false;
  }
  local_10 = 0;
  pcVar1 = local_152 + 2;
  _strcpy(pcVar1,param_3);
  uVar4 = 0xffffffff;
  pcVar8 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  iVar5 = ~uVar4 - 2;
  if (-1 < iVar5) {
    pcVar8 = pcVar1 + iVar5;
    cVar2 = *pcVar8;
    if (((*(char *)(param_1 + 0x10) != cVar2) && (*(char *)(param_1 + 0x11) != cVar2)) &&
       (*(char *)(param_1 + 0x12) != cVar2)) {
      iVar6 = 0;
      do {
        pcVar8 = pcVar8 + -1;
        if (iVar5 == iVar6) goto LAB_0000ace0;
        cVar2 = *pcVar8;
      } while (((*(char *)(param_1 + 0x10) != cVar2) && (*(char *)(param_1 + 0x11) != cVar2)) &&
              (iVar6 = iVar6 + 1, *(char *)(param_1 + 0x12) != cVar2));
    }
    *pcVar8 = '\0';
  }
LAB_0000ace0:
  FUN_0000a13a(param_1,pcVar1,pvVar3,&local_10,param_5);
  FUN_00009cd6(param_1,pvVar3,local_10);
  if (param_3 != (char *)0x0) {
    _strcpy(local_290,param_3);
    uVar4 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    iVar5 = ~uVar4 - 2;
    if (-1 < iVar5) {
      param_3 = param_3 + iVar5;
      cVar2 = *param_3;
      if (((*(char *)(param_1 + 0x10) != cVar2) && (*(char *)(param_1 + 0x11) != cVar2)) &&
         (*(char *)(param_1 + 0x12) != cVar2)) {
        iVar6 = 0;
        do {
          param_3 = param_3 + -1;
          if (iVar5 == iVar6) goto LAB_0000add8;
          cVar2 = *param_3;
        } while (((cVar2 != *(char *)(param_1 + 0x10)) && (cVar2 != *(char *)(param_1 + 0x11))) &&
                (iVar6 = iVar6 + 1, *(char *)(param_1 + 0x12) != cVar2));
      }
      _strcpy(local_290,param_3 + 1);
    }
  }
LAB_0000add8:
  local_2b8 = (char *)0x0;
  local_2b4 = -1;
  pcVar8 = (char *)((int)pvVar3 + -0x140);
  do {
    if (local_10 + -1 <= local_2b4) {
      pcVar7 = (char *)0x0;
      goto LAB_0000aeee;
    }
    local_2b4 = local_2b4 + 1;
    pcVar8 = pcVar8 + 0x140;
    iVar5 = _strcasecmp(pcVar8,local_290);
    if ((iVar5 < 1) || (param_2 == '\0')) {
      pcVar7 = (char *)0x0;
      iVar5 = _strcasecmp(pcVar8,local_290);
    }
    else {
      iVar5 = _strcasecmp(pcVar8,local_290);
      pcVar7 = pcVar8;
    }
    if ((iVar5 < 0) && (param_2 == '\0')) {
      local_2b8 = pcVar8;
    }
    iVar5 = _strcasecmp(pcVar8,local_290);
    if ((-1 < iVar5) && (param_2 == '\0')) {
      pcVar7 = local_2b8;
    }
  } while (pcVar7 == (char *)0x0);
  _strcpy(param_4,pcVar1);
  FUN_0000a024(param_1,param_4,pcVar7);
LAB_0000aeee:
  _free(pvVar3);
  return pcVar7 != (char *)0x0;
}

