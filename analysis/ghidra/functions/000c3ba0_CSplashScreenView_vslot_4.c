/* 000c3ba0 CSplashScreenView_vslot_4 */

void CSplashScreenView_vslot_4(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 0x32) == '\0') {
    (**(code **)(*(int *)param_1[0xd] + 0x10))
              ((int *)param_1[0xd],param_2,param_1 + 2,param_1[0xf] + 0x8c);
                    /* WARNING: Could not recover jumptable at 0x000c3c7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x54))();
    return;
  }
  iVar1 = param_1[0xf];
  if (*(char *)(iVar1 + 0x94) != '\0') {
    (**(code **)(*(int *)param_1[0xd] + 0x18))
              ((int *)param_1[0xd],param_2,param_1 + 2,iVar1 + 0x8c,*(char *)(iVar1 + 0x94));
                    /* WARNING: Could not recover jumptable at 0x000c3c08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x54))();
    return;
  }
  (**(code **)(*(int *)param_1[0xd] + 0x14))((int *)param_1[0xd],param_2,param_1 + 2,iVar1 + 0x8c);
                    /* WARNING: Could not recover jumptable at 0x000c3c42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x54))();
  return;
}

