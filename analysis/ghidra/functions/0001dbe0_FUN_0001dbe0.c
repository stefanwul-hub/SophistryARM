/* 0001dbe0 FUN_0001dbe0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0001dbe0(int *param_1,undefined4 param_2,float param_3,int param_4)

{
  int iVar1;
  longdouble lVar2;
  int local_28;
  int *local_24;
  int *local_20 [4];
  
  local_24 = (int *)0xffffffff;
  FUN_0001cb52(param_1,param_2,local_20,&local_24,&local_28);
  if ((local_24 == (int *)0xffffffff) || (local_20[0] == (int *)0x0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*local_20[0] + 0x30))(local_20[0],local_28,local_24);
  }
  local_28 = -1;
  FUN_0001cb52(param_1,param_2,local_20,&local_28,&local_24);
  if ((-1 < local_28) && (local_20[0] != (int *)0x0)) {
    (**(code **)(*local_20[0] + 0x24))(local_20[0],local_24,local_28,param_4 + iVar1);
  }
  lVar2 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,param_2);
  local_20[0] = (int *)0xffffffff;
  FUN_0001cb52(param_1,param_2,&local_24,local_20,&local_28);
  if ((-1 < (int)local_20[0]) && (local_24 != (int *)0x0)) {
    (**(code **)(*local_24 + 0x24))(local_24,local_28,local_20[0],iVar1);
  }
  return (longdouble)(((float)lVar2 - param_3) * 1.001);
}

