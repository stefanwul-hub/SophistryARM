/* 0000fa74 RampGlide_c_vslot_57 */

void RampGlide_c_vslot_57(int param_1)

{
  if (*(char *)(param_1 + 0x1f8) != '\0') {
    **(undefined4 **)(param_1 + 0x1d8) = 0;
    **(undefined4 **)(param_1 + 0x1dc) = 0x7ffffbff;
  }
  return;
}

