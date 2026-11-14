/* 00031b0e GloFil_c_vslot_59 */

bool GloFil_c_vslot_59(int *param_1,char param_2,int param_3)

{
  int iVar1;
  longdouble lVar2;
  
  if (param_2 == '\0') {
    if ((char)param_1[0x75] == '\0') {
      iVar1 = param_1[0x76];
    }
    else {
      lVar2 = (longdouble)(**(code **)(*param_1 + 0xf4))(param_1);
      param_1[0x76] = (int)((float)lVar2 * (float)param_1[0x50]);
      iVar1 = param_1[0x76];
    }
    if (0 < iVar1) {
      (**(code **)(*param_1 + 0xe0))(param_1,param_3);
      param_1[0x76] = param_1[0x76] - param_3;
    }
    *(undefined1 *)(param_1 + 0x75) = 0;
    return 0 < iVar1;
  }
  *(undefined1 *)(param_1 + 0x75) = 1;
  (**(code **)(*param_1 + 0xe0))(param_1,param_3);
  return true;
}

