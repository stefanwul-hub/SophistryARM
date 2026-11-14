/* 0000fa2c RampGlide_c_vslot_58 */

void RampGlide_c_vslot_58(int param_1,int param_2,undefined4 param_3,undefined1 param_4)

{
  if (-1 < param_2) {
    if (1 < param_2) {
      param_2 = 1;
    }
    *(undefined4 *)(param_1 + 0x1fc + param_2 * 4) = param_3;
    *(undefined1 *)(param_2 + 0x200 + param_1) = param_4;
    return;
  }
  *(undefined4 *)(param_1 + 0x1fc) = param_3;
  *(undefined1 *)(param_1 + 0x200) = param_4;
  return;
}

