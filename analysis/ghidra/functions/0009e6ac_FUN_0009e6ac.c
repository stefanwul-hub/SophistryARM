/* 0009e6ac FUN_0009e6ac */

void FUN_0009e6ac(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 0x30) = (char)param_2;
  *(char *)(param_1 + 0x31) = (char)((uint)param_2 >> 8);
  *(char *)(param_1 + 0x32) = (char)((uint)param_2 >> 0x10);
  *(char *)(param_1 + 0x33) = (char)((uint)param_2 >> 0x18);
  return;
}

