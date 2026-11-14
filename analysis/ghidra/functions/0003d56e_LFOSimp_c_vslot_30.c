/* 0003d56e LFOSimp_c_vslot_30 */

void LFOSimp_c_vslot_30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if ((param_3 == -1) || (param_3 == 4)) {
    iVar1 = FUN_00012888(param_1,param_2);
    if ((iVar1 != 0) && (*(char *)(iVar1 + 0x1dc) == '\0')) {
      FUN_000109c8(iVar1 + 0x230,*(undefined4 *)(iVar1 + 0x254));
      FUN_000109c8();
      return;
    }
  }
  return;
}

