/* 00003334 LPAUSynth_vslot_76 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined * LPAUSynth_vslot_76(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined *local_70;
  undefined1 local_6c [92];
  
  iVar3 = _CFBundleGetBundleWithIdentifier(&cf_com_linplug_au_Sophistry);
  if (iVar3 == 0) {
    _fwrite("WARNING: LinPlug AU: Cannot receive plug-in bundle reference!\n",1,0x3e,
            (FILE *)(PTR_001037f8 + 0xb0));
    return (undefined *)0x0;
  }
  _CFRetain(iVar3);
  iVar4 = _CFBundleCopyBundleURL(iVar3);
  if (iVar4 == 0) {
    _fwrite("WARNING: LinPlug AU: Cannot receive get bundle URL from bundle reference!\n",1,0x4a,
            (FILE *)(PTR_001037f8 + 0xb0));
    local_70 = (undefined *)0x0;
  }
  else {
    _CFRetain(iVar4);
    cVar1 = _CFURLGetFSRef(iVar4,local_6c);
    if (cVar1 == '\0') {
      _fwrite("WARNING: LinPlug AU: Cannot receive get bundle FSRef from bundle URL!\n",1,0x46,
              (FILE *)(PTR_001037f8 + 0xb0));
      local_70 = (undefined *)0x0;
    }
    else {
      local_70 = &DAT_000fb960;
      sVar2 = _FSGetCatalogInfo(local_6c,0,0,0,&DAT_000fb960,0);
      if (sVar2 != 0) {
        _fwrite("WARNING: LinPlug AU: Cannot receive get bundle FSSpec from bundle FSRef!\n",1,0x49,
                (FILE *)(PTR_001037f8 + 0xb0));
        local_70 = (undefined *)0x0;
      }
    }
    _CFRelease(iVar4);
  }
  _CFRelease(iVar3);
  return local_70;
}

