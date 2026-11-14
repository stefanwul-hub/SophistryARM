/* 00003d14 LPAUSynth_vslot_29 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int LPAUSynth_vslot_29(int param_1,undefined4 *param_2)

{
  int iVar1;
  int local_20 [4];
  
  if (*(char *)(param_1 + 0x32b430) == '\0') {
    (**(code **)(*(int *)(param_1 + 0xec) + 0xc))(param_1 + 0xec);
    *(undefined1 *)(param_1 + 0x32b430) = 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = AUBase_vslot_29(param_1,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
    local_20[0] = 0;
    iVar1 = (**(code **)(*(int *)(param_1 + 0xec) + 0x54))(param_1 + 0xec,local_20,0);
    if ((0 < iVar1) && (local_20[0] != 0)) {
      iVar1 = _CFDataCreate(0,local_20[0],iVar1);
      if (iVar1 != 0) {
        _CFDictionaryRemoveValue(*param_2,&cf_data);
        _CFDictionarySetValue(*param_2,&cf_vstdata,iVar1);
        _CFRelease(iVar1);
        return 0;
      }
    }
    _CFRelease(*param_2);
    *param_2 = 0;
  }
  return -0x2a63;
}

