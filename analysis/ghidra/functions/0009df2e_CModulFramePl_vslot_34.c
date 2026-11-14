/* 0009df2e CModulFramePl_vslot_34 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int * CModulFramePl_vslot_34(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = *param_2 - *(int *)(param_1 + 8);
  param_2[1] = param_2[1] - iVar1;
  piVar3 = *(int **)(param_1 + 0x2c);
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 0xa4))(piVar3,"CViewContainer");
    if (cVar2 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0009df91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x2c) + 0x88))();
      return piVar3;
    }
  }
  return param_2;
}

