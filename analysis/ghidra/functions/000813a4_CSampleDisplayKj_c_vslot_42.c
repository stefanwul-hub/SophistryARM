/* 000813a4 CSampleDisplayKj_c_vslot_42 */

void CSampleDisplayKj_c_vslot_42(int *param_1)

{
  if ((char)param_1[0x1d] == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000813b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}

