/* 0001d1ca FUN_0001d1ca */

void FUN_0001d1ca(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int local_18;
  int *local_14;
  undefined4 local_10 [2];
  
  local_18 = -1;
  FUN_0001cb52(param_1,param_2,&local_14,&local_18,local_10);
  if ((-1 < local_18) && (local_14 != (int *)0x0)) {
    (**(code **)(*local_14 + 0x24))(local_14,local_10[0],local_18,param_3);
  }
  return;
}

