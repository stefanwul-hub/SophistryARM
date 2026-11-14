/* 0007812a FilterMoogSI_c_vslot_30 */

void FilterMoogSI_c_vslot_30(int *param_1,int param_2,int param_3)

{
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if ((param_2 == param_1[0x4a]) && (((param_3 == -1 || (param_3 == 3)) || (param_3 == 6)))) {
                    /* WARNING: Could not recover jumptable at 0x00078187. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x7c))();
    return;
  }
  return;
}

