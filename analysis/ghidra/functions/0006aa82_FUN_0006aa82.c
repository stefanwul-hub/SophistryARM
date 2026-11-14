/* 0006aa82 FUN_0006aa82 */

void FUN_0006aa82(int *param_1,char *param_2)

{
  char cVar1;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    cVar1 = FUN_0000979c(param_1 + 1,param_2);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 8))(param_1);
      FUN_000098c4();
      return;
    }
  }
  return;
}

