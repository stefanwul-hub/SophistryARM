/* 00034f24 WaveRAM2_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveRAM2_c_vslot_0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int local_24;
  
  *param_1 = &PTR_WaveRAM2_c_vslot_0_000e8348;
  FUN_000349f0(param_1,0);
  piVar1 = (int *)param_1[0x48];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  param_1[0x48] = 0;
  OsLib_c_vslot_0(param_1 + 0x286d);
  Disk_c_vslot_0(param_1 + 0x27c8);
  if ((param_1 != (undefined4 *)0xfffffe20) && (puVar2 = param_1 + 0x27b8, param_1 + 0x78 != puVar2)
     ) {
    param_1 = param_1 + 0x271b;
    local_24 = 0x40;
    do {
      puVar2 = puVar2 + -0x9d;
      (**(code **)*param_1)(puVar2);
      param_1 = param_1 + -0x9d;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  FUN_00032014();
  return;
}

