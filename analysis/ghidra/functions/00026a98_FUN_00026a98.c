/* 00026a98 FUN_00026a98 */

void FUN_00026a98(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,int param_8,int param_9,int param_10,
                 undefined1 param_11)

{
  void *pvVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (param_2 != 0) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    iVar2 = *(int *)(param_1 + 0x25854) + -1;
    if (param_3 <= iVar2) {
      iVar2 = param_3;
    }
    local_1c = param_7;
    local_18 = param_8;
    local_14 = param_7 + param_9;
    local_10 = param_8 + param_10;
    pvVar1 = operator_new(0xd0);
    FUN_00008ef0(pvVar1,&local_1c,param_1 + 0x20,iVar2,*(undefined4 *)(param_1 + 0x4c),param_4,
                 param_5,param_6,param_11);
    if (pvVar1 != (void *)0x0) {
      FUN_000266ca(param_1,pvVar1,iVar2,param_2);
    }
  }
  return;
}

