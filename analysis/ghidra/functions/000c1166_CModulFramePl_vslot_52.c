/* 000c1166 CModulFramePl_vslot_52 */

void CModulFramePl_vslot_52(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x50) = *param_2;
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  return;
}

