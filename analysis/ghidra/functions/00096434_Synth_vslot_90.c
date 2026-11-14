/* 00096434 Synth_vslot_90 */

void Synth_vslot_90(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x200;
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffdff;
  return;
}

