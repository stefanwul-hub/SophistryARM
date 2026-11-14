/* 000ad9ec AUMIDIBase_vslot_5 */

undefined4
AUMIDIBase_vslot_5(int *param_1,char param_2,undefined1 param_3,undefined1 param_4,char param_5,
                  undefined4 param_6)

{
  if (*(char *)(param_1[1] + 0xd) == '\0') {
    return 0xffffd58d;
  }
  if (param_2 != -0x80) {
    if (param_2 == -0x70) {
      if (param_5 == '\0') {
        (**(code **)(*param_1 + 0x24))(param_1,param_3,param_4,0,param_6);
      }
      else {
        (**(code **)(*param_1 + 0x20))(param_1,param_3,param_4,param_5,param_6);
      }
    }
    else {
      (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    return 0;
  }
  (**(code **)(*param_1 + 0x24))(param_1,param_3,param_4,param_5,param_6);
  return 0;
}

