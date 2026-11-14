/* 00007740 FUN_00007740 */

void FUN_00007740(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xf4) != param_2) {
    *(int *)(param_1 + 0xf4) = param_2;
    *(undefined1 *)(param_1 + 0x74) = 1;
  }
  return;
}

