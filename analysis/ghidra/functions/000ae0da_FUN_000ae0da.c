/* 000ae0da FUN_000ae0da */

undefined4
FUN_000ae0da(int param_1,uint param_2,undefined1 param_3,undefined1 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = (**(code **)(*(int *)(param_1 + 0xe4) + 0x14))
                      (param_1 + 0xe4,param_2 & 0xf0,param_2 & 0xf,param_3,param_4,param_5);
    return uVar1;
  }
  return 0xffffffce;
}

