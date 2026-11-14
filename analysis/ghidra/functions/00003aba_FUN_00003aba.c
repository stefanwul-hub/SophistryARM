/* 00003aba FUN_00003aba */

void FUN_00003aba(int param_1,int param_2)

{
  if ((param_2 != 0) && (*(char *)(param_2 + 0x32b418) != '\0')) {
    (**(code **)(*(int *)(param_2 + 0xec) + 600))(param_2 + 0xec);
  }
  if (param_1 != 0) {
    _SetEventLoopTimerNextFireTime(param_1,0,0x3fd00000);
  }
  return;
}

