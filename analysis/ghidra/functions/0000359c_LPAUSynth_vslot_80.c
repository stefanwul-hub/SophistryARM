/* 0000359c LPAUSynth_vslot_80 */

void LPAUSynth_vslot_80(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((*(char *)(param_1 + 0xd) != '\0') && (*(char *)(param_1 + 0x32b434) == '\0')) {
    local_14 = 0;
    local_10 = 0;
    local_18 = 0xffffffff;
    local_1c = *(undefined4 *)(param_1 + 4);
    _AUParameterListenerNotify(0,0,&local_1c);
    return;
  }
  return;
}

