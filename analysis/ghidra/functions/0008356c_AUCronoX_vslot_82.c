/* 0008356c AUCronoX_vslot_82 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble AUCronoX_vslot_82(int param_1,undefined4 param_2)

{
  longdouble lVar1;
  int local_38 [10];
  
  lVar1 = (longdouble)FUN_0001d2e8(param_1 + 0xec,param_2);
  FUN_0001ce0e(param_1 + 0xec,param_2,local_38);
  if (local_38[0] != 5) {
    return (longdouble)(float)lVar1;
  }
  return (longdouble)((float)lVar1 / 5.0);
}

