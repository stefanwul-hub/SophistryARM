/* 000091e0 CVarDisplay_vslot_80 */

void CVarDisplay_vslot_80(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 0xbc) = (char)param_2;
  *(char *)(param_1 + 0xbd) = (char)((uint)param_2 >> 8);
  *(char *)(param_1 + 0xbe) = (char)((uint)param_2 >> 0x10);
  *(char *)(param_1 + 0xbf) = (char)((uint)param_2 >> 0x18);
  return;
}

