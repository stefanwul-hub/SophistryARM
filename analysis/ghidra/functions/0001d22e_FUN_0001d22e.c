/* 0001d22e FUN_0001d22e */

longdouble FUN_0001d22e(undefined4 param_1,undefined4 param_2)

{
  longdouble lVar1;
  int local_18;
  int *local_14;
  undefined4 local_10 [2];
  
  FUN_0001cb52(param_1,param_2,&local_14,&local_18,local_10);
  if ((local_18 != -1) && (local_14 != (int *)0x0)) {
    lVar1 = (longdouble)(**(code **)(*local_14 + 0x38))(local_14,local_10[0],local_18);
    return lVar1;
  }
  return (longdouble)0;
}

