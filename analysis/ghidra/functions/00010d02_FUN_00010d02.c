/* 00010d02 FUN_00010d02 */

void FUN_00010d02(int param_1,char *param_2)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *local_14;
  int local_10;
  
  if (*(int *)(param_1 + 4) == 0) {
    return;
  }
  pcVar3 = *(char **)(param_1 + 0x30);
  pcVar2 = _strstr(pcVar3,param_2);
  if ((pcVar2 == (char *)0x0) ||
     (iVar6 = (int)pcVar2 - (int)pcVar3, iVar6 % *(int *)(param_1 + 0x54) != 0)) {
    piVar1 = *(int **)(param_1 + 0x50);
    if (piVar1 == (int *)0x0) {
      iVar6 = *(int *)(param_1 + 0x4c);
      if (*(int *)(param_1 + 0x48) < *(int *)(param_1 + 0x4c)) {
        iVar6 = *(int *)(param_1 + 0x48);
      }
      iVar4 = *(int *)(param_1 + 0x44);
      if (*(int *)(param_1 + 0x44) <= iVar6) {
        iVar4 = iVar6;
      }
      *(int *)(param_1 + 0x5c) = iVar4;
    }
    else {
      local_14 = (char *)*piVar1;
      if (local_14 == (char *)0x0) {
        return;
      }
      local_10 = 0;
      while ((pcVar3 = _strstr(local_14,param_2), pcVar3 == (char *)0x0 ||
             (((int)pcVar3 - (int)local_14) % *(int *)(param_1 + 0x54) != 0))) {
        local_10 = local_10 + 1;
        local_14 = (char *)piVar1[local_10];
        if (local_14 == (char *)0x0) {
          return;
        }
      }
      iVar6 = *(int *)(param_1 + 0x44);
      iVar4 = ((int)pcVar3 - piVar1[local_10]) / *(int *)(param_1 + 0x54) + iVar6;
      if (*(int *)(param_1 + 0x48) < iVar4) {
        iVar4 = *(int *)(param_1 + 0x48);
      }
      if (iVar6 <= iVar4) {
        iVar6 = iVar4;
      }
      *(int *)(param_1 + 0x5c) = iVar6;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x44);
    iVar5 = iVar6 / *(int *)(param_1 + 0x54) + iVar4;
    iVar6 = *(int *)(param_1 + 0x48);
    if (iVar5 <= *(int *)(param_1 + 0x48)) {
      iVar6 = iVar5;
    }
    if (iVar4 <= iVar6) {
      iVar4 = iVar6;
    }
    *(int *)(param_1 + 0x5c) = iVar4;
  }
  FUN_0000ff7e();
  return;
}

