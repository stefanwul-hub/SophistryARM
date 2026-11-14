/* 0000d3ec Instrument_c_vslot_24 */

void Instrument_c_vslot_24(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0xed4 + *(int *)(param_2 + 8) * 4) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x0000d421. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(param_2 + 8) * 0x14 + 0x10d4 + param_1) + 0x10))();
  return;
}

