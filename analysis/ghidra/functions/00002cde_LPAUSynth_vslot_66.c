/* 00002cde LPAUSynth_vslot_66 */

void LPAUSynth_vslot_66(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  Synth_vslot_13(param_1 + 0x3b,param_2,param_3);
  iVar2 = (**(code **)(param_1[0x3b] + 0x31c))(param_1 + 0x3b);
  local_10 = param_2 + iVar2 * param_1[0xf0a];
  cVar1 = (**(code **)(*param_1 + 0x134))(param_1,&local_10);
  if (cVar1 != '\0') {
    param_1[0xcad0b] = local_10;
    local_20 = param_1[1];
    local_18 = 0;
    local_14 = 0;
    local_1c = local_10;
    local_24 = 0;
    _AUEventListenerNotify(0,0,&local_24);
    _AUParameterListenerNotify(0,0,&local_20);
    param_1[0xcad0b] = -1;
  }
  return;
}

