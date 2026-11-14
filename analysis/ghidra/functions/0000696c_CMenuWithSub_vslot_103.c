/* 0000696c CMenuWithSub_vslot_103 */

void CMenuWithSub_vslot_103(int *param_1,int *param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (*param_2 + 1 < param_3) {
    cVar3 = (**(code **)(*param_1 + 0x194))(param_1,*param_2,param_3);
    if (cVar3 != '\0') {
      iVar2 = *param_2;
      uVar4 = (**(code **)(*param_1 + 0x18c))(param_1,iVar2);
      (**(code **)(*param_1 + 0x198))(param_1,param_2,param_3,uVar4,(char)param_1[0x367]);
      uVar4 = (**(code **)(*param_1 + 400))(param_1,param_1[0x369],iVar2,uVar4);
      (**(code **)(*param_1 + 0x130))(param_1,param_1[param_1[0x369] + 0x45],uVar4);
      param_1[0x369] = param_1[0x369] + 1;
      return;
    }
  }
  pcVar1 = *(code **)(*param_1 + 0x17c);
  iVar2 = param_1[0x368];
  param_1[0x368] = iVar2 + 1;
  (*pcVar1)(param_1,param_1,*param_2,iVar2);
  *param_2 = *param_2 + 1;
  return;
}

