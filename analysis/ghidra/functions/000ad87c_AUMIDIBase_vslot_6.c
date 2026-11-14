/* 000ad87c AUMIDIBase_vslot_6 */

void AUMIDIBase_vslot_6(int *param_1,byte param_2,undefined4 param_3,char param_4)

{
  code *UNRECOVERED_JUMPTABLE_00;
  
  if (param_2 == 0xc0) {
                    /* WARNING: Could not recover jumptable at 0x000ad928. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x34))();
    return;
  }
  if (param_2 < 0xc1) {
    if (param_2 == 0xa0) {
                    /* WARNING: Could not recover jumptable at 0x000ad9ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x38))();
      return;
    }
    if (param_2 == 0xb0) {
      if (param_4 == 'y') {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(*param_1 + 0x3c);
      }
      else if (param_4 == '{') {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(*param_1 + 0x40);
      }
      else {
        if (param_4 != 'x') {
          UNRECOVERED_JUMPTABLE_00 = *(code **)(*param_1 + 0x28);
          goto LAB_000ad952;
        }
        UNRECOVERED_JUMPTABLE_00 = *(code **)(*param_1 + 0x44);
      }
                    /* WARNING: Could not recover jumptable at 0x000ad9c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
  }
  else {
    if (param_2 == 0xd0) {
                    /* WARNING: Could not recover jumptable at 0x000ad97c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x30))();
      return;
    }
    if (param_2 == 0xe0) {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*param_1 + 0x2c);
LAB_000ad952:
                    /* WARNING: Could not recover jumptable at 0x000ad958. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
  }
  return;
}

