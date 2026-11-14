/* 0001d28c FUN_0001d28c */

undefined4 FUN_0001d28c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_18;
  int *local_14;
  undefined4 local_10 [3];
  
  local_18 = -1;
  FUN_0001cb52(param_1,param_2,&local_14,&local_18,local_10);
  if ((local_18 != -1) && (local_14 != (int *)0x0)) {
    uVar1 = (**(code **)(*local_14 + 0x30))(local_14,local_10[0],local_18);
    return uVar1;
  }
  return 0;
}

