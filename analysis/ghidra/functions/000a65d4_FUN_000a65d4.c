/* 000a65d4 FUN_000a65d4 */

int FUN_000a65d4(int *param_1)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar1 == 0) {
      *(undefined1 *)((int)param_1 + 0xd) = 1;
      (**(code **)(*param_1 + 0xbc))(param_1);
      return 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

