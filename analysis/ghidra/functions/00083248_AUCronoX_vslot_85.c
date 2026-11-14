/* 00083248 AUCronoX_vslot_85 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUCronoX_vslot_85(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_9c [127];
  undefined1 local_1d;
  
  puVar1 = PTR_001037ec;
  iVar2 = _CFArrayCreateMutable(*(undefined4 *)PTR_001037ec,0x25a,PTR_00103824);
  if (iVar2 != 0) {
    iVar4 = 0;
    do {
      (**(code **)(*(int *)(param_1 + 0xec) + 0x50))(param_1 + 0xec,iVar4,local_9c);
      local_1d = 0;
      uVar3 = _CFStringCreateWithCString(*(undefined4 *)puVar1,local_9c,0x8000100);
      _CFArrayAppendValue(iVar2,uVar3);
      _CFRelease(uVar3);
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x25a);
    iVar4 = *(int *)(param_1 + 0x32b460);
    *(int *)(param_1 + 0x32b460) = iVar2;
    if (iVar4 != 0) {
      _CFRelease(iVar4);
    }
  }
  return;
}

