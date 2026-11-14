/* 00089c16 Amp_c_vslot_53 */

void Amp_c_vslot_53(int param_1)

{
  Envelope_c_vslot_53(param_1);
  *(bool *)(param_1 + 0x15c) = *(int *)(param_1 + 0x1e8) != 0;
  return;
}

