/* 000077b0 CModDepthDisp_vslot_44 */

void CModDepthDisp_vslot_44(int param_1,float param_2)

{
  if (param_2 != *(float *)(*(int *)(param_1 + 0x90) + 4)) {
    *(undefined4 *)(param_1 + 0xf8) = 0xbf800000;
  }
  CControlPl_vslot_44();
  return;
}

