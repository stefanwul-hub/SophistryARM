/* 00054ca4 FUN_00054ca4 */

void FUN_00054ca4(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
  local_14 = param_3;
  local_10 = param_3 + 1;
  local_24 = param_4;
  local_20 = param_5;
  local_1c = param_6 + param_4;
  local_18 = param_6 + param_5;
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  pvVar3 = operator_new(200);
  FUN_00072790(pvVar3,&local_24,param_1 + 0x20,param_3,uVar2,uVar1);
  if (pvVar3 != (void *)0x0) {
    FUN_00025a06(param_1,pvVar3,&local_14,2,param_2);
    *(undefined4 *)(param_1 + 0x2085c + param_3 * 0xc) = 0xe;
  }
  return;
}

