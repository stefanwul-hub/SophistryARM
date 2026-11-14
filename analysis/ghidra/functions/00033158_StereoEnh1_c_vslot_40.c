/* 00033158 StereoEnh1_c_vslot_40 */

void StereoEnh1_c_vslot_40(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x140);
  *(undefined4 *)(param_1 + 0x140) = param_2;
  FUN_00033024(param_1);
  *(undefined4 *)(param_1 + 0x140) = uVar1;
  Part_c_vslot_40();
  return;
}

