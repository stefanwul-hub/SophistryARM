/* 000c3b3c CSplashScreenView_vslot_7 */

void CSplashScreenView_vslot_7(int *param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  if ((param_4 & 1) == 0) {
    return;
  }
  (**(code **)(*(int *)param_1[0xf] + 0x100))((int *)param_1[0xf],param_2);
  (**(code **)(*(int *)param_1[10] + 0x54))((int *)param_1[10],1);
  (**(code **)(*(int *)param_1[10] + 0x124))((int *)param_1[10],0);
                    /* WARNING: Could not recover jumptable at 0x000c3b9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}

