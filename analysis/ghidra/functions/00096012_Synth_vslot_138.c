/* 00096012 Synth_vslot_138 */

void Synth_vslot_138(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x800;
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffff7ff;
  return;
}

