/* 00058a98 FUN_00058a98 */

void FUN_00058a98(int param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  undefined1 local_16c [320];
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  
  if (param_2 != (int *)0x0) {
    uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if ((param_3 & 1) == 0) {
      local_180 = 0x20;
      local_178 = 0x30;
    }
    else {
      local_180 = 0;
      local_178 = 0x10;
    }
    local_174 = local_178;
    local_170 = param_3 * 0x30 + 0x346;
    local_17c = 0;
    do {
      local_20 = local_174 + 10;
      local_2c = 0x51;
      local_28 = local_174;
      local_24 = 0xad;
      local_1c = 0x51;
      local_18 = local_174;
      local_14 = 0xad;
      uVar1 = *(undefined4 *)(param_1 + 0x34);
      local_10 = local_20;
      piVar3 = (int *)operator_new(0xd8);
      FUN_00005f56(piVar3,&local_1c,param_1 + 0x20,local_170,uVar2,3,uVar1,0);
      FUN_0001d532(*(undefined4 *)(param_1 + 0x4c),local_170,local_16c,0x13f);
      (**(code **)(*piVar3 + 0x130))(piVar3,local_16c);
      (**(code **)(*piVar3 + 0x58))(piVar3,0);
      FUN_000266ca(param_1,piVar3,local_170,param_2);
      FUN_000268f0(param_1,param_2,local_170 + 8,0xb3,local_174,0x14,10,
                   *(undefined4 *)(param_1 + 0x34));
      FUN_000268f0(param_1,param_2,local_170 + 0x10,200,local_174,0x14,10,
                   *(undefined4 *)(param_1 + 0x34));
      FUN_000268f0(param_1,param_2,local_170 + 0x18,0xde,local_174,0x14,10,
                   *(undefined4 *)(param_1 + 0x34));
      FUN_000268f0(param_1,param_2,local_170 + 0x20,0xf4,local_174,0x14,10,
                   *(undefined4 *)(param_1 + 0x34));
      FUN_000268f0(param_1,param_2,local_170 + 0x28,0x10d,local_174,0x14,10,
                   *(undefined4 *)(param_1 + 0x34));
      local_17c = local_17c + 1;
      local_174 = local_174 + 0xc;
      local_170 = local_170 + 1;
    } while (local_17c != 8);
    FUN_00025926(param_1,param_2,param_3 + 0x3a6,0x42,local_180 - (uint)((byte)param_3 & 1 ^ 1),1,8,
                 *(undefined4 *)(param_1 + 0x27874),1);
    FUN_00025926(param_1,param_2,param_3 + 0x3a8,0x123,local_178 + -1,1,8,
                 *(undefined4 *)(param_1 + 0x27830),1);
    FUN_00025b40(param_1,param_3 + 0x3aa);
  }
  return;
}

