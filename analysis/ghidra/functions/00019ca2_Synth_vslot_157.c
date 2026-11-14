/* 00019ca2 Synth_vslot_157 */

void Synth_vslot_157(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x14))(param_1);
  (**(code **)(*param_1 + 0x278))(param_1);
  if (0 < param_1[0x2693]) {
    iVar1 = 0;
    do {
      FUN_00019748(param_1,0,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x2693]);
  }
  if (0 < param_1[0x33ec]) {
    iVar1 = 0;
    do {
      while (*(char *)((int)param_1 + 0xcfd5) != '\0') {
        Envelope_c_vslot_9(param_1 + 0x169,iVar1,1,iVar1);
        iVar1 = iVar1 + 1;
        if (param_1[0x33ec] <= iVar1) goto LAB_00019d2e;
      }
      (**(code **)(*param_1 + 0x2a4))(param_1,iVar1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x33ec]);
  }
LAB_00019d2e:
                    /* WARNING: Could not recover jumptable at 0x00019d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x18))();
  return;
}

