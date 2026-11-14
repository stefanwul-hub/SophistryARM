/* 0009eba0 CFrame_vslot_71 */

undefined4 CFrame_vslot_71(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  
  cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = _HIViewGetFrame(param_1[0x1f],&local_24);
  if (iVar2 == 0) {
    *param_2 = (int)local_24;
    param_2[1] = (int)local_20;
    param_2[2] = (int)local_1c + (int)local_24;
    param_2[3] = (int)local_18 + (int)local_20;
    return 1;
  }
  uVar3 = _GetWindowPort(param_1[0x19]);
  _GetPortBounds(uVar3,&local_14);
  *param_2 = (int)local_12;
  param_2[1] = (int)local_14;
  param_2[2] = (int)local_e;
  param_2[3] = (int)local_10;
  return 1;
}

