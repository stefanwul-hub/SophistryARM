/* 0003eb16 DelayStereo_c_vslot_53 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayStereo_c_vslot_53(int param_1)

{
  byte bVar1;
  
  Envelope_c_vslot_53(param_1);
  bVar1 = *(int *)(param_1 + 0x224) != 0 &
          *(int *)(param_1 + 0x220) != 0 & *(byte *)(param_1 + 0x15c);
  *(byte *)(param_1 + 0x15c) = bVar1;
  *(byte *)(param_1 + 0x15c) =
       0 < *(int *)(param_1 + 0x228) &
       *(int *)(param_1 + 0x120) != 0 & 22000.0 < *(float *)(param_1 + 0x140) & bVar1;
  return;
}

