/* 00097390 CMenuFileList_vslot_73 */

void CMenuFileList_vslot_73(int *param_1,int param_2)

{
  if (param_1[0x20] != param_2) {
    param_1[0x20] = param_2;
                    /* WARNING: Could not recover jumptable at 0x000973b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x54))();
    return;
  }
  return;
}

