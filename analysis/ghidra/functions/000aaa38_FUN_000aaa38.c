/* 000aaa38 FUN_000aaa38 */

undefined4
FUN_000aaa38(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x44))(param_1,param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  return 0xffffffce;
}

