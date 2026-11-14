/* 000c7550 FUN_000c7550 */

int * FUN_000c7550(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = (int)param_2 - (int)param_1;
  if (0 < iVar4 >> 4) {
    iVar3 = *param_3;
    if (iVar3 == *param_1) {
      return param_1;
    }
    if (param_1[1] == iVar3) {
      return param_1 + 1;
    }
    if (param_1[2] == iVar3) {
      return param_1 + 2;
    }
    if (param_1[3] == iVar3) {
      return param_1 + 3;
    }
    iVar5 = 0;
    piVar6 = param_1;
    while (param_1 = piVar6 + 4, (iVar4 >> 4) + -1 != iVar5) {
      if (piVar6[4] == iVar3) {
        return param_1;
      }
      if (piVar6[5] == iVar3) {
        return piVar6 + 5;
      }
      if (iVar3 == piVar6[6]) {
        return piVar6 + 6;
      }
      piVar1 = piVar6 + 7;
      iVar5 = iVar5 + 1;
      piVar2 = piVar6 + 7;
      piVar6 = param_1;
      if (iVar3 == *piVar2) {
        return piVar1;
      }
    }
    iVar4 = (int)param_2 - (int)param_1;
  }
  iVar4 = iVar4 >> 2;
  if (iVar4 != 2) {
    if (iVar4 != 3) {
      if (iVar4 != 1) {
        return param_2;
      }
      goto LAB_000c7613;
    }
    if (*param_1 == *param_3) {
      return param_1;
    }
    param_1 = param_1 + 1;
  }
  if (*param_1 == *param_3) {
    return param_1;
  }
  param_1 = param_1 + 1;
LAB_000c7613:
  if (*param_1 == *param_3) {
    return param_1;
  }
  return param_2;
}

