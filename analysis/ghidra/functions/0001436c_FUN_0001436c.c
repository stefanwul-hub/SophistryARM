/* 0001436c FUN_0001436c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0001436c(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_PartGroup_c_vslot_0_000e6ce8;
  FUN_0002e178(param_1 + 2);
  param_1[1] = 0;
  iVar2 = 0;
  puVar1 = param_1;
  do {
    puVar1[5] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0x40);
  param_1[0x45] = 0;
  param_1[3] = 0xbf800000;
  param_1[4] = 0xbf800000;
  return;
}

