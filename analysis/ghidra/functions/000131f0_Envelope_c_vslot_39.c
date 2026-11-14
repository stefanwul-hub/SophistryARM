/* 000131f0 Envelope_c_vslot_39 */

void Envelope_c_vslot_39(int param_1,int param_2)

{
  if (param_2 < 0x20) {
    *(undefined1 *)(param_2 + 0x1b4 + param_1) = 0;
  }
  return;
}

