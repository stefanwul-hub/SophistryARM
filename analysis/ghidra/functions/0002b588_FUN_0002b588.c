/* 0002b588 FUN_0002b588 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002b588(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_0001436c(param_1);
  *param_1 = &PTR_Tone_c_vslot_0_000e7608;
  param_1[0x52] = PTR_DAT_00103808 + 8;
  *(undefined1 *)(param_1 + 0x53) = 0;
  param_1[0x54] = 0xffffffff;
  param_1[0x55] = 0xffffffff;
  param_1[0x52] = PTR_DAT_00103814 + 8;
  param_1[0x56] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x53) = 1;
  param_1[0x46] = 0x3f800000;
  param_1[0x47] = 0xbf800000;
  param_1[0x48] = 0xbf800000;
  param_1[0x49] = 0xbf800000;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x8e] = 0x3f800000;
  param_1[0x8f] = 0x3f800000;
  param_1[0x50] = 0xffffffff;
  param_1[0x51] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x57] = 0;
  param_1[0x4f] = 0xffffffff;
  param_1[0x311] = 0x3b23d70a;
  iVar2 = 0x19;
  puVar1 = param_1;
  do {
    puVar1[0x148] = 0;
    puVar1[0x161] = 0;
    puVar1[0x17a] = 0;
    puVar1[0x193] = 0;
    puVar1[0x1ac] = 0;
    puVar1[0x1c5] = 0;
    puVar1[0x1de] = 0;
    puVar1[0x1f7] = 0;
    puVar1[0x210] = 0;
    puVar1[0x229] = 0;
    puVar1[0x242] = 0;
    puVar1[0x25b] = 0;
    puVar1[0x274] = 0;
    puVar1[0x28d] = 0;
    puVar1[0x2a6] = 0;
    puVar1[0x2bf] = 0;
    puVar1[0x2d8] = 0;
    puVar1[0x2f1] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x30a] = 0;
  param_1[0x30b] = 0;
  param_1[0x30c] = 0;
  puVar1 = param_1;
  puVar3 = param_1;
  do {
    puVar3[0x100] = param_1 + 0x8e;
    *(undefined1 *)(puVar1 + 0x130) = 0;
    *(undefined1 *)(puVar1 + 0x13c) = 0;
    puVar3 = puVar3 + 1;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  } while (puVar3 != param_1 + 0x30);
  puVar1 = param_1;
  puVar3 = param_1;
  do {
    puVar3[0x90] = param_1 + 0x8f;
    *(undefined1 *)(puVar1 + 0xd0) = 0;
    *(undefined1 *)(puVar1 + 0xe0) = 0;
    *(undefined1 *)(puVar1 + 0xf0) = 0;
    puVar3 = puVar3 + 1;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  } while (param_1 + 0x18 != puVar3);
  param_1[0x5a] = 0xffffffff;
  param_1[0x5c] = 0xbf800000;
  param_1[0x5b] = 0xbf800000;
  param_1[0x5d] = 0;
  param_1[0x30e] = 0;
  param_1[0x30f] = 0;
  param_1[0x310] = 0;
  param_1[0x312] = 0xffffffff;
  param_1[0x313] = 0xffffffff;
  return;
}

