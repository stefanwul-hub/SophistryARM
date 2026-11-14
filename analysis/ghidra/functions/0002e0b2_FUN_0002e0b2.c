/* 0002e0b2 FUN_0002e0b2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0002e0b2(int param_1,uint param_2,int *param_3)

{
  if ((-1 < (int)param_2) && (param_2 < *(uint *)(param_1 + 8) >> 2)) {
    if (*(int *)(param_1 + 4) != 0) {
      *param_3 = *(int *)(param_1 + 4) + param_2 * 4;
      return 1;
    }
    *param_3 = (int)"";
    return 0;
  }
  return 0;
}

