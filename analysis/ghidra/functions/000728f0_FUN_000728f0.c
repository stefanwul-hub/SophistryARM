/* 000728f0 FUN_000728f0 */

void FUN_000728f0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar5 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = iVar2;
  if ((iVar2 <= param_3) && (iVar4 = iVar3, param_3 <= iVar3)) {
    iVar4 = param_3;
  }
  if ((iVar2 <= param_4) && (iVar2 = iVar3, param_4 <= iVar3)) {
    iVar2 = param_4;
  }
  iVar3 = iVar5;
  if ((iVar5 <= param_5) && (iVar3 = param_5, iVar1 < param_5)) {
    iVar3 = iVar1;
  }
  if ((iVar5 <= param_6) && (iVar5 = param_6, iVar1 < param_6)) {
    iVar5 = iVar1;
  }
  FUN_0009f51a(param_2,param_7);
  local_1c = iVar2;
  local_18 = iVar5;
  local_14 = iVar4;
  local_10 = iVar3;
  FUN_0009df12(param_2,&local_14);
  FUN_000a0cea(param_2,&local_1c);
  return;
}

