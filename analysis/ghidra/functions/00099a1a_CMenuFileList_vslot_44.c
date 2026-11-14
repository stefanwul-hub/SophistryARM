/* 00099a1a CMenuFileList_vslot_44 */

void CMenuFileList_vslot_44(int *param_1,float param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  if ((-1 < iVar1) && (iVar1 < param_1[0x2d])) {
    param_1[0x2f] = iVar1;
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      param_1[0x13] = (int)param_2;
                    /* WARNING: Could not recover jumptable at 0x00099a59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    *(byte *)(iVar1 + param_1[0x2b]) = *(byte *)(iVar1 + param_1[0x2b]) ^ 1;
    param_1[0x13] = (int)param_2;
                    /* WARNING: Could not recover jumptable at 0x00099a79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x54))();
    return;
  }
  return;
}

