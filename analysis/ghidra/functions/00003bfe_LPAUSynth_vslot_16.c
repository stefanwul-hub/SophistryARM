/* 00003bfe LPAUSynth_vslot_16 */

undefined4
LPAUSynth_vslot_16(int *param_1,undefined4 param_2,int param_3,int param_4,float *param_5)

{
  char cVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined4 local_10 [2];
  
  if ((char)param_1[0xcad0c] == '\0') {
    (**(code **)(param_1[0x3b] + 0xc))(param_1 + 0x3b);
    *(undefined1 *)(param_1 + 0xcad0c) = 1;
  }
  if ((param_3 == 0) && (param_4 == 0)) {
    local_10[0] = param_2;
    cVar1 = (**(code **)(*param_1 + 0x134))(param_1,local_10);
    if (cVar1 == '\0') {
      uVar2 = 0xffffd582;
    }
    else {
      lVar3 = (longdouble)(**(code **)(*param_1 + 0x148))(param_1,param_2);
      *param_5 = (float)lVar3;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

