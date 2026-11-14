/* 00073026 FUN_00073026 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00073026(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_00013e4c(param_1);
  *param_1 = &PTR_ChordMem_c_vslot_0_000f1308;
  puVar1 = param_1 + 0x79;
  iVar2 = 0x7e;
  do {
    FUN_0002d7d0(puVar1);
    puVar1 = puVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != -2);
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  if (param_2 != 0) {
    param_1[0x75] = param_2;
  }
  return;
}

