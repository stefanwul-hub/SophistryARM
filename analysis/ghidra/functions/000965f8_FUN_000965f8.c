/* 000965f8 FUN_000965f8 */

bool FUN_000965f8(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x2c,param_2,0,0,0);
    return iVar1 != 0;
  }
  return false;
}

