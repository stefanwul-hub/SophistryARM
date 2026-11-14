/* 0004b6c8 Kaja_c_vslot_242 */

void Kaja_c_vslot_242(int param_1)

{
  FUN_00017798(param_1);
  Envelope_c_vslot_7("Gen-Tim 2 Reverse" + param_1 + 0x10,0,2,0x3dd9e83e);
  Envelope_c_vslot_7("Gen-WT 1 Ride" + param_1 + 0xc,0,2,0x3dd9e83e);
  Envelope_c_vslot_7("Gen-Tim 2 Reverse" + param_1 + 0x10,0,3,0x3f000000);
  Envelope_c_vslot_7("Gen-WT 1 Ride" + param_1 + 0xc,0,3,0x3f000000);
  Envelope_c_vslot_7("Loop Counter" + param_1 + 4,0,5,0x3f800000);
  Envelope_c_vslot_7("Off  16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
                     + param_1 + 0x14,0,5,0x3f800000);
  return;
}

