/* 00010b1c FUN_00010b1c */

int FUN_00010b1c(int param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) != 0) {
    pcVar1 = *(char **)(param_1 + 0x30);
    pcVar2 = _strstr(pcVar1,param_2);
    if ((pcVar2 != (char *)0x0) &&
       (iVar3 = (int)pcVar2 - (int)pcVar1, iVar3 % *(int *)(param_1 + 0x54) == 0)) {
      return iVar3 / *(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x44);
    }
  }
  return 0;
}

