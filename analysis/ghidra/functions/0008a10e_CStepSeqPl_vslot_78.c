/* 0008a10e CStepSeqPl_vslot_78 */

void CStepSeqPl_vslot_78(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 0xb4) = (char)param_2;
  *(char *)(param_1 + 0xb5) = (char)((uint)param_2 >> 8);
  *(char *)(param_1 + 0xb6) = (char)((uint)param_2 >> 0x10);
  *(char *)(param_1 + 0xb7) = (char)((uint)param_2 >> 0x18);
  return;
}

