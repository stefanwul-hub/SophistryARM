/* 000076e8 CModDepthDisp_vslot_80 */

void CModDepthDisp_vslot_80(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 0xd0) = (char)param_2;
  *(char *)(param_1 + 0xd1) = (char)((uint)param_2 >> 8);
  *(char *)(param_1 + 0xd2) = (char)((uint)param_2 >> 0x10);
  *(char *)(param_1 + 0xd3) = (char)((uint)param_2 >> 0x18);
  return;
}

