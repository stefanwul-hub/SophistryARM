/* 0002cbbe FUN_0002cbbe */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

char * FUN_0002cbbe(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x298) < 1) {
    return "";
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x298))) {
    if (*(int *)(param_1 + 0x2a4) != 0) {
      return *(char **)(*(int *)(param_1 + 0x2a4) + param_2 * 4);
    }
    return "fault";
  }
  return (char *)0x0;
}

