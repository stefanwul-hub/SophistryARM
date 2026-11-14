/* 00010462 FUN_00010462 */

undefined4 FUN_00010462(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0002d6ea(param_1 + 0x68,2);
  if ((cVar1 == '\0') || (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x48))) {
    cVar1 = FUN_0002d6ea(param_1 + 0x68,1);
    if ((cVar1 == '\0') || (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x44))) {
      return 0;
    }
  }
  return 1;
}

