/* 00025bb8 SynthEditor_c_vslot_5 */

void SynthEditor_c_vslot_5(int *param_1)

{
  if (*(char *)((int)param_1 + 0x51) == '\0') {
    return;
  }
  *(undefined1 *)((int)param_1 + 0x51) = 0;
                    /* WARNING: Could not recover jumptable at 0x00025bd3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x5c))();
  return;
}

