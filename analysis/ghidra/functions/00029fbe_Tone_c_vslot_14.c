/* 00029fbe Tone_c_vslot_14 */

void Tone_c_vslot_14(int param_1,float param_2)

{
  *(float *)(param_1 + 300) = param_2;
  *(float *)(param_1 + 0x134) = param_2 + *(float *)(param_1 + 0x130);
  return;
}

