/* 00012bf8 Envelope_c_vslot_13 */

uint Envelope_c_vslot_13(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x120);
  if (uVar1 != 0) {
    uVar1 = FUN_000122e4(uVar1,param_2,param_3);
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}

