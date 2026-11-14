/* 00089110 DistSimp2_c_vslot_27 */

longdouble DistSimp2_c_vslot_27(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0x124) != 0) && (param_2 == 0)) {
    return (longdouble)*(float *)(*(int *)(param_1 + 0x124) + 0xec);
  }
  return (longdouble)0;
}

