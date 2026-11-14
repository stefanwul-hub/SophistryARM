/* 00003c80 LPAUSynth_vslot_17 */

undefined4 LPAUSynth_vslot_17(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  int local_10 [2];
  
  if ((char)param_1[0xcad0c] == '\0') {
    (**(code **)(param_1[0x3b] + 0xc))(param_1 + 0x3b);
    *(undefined1 *)(param_1 + 0xcad0c) = 1;
  }
  if ((param_3 == 0) && (param_4 == 0)) {
    local_10[0] = param_2;
    cVar1 = (**(code **)(*param_1 + 0x134))(param_1,local_10);
    if (cVar1 == '\0') {
      return 0xffffd582;
    }
    if (param_1[0xcad0b] != local_10[0]) {
      (**(code **)(*param_1 + 0x144))(param_1,param_2,param_5);
      return 0;
    }
  }
  return 0;
}

