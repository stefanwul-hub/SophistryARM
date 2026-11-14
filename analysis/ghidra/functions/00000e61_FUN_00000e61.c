/* 00000e61 FUN_00000e61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_00000e61(code *param_1,code *param_2)

{
  int iVar1;
  int local_20;
  int local_14;
  code *local_10;
  
  local_14 = 0;
  local_10 = param_1;
  iVar1 = (*param_1)(0xe1d,&local_14,&local_14);
  if (iVar1 == 0) {
    (*param_2)(&local_14);
    if (local_14 == 0) {
      (*param_2)(&local_14);
      local_14 = 0;
    }
    local_20 = local_14;
  }
  else {
    local_20 = -1;
  }
  return local_20;
}

