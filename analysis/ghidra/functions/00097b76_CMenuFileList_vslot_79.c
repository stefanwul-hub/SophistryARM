/* 00097b76 CMenuFileList_vslot_79 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CMenuFileList_vslot_79(int *param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  int local_24;
  int local_20;
  
  if ((param_2 < 0) || (iVar1 = param_1[0x2d], iVar1 <= param_2)) {
    return 0;
  }
  bVar8 = param_3 == '\0';
  if (bVar8) {
    bVar8 = iVar1 == 0;
    if (iVar1 < 1) {
      local_24 = -1;
    }
    else {
      local_20 = 0;
      local_24 = 0;
      iVar2 = local_24;
      do {
        local_24 = iVar2;
        pcVar5 = *(char **)(param_1[0x29] + local_24 * 4);
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
          local_20 = (local_20 + 1) - (uint)(iVar2 == 0);
        }
      } while ((local_20 <= param_2) &&
              (bVar8 = local_24 + 1 == iVar1, iVar2 = local_24 + 1, !bVar8));
    }
    param_1[0x2f] = local_24;
  }
  else {
    pcVar5 = *(char **)(param_1[0x29] + param_2 * 4);
    iVar1 = 2;
    pcVar3 = pcVar5;
    pcVar6 = "-";
    do {
      pcVar4 = pcVar3;
      pcVar7 = pcVar6;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      pcVar7 = pcVar6 + 1;
      pcVar4 = pcVar3 + 1;
      bVar8 = *pcVar3 == *pcVar6;
      pcVar3 = pcVar4;
      pcVar6 = pcVar7;
    } while (bVar8);
    iVar1 = 0;
    if (!bVar8) {
      iVar1 = (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar7[-1];
    }
    bVar8 = iVar1 == 0;
    if (bVar8) {
      iVar1 = 2;
      pcVar3 = "-T";
      do {
        pcVar6 = pcVar5;
        pcVar4 = pcVar3;
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        pcVar4 = pcVar3 + 1;
        pcVar6 = pcVar5 + 1;
        bVar8 = *pcVar5 == *pcVar3;
        pcVar5 = pcVar6;
        pcVar3 = pcVar4;
      } while (bVar8);
      iVar1 = 0;
      if (!bVar8) {
        iVar1 = (uint)(byte)pcVar6[-1] - (uint)(byte)pcVar4[-1];
      }
      if (iVar1 != 0) {
        return 0;
      }
    }
    param_1[0x2f] = param_2;
  }
  if ((*(byte *)(param_1 + 0x20) & 1) != 0) {
    *(byte *)(param_1[0x2b] + param_1[0x2f]) = *(byte *)(param_1[0x2b] + param_1[0x2f]) ^ 1;
  }
  (**(code **)(*param_1 + 0x54))(param_1,1);
  return 1;
}

