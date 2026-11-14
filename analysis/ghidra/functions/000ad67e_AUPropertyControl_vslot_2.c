/* 000ad67e AUPropertyControl_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUPropertyControl_vslot_2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_20 [4];
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar2 = _CFDictionaryCreateMutable(0,0,0,0);
    *(undefined4 *)(param_1 + 4) = uVar2;
  }
  cVar1 = _CFDictionaryGetValueIfPresent(*(undefined4 *)(param_1 + 4),param_2,local_20);
  if (cVar1 != '\0') {
    _AddEventTypesToHandler(local_20[0],param_3,param_4);
    return;
  }
  _InstallEventHandler(param_2,FUN_000ad424,param_3,param_4,param_1,local_20);
  _CFDictionaryAddValue(*(undefined4 *)(param_1 + 4),param_2,local_20[0]);
  return;
}

