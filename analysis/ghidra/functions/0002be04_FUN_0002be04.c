/* 0002be04 FUN_0002be04 */

void FUN_0002be04(int param_1,int param_2,int param_3)

{
  if (((param_1 == 2) && (param_3 != 0)) && (*(int *)(param_3 + 0xc) != 0)) {
    _NavCustomControl(*(undefined4 *)(param_2 + 2),8,param_3 + 8);
    return;
  }
  return;
}

