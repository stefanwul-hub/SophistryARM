/* 00006ecc CMenuWithSub_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CMenuWithSub_vslot_0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = &PTR_CMenuWithSub_vslot_0_000e5888;
  param_1[0x43] = &PTR_LAB_000e5a30;
  CMenuFileList_vslot_83(param_1);
  iVar3 = 0x20;
  puVar2 = param_1;
  do {
    piVar1 = (int *)puVar2[0x45];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = &PTR_CMenuBase_vslot_0_000e53e8;
  FUN_0009c43a();
  return;
}

