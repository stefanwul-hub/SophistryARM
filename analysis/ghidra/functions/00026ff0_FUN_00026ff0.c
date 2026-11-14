/* 00026ff0 FUN_00026ff0 */

void FUN_00026ff0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,undefined4 param_11,int param_12,
                 int param_13)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (param_13 != 0) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    iVar4 = *(int *)(param_1 + 0x25854) + -1;
    if (param_2 <= iVar4) {
      iVar4 = param_2;
    }
    local_1c = param_3;
    local_18 = param_4;
    local_14 = param_3 + param_5;
    local_10 = param_4 + param_6;
    if (param_6 < param_5) {
      iVar3 = *(int *)(param_12 + 0xc) + -2;
      iVar3 = iVar3 - (iVar3 >> 0x1f);
      iVar1 = *(int *)(param_12 + 0x10) - param_10;
      iVar1 = iVar1 - (iVar1 >> 0x1f);
    }
    else {
      iVar3 = *(int *)(param_12 + 0xc) - param_9;
      iVar3 = iVar3 - (iVar3 >> 0x1f);
      iVar1 = *(int *)(param_12 + 0x10) + -2;
      iVar1 = iVar1 - (iVar1 >> 0x1f);
    }
    local_2c = param_7 - (iVar3 >> 1);
    local_28 = param_8 - (iVar1 >> 1);
    local_24 = (iVar3 >> 1) + param_7 + param_9;
    local_20 = (iVar1 >> 1) + param_8 + param_10;
    pvVar2 = operator_new(0xec);
    FUN_00008c52(pvVar2,&local_1c,&local_2c,param_1 + 0x20,iVar4,param_12,param_11);
    if (pvVar2 != (void *)0x0) {
      FUN_000266ca(param_1,pvVar2,iVar4,param_13);
    }
  }
  return;
}

