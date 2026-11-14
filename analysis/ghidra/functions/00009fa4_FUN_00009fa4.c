/* 00009fa4 FUN_00009fa4 */

void FUN_00009fa4(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  
  if ((((param_3 != (char *)0x0) && (*param_3 != '\0')) && (param_2 != (char *)0x0)) &&
     (*param_2 != '\0')) {
    pcVar1 = _strchr(param_3,(int)*(char *)(param_1 + 0x10));
    if (pcVar1 == (char *)0x0) {
      pcVar1 = _strchr(param_3,(int)*(char *)(param_1 + 0x11));
      if (pcVar1 == (char *)0x0) {
        pcVar1 = _strchr(param_3,(int)*(char *)(param_1 + 0x12));
        if (pcVar1 == (char *)0x0) {
          FUN_00009ebe();
          return;
        }
      }
    }
  }
  return;
}

