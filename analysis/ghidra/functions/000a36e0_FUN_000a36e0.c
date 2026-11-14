/* 000a36e0 FUN_000a36e0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a36e0(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_20;
  
  param_1[1] = 1;
  *param_1 = &PTR_CBitmap_vslot_0_000f43c8;
  param_1[2] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 6) = 1;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  CBitmap_vslot_9(param_1,param_2);
  uVar2 = DAT_000e20cc;
  uVar1 = (uint)DAT_000e20cc >> 8;
  *(char *)(param_1 + 5) = (char)DAT_000e20cc;
  *(char *)((int)param_1 + 0x15) = (char)uVar1;
  *(char *)((int)param_1 + 0x16) = (char)((uint)uVar2 >> 0x10);
  local_20 = (undefined1)((uint)uVar2 >> 0x18);
  *(undefined1 *)((int)param_1 + 0x17) = local_20;
  return;
}

