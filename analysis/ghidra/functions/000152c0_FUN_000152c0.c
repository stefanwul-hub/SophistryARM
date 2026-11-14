/* 000152c0 FUN_000152c0 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble FUN_000152c0(float param_1,float param_2)

{
  if ((param_2 == 0.0) && (!NAN(param_2))) {
    return (longdouble)1e+09;
  }
  return (longdouble)(param_1 / param_2);
}

