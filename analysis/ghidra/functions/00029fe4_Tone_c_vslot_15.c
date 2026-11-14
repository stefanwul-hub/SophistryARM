/* 00029fe4 Tone_c_vslot_15 */

void Tone_c_vslot_15(int param_1,float param_2)

{
  *(float *)(param_1 + 0x130) = param_2;
  *(float *)(param_1 + 0x134) = param_2 + *(float *)(param_1 + 300);
  return;
}

