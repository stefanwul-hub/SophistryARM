/* 000ad1ce AUVPresets_vslot_4 */

undefined4 AUVPresets_vslot_4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  if (param_2[1] == *(int *)(param_1 + 0x1c)) {
    local_10 = 8;
    iVar1 = _AudioUnitGetProperty(*param_2,param_2[1],param_2[2],param_2[3],local_18,&local_10);
    if (iVar1 == 0) {
      if ((param_2[1] == 0x1c) && (local_14 != 0)) {
        _CFRetain(local_14);
      }
      FUN_000ad132(param_1,local_18);
      return 1;
    }
  }
  return 0;
}

