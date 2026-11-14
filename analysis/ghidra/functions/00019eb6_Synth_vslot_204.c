/* 00019eb6 Synth_vslot_204 */

undefined4 Synth_vslot_204(int *param_1,int param_2)

{
  if (param_2 == 0xb) {
    (**(code **)(*param_1 + 0x32c))(param_1,0x10,0,0,0);
    return 1;
  }
  if (param_2 != 0xd) {
    return 0;
  }
  (**(code **)(*param_1 + 0x32c))(param_1,0xf,0,0,0);
  return 1;
}

