/* 0007a986 OscAnalog3_c_vslot_53 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void OscAnalog3_c_vslot_53(int param_1)

{
  byte bVar1;
  
  Envelope_c_vslot_53(param_1);
  bVar1 = *(int *)(param_1 + 0x200) != 0 &
          *(int *)(param_1 + 0x1fc) != 0 &
          *(int *)(param_1 + 0x1f8) != 0 & *(byte *)(param_1 + 0x15c);
  *(byte *)(param_1 + 0x15c) = bVar1;
  *(byte *)(param_1 + 0x15c) =
       *(int *)(param_1 + 0x124) != 0 & 22000.0 < *(float *)(param_1 + 0x140) & bVar1;
  return;
}

