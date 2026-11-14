/* 00012482 FUN_00012482 */

void FUN_00012482(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  if ((param_4 != (undefined1 *)0x0) &&
     (*param_4 = 0, *(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0)) {
    FUN_00010aee();
    return;
  }
  return;
}

