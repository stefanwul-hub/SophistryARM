/* 0008c0fc FUN_0008c0fc */

int FUN_0008c0fc(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                undefined4 *param_6,int *param_7)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_18;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 != 0) {
    piVar2 = (int *)(iVar1 + 0x4d8);
    piVar3 = (int *)(iVar1 + 0x388);
    local_18 = -1;
    local_14 = 0;
    iVar4 = 0;
    while( true ) {
      if ((*piVar2 == param_2) && (*piVar3 == param_3)) {
        local_18 = (local_18 + 1) - (uint)(*(int *)(iVar1 + 0x628 + iVar4) == 0);
      }
      if (local_18 == param_4) break;
      local_14 = local_14 + 1;
      piVar2 = piVar2 + 0x134;
      iVar4 = iVar4 + 0x4d0;
      piVar3 = piVar3 + 0x134;
      if (local_14 == 0x80) {
        return 0;
      }
    }
    *param_5 = *(undefined4 *)(iVar1 + iVar4 + 0x548);
    *param_6 = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x318 + iVar4);
    *param_7 = local_14;
    iVar1 = 1;
  }
  return iVar1;
}

