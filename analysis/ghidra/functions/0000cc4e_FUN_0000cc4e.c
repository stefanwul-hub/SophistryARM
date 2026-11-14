/* 0000cc4e FUN_0000cc4e */

void FUN_0000cc4e(int param_1,char param_2)

{
  *(char *)(param_1 + 0xec0) = param_2;
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x1adc) = 0;
  }
  return;
}

