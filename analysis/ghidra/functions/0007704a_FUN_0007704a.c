/* 0007704a FUN_0007704a */

void FUN_0007704a(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  param_1[0x7a] = param_2;
  param_1[0x7b] = param_3;
  param_1[0x7c] = param_4;
  param_1[0x7d] = param_5;
                    /* WARNING: Could not recover jumptable at 0x00077080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}

