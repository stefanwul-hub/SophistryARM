/* 00036318 FUN_00036318 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00036318(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_0000bf98(param_1,1);
  *param_1 = &PTR_SamLoop_c_vslot_0_000e8448;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x86] = 0x3f800000;
  param_1[0x87] = 0;
  param_1[0x8e] = 0;
  iVar2 = 8;
  puVar1 = param_1;
  puVar3 = param_1;
  do {
    puVar1[0xce] = 0;
    puVar1[0xcf] = 0xbff00000;
    puVar1[0xde] = 0;
    puVar1[0xdf] = 0xbff00000;
    puVar1[0xee] = 0;
    puVar1[0xef] = 0xbff00000;
    *(undefined1 *)(puVar3 + 0x98) = 0;
    puVar1 = puVar1 + 2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 0x116) = 0;
  *(undefined1 *)((int)param_1 + 0x459) = 0;
  param_1[0x79] = 0;
  return;
}

