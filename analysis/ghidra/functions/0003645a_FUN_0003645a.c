/* 0003645a FUN_0003645a */

void FUN_0003645a(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  param_1[0x8e] = param_2;
  param_1[0x7e] = param_3;
  param_1[0x7f] = param_4;
  param_1[0x80] = param_5;
  param_1[0x81] = param_6;
  if ((param_5 != 0) && (param_6 != 0)) {
    *(undefined1 *)((int)param_1 + 0x459) = 1;
                    /* WARNING: Could not recover jumptable at 0x000364ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
  *(undefined1 *)((int)param_1 + 0x459) = 0;
                    /* WARNING: Could not recover jumptable at 0x000364c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}

