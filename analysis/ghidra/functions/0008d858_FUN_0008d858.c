/* 0008d858 FUN_0008d858 */

void FUN_0008d858(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 *param_5
                 )

{
  if ((*(int *)(param_1 + 0x120) != 0) && (param_4 != (undefined4 *)0x0)) {
    *param_4 = *(undefined4 *)(param_1 + 0x1d4 + param_2 * 4);
    param_4[1] = 0;
    *param_5 = *(undefined4 *)(param_1 + 0x44c + param_2 * 4);
  }
  return;
}

