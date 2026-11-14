/* 000952e0 Synth_vslot_48 */

void Synth_vslot_48(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 8;
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffff7;
  return;
}

