/* 0001325a Envelope_c_vslot_55 */

void Envelope_c_vslot_55(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)_malloc(6);
  *puVar1 = (char)((uint)param_2 >> 0x18);
  puVar1[1] = (char)((uint)param_2 >> 0x10);
  puVar1[2] = (char)((uint)param_2 >> 8);
  puVar1[3] = (char)param_2;
  puVar1[4] = 0;
  return;
}

