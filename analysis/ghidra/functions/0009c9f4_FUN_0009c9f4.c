/* 0009c9f4 FUN_0009c9f4 */

void FUN_0009c9f4(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x3c) != param_2) {
    *(int *)(param_1 + 0x3c) = param_2;
    if (*(int *)(param_1 + 0x60) != 0) {
      _CGContextSetLineWidth();
      return;
    }
  }
  return;
}

