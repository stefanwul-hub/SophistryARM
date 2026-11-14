/* 00010b62 FUN_00010b62 */

void FUN_00010b62(int param_1,char *param_2)

{
  size_t sVar1;
  
  if ((param_2 != (char *)0x0) && (*param_2 = '\0', *(int *)(param_1 + 4) != 0)) {
    sVar1 = *(size_t *)(param_1 + 0x54);
    _strncpy(param_2,(char *)(sVar1 * (*(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x44)) +
                             *(int *)(param_1 + 0x30)),sVar1);
    param_2[sVar1] = '\0';
    return;
  }
  return;
}

