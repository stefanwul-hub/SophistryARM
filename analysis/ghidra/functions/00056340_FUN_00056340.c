/* 00056340 FUN_00056340 */

void FUN_00056340(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
  FUN_0002666e(param_1,param_2,*(undefined4 *)(param_1 + 0x34),0x287,0x18,0x109,0x6d,0x10,0,0);
  local_1c = 0x43;
  local_18 = 0x97;
  local_14 = 0x123;
  local_10 = 0xff;
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  pvVar3 = operator_new(0x368);
  FUN_0008a516(pvVar3,&local_1c,param_1 + 0x20,0x288,*(undefined4 *)(param_1 + 0x4c),uVar2,
               *(undefined4 *)(param_1 + 0x27878),uVar1,4,8,0x10,0,1,1,1);
  FUN_000266ca(param_1,pvVar3,0x288,param_2);
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27884),
               0x289,0xb6,0x104,1,1);
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27888),
               0x28a,0x10b,0x104,1,1);
  FUN_00026b74(param_1,param_2,0x290,0x12f,0x104,*(undefined4 *)(param_1 + 0x27938),0);
  FUN_00055b42(param_1,1,param_2,0x28c,0x13b,0xb1,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,1,param_2,0x28e,0x15c,0xb1,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00025926(param_1,param_2,0x28d,0x2d,0xae,1,4,*(undefined4 *)(param_1 + 0x2787c),1);
  FUN_00055b42(param_1,1,param_2,0x28f,0x13b,0xe0,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,1,param_2,0x28b,0x15c,0xe0,0,*(undefined4 *)(param_1 + 0x34));
  return;
}

