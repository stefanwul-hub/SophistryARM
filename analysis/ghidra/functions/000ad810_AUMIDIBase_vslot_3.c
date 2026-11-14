/* 000ad810 AUMIDIBase_vslot_3 */

undefined4 AUMIDIBase_vslot_3(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    return 0xffffd58e;
  }
  if (param_4 != 0) {
    return 0xffffd583;
  }
  if (param_2 != 0x3ee) {
    return 0xffffd581;
  }
                    /* WARNING: Could not recover jumptable at 0x000ad857. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x1c))();
  return uVar1;
}

