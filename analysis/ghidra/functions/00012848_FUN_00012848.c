/* 00012848 FUN_00012848 */

void FUN_00012848(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    param_1[3] = param_2;
    pcVar1 = *(code **)(*param_1 + 0xdc);
    uVar2 = (**(code **)(*param_1 + 100))(param_1);
    iVar3 = (*pcVar1)(param_1,uVar2);
    param_1[1] = iVar3;
    param_1[0x5b] = param_3;
  }
  return;
}

