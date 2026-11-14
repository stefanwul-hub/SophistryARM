/* 00006c74 CMenuWithSub_vslot_93 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CMenuWithSub_vslot_93(int *param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  
  CMenuFileList_vslot_21(param_1,1);
  if (param_1[0x3d] < param_1[0x3e]) {
    iVar2 = (int)((float)(param_1[0x3e] - param_1[0x3d]) * param_2 + 0.1);
    param_1[0x36b] = iVar2;
    piVar1 = (int *)param_1[iVar2 + 0x65];
  }
  else {
    piVar1 = (int *)param_1[param_1[0x36b] + 0x65];
  }
  if (piVar1 != (int *)0x0) {
    if (piVar1 == param_1) {
                    /* WARNING: Could not recover jumptable at 0x00006d39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar1 + 0xb0))();
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x00006d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xb0))();
    return;
  }
  return;
}

