/* 000ae9ac FUN_000ae9ac */

void FUN_000ae9ac(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    _RemoveEventLoopTimer(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    _DisposeEventLoopTimerUPP(*(int *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined1 *)(param_1 + 0x14) = 0;
  return;
}

