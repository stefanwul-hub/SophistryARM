/* 00012bda Envelope_c_vslot_12 */

undefined4 Envelope_c_vslot_12(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    uVar1 = FUN_000122c2();
    return uVar1;
  }
  return 0;
}

