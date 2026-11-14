/* 00095316 Synth_vslot_28 */

void Synth_vslot_28(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x20;
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xffffffdf;
  return;
}

