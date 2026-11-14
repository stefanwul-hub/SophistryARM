/* 0004da9e Kaja_c_vslot_181 */

void Kaja_c_vslot_181(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    iVar1 = FUN_00012888("Gen 2 Release" + param_1,param_2);
    if (iVar1 != 0) {
      FUN_000109c8(iVar1 + 0x70,*param_3);
      FUN_000109c8(iVar1 + 0xe0,param_3[1]);
      FUN_000109c8(iVar1 + 0x150,param_3[2]);
      FUN_000109c8();
      return;
    }
  }
  return;
}

