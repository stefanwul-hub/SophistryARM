/* 00010c3c FUN_00010c3c */

void FUN_00010c3c(int param_1,char *param_2,short param_3)

{
  if (((param_2 != (char *)0x0) && (*(char **)(param_1 + 0x40) != (char *)0x0)) && (0 < param_3)) {
    _strncpy(param_2,*(char **)(param_1 + 0x40),(int)param_3 - 1);
    param_2[param_3 + -1] = '\0';
  }
  return;
}

