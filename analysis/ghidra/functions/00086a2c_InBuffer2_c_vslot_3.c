/* 00086a2c InBuffer2_c_vslot_3 */

void InBuffer2_c_vslot_3(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  void *pvVar1;
  
  if (((1 < param_4) && (param_4 < 7)) && (param_5 != 0)) {
    *(undefined1 *)((int)param_1 + 0x25) = 1;
    param_1[4] = param_2;
    param_1[7] = param_3;
    param_1[5] = param_4;
    if (param_4 == 2) {
      param_1[6] = 3;
      if (0 < param_3) {
        pvVar1 = _malloc(param_3 * 4 + 0x14);
        param_1[0xe] = (int)pvVar1;
      }
    }
    else {
      param_1[6] = param_4 + 2;
      if (0 < param_3) {
        pvVar1 = _malloc(param_3 * 4 + 0x14);
        param_1[0xe] = (int)pvVar1;
      }
      if (0 < param_1[7]) {
        pvVar1 = _malloc(param_1[7] * 4 + 0x14);
        param_1[0x10] = (int)pvVar1;
      }
    }
    param_1[3] = param_5;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)((int)param_1 + 9) = 1;
    (**(code **)(*param_1 + 0x68))(param_1);
                    /* WARNING: Could not recover jumptable at 0x00086ab9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x5c))();
    return;
  }
  return;
}

