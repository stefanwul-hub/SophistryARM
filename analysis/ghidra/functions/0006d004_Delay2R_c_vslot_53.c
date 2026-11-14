/* 0006d004 Delay2R_c_vslot_53 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Delay2R_c_vslot_53(int param_1)

{
  byte bVar1;
  
  Envelope_c_vslot_53(param_1);
  bVar1 = *(int *)(param_1 + 0xa44) != 0 & *(byte *)(param_1 + 0x15c);
  *(byte *)(param_1 + 0x15c) = bVar1;
  *(byte *)(param_1 + 0x15c) =
       0 < *(int *)(param_1 + 0xa48) &
       *(int *)(param_1 + 0x120) != 0 & 11000.0 < *(float *)(param_1 + 0x140) & bVar1;
  return;
}

