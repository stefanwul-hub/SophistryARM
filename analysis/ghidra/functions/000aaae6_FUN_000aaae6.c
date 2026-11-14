/* 000aaae6 FUN_000aaae6 */

undefined4
FUN_000aaae6(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  if ((param_3 != 0) && (param_6 != 0)) {
    if (param_2 == (undefined4 *)0x0) {
      local_10[0] = 0;
      param_2 = local_10;
    }
    uVar1 = FUN_000a7014(param_1,param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  return 0xffffffce;
}

