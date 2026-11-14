/* 00012c46 Envelope_c_vslot_16 */

longdouble Envelope_c_vslot_16(int param_1)

{
  longdouble lVar1;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    lVar1 = (longdouble)FUN_000123ec();
    return lVar1;
  }
  return (longdouble)0;
}

