/* 0002cf10 FileList_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FileList_c_vslot_1(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int local_20;
  
  *param_1 = &PTR_FileList_c_vslot_0_000e76a8;
  if (param_1[0xa9] != 0) {
    if ((int)param_1[0xa6] < 1) {
      pvVar2 = (void *)param_1[0xa9];
    }
    else {
      local_20 = 0;
      pvVar2 = (void *)param_1[0xa9];
      do {
        iVar3 = local_20 * 4;
        pvVar1 = *(void **)((int)pvVar2 + iVar3);
        if (pvVar1 != (void *)param_1[0xa8]) {
          if (pvVar1 != (void *)0x0) {
            _free(pvVar1);
            pvVar2 = (void *)param_1[0xa9];
          }
          *(undefined4 *)((int)pvVar2 + iVar3) = 0;
          *(undefined4 *)(iVar3 + param_1[0xa9]) = param_1[0xa8];
          pvVar2 = (void *)param_1[0xa9];
        }
        local_20 = local_20 + 1;
      } while (local_20 < (int)param_1[0xa6]);
    }
    param_1[0x14a] = 0;
    if (pvVar2 != (void *)0x0) {
      _free(pvVar2);
    }
  }
  param_1[0xa9] = 0;
  Disk_c_vslot_0(param_1 + 1);
  operator_delete(param_1);
  return;
}

