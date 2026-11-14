/* 0009ce56 CControlPl_vslot_34 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CControlPl_vslot_34(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0xa4))(piVar1,"CViewContainer");
    if (cVar2 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0009ceac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x88))();
      return uVar3;
    }
  }
  return param_2;
}

