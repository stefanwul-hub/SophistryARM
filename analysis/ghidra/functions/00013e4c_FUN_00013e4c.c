/* 00013e4c FUN_00013e4c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00013e4c(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *param_1 = &PTR_Part_c_vslot_0_000e6be8;
  param_1[0x4b] = PTR_DAT_00103808 + 8;
  *(undefined1 *)(param_1 + 0x4c) = 0;
  param_1[0x4d] = 0xffffffff;
  param_1[0x4e] = 0xffffffff;
  FUN_0002e178(param_1 + 0x5a);
  param_1[1] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 0x57) = 0;
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  iVar2 = 0x20;
  puVar1 = param_1;
  puVar3 = param_1;
  do {
    puVar1[6] = 0;
    puVar1[7] = 0;
    *(undefined1 *)(puVar3 + 0x6d) = 1;
    puVar1 = puVar1 + 2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0xffffffff;
  *(undefined1 *)((int)param_1 + 0x15d) = 0;
  param_1[0x50] = 0xbf800000;
  param_1[0x51] = 0xbf800000;
  param_1[0x52] = 0xbf800000;
  param_1[0x53] = 0x3f800000;
  param_1[0x54] = 0x42f00000;
  param_1[0x55] = 0x3c088889;
  param_1[0x56] = 0x3c;
  param_1[0x58] = 0x3f800000;
  param_1[0x59] = 0x3f800000;
  param_1[0x5b] = 0;
  param_1[0x4f] = 0;
  iVar2 = 0x10;
  do {
    param_1[0x5d] = 0;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

