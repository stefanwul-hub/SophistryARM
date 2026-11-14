/* 0002d838 FUN_0002d838 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002d838(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_Key_c_vslot_0_000e76f8;
  param_1[1] = &PTR_BitCode_c_vslot_0_000e76e8;
  iVar2 = 0x80;
  puVar1 = param_1;
  do {
    puVar1[2] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  param_1[0x82] = "ADFGLMNPRSTWXYZabdefghrs23456789";
  return;
}

