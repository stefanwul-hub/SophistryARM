/* 00012b44 Envelope_c_vslot_8 */

longdouble Envelope_c_vslot_8(int param_1)

{
  longdouble lVar1;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    lVar1 = (longdouble)FUN_000121dc();
    return lVar1;
  }
  return (longdouble)0;
}

