/* 0000ce56 Instrument_c_vslot_20 */

void Instrument_c_vslot_20(int *param_1)

{
  (**(code **)(*param_1 + 0xa8))(param_1,0x10);
                    /* WARNING: Could not recover jumptable at 0x0000ce83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xbc))();
  return;
}

