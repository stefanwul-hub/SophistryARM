/* 000037ce FUN_000037ce */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000037ce(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  iVar1 = _CFBundleGetMainBundle();
  if (((iVar1 != 0) && (iVar2 = _CFBundleGetIdentifier(iVar1), iVar2 != 0)) &&
     (iVar1 = _CFBundleGetValueForInfoDictionaryKey(iVar1,*(undefined4 *)PTR_001037f4), iVar1 != 0))
  {
    uVar5 = _CFStringFind(iVar2,&cf_com_apple_logic,1);
    if (((int)uVar5 != -1) && ((int)((ulonglong)uVar5 >> 0x20) != 0)) {
      uVar4 = _CFStringGetLength(&cf_7_0_1);
      iVar1 = _CFStringCompareWithOptions(iVar1,&cf_7_0_1,0,uVar4,0);
      if (iVar1 != 1) {
        *(undefined1 *)(param_1 + 0x32b406) = 0;
      }
      *(undefined4 *)(param_1 + 0x32b440) = 0x69676f4c;
      *(undefined2 *)(param_1 + 0x32b444) = 99;
      return;
    }
    iVar3 = _CFStringCompare(iVar2,&cf_info_emagic_Logic,1);
    if ((iVar3 != 0) && (iVar3 = _CFStringCompare(iVar2,&cf_de_emagic_Logic,1), iVar3 != 0)) {
      iVar2 = _CFStringCompare(iVar2,&cf_com_apple_garageband,1);
      if (iVar2 != 0) {
        return;
      }
      uVar4 = _CFStringGetLength(&cf_1_0);
      iVar1 = _CFStringCompareWithOptions(iVar1,&cf_1_0,0,uVar4,0);
      if (iVar1 != 1) {
        *(undefined1 *)(param_1 + 0x32b405) = 0;
      }
      *(undefined4 *)(param_1 + 0x32b440) = 0x61726147;
      *(undefined4 *)(param_1 + 0x32b444) = 0x61426567;
      *(undefined2 *)(param_1 + 0x32b448) = 0x646e;
      *(undefined1 *)(param_1 + 0x32b44a) = 0;
      *(undefined1 *)(param_1 + 0x32b406) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x32b440) = 0x69676f4c;
    *(undefined2 *)(param_1 + 0x32b444) = 99;
    *(undefined1 *)(param_1 + 0x32b406) = 0;
    uVar4 = _CFStringGetLength(&cf_6_4_1);
    iVar2 = _CFStringCompareWithOptions(iVar1,&cf_6_4_1,0,uVar4,0);
    if (iVar2 != 1) {
      *(undefined1 *)(param_1 + 0x32b405) = 0;
    }
    uVar4 = _CFStringGetLength(&cf_6_4_3);
    iVar1 = _CFStringCompareWithOptions(iVar1,&cf_6_4_3,0,uVar4,0);
    if (iVar1 != 1) {
      *(undefined1 *)(param_1 + 0x32b404) = 1;
    }
  }
  return;
}

