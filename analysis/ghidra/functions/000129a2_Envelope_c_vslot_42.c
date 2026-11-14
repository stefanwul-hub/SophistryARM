/* 000129a2 Envelope_c_vslot_42 */

void Envelope_c_vslot_42(int param_1,int param_2)

{
  if (0x17 < param_2) {
    if (0x60 < param_2) {
      param_2 = 0x60;
    }
    *(int *)(param_1 + 0x158) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x158) = 0x18;
  return;
}

