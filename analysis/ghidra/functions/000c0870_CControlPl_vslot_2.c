/* 000c0870 CControlPl_vslot_2 */

void CControlPl_vslot_2(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000c088e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 4))();
  return;
}

