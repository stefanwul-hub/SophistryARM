/* 0000142c CControlPl_vslot_66 */

void CControlPl_vslot_66(int param_1,int param_2,undefined4 param_3)

{
  if ((*(int *)(param_1 + 0x90) != 0) && (param_2 < *(int *)(param_1 + 0xa4))) {
    *(undefined4 *)(*(int *)(param_1 + 0x90) + param_2 * 0x18) = param_3;
  }
  return;
}

