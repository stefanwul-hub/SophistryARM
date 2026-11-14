/* 00001b78 CControlPl_vslot_4 */

void CControlPl_vslot_4(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack00000008;
  
  if (0 < param_1[0x29]) {
    iVar2 = 0;
    iVar1 = 0;
    do {
      *(undefined4 *)(iVar1 + param_1[0x24] + 0x10) = *(undefined4 *)(iVar1 + param_1[0x24] + 0xc);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < param_1[0x29]);
  }
  uStack00000008 = 0;
                    /* WARNING: Could not recover jumptable at 0x00001bbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x54))();
  return;
}

