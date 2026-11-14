/* 0009a7d2 FUN_0009a7d2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009a7d2(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  FUN_000a3468(param_1,param_2);
  *param_1 = &PTR_CControl_vslot_0_000f3988;
  param_1[0xf] = param_3;
  param_1[0x10] = param_4;
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0x3f000000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0x3f800000;
  param_1[0x16] = 0x3dcccccd;
  param_1[0x17] = 0xffffffff;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  iVar1 = _GetDblTime();
  iVar2 = 0xfa;
  if (0xf9 < iVar1) {
    iVar2 = iVar1;
  }
  param_1[0x18] = iVar2;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 1;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  CMenuFileList_vslot_8(param_1,param_5);
  return;
}

