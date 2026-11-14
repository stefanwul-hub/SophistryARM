/* 0009ea10 FUN_0009ea10 */

void FUN_0009ea10(int *param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  short local_10;
  short local_e;
  
  uVar3 = (**(code **)(*param_1 + 0x1c))(param_1);
  cVar2 = _QDSwapPort(uVar3,&local_14);
  _GetMouse(&local_10);
  if (cVar2 != '\0') {
    _QDSwapPort(local_14,0);
  }
  *param_2 = (int)local_e;
  param_2[1] = (int)local_10;
  iVar4 = *(int *)(param_1[8] + 0x90);
  iVar5 = (int)local_e + *(int *)(param_1[8] + 0x8c);
  *param_2 = iVar5;
  iVar4 = iVar4 + local_10;
  param_2[1] = iVar4;
  iVar1 = param_1[3];
  *param_2 = iVar5 - param_1[2];
  param_2[1] = iVar4 - iVar1;
  return;
}

