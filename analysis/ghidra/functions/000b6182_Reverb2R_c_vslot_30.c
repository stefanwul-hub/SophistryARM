/* 000b6182 Reverb2R_c_vslot_30 */

void Reverb2R_c_vslot_30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  iVar1 = FUN_00012888(param_1,param_2);
  if ((iVar1 != 0) && ((param_3 == -1 || (param_3 == 2)))) {
    if (*(int *)(iVar1 + 0xe8) != -1) {
      FUN_000109c8(iVar1 + 0x2a0,*(int *)(iVar1 + 0xe8) * 10);
    }
    FUN_000109c8();
    return;
  }
  return;
}

