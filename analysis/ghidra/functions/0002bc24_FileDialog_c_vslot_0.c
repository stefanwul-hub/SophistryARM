/* 0002bc24 FileDialog_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FileDialog_c_vslot_0(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FileDialog_c_vslot_0_000e7688;
  if (*(char *)(param_1 + 0x17) != '\0') {
    FUN_0002e63a(param_1 + 0x1ad,param_1[0x16],param_1 + 0x17);
  }
  pvVar1 = (void *)param_1[0x16];
  if (pvVar1 != (void *)param_1[0x15]) {
    if (pvVar1 != (void *)0x0) {
      _free(pvVar1);
    }
    param_1[0x16] = 0;
  }
  OsLib_c_vslot_0(param_1 + 0x1ad);
  Disk_c_vslot_0();
  return;
}

