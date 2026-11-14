/* 0000dbc4 Instrument_c_vslot_41 */

undefined4 Instrument_c_vslot_41(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x1ac) != 0) &&
     (iVar2 = *(int *)(param_1 + 0x1a8),
     SBORROW4(iVar2,*(int *)(param_1 + 0x1c4) * 2) != iVar2 + *(int *)(param_1 + 0x1c4) * -2 < 0)) {
    iVar1 = *(int *)(param_1 + 0x1ac) + iVar2 * 0x14;
    *(int *)(param_1 + 0x1a8) = iVar2 + 1;
    *(undefined1 *)(iVar1 + 4) = *(undefined1 *)(param_2 + 4);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    return 1;
  }
  return 0;
}

