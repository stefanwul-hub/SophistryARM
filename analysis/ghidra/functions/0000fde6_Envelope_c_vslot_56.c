/* 0000fde6 Envelope_c_vslot_56 */

void Envelope_c_vslot_56(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  if (((param_2 != (undefined4 *)0x0) && (param_3 != 0)) && (param_4 != 0)) {
    *(undefined4 **)(param_1 + 0x1d4) = param_2;
    *(int *)(param_1 + 0x1d8) = param_3;
    *(int *)(param_1 + 0x1dc) = param_4;
    *param_2 = 0;
    **(undefined4 **)(param_1 + 0x1d8) = 0;
    **(undefined4 **)(param_1 + 0x1dc) = 0x7ffffbff;
    *(undefined1 *)(param_1 + 0x1f8) = 1;
  }
  return;
}

