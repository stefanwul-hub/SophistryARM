/* 00087544 Flanger2R_c_vslot_53 */

void Flanger2R_c_vslot_53(int param_1)

{
  Envelope_c_vslot_53(param_1);
  *(byte *)(param_1 + 0x15c) =
       *(int *)(param_1 + 0x210) != 0 & *(int *)(param_1 + 0x20c) != 0 & *(byte *)(param_1 + 0x15c);
  return;
}

