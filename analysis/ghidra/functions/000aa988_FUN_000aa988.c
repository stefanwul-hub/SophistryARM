/* 000aa988 FUN_000aa988 */

undefined4
FUN_000aa988(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_5 != 0)) {
    uVar1 = (**(code **)(*param_1 + 0x40))(param_1,param_2,param_3,param_4,param_5);
    return uVar1;
  }
  return 0xffffffce;
}

