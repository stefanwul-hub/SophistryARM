/* 0009d240 CFrame_vslot_69 */

undefined4 CFrame_vslot_69(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  short local_14;
  short local_12;
  
  cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  _GetWindowBounds(param_1[0x19],0x21,&local_14);
  *param_2 = (int)local_12;
  *param_3 = (int)local_14;
  return 1;
}

