/* 00057cce FUN_00057cce */

void FUN_00057cce(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((param_3 & 1) == 0) {
    uVar1 = 0x6d;
    local_24 = 0x54;
    local_20 = 0x4c;
    local_1c = 0x2c;
    local_18 = 0x29;
    local_14 = 0x44;
    local_10 = 0x5f;
  }
  else {
    uVar1 = 0x66;
    local_24 = 0x4d;
    local_20 = 0x45;
    local_1c = 0x25;
    local_18 = 0x22;
    local_14 = 0x3d;
    local_10 = 0x58;
  }
  FUN_00026b74(param_1,param_2,param_3 + 0x20,0x1b5,uVar1,*(undefined4 *)(param_1 + 0x27944),0);
  FUN_00026b74(param_1,param_2,param_3 + 0x28,0x1ad,local_24,*(undefined4 *)(param_1 + 0x27804),0);
  FUN_00055b42(param_1,4,param_2,param_3 + 0xc,0xce,local_20,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,4,param_2,param_3 + 0x10,0x158,local_20,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,0x10,param_2,param_3 + 0x24,0x1d0,local_1c,0xc,
               *(undefined4 *)(param_1 + 0x38));
  FUN_00056e50(param_1,param_2,param_3 + 0x14,0x215,local_18,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x18,0x215,local_14,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x1c,0x215,local_10,0);
  return;
}

