/* 00095256 FUN_00095256 */

void FUN_00095256(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x2c))(param_1,param_2,param_3);
  if ((code *)param_1[1] != (code *)0x0) {
    (*(code *)param_1[1])(param_1 + 8,0,param_2,0,0,param_3);
  }
  return;
}

