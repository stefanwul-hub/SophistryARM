/* 00012a40 Envelope_c_vslot_47 */

void Envelope_c_vslot_47(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x18 + param_2 * 8) = param_3;
  *(undefined4 *)(param_1 + 0x1c + param_2 * 8) = param_4;
  if (param_2 != *(int *)(param_1 + 0x128)) {
    return;
  }
  *(undefined4 *)(param_1 + 0x118) = param_3;
  *(undefined4 *)(param_1 + 0x11c) = param_4;
  return;
}

