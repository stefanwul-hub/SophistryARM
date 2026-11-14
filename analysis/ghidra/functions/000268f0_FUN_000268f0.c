/* 000268f0 FUN_000268f0 */

void FUN_000268f0(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((((0 < param_6) && (0 < param_7)) && (param_2 != (int *)0x0)) &&
     (*(int *)(param_1 + 0x4c) != 0)) {
    uVar1 = (**(code **)(*param_2 + 0x24))(param_2);
    FUN_0001ce0e(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + param_3 * 4),
                 &local_54);
    local_1c = param_4;
    local_18 = param_5;
    local_14 = param_6 + param_4;
    local_10 = param_7 + param_5;
    local_38 = local_54;
    local_34 = local_50;
    local_30 = local_4c;
    local_2c = local_48;
    local_28 = local_44;
    local_24 = local_40;
    local_20 = local_3c;
    piVar2 = (int *)operator_new(0xe8);
    FUN_00009542(piVar2,&local_1c,param_1 + 0x20,param_3,uVar1,local_38,local_34,local_30,local_2c,
                 local_28,local_24,local_20);
    if (piVar2 != (int *)0x0) {
      FUN_000266ca(param_1,piVar2,param_3,param_2);
      (**(code **)(*piVar2 + 0x13c))(piVar2,4);
      (**(code **)(*piVar2 + 0x138))(piVar2,param_8);
      (**(code **)(*piVar2 + 0x144))(piVar2,1);
      *(undefined4 *)(param_1 + 0x2085c + param_3 * 0xc) = 0xb;
    }
  }
  return;
}

