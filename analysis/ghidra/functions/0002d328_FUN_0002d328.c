/* 0002d328 FUN_0002d328 */

void FUN_0002d328(int param_1,char *param_2,undefined1 param_3)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int local_10;
  
  if (((*(int *)(param_1 + 0x2a4) != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    _strncpy((char *)(param_1 + 1000),param_2,0x13f);
    *(undefined1 *)(param_1 + 0x527) = 0;
    FUN_0002cfde(param_1,param_3);
    FUN_0002cc04(param_1,*(undefined4 *)(param_1 + 0x2a4),*(undefined4 *)(param_1 + 0x528));
    if (((*(int *)(param_1 + 0x52c) != 0) && (0 < *(int *)(param_1 + 0x528))) &&
       (pcVar7 = (char *)**(int **)(param_1 + 0x2a4), pcVar7 != (char *)0x0)) {
      local_10 = 0;
      do {
        uVar5 = 0xffffffff;
        pcVar3 = pcVar7;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        pcVar3 = _strchr(pcVar7,0x2e);
        if (pcVar3 != (char *)0x0) {
          iVar1 = ~uVar5 - 2;
          iVar6 = iVar1;
          if (pcVar7[~uVar5 - 2] == '.') {
LAB_0002d464:
            if (0 < iVar6) {
              pcVar7[iVar6] = '\0';
            }
          }
          else if (0 < iVar1) {
            pcVar3 = pcVar7 + iVar1;
            iVar4 = 0;
            do {
              iVar6 = iVar6 + -1;
              if (pcVar3[-1] == '.') goto LAB_0002d464;
              iVar4 = iVar4 + 1;
              pcVar3 = pcVar3 + -1;
            } while (iVar1 != iVar4);
          }
        }
        local_10 = local_10 + 1;
      } while ((local_10 < *(int *)(param_1 + 0x528)) &&
              (pcVar7 = *(char **)(*(int *)(param_1 + 0x2a4) + local_10 * 4), pcVar7 != (char *)0x0)
              );
    }
  }
  return;
}

