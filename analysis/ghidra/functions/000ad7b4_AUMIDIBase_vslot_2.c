/* 000ad7b4 AUMIDIBase_vslot_2 */

undefined4
AUMIDIBase_vslot_2(int *param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                  undefined1 *param_6)

{
  int iVar1;
  
  if (param_3 != 0) {
    return 0xffffd58e;
  }
  if (param_4 != 0) {
    return 0xffffd583;
  }
  if (param_2 == 0x3ee) {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,0);
    if (iVar1 == 0) {
      *param_5 = 4;
      *param_6 = 0;
      return 0;
    }
  }
  return 0xffffd581;
}

