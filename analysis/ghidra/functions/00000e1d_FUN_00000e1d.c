/* 00000e1d FUN_00000e1d */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00000e1d(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[1])(0xe0c,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

