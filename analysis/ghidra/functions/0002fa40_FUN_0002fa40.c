/* 0002fa40 FUN_0002fa40 */

void FUN_0002fa40(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  
  if ((*(int *)(param_1 + 0x10) != 0) && (iVar3 = FUN_0002e1c0(param_1 + 4), 0 < param_3)) {
    local_10 = -1;
    local_20 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0xc);
      if (0 < iVar2) {
        piVar6 = *(int **)(param_1 + 0x10);
        iVar4 = 0;
        local_1c = iVar3 + 1;
        do {
          while (((iVar5 = iVar4, param_2 != piVar6[1] || (*piVar6 != 2)) ||
                 (piVar1 = piVar6 + 8, local_1c <= *piVar1))) {
            piVar6 = piVar6 + 9;
            iVar4 = iVar5 + 1;
            if (iVar2 == iVar5 + 1) goto LAB_0002fac3;
          }
          piVar6 = piVar6 + 9;
          iVar4 = iVar5 + 1;
          local_1c = *piVar1;
          local_10 = iVar5;
        } while (iVar2 != iVar5 + 1);
      }
LAB_0002fac3:
      if (local_10 < 0) {
        if (0 < iVar2) {
          piVar6 = *(int **)(param_1 + 0x10);
          iVar4 = 0;
          local_18 = iVar3 + 1;
          do {
            while (((iVar5 = iVar4, piVar6[1] != param_2 || (*piVar6 != 1)) ||
                   (piVar1 = piVar6 + 7, local_18 <= *piVar1))) {
              piVar6 = piVar6 + 9;
              iVar4 = iVar5 + 1;
              if (iVar5 + 1 == iVar2) goto LAB_0002fb4e;
            }
            piVar6 = piVar6 + 9;
            iVar4 = iVar5 + 1;
            local_18 = *piVar1;
            local_10 = iVar5;
          } while (iVar5 + 1 != iVar2);
LAB_0002fb4e:
          if (-1 < local_10) goto LAB_0002faca;
        }
      }
      else {
LAB_0002faca:
        if (*(int *)(param_1 + 0x10) != 0) {
          iVar4 = iVar2 + -1;
          if (local_10 <= iVar2 + -1) {
            iVar4 = local_10;
          }
          FUN_0002f468(param_1,iVar4,0,0);
        }
      }
      local_20 = local_20 + 1;
    } while (param_3 != local_20);
  }
  return;
}

