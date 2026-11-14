/* 00015302 FUN_00015302 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble FUN_00015302(double param_1,double param_2)

{
  if ((param_2 == 0.0) && (!NAN(param_2))) {
    return (longdouble)999999999.9;
  }
  return (longdouble)(param_1 / param_2);
}

