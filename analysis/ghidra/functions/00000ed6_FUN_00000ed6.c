/* 00000ed6 FUN_00000ed6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void * FUN_00000ed6(void)

{
  int iVar1;
  undefined4 uVar2;
  void *local_1c;
  void *local_18;
  int local_14;
  int local_10;
  
  iVar1 = __keymgr_get_and_lock_processwide_ptr_2(0xe,&local_1c);
  if (iVar1 != 0) {
    return (void *)0x0;
  }
  local_18 = local_1c;
  if ((local_1c == (void *)0x0) && (local_18 = _calloc(0x14,1), local_18 == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)local_18 + 3) != '\0') {
    return local_18;
  }
  local_14 = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
  if (local_14 != 0) {
    uVar2 = _dlsym(local_14,"__cxa_atexit");
    *(undefined4 *)((int)local_18 + 8) = uVar2;
    uVar2 = _dlsym(local_14,"__cxa_finalize");
    *(undefined4 *)((int)local_18 + 0xc) = uVar2;
    if (((*(int *)((int)local_18 + 8) != 0) && (*(int *)((int)local_18 + 0xc) != 0)) &&
       (local_10 = FUN_00000e61(*(undefined4 *)((int)local_18 + 8),
                                *(undefined4 *)((int)local_18 + 0xc)), local_10 != -1)) {
      if (local_10 == 0) {
        *(undefined1 *)((int)local_18 + 3) = 2;
      }
      else {
        uVar2 = _dlsym(local_14,"atexit");
        *(undefined4 *)((int)local_18 + 0x10) = uVar2;
        if (*(int *)((int)local_18 + 0x10) == 0) goto LAB_00001020;
        *(undefined1 *)((int)local_18 + 3) = 0x10;
      }
      return local_18;
    }
  }
LAB_00001020:
  __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  return (void *)0x0;
}

