/* 0000552c LPAUView_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUView_vslot_6(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    local_20[0] = 4;
    _AudioUnitGetProperty(iVar1,0x267134,0,0,param_1 + 0x54,local_20);
    if (*(int *)(param_1 + 0x54) != 0) {
      piVar2 = *(int **)(param_1 + 0x58);
      if ((piVar2 != (int *)0x0) &&
         (_OSAtomicAdd32Barrier(0xffffffff,piVar2 + 0x9e72), piVar2[0x9e72] == 0)) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      iVar4 = (**(code **)(**(int **)(param_1 + 0x54) + 0x13c))(*(int **)(param_1 + 0x54));
      *(int *)(param_1 + 0x58) = iVar4;
      if (iVar4 != 0) {
        _OSAtomicAdd32Barrier(1,iVar4 + 0x279c8);
        (**(code **)(**(int **)(param_1 + 0x58) + 0xb4))(*(int **)(param_1 + 0x58),param_1);
        (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + 0xec) + 8))
                  (*(int *)(param_1 + 0x54) + 0xec,0xe,0,0,*(undefined4 *)(param_1 + 0x34),0);
        _HIViewMoveBy(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x1c) + 0x7c),param_2,
                      param_3);
        FUN_000ac6b8(param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x1c) + 0x7c));
        local_28 = 0x636e746c;
        local_24 = 0x9a;
        pcVar3 = *(code **)(*(int *)(param_1 + 8) + 8);
        uVar5 = _GetControlEventTarget
                          (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x1c) + 0x7c));
        (*pcVar3)(param_1 + 8,uVar5,1,&local_28);
        uVar5 = FUN_000ac992(param_1,0x3dcccccd,0x3d4ccccd);
        _AudioUnitAddPropertyListener(iVar1,0x267135,FUN_00004df4,param_1);
        return uVar5;
      }
    }
  }
  return 0xffffd585;
}

