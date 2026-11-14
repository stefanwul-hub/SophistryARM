/* 0002a428 Tone_c_vslot_13 */

int Tone_c_vslot_13(int param_1,int param_2)

{
  if (param_2 < 0x18) {
    return param_1 + 0x1d8 + param_2 * 4;
  }
  return 0;
}

