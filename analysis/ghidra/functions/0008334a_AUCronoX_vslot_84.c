/* 0008334a AUCronoX_vslot_84 */

undefined4 AUCronoX_vslot_84(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = Synth_vslot_178(param_1 + 0x3b,param_2,param_3,param_4);
  (**(code **)(*param_1 + 0x140))(param_1);
  return uVar1;
}

