/* 000b6120 Reverb2R_c_vslot_53 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Reverb2R_c_vslot_53(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  Envelope_c_vslot_53(param_1);
  bVar1 = *(int *)(param_1 + 0x124) != 0 &
          22000.0 < *(float *)(param_1 + 0x140) & *(byte *)(param_1 + 0x15c);
  *(byte *)(param_1 + 0x15c) = bVar1;
  bVar2 = FUN_000b60a8(param_1);
  *(byte *)(param_1 + 0x15c) = bVar1 & bVar2;
  return;
}

