/* 0002e7e4 FUN_0002e7e4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint FUN_0002e7e4(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    uVar4 = 0;
  }
  else {
    uVar1 = *(undefined4 *)PTR_001037ec;
    uVar4 = _CFStringCreateWithCString(uVar1,param_2,0x8000100);
    if (uVar4 != 0) {
      iVar5 = _CFNumberCreate(uVar1,10,&stack0x0000000c);
      if (iVar5 == 0) {
        uVar6 = 0;
      }
      else {
        uVar1 = *(undefined4 *)PTR_00103828;
        uVar2 = *(undefined4 *)PTR_0010382c;
        _CFPreferencesSetValue(uVar4,iVar5,&cf_com_linplug_Sophistry,uVar2,uVar1);
        cVar3 = _CFPreferencesSynchronize(&cf_com_linplug_Sophistry,uVar2,uVar1);
        uVar6 = (uint)(cVar3 != '\0');
        _CFRelease(iVar5);
      }
      _CFRelease(uVar4);
      return uVar6;
    }
  }
  return uVar4;
}

