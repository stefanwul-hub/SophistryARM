/* 00040fc8 Chorus1_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Chorus1_c_vslot_40(int param_1,float param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = (int)(param_2 * 0.006 + param_2 * 0.006) + 1;
  if (iVar3 < 2) {
    iVar4 = 1;
    *(undefined4 *)(param_1 + 0x20ec) = 1;
    *(undefined4 *)(param_1 + 0x20f0) = 0;
    pvVar1 = *(void **)(param_1 + 0x20f8);
  }
  else {
    iVar5 = 1;
    do {
      iVar4 = iVar5 * 2;
      iVar2 = iVar5 * -2;
      iVar5 = iVar4;
    } while (iVar3 != iVar4 && SBORROW4(iVar3,iVar4) == iVar3 + iVar2 < 0);
    *(int *)(param_1 + 0x20ec) = iVar4;
    *(int *)(param_1 + 0x20f0) = iVar4 + -1;
    pvVar1 = *(void **)(param_1 + 0x20f8);
  }
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x20f8) = 0;
    iVar3 = FUN_00013124(param_1,iVar4);
    *(int *)(param_1 + 0x20f8) = iVar3;
  }
  else {
    _free(pvVar1);
    *(undefined4 *)(param_1 + 0x20f8) = 0;
    iVar3 = FUN_00013124(param_1,*(undefined4 *)(param_1 + 0x20ec));
    *(int *)(param_1 + 0x20f8) = iVar3;
  }
  if (iVar3 != 0) {
    Part_c_vslot_40();
    return;
  }
  return;
}

