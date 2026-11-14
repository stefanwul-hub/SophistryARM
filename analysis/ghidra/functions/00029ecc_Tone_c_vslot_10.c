/* 00029ecc Tone_c_vslot_10 */

void Tone_c_vslot_10(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
                    int param_7,undefined4 param_8)

{
  if (((param_2 != 0) && (param_3 != 0)) && ((param_5 != 0 || (param_7 == 0)))) {
    if ((param_6 == 0) && (param_7 != 0)) {
      return;
    }
    *(int *)(param_1 + 4) = param_2;
    *(int *)(param_1 + 0xc38) = param_3;
    *(undefined4 *)(param_1 + 0x13c) = param_4;
    *(int *)(param_1 + 0xc3c) = param_5;
    *(int *)(param_1 + 0xc40) = param_6;
    *(int *)(param_1 + 0xc48) = param_7;
    *(undefined4 *)(param_1 + 0xc4c) = param_8;
  }
  return;
}

