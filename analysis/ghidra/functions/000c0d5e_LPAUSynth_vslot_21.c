/* 000c0d5e LPAUSynth_vslot_21 */

undefined4
LPAUSynth_vslot_21(int *param_1,undefined4 param_2,double *param_3,undefined4 param_4,
                  undefined4 param_5)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  
  dVar1 = *param_3;
  dVar2 = *(double *)(param_1 + 0x26);
  *(double *)(param_1 + 0x26) = dVar1;
  if (dVar1 != dVar2) {
    param_4 = param_5;
                    /* WARNING: Could not recover jumptable at 0x000c0da5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*param_1 + 0x58))();
    return uVar3;
  }
  return 0;
}

