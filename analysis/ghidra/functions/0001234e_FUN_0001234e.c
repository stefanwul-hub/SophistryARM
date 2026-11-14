/* 0001234e FUN_0001234e */

longdouble FUN_0001234e(int param_1,int param_2)

{
  longdouble lVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    lVar1 = (longdouble)FUN_00010a3c();
    return lVar1;
  }
  return (longdouble)0;
}

