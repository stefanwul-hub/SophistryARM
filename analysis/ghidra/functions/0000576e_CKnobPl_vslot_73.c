/* 0000576e CKnobPl_vslot_73 */

void CKnobPl_vslot_73(int *param_1)

{
  if (*(char *)((int)param_1 + 0x75) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0000578c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x13c))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000057a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x140))();
  return;
}

