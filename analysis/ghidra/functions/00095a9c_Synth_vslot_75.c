/* 00095a9c Synth_vslot_75 */

undefined4 Synth_vslot_75(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,7,0,param_2,0,0);
    return uVar1;
  }
  return 0;
}

