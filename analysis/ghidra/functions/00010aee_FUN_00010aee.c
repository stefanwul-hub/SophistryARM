/* 00010aee FUN_00010aee */

void FUN_00010aee(int param_1,char *param_2)

{
  if ((param_2 != (char *)0x0) && (*param_2 = '\0', *(int *)(param_1 + 4) != 0)) {
    _strcpy(param_2,*(char **)(param_1 + 0x60));
    return;
  }
  return;
}

