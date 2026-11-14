/* 000a661e FUN_000a661e */

void FUN_000a661e(int *param_1)

{
  if (*(char *)((int)param_1 + 0xd) != '\0') {
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  return;
}

