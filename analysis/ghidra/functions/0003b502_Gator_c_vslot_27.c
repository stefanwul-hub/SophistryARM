/* 0003b502 Gator_c_vslot_27 */

longdouble Gator_c_vslot_27(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0x124) != 0) && (param_2 == 0)) {
    return (longdouble)*(float *)(*(int *)(param_1 + 0x124) + 0x2b4);
  }
  return (longdouble)0;
}

