/* 0009f958 CMenuFileList_vslot_42 */

void CMenuFileList_vslot_42(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 0x50))(param_1);
  if (cVar2 == '\0') {
    return;
  }
  if (param_2 == 0) {
    piVar1 = (int *)param_1[10];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x160))(piVar1,param_1);
                    /* WARNING: Could not recover jumptable at 0x0009f9ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x54))();
      return;
    }
  }
  else {
    (**(code **)(*param_1 + 0x98))(param_1,param_2,param_1 + 2);
  }
                    /* WARNING: Could not recover jumptable at 0x0009f9a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x54))();
  return;
}

