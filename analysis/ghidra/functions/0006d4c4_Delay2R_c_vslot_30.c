/* 0006d4c4 Delay2R_c_vslot_30 */

void Delay2R_c_vslot_30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if ((param_3 == -1) || (param_3 == 8)) {
    iVar1 = FUN_00012888(param_1,param_2);
    if (iVar1 == 0) {
      return;
    }
    if (*(char *)(iVar1 + 0x39c) == '\0') {
      FUN_000109c8(iVar1 + 0x3f0,*(undefined4 *)(iVar1 + 0x414));
      FUN_000109c8(iVar1 + 0x380,1);
    }
    if (param_3 == -1) goto LAB_0006d525;
  }
  if (param_3 != 4) {
    return;
  }
LAB_0006d525:
  iVar1 = FUN_00012888(param_1,param_2);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x1c8) != 0)) {
    FUN_000109c8(iVar1 + 0x460,-*(int *)(iVar1 + 0x1c8));
    FUN_000109c8();
    return;
  }
  return;
}

