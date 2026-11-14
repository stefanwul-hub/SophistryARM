/* 0008a3ca CStepSeqPl_vslot_76 */

void CStepSeqPl_vslot_76(int param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int local_14;
  int local_10;
  
  if (param_2 != (char *)0x0) {
    iVar5 = -1;
    pcVar3 = param_2;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar5 == -0x104) {
      pcVar3 = (char *)(param_1 + 0xd0);
      iVar5 = _strcmp(param_2,pcVar3);
      if (iVar5 != 0) {
        uVar4 = (int)param_2[1] + 0x100U & 0x800000ff;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xffffff00) + 1;
        }
        local_10 = uVar4 - 1;
        uVar4 = (int)*(char *)(param_1 + 0xd1) + 0x100U & 0x800000ff;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xffffff00) + 1;
        }
        iVar5 = uVar4 - 1;
        local_14 = iVar5;
        if (iVar5 < local_10) {
          local_14 = local_10;
          local_10 = iVar5;
        }
        iVar7 = 0;
        iVar5 = param_1;
        pcVar6 = param_2;
        iVar8 = param_1;
        do {
          if (((*(char *)(iVar5 + 0xd2) == pcVar6[2]) && (*(char *)(iVar5 + 0xd3) == pcVar6[3])) &&
             ((iVar7 < local_10 || (local_14 <= iVar7)))) {
            uVar2 = 0;
          }
          else {
            uVar2 = 1;
          }
          *(undefined1 *)(iVar8 + 0x2d6) = uVar2;
          iVar7 = iVar7 + 1;
          pcVar6 = pcVar6 + 2;
          iVar5 = iVar5 + 2;
          iVar8 = iVar8 + 1;
        } while (iVar7 != 0x80);
        _strncpy(pcVar3,param_2,0x102);
        *(undefined1 *)(param_1 + 0x1d2) = 0;
        *(undefined1 *)(param_1 + 0x74) = 1;
      }
      *(char **)(param_1 + 0x84) = pcVar3;
      return;
    }
  }
  return;
}

