/* 00025988 FUN_00025988 */

void FUN_00025988(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_2 + 0x24))(param_2);
  FUN_0000b87a(param_1 + 0x54 + param_3 * 0x68,param_3,param_1,*(undefined4 *)(param_1 + 0x4c),
               param_4,param_5,param_6,param_7,*(undefined4 *)(param_1 + 0x34),uVar1,param_2);
  *(undefined4 *)(param_3 * 0xc + 0x2085c + param_1) = 0xd;
  return;
}

