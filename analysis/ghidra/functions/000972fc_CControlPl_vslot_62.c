/* 000972fc CControlPl_vslot_62 */

void CControlPl_vslot_62(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x54);
  if ((fVar1 < *(float *)(param_1 + 0x4c)) ||
     (fVar1 = *(float *)(param_1 + 0x50), *(float *)(param_1 + 0x4c) < fVar1)) {
    *(float *)(param_1 + 0x4c) = fVar1;
  }
  return;
}

