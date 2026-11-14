/* 0008731e Flanger2R_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Flanger2R_c_vslot_40(int param_1,float param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  
  if (0.0 < param_2) {
    iVar1 = (int)(param_2 * 0.085) * 2 + 2;
    if (iVar1 < 3) {
      iVar5 = 2;
      iVar3 = 8;
    }
    else {
      iVar5 = 2;
      do {
        iVar3 = iVar5;
        iVar5 = iVar3 * 2;
      } while (iVar1 != iVar5 && SBORROW4(iVar1,iVar5) == iVar1 + iVar3 * -2 < 0);
      iVar3 = iVar3 * 8;
    }
    pvVar4 = _malloc(iVar3 + 4U);
    if (pvVar4 != (void *)0x0) {
      pvVar2 = *(void **)(param_1 + 0x20c);
      *(void **)(param_1 + 0x20c) = pvVar4;
      *(int *)(param_1 + 0x1e0) = iVar5;
      *(int *)(param_1 + 0x1e4) = iVar5 + -1;
      if (pvVar2 != (void *)0x0) {
        _free(pvVar2);
      }
    }
    pvVar4 = _malloc(iVar3 + 4U);
    if (pvVar4 != (void *)0x0) {
      pvVar2 = *(void **)(param_1 + 0x210);
      *(void **)(param_1 + 0x210) = pvVar4;
      *(int *)(param_1 + 0x1e0) = iVar5;
      *(int *)(param_1 + 0x1e4) = iVar5 + -1;
      if (pvVar2 != (void *)0x0) {
        _free(pvVar2);
      }
    }
    Part_c_vslot_40();
    return;
  }
  return;
}

