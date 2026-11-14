/* 000179d4 Synth_vslot_11 */

void Synth_vslot_11(int *param_1,int param_2)

{
  if ((((char)param_1[0xec4] == '\0') && (param_2 % param_1[0xecf] < param_1[0x2691])) &&
     (((param_1[0x33fa] != 4 && (param_1[0x33fa] != 0xc)) || (param_1[0xed0] != 0)))) {
                    /* WARNING: Could not recover jumptable at 0x00017a26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2b0))();
    return;
  }
  return;
}

