/* 0002790a FUN_0002790a */

void FUN_0002790a(int *param_1,undefined4 param_2,int *param_3)

{
  if (param_3 == (int *)0x0) {
    return;
  }
  if ((param_3[0x2a] != 9) && (param_3[0x2a] == 0xf)) {
    (**(code **)(*param_1 + 0x98))(param_1);
                    /* WARNING: Could not recover jumptable at 0x0002796c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_3 + 0x54))();
    return;
  }
  FUN_00026254(param_1,param_3);
                    /* WARNING: Could not recover jumptable at 0x0002794b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x54))();
  return;
}

