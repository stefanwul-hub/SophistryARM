/* 000118be FUN_000118be */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000118be(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,char param_6)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(char **)(param_1 + 0x40) = "dB";
  *(undefined4 *)(param_1 + 4) = 5;
  *(undefined4 *)(param_1 + 0x20) = 5;
  iVar1 = param_3 * 5 + -1 + (uint)(param_6 == '\0');
  *(int *)(param_1 + 0x44) = iVar1;
  *(int *)(param_1 + 0x24) = iVar1;
  *(int *)(param_1 + 0x48) = param_4 * 5;
  *(int *)(param_1 + 0x28) = param_4 * 5;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  lVar3 = (longdouble)_pow(0,0x40240000,0,0);
  *(int *)(param_1 + 100) = (int)((float)lVar3 + 0.5);
  if (param_6 == '\0') {
    FUN_0002d6d6(param_1 + 0x68,1);
  }
  else {
    FUN_0002d6c8(param_1 + 0x68,1);
  }
  FUN_0002d6d6(param_1 + 0x68,2);
  iVar1 = *(int *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x44) <= param_5) {
    iVar1 = param_5;
  }
  iVar2 = *(int *)(param_1 + 0x48);
  if (iVar1 <= *(int *)(param_1 + 0x48)) {
    iVar2 = iVar1;
  }
  *(int *)(param_1 + 0x5c) = iVar2;
  *(int *)(param_1 + 0x4c) = iVar2;
  *(int *)(param_1 + 0x2c) = iVar2;
  FUN_0000ff7e();
  return;
}

