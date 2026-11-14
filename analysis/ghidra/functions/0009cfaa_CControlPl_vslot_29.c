/* 0009cfaa CControlPl_vslot_29 */

void CControlPl_vslot_29(int *param_1,int *param_2)

{
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
                    /* WARNING: Could not recover jumptable at 0x0009cfda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x54))();
  return;
}

