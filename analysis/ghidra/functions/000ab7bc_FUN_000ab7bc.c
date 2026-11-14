/* 000ab7bc FUN_000ab7bc */

void FUN_000ab7bc(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    _CFRelease(*(int *)(param_1 + 0x30));
  }
  *(int *)(param_1 + 0x30) = param_2;
  if (param_2 != 0) {
    _CFRetain(param_2);
  }
  return;
}

