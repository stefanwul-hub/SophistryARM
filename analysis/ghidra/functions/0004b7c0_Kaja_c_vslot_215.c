/* 0004b7c0 Kaja_c_vslot_215 */

void Kaja_c_vslot_215(int param_1)

{
  Synth_vslot_215(param_1);
  Envelope_c_vslot_10(param_1 + 0x3cc,0,1,0);
  Envelope_c_vslot_10(param_1 + 0x3cc,0,0x19,6);
  return;
}

