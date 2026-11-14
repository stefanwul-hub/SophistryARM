/* 00018bba Synth_vslot_164 */

longdouble
Synth_vslot_164(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
               int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  
  if ((((*(int *)(param_3 + 8) < param_4) || (param_5 < *(int *)(param_3 + 8))) ||
      (*(int *)(param_3 + 0xc) < param_6)) || (param_7 < *(int *)(param_3 + 0xc))) {
    lVar6 = (longdouble)0;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x3b4))(param_1,param_2,param_4);
    iVar3 = (**(code **)(*param_1 + 0x3b8))(param_1,param_2,param_5);
    iVar4 = (**(code **)(*param_1 + 0x3bc))(param_1,param_2,param_6);
    iVar5 = (**(code **)(*param_1 + 0x3c0))(param_1,param_2,param_7);
    iVar1 = *(int *)(param_3 + 8);
    if ((iVar1 < param_4) || (iVar2 < iVar1)) {
      lVar6 = (longdouble)1;
    }
    else {
      lVar6 = (longdouble)((float)((iVar1 - param_4) + 1) / (float)((iVar2 - param_4) + 2));
    }
    if ((iVar1 <= param_5) && (iVar3 <= iVar1)) {
      lVar6 = (longdouble)
              ((float)lVar6 * ((float)((param_5 - iVar1) + 1) / (float)((param_5 - iVar3) + 2)));
    }
    iVar1 = *(int *)(param_3 + 0xc);
    if ((param_6 <= iVar1) && (iVar1 <= iVar4)) {
      lVar6 = (longdouble)
              ((float)lVar6 * ((float)((iVar1 - param_6) + 1) / (float)((iVar4 - param_6) + 2)));
    }
    if ((iVar1 <= param_7) && (iVar5 <= iVar1)) {
      lVar6 = (longdouble)
              ((float)lVar6 * ((float)((param_7 - iVar1) + 1) / (float)((param_7 - iVar5) + 2)));
    }
  }
  return lVar6;
}

