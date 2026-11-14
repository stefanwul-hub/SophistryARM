/* 0001b998 Synth_vslot_21 */

undefined4 Synth_vslot_21(int *param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  
  if ((char)param_1[0x33f1] == '\0') {
    return 0;
  }
  _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
  if (param_3 == '\0') {
    uVar1 = (**(code **)(*param_1 + 0x2c0))(param_1,param_2);
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x2d0))(param_1,param_1[0x33f8],param_2);
  }
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  return uVar1;
}

