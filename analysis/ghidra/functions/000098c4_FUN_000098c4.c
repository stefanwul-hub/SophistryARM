/* 000098c4 FUN_000098c4 */

void FUN_000098c4(int param_1)

{
  if (*(FILE **)(param_1 + 8) != (FILE *)0x0) {
    _fclose(*(FILE **)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

