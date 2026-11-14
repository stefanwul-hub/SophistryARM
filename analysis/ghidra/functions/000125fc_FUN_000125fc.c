/* 000125fc FUN_000125fc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

char * FUN_000125fc(int param_1,int param_2)

{
  char *pcVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    pcVar1 = (char *)FUN_00010898();
    return pcVar1;
  }
  return "";
}

