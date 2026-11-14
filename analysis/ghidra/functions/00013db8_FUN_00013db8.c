/* 00013db8 FUN_00013db8 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble FUN_00013db8(undefined4 param_1,int param_2,double param_3)

{
  double dVar1;
  undefined4 local_c;
  
  if ((param_3 < 0.0) && (!NAN(param_3))) {
    return (longdouble)0.0;
  }
  if (param_3 <= 0.0) {
    dVar1 = 0.499999999999;
  }
  else {
    dVar1 = -0.499999999999;
  }
  local_c = SUB84(dVar1 + param_3 + 6755399441055744.0,0);
  return (longdouble)
         ((1.0 - (float)(param_3 - (double)local_c)) * *(float *)(param_2 + local_c * 4) +
         (float)(param_3 - (double)local_c) * *(float *)(param_2 + 4 + local_c * 4));
}

