/* 00039354 SamWT_c_vslot_31 */

void SamWT_c_vslot_31(int param_1)

{
  if (*(int *)(param_1 + 0x124) != 0) {
    *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x38c);
  }
  return;
}

