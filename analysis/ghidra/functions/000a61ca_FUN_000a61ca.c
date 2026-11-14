/* 000a61ca FUN_000a61ca */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a61ca(void)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  
  iVar2 = __dyld_image_count();
  if (iVar2 < 2) {
    return;
  }
  iVar7 = 1;
  while (puVar3 = (undefined *)__dyld_get_image_header(iVar7), puVar3 != PTR_001038ac) {
    iVar7 = iVar7 + 1;
    if (iVar2 == iVar7) {
      return;
    }
  }
  pcVar4 = (char *)__dyld_get_image_name(iVar7);
  if (pcVar4 == (char *)0x0) {
    return;
  }
  uVar6 = 0xffffffff;
  pcVar8 = pcVar4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  iVar2 = _CFURLCreateFromFileSystemRepresentation(0,pcVar4,~uVar6 - 1,0);
  if (iVar2 != 0) {
    iVar7 = _CFURLCreateCopyDeletingLastPathComponent(0,iVar2);
    _CFRelease(iVar2);
    if (iVar7 != 0) {
      iVar2 = _CFURLCreateCopyDeletingLastPathComponent(0,iVar7);
      _CFRelease(iVar7);
      if (iVar2 != 0) {
        iVar7 = _CFURLCreateCopyDeletingLastPathComponent(0,iVar2);
        _CFRelease(iVar2);
        if (iVar7 != 0) {
          uVar5 = _CFBundleCreate(0,iVar7);
          _CFRelease(iVar7);
          DAT_000e2200 = uVar5;
          return;
        }
      }
    }
  }
  DAT_000e2200 = 0;
  return;
}

