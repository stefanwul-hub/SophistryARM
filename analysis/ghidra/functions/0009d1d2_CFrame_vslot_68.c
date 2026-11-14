/* 0009d1d2 CFrame_vslot_68 */

undefined4 CFrame_vslot_68(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  float local_1c;
  float local_18;
  
  cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
  if ((((cVar1 != '\0') && (param_1[0x1f] != 0)) &&
      (iVar2 = _HIViewGetFrame(param_1[0x1f],&local_1c), iVar2 == 0)) &&
     (iVar2 = _HIViewMoveBy(param_1[0x1f],(float)param_2 - local_1c,(float)param_3 - local_18),
     iVar2 == 0)) {
    return 1;
  }
  return 0;
}

