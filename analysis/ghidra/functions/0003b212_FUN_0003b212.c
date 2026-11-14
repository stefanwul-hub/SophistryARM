/* 0003b212 FUN_0003b212 */

int FUN_0003b212(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 != 0) {
    *(int *)(param_1 + 0x1e0) = param_2;
    *(undefined4 *)(param_1 + 0x1e4) = param_3;
    param_2 = 1;
  }
  return param_2;
}

