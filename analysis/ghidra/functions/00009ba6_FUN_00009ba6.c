/* 00009ba6 FUN_00009ba6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined * FUN_00009ba6(void)

{
  undefined1 *puVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  stat local_cc;
  
  puVar1 = (undefined1 *)((int)local_cc.st_qspare + 4);
  sVar3 = _FSFindFolder(0xffff8003,0x61737570,1,puVar1);
  if ((sVar3 != 0) || (iVar4 = _CFURLCreateFromFSRef(0,puVar1), iVar4 == 0)) {
    return (undefined *)0x0;
  }
  iVar5 = _CFURLCreateCopyAppendingPathComponent(0,iVar4,&cf_LinPlug,1);
  if (iVar5 == 0) {
    puVar7 = (undefined *)0x0;
    goto LAB_00009c6a;
  }
  puVar7 = &DAT_000fbc20;
  cVar2 = _CFURLGetFileSystemRepresentation(iVar5,1,&DAT_000fbc20,0x140);
  if (cVar2 == '\0') {
LAB_00009c5a:
    puVar7 = (undefined *)0x0;
  }
  else {
    iVar6 = _stat(&DAT_000fbc20,&local_cc);
    if ((iVar6 != 0) && (iVar6 = _mkdir(&DAT_000fbc20,0x1fd), iVar6 != 0)) {
      _fwrite("Warning: could not create LinPlug folder in Application Support!\n",1,0x41,
              (FILE *)(PTR_001037f8 + 0xb0));
      goto LAB_00009c5a;
    }
  }
  _CFRelease(iVar5);
LAB_00009c6a:
  _CFRelease(iVar4);
  return puVar7;
}

