/* 00095b3c FUN_00095b3c */

bool FUN_00095b3c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,8,0,0,param_2,0);
    return iVar1 == 1;
  }
  return false;
}

