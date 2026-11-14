/* 000ab9ac FUN_000ab9ac */

void FUN_000ab9ac(int *param_1,int param_2)

{
  char cVar1;
  
  if (*(char *)(param_1[1] + 0xd) != '\0') {
    if (param_2 == 0) {
      param_2 = *(int *)(param_1[1] + 0xa0);
    }
    cVar1 = (**(code **)(*param_1 + 0x10))(param_1);
    if (cVar1 == '\0') {
      param_2 = 0;
    }
    FUN_000ae25c(param_1 + 0x17,param_1 + 0xd,param_2);
  }
  return;
}

