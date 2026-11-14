/* 000952c8 Synth_vslot_47 */

void Synth_vslot_47(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 2;
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffffd;
  return;
}

