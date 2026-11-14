/* 0009637a Synth_vslot_86 */

undefined4
Synth_vslot_86(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x23,param_2,param_3,param_4,param_5);
    return uVar1;
  }
  return 0;
}

