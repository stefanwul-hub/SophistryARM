/* 000a40a0 CViewContainer_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CViewContainer_vslot_0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  *param_1 = &PTR_CViewContainer_vslot_0_000f42c8;
  piVar3 = (int *)param_1[0xf];
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    piVar2 = (int *)*piVar3;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x7c))(piVar2,param_1);
      (**(code **)(*(int *)*piVar3 + 8))((int *)*piVar3);
      piVar2 = (int *)*piVar3;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    operator_delete(piVar3);
    piVar3 = piVar1;
  }
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  piVar3 = (int *)param_1[0x12];
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  param_1[0x12] = 0;
  FUN_000a34ec();
  return;
}

