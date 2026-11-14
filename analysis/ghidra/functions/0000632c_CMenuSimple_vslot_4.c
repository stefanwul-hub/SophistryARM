/* 0000632c CMenuSimple_vslot_4 */

void CMenuSimple_vslot_4(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0xec) != '\0') {
    CMenuBase_vslot_4(param_1,param_2);
  }
  *(undefined1 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x4c);
  return;
}

