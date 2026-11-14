/* 00005354 LPAUView_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LPAUView_vslot_0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_LPAUView_vslot_0_000e4f48;
  param_1[2] = &PTR_LAB_000e4f80;
  if (param_1[4] != 0) {
    _AudioUnitRemovePropertyListener(param_1[4],0x267135,FUN_00004df4);
  }
  iVar1 = param_1[0x15];
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0xec) + 8))(iVar1 + 0xec,0xf,0,0,0,0);
    param_1[0x15] = 0;
  }
  piVar2 = (int *)param_1[0x16];
  if (piVar2 != (int *)0x0) {
    _OSAtomicAdd32Barrier(0xffffffff,piVar2 + 0x9e72);
    if (piVar2[0x9e72] == 0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    param_1[0x16] = 0;
  }
  FUN_000aceca();
  return;
}

