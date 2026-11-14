/* 0009c36a COptionMenu_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void COptionMenu_vslot_1(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_COptionMenu_vslot_0_000f3d48;
  CMenuFileList_vslot_83(param_1);
  piVar1 = (int *)param_1[0x30];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = &PTR_CControl_vslot_0_000f3988;
  FUN_000a34ec(param_1);
  operator_delete(param_1);
  return;
}

