/* 000186f4 Kaja_c_vslot_249 */

bool Kaja_c_vslot_249(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xf < param_2) {
    param_2 = 0xf;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar1 = *(int *)(param_1 + 0xcfb0) + -1;
  if (param_3 <= iVar1) {
    iVar1 = param_3;
  }
  iVar1 = Envelope_c_vslot_12(param_1 + 0x5a4,iVar1,8);
  return iVar1 == 0x10 || param_2 == iVar1;
}

