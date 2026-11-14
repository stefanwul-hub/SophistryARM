/* 00017798 FUN_00017798 */

void FUN_00017798(int *param_1)

{
  int iVar1;
  
  if (0 < param_1[0x33ec]) {
    iVar1 = 0;
    do {
      Envelope_c_vslot_9(param_1 + 0x169,iVar1,1,iVar1);
      Envelope_c_vslot_9(param_1 + 0x169,iVar1,10,iVar1 == 0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x33ec]);
                    /* WARNING: Could not recover jumptable at 0x00017826. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x35c))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000177be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x35c))();
  return;
}

