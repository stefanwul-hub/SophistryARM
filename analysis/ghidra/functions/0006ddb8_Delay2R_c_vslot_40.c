/* 0006ddb8 Delay2R_c_vslot_40 */

void Delay2R_c_vslot_40(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x140);
  *(undefined4 *)(param_1 + 0x140) = param_2;
  FUN_0006dc60(param_1);
  *(undefined4 *)(param_1 + 0x140) = uVar1;
  Crossfader_c_vslot_3(param_1 + 0xa50,param_2);
  Crossfader_c_vslot_3(param_1 + 0xa74,param_2);
  Part_c_vslot_40();
  return;
}

