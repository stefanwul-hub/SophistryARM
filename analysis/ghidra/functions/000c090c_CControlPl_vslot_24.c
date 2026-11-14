/* 000c090c CControlPl_vslot_24 */

void CControlPl_vslot_24(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_2[1];
  *(undefined4 *)(param_1 + 0x20) = param_2[2];
  *(undefined4 *)(param_1 + 0x24) = param_2[3];
  return;
}

