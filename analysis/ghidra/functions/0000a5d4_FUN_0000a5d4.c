/* 0000a5d4 FUN_0000a5d4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000a5d4(undefined4 *param_1)

{
  *param_1 = PTR_DAT_0010380c + 8;
  FUN_0002e178(param_1 + 1);
  *param_1 = &PTR_Disk_c_vslot_0_000e6648;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  *(undefined1 *)((int)param_1 + 0x153) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0x3a;
  *(undefined1 *)((int)param_1 + 0x11) = 0x2f;
  *(undefined1 *)((int)param_1 + 0x12) = 0x5c;
  return;
}

