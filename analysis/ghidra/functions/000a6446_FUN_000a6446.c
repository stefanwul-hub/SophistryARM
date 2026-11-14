/* 000a6446 FUN_000a6446 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a6446(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  param_1[1] = param_2;
  param_1[2] = 0;
  *param_1 = &PTR_AEffGUIEditor_vslot_0_000f4428;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 0xe) = 0;
  iVar1 = _TickCount();
  param_1[5] = (uint)(iVar1 * 1000) / 0x3c;
  FUN_00094d74(param_2,param_1);
  FUN_000a61ca();
  return;
}

