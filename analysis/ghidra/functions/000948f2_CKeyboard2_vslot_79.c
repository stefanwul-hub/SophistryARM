/* 000948f2 CKeyboard2_vslot_79 */

void CKeyboard2_vslot_79(int param_1,int param_2,int param_3)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7f < param_2) {
    param_2 = 0x7f;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x7f < param_3) {
    param_3 = 0x7f;
  }
  if (param_3 != *(int *)(param_1 + 0xb0 + param_2 * 4)) {
    *(int *)(param_1 + 0xb0 + param_2 * 4) = param_3;
    *(undefined1 *)(param_1 + 0x74) = 1;
  }
  return;
}

