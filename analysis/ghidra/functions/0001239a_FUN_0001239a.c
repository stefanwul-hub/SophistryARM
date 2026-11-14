/* 0001239a FUN_0001239a */

undefined4 FUN_0001239a(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    uVar1 = FUN_00010b1c();
    return uVar1;
  }
  return 0;
}

