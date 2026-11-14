/* 0008d4da WaveTable_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveTable_c_vslot_0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_WaveTable_c_vslot_0_000f3028;
  if ((void *)param_1[0x75] != (void *)0x0) {
    _free((void *)param_1[0x75]);
    param_1[0x75] = 0;
  }
  Disk_c_vslot_0(param_1 + 0x115);
  puVar1 = param_1 + 0x76;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 != param_1 + 0x113)) {
    (**(code **)param_1[0x76])(puVar1);
  }
  FUN_00032014();
  return;
}

