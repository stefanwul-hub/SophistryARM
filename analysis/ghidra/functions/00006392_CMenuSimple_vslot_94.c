/* 00006392 CMenuSimple_vslot_94 */

void CMenuSimple_vslot_94(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char acStack_14f [323];
  
  if (((param_3 < 0) || (param_4 < 0)) ||
     ((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4)) + 1 <= param_3)) {
    return;
  }
  pcVar1 = acStack_14f + 3;
  _strncpy(pcVar1,(char *)(param_3 * *(int *)(param_1 + 0x104) + *(int *)(param_1 + 0x100) + param_5
                          ),*(int *)(param_1 + 0x104) - param_5);
  acStack_14f[(*(int *)(param_1 + 0x104) - param_5) + 3] = '\0';
  uVar4 = 0xffffffff;
  pcVar3 = pcVar1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  iVar5 = ~uVar4 - 2;
  if ((-1 < iVar5) && (pcVar1[iVar5] == ' ')) {
    iVar6 = 0;
    pcVar3 = pcVar1 + iVar5;
    pcVar7 = acStack_14f + ~uVar4;
    do {
      *pcVar3 = '\0';
      if (iVar5 == iVar6) break;
      iVar6 = iVar6 + 1;
      cVar2 = *pcVar7;
      pcVar3 = pcVar7;
      pcVar7 = pcVar7 + -1;
    } while (cVar2 == ' ');
  }
  pcVar3 = _strchr(pcVar1,0x24);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = ' ';
  }
  (**(code **)(*param_2 + 0x134))(param_2,pcVar1,param_4);
  return;
}

