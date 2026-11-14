/* 000ad258 AUVPresets_vslot_5 */

void AUVPresets_vslot_5(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20 = 3;
  local_1c = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10);
  local_18 = *(undefined4 *)(param_1 + 0x1c);
  local_14 = 0;
  local_10 = 0;
  _AUEventListenerAddEventType(param_2,param_3,&local_20);
  return;
}

