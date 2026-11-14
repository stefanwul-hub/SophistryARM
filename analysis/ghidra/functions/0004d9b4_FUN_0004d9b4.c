/* 0004d9b4 FUN_0004d9b4 */

void FUN_0004d9b4(int *param_1,int param_2,int param_3,int param_4)

{
  undefined1 local_2b0 [676];
  
  if ((param_2 < 0) || (0 < param_2)) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (1 < param_3) {
    param_3 = 1;
  }
  if (param_4 != 0) {
    FUN_0006aacc(local_2b0,param_1,param_1 + param_3 * 0x286e + 0x23678,param_2);
    FUN_000349f0(param_1 + param_3 * 0x286e + 0x23678,param_2);
    FUN_0006aa82(local_2b0,param_4);
    (**(code **)(*param_1 + 0x350))(param_1);
    (**(code **)(*param_1 + 700))(param_1);
    InterSF2_c_vslot_0(local_2b0);
  }
  return;
}

