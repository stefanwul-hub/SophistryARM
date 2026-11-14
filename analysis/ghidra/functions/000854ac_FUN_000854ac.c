/* 000854ac FUN_000854ac */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000854ac(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_InBuffer2_c_vslot_0_000f28e8;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0;
  *(undefined1 *)((int)param_1 + 0x26) = 0;
  *(undefined1 *)((int)param_1 + 0x27) = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0x29) = 0;
  *(undefined1 *)((int)param_1 + 0x2a) = 0;
  param_1[8] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  iVar2 = 0;
  puVar1 = param_1;
  do {
    puVar1[0xd] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 8);
  param_1[4] = "unnamed";
  return;
}

