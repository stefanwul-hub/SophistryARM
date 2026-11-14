/* 0002e72e FUN_0002e72e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_0002e72e(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  bool local_1d;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar2 = _CFStringCreateWithCString(*(undefined4 *)PTR_001037ec,param_2,0x8000100);
    if (iVar2 != 0) {
      iVar3 = _CFPreferencesCopyValue
                        (iVar2,&cf_com_linplug_Sophistry,*(undefined4 *)PTR_0010382c,
                         *(undefined4 *)PTR_00103828);
      if (iVar3 == 0) {
        local_1d = false;
      }
      else {
        cVar1 = _CFNumberGetValue(iVar3,10,param_3);
        local_1d = cVar1 != '\0';
        _CFRelease(iVar3);
      }
      _CFRelease(iVar2);
      return local_1d;
    }
  }
  return false;
}

