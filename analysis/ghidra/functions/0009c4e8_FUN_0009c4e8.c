/* 0009c4e8 FUN_0009c4e8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009c4e8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined *puVar1;
  
  FUN_0009a7d2(param_1,param_2,0,0,param_3);
  *param_1 = &PTR_CParamDisplay_vslot_0_000f3aa8;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1f] = 1;
  param_1[0x20] = param_4;
  *(undefined1 *)(param_1 + 0x27) = 1;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x21] = 3;
  param_1[0x22] = 0;
  puVar1 = PTR_DAT_00103804;
  *(undefined *)(param_1 + 0x23) = *PTR_DAT_00103804;
  *(undefined *)((int)param_1 + 0x8d) = puVar1[1];
  *(undefined *)((int)param_1 + 0x8e) = puVar1[2];
  *(undefined *)((int)param_1 + 0x8f) = puVar1[3];
  puVar1 = PTR_DAT_00103800;
  *(undefined *)(param_1 + 0x24) = *PTR_DAT_00103800;
  *(undefined *)((int)param_1 + 0x91) = puVar1[1];
  *(undefined *)((int)param_1 + 0x92) = puVar1[2];
  *(undefined *)((int)param_1 + 0x93) = puVar1[3];
  *(undefined *)(param_1 + 0x25) = *puVar1;
  *(undefined *)((int)param_1 + 0x95) = puVar1[1];
  *(undefined *)((int)param_1 + 0x96) = puVar1[2];
  *(undefined *)((int)param_1 + 0x97) = puVar1[3];
  puVar1 = PTR_DAT_00103898;
  *(undefined *)(param_1 + 0x26) = *PTR_DAT_00103898;
  *(undefined *)((int)param_1 + 0x99) = puVar1[1];
  *(undefined *)((int)param_1 + 0x9a) = puVar1[2];
  *(undefined *)((int)param_1 + 0x9b) = puVar1[3];
  param_1[0x1e] = 0;
  if ((param_4 & 0x1000) != 0) {
    *(undefined1 *)(param_1 + 0xc) = 0;
    param_1[0x11] = param_1[0x13];
  }
  return;
}

