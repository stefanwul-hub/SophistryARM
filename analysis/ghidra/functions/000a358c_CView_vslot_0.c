/* 000a358c CView_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CView_vslot_0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = &PTR_CView_vslot_0_000f4088;
  piVar2 = (int *)param_1[0xd];
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)param_1[0xe];
  }
  else {
    (**(code **)(*piVar2 + 8))(piVar2);
    piVar2 = (int *)param_1[0xe];
  }
  if (piVar2 == (int *)0x0) {
    *param_1 = PTR_DAT_00103888 + 8;
    return;
  }
  do {
    piVar1 = (int *)*piVar2;
    if ((void *)piVar2[1] != (void *)0x0) {
      _free((void *)piVar2[1]);
    }
    operator_delete(piVar2);
    piVar2 = piVar1;
  } while (piVar1 != (int *)0x0);
  *param_1 = PTR_DAT_00103888 + 8;
  return;
}

