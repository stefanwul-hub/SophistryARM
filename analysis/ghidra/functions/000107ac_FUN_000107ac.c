/* 000107ac FUN_000107ac */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000107ac(int param_1,char *param_2)

{
  int iVar1;
  
  if (param_2 != (char *)0x0) {
    iVar1 = *(int *)(param_1 + 0x5c);
    if (iVar1 == *(int *)(param_1 + 0x44)) {
      builtin_strncpy(param_2,"-oo",4);
      return;
    }
    if (iVar1 < -0x31) {
      _sprintf(param_2,"-%d",-iVar1 / 5);
      return;
    }
    if (iVar1 < 0) {
      _sprintf(param_2,"-%d.%d",-iVar1 / 5,(-iVar1 % 5) * 2);
      return;
    }
    _sprintf(param_2,"%d.%d",iVar1 / 5,(iVar1 % 5) * 2);
  }
  return;
}

