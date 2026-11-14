/* 00085a30 InBuffer2_c_vslot_20 */

void InBuffer2_c_vslot_20(undefined4 param_1,int param_2,int param_3,uint param_4,float *param_5)

{
  uint uVar1;
  float in_XMM1_Da;
  
  if (0 < (int)param_4) {
    uVar1 = 0;
    do {
      if ((uVar1 & 7) == 0) {
        in_XMM1_Da = *param_5;
        param_5 = param_5 + 1;
      }
      *(float *)(param_2 + uVar1 * 4) = in_XMM1_Da * *(float *)(param_3 + uVar1 * 4);
      uVar1 = uVar1 + 1;
    } while (uVar1 != param_4);
  }
  return;
}

