/* 00002c9e LPAUSynth_vslot_64 */

undefined4 LPAUSynth_vslot_64(int param_1,uint param_2)

{
  if ((-1 < (int)param_2) && (param_2 < *(uint *)(param_1 + 0x32b424))) {
    return 1;
  }
  return 0;
}

