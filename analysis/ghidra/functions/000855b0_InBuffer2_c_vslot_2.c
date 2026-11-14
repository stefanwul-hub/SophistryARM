/* 000855b0 InBuffer2_c_vslot_2 */

void InBuffer2_c_vslot_2(int *param_1,int param_2,int param_3,int param_4,int param_5,
                        undefined1 param_6,undefined1 param_7)

{
  if ((((0 < param_3) && (0 < param_4)) && (param_4 < 7)) && (param_5 != 0)) {
    param_1[4] = param_2;
    param_1[7] = param_3;
    param_1[5] = param_4;
    if (param_4 == 1) {
      param_1[6] = 1;
    }
    else if (param_4 == 2) {
      param_1[6] = 3;
    }
    else if (2 < param_4) {
      param_1[6] = param_4 + 2;
    }
    param_1[3] = param_5;
    (**(code **)(*param_1 + 0x54))(param_1);
    *(undefined1 *)(param_1 + 2) = param_6;
    *(undefined1 *)((int)param_1 + 9) = param_7;
    (**(code **)(*param_1 + 0x68))(param_1);
                    /* WARNING: Could not recover jumptable at 0x00085630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x5c))();
    return;
  }
  return;
}

