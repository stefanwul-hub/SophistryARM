/* 0002bb40 FUN_0002bb40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002bb40(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = &PTR_FileDialog_c_vslot_0_000e7688;
  FUN_0000a5d4(param_1 + 0x108);
  FUN_0002e178(param_1 + 0x1ad);
  param_1[1] = "File Dialog";
  param_1[2] = "Any File";
  param_1[4] = "*.*";
  param_1[5] = 0;
  param_1[0x15] = "FileDialog";
  param_1[0x16] = "FileDialog";
  param_1[3] = 0;
  _memset(param_1 + 0x17,0,0x140);
  _memset(param_1 + 0x67,0,0x140);
  _memset(param_1 + 0xb7,0,0x140);
  param_1[0x107] = param_2;
  return;
}

