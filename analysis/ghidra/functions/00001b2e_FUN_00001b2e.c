/* 00001b2e FUN_00001b2e */

void FUN_00001b2e(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4 + param_3 * 0x18) = param_4;
                    /* WARNING: Could not recover jumptable at 0x00001b62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)**(undefined4 **)(param_1 + 0x94))();
  return;
}

