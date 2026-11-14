/* 0000c89a Instrument_c_vslot_4 */

void Instrument_c_vslot_4(int param_1)

{
  int iVar1;
  
  iVar1 = 4;
  do {
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
    param_1 = param_1 + 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  PartGroup_c_vslot_4();
  return;
}

