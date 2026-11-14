/* 00002bbc LPAUSynth_vslot_37 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_37(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _CFBundleGetBundleWithIdentifier(&cf_com_linplug_au_Sophistry);
  if (iVar1 != 0) {
    _CFRetain(iVar1);
    uVar2 = _CFBundleCopyResourceURL(iVar1,&cf_Icon,&cf_icns,0);
    _CFRelease(iVar1);
    return uVar2;
  }
  return 0;
}

