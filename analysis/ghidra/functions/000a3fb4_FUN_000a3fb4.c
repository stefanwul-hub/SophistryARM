/* 000a3fb4 FUN_000a3fb4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a3fb4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_000a37c0(param_1,param_2,0,0);
  *param_1 = &PTR_CFrame_vslot_0_000f4148;
  param_1[0x18] = param_4;
  param_1[0x19] = param_3;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x1c) = 1;
  *(undefined1 *)((int)param_1 + 0x72) = 0;
  *(undefined1 *)((int)param_1 + 0x73) = 0;
  *(undefined1 *)(param_1 + 0x22) = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  *(undefined1 *)((int)param_1 + 0x71) = 1;
  param_1[10] = param_1;
  FUN_0009dff8(param_1,param_3);
  _Gestalt(0x73797376,&DAT_00102840);
  param_1[0x25] = 0;
  return;
}

