/* 00010c80 FUN_00010c80 */

void FUN_00010c80(int param_1,char *param_2,short param_3)

{
  if (param_2 != (char *)0x0) {
    if (*(char **)(param_1 + 0x3c) == (char *)0x0) {
      *param_2 = '\0';
      return;
    }
    _strncpy(param_2,*(char **)(param_1 + 0x3c),(int)param_3 - 1);
    param_2[param_3 + -1] = '\0';
  }
  return;
}

