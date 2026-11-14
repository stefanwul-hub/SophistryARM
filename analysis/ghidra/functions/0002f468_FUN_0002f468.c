/* 0002f468 FUN_0002f468 */

void FUN_0002f468(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_30;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 0) {
    return;
  }
  piVar2 = (int *)(iVar5 + param_2 * 0x24);
  iVar4 = *piVar2;
  piVar3 = (int *)piVar2[2];
  iVar1 = piVar2[5];
  if (iVar4 == 0) {
    if (param_3 == 1) {
      if (param_4 == (int *)0x0) {
        return;
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      param_4[0x53] = param_4[0x53] + 1;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      param_4[0x55] = param_4[0x55] + 1;
      iVar5 = *(int *)(param_1 + 0xc);
      if (iVar5 < 1) {
        local_30 = 0;
      }
      else {
        piVar2 = *(int **)(param_1 + 0x10);
        if (iVar1 == 0x10) {
          local_20 = 0;
          local_30 = 0;
          do {
            iVar4 = local_30 + 1;
            if (*piVar2 != 1) {
              iVar4 = local_30;
            }
            local_20 = local_20 + 1;
            piVar2 = piVar2 + 9;
            local_30 = iVar4;
          } while (iVar5 != local_20);
        }
        else {
          iVar4 = 0;
          local_30 = 0;
          do {
            if ((iVar1 == piVar2[5]) && (*piVar2 == 1)) {
              local_30 = local_30 + 1;
            }
            iVar4 = iVar4 + 1;
            piVar2 = piVar2 + 9;
          } while (iVar5 != iVar4);
        }
      }
      (**(code **)(*param_4 + 0x8c))(param_4,iVar1,local_30 == 0);
      iVar5 = *(int *)(param_1 + 0x10);
      piVar3 = param_4;
      goto LAB_0002f4ae;
    }
  }
  else if (iVar4 == 1) {
    if (param_3 == 1) {
      if (param_4 == (int *)0x0) {
        return;
      }
      piVar3[0x53] = piVar3[0x53] + -1;
      param_4[0x53] = param_4[0x53] + 1;
      piVar3[0x55] = piVar3[0x55] + -1;
      param_4[0x55] = param_4[0x55] + 1;
      if (piVar3 == param_4) {
        iVar5 = *(int *)(param_1 + 0x10);
      }
      else {
        iVar5 = *(int *)(param_1 + 0xc);
        if (iVar5 < 1) {
          local_30 = 0;
        }
        else {
          piVar2 = *(int **)(param_1 + 0x10);
          if (iVar1 == 0x10) {
            local_1c = 0;
            local_30 = 0;
            do {
              iVar4 = local_30 + 1;
              if (*piVar2 != 1) {
                iVar4 = local_30;
              }
              local_1c = local_1c + 1;
              piVar2 = piVar2 + 9;
              local_30 = iVar4;
            } while (iVar5 != local_1c);
          }
          else {
            iVar4 = 0;
            local_30 = 0;
            do {
              if ((iVar1 == piVar2[5]) && (*piVar2 == 1)) {
                local_30 = local_30 + 1;
              }
              iVar4 = iVar4 + 1;
              piVar2 = piVar2 + 9;
            } while (iVar4 != iVar5);
          }
        }
        (**(code **)(*param_4 + 0x8c))(param_4,iVar1,local_30 == 1);
        iVar5 = *(int *)(param_1 + 0x10);
        piVar3 = param_4;
      }
      goto LAB_0002f4ae;
    }
    if (param_3 - 2U < 2) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
      piVar3[0x55] = piVar3[0x55] + -1;
      iVar5 = *(int *)(param_1 + 0x10);
      goto LAB_0002f4ae;
    }
    if (param_3 == 0) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
      piVar3[0x55] = piVar3[0x55] + -1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      piVar3[0x53] = piVar3[0x53] + -1;
      iVar5 = *(int *)(param_1 + 0x10);
      goto LAB_0002f4ae;
    }
  }
  if (iVar4 - 2U < 2) {
    if (param_3 == 0) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      piVar3[0x53] = piVar3[0x53] + -1;
      iVar5 = *(int *)(param_1 + 0x10);
    }
    else if (param_3 == 1) {
      if (param_4 == (int *)0x0) {
        return;
      }
      piVar3[0x53] = piVar3[0x53] + -1;
      param_4[0x53] = param_4[0x53] + 1;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      param_4[0x55] = param_4[0x55] + 1;
      iVar5 = *(int *)(param_1 + 0xc);
      if (iVar5 < 1) {
        local_30 = 0;
      }
      else {
        piVar2 = *(int **)(param_1 + 0x10);
        if (iVar1 == 0x10) {
          local_18 = 0;
          local_30 = 0;
          do {
            iVar4 = local_30 + 1;
            if (*piVar2 != 1) {
              iVar4 = local_30;
            }
            local_18 = local_18 + 1;
            piVar2 = piVar2 + 9;
            local_30 = iVar4;
          } while (local_18 != iVar5);
        }
        else {
          iVar4 = 0;
          local_30 = 0;
          do {
            if ((iVar1 == piVar2[5]) && (*piVar2 == 1)) {
              local_30 = local_30 + 1;
            }
            iVar4 = iVar4 + 1;
            piVar2 = piVar2 + 9;
          } while (iVar5 != iVar4);
        }
      }
      (**(code **)(*param_4 + 0x8c))(param_4,iVar1,local_30 == 0);
      iVar5 = *(int *)(param_1 + 0x10);
      piVar3 = param_4;
    }
  }
LAB_0002f4ae:
  *(int *)(param_2 * 0x24 + iVar5) = param_3;
  if (piVar3[0x55] < 0) {
    piVar3[0x55] = 0;
  }
  if (*(int *)(param_1 + 0xc) < piVar3[0x55]) {
    piVar3[0x55] = *(int *)(param_1 + 0xc);
  }
  if (piVar3[0x53] < 0) {
    piVar3[0x53] = 0;
  }
  if (*(int *)(param_1 + 0xc) < piVar3[0x53]) {
    piVar3[0x53] = *(int *)(param_1 + 0xc);
  }
  return;
}

