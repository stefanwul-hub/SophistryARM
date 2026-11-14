/* 00002e3e LPAUSynth_vslot_68 */

char LPAUSynth_vslot_68(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = (**(code **)(param_1[0x3b] + 0x31c))(param_1 + 0x3b);
  param_2 = param_2 + iVar2 * param_1[0xf0a];
  cVar1 = (**(code **)(*param_1 + 0x134))(param_1,&param_2);
  if (cVar1 != '\0') {
    local_1c = param_1[1];
    local_14 = 0;
    local_10 = 0;
    local_18 = param_2;
    local_20 = 2;
    _AUEventListenerNotify(0,0,&local_20);
  }
  return cVar1;
}

