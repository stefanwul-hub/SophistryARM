/* 0008a154 CStepSeqPl_vslot_42 */

void CStepSeqPl_vslot_42(int param_1,undefined4 param_2)

{
  *(undefined1 *)(param_1 + 0x356) = 1;
  CControlPl_vslot_42(param_1,param_2);
  *(undefined1 *)(param_1 + 0x356) = 0;
  return;
}

