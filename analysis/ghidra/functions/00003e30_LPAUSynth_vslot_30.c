/* 00003e30 LPAUSynth_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_30(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (*(char *)(param_1 + 0x32b430) == '\0') {
    (**(code **)(*(int *)(param_1 + 0xec) + 0xc))(param_1 + 0xec);
    *(undefined1 *)(param_1 + 0x32b430) = 1;
  }
  iVar1 = _CFGetTypeID(param_2);
  iVar2 = _CFDictionaryGetTypeID();
  if ((iVar1 == iVar2) && (iVar1 = _CFDictionaryGetValue(param_2,&cf_vstdata), iVar1 != 0)) {
    iVar2 = _CFGetTypeID(iVar1);
    iVar3 = _CFDataGetTypeID();
    if (iVar2 == iVar3) {
      *(undefined1 *)(param_1 + 0x32b434) = 1;
      iVar2 = _CFDataGetLength(iVar1);
      iVar1 = _CFDataGetBytePtr(iVar1);
      if ((0 < iVar2) && (iVar1 != 0)) {
        (**(code **)(*(int *)(param_1 + 0xec) + 0x58))(param_1 + 0xec,iVar1,iVar2,0);
      }
      uVar4 = _CFDictionaryCreateMutableCopy(*(undefined4 *)PTR_001037ec,0,param_2);
      _CFDictionaryRemoveValue(uVar4,&cf_element_name);
      uVar5 = AUBase_vslot_30(param_1,uVar4);
      _CFRelease(uVar4);
      *(undefined1 *)(param_1 + 0x32b434) = 0;
      return uVar5;
    }
  }
  return 0xffffd59d;
}

