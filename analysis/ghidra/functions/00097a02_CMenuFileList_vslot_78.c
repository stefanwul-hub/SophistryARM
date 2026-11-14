/* 00097a02 CMenuFileList_vslot_78 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int CMenuFileList_vslot_78(int param_1,char *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  int local_40;
  int local_24;
  
  iVar1 = *(int *)(param_1 + 0xbc);
  if (iVar1 < 0) {
    return -1;
  }
  if (param_3 != '\0') {
    if (param_2 != (char *)0x0) {
      _strcpy(param_2,*(char **)(*(int *)(param_1 + 0xa4) + iVar1 * 4));
      iVar1 = *(int *)(param_1 + 0xbc);
    }
    return iVar1;
  }
  bVar8 = iVar1 == 0;
  if (iVar1 < 1) {
    local_24 = 0;
  }
  else {
    local_40 = 0;
    local_24 = 0;
    do {
      pcVar5 = *(char **)(*(int *)(param_1 + 0xa4) + local_40 * 4);
      iVar2 = 2;
      pcVar3 = pcVar5;
      pcVar6 = "-";
      do {
        pcVar4 = pcVar3;
        pcVar7 = pcVar6;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar7 = pcVar6 + 1;
        pcVar4 = pcVar3 + 1;
        bVar8 = *pcVar3 == *pcVar6;
        pcVar3 = pcVar4;
        pcVar6 = pcVar7;
      } while (bVar8);
      iVar2 = 0;
      if (!bVar8) {
        iVar2 = (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar7[-1];
      }
      bVar8 = iVar2 == 0;
      if (!bVar8) {
        iVar2 = 2;
        pcVar3 = "-T";
        do {
          pcVar6 = pcVar5;
          pcVar4 = pcVar3;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar4 = pcVar3 + 1;
          pcVar6 = pcVar5 + 1;
          bVar8 = *pcVar5 == *pcVar3;
          pcVar5 = pcVar6;
          pcVar3 = pcVar4;
        } while (bVar8);
        iVar2 = 0;
        if (!bVar8) {
          iVar2 = (uint)(byte)pcVar6[-1] - (uint)(byte)pcVar4[-1];
        }
        local_24 = (local_24 + 1) - (uint)(iVar2 == 0);
      }
      local_40 = local_40 + 1;
      bVar8 = iVar1 == local_40;
    } while (!bVar8);
  }
  if (param_2 != (char *)0x0) {
    _strcpy(param_2,*(char **)(*(int *)(param_1 + 0xa4) + iVar1 * 4));
  }
  return local_24;
}

