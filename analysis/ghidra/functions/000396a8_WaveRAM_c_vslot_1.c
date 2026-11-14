/* 000396a8 WaveRAM_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveRAM_c_vslot_1(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_WaveRAM_c_vslot_0_000e8688;
  piVar1 = (int *)param_1[0x48];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  param_1[0x48] = 0;
  Disk_c_vslot_0(param_1 + 0x116);
  puVar2 = param_1 + 0x79;
  if ((puVar2 != (undefined4 *)0x0) && (puVar2 != param_1 + 0x116)) {
    (**(code **)param_1[0x79])(puVar2);
  }
  FUN_00032014(param_1);
  operator_delete(param_1);
  return;
}

