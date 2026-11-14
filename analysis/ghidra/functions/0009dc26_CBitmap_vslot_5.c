/* 0009dc26 CBitmap_vslot_5 */

void CBitmap_vslot_5(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((char)param_1[6] == '\0') {
    (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,param_4,0xff);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,1);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,param_4,0xff);
      _CGImageRelease();
      return;
    }
  }
  return;
}

