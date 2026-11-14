/* 0008d188 FUN_0008d188 */

int FUN_0008d188(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                char param_6)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 == 0) {
    return -1;
  }
  if (param_6 == '\0') {
    piVar5 = (int *)(iVar1 + 0x628);
    piVar3 = (int *)(iVar1 + 0x388);
    piVar4 = (int *)(iVar1 + 0x4d8);
    local_14 = 0;
    do {
      if ((param_5 == *piVar3) && (param_4 == *piVar4)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (*piVar5 == 0) break;
      if (bVar2) {
        bVar2 = true;
        break;
      }
      local_14 = local_14 + 1;
      piVar5 = piVar5 + 0x134;
      piVar3 = piVar3 + 0x134;
      piVar4 = piVar4 + 0x134;
    } while (local_14 != 0x80);
  }
  else {
    piVar5 = (int *)(iVar1 + 0x628);
    piVar3 = (int *)(iVar1 + 0x388);
    piVar4 = (int *)(iVar1 + 0x4d8);
    local_14 = 0;
    do {
      if ((param_5 == *piVar3) && (param_4 == *piVar4)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (*piVar5 == 0) break;
      local_14 = local_14 + 1;
      piVar5 = piVar5 + 0x134;
      piVar3 = piVar3 + 0x134;
      piVar4 = piVar4 + 0x134;
    } while (local_14 != 0x80);
  }
  if ((*(char *)(param_1 + 0x316) == '\0') && (local_14 < 0x80)) {
    iVar6 = local_14 * 0x4d0;
    FUN_000109c8(iVar1 + 0x310 + iVar6,param_3);
    FUN_000109c8(iVar6 + *(int *)(param_1 + 0x124) + 0x540,param_2);
    FUN_000109c8(iVar6 + *(int *)(param_1 + 0x124) + 0x380,param_5);
    FUN_000109c8(iVar6 + *(int *)(param_1 + 0x124) + 0x4d0,param_4);
    FUN_000109c8(iVar6 + *(int *)(param_1 + 0x124) + 0x620,1);
  }
  if ((*(char *)(param_1 + 0x316) != '\0') && (bVar2)) {
    FUN_0008cea6(param_1,param_4,param_5);
    return local_14;
  }
  return local_14;
}

