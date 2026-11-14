/* 00033d1c FUN_00033d1c */

void FUN_00033d1c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  param_3 = param_3 * 0x14;
  uVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + -9);
  uVar2 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + -8);
  uVar3 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + -7);
  uVar4 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + -7);
  FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + 0xb,uVar1);
  FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + 0xc,uVar2);
  FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + 0xd,uVar3);
  FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,param_3 + 0xe,uVar4);
  return;
}

