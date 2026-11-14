/* 000a0df0 FUN_000a0df0 */

void FUN_000a0df0(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_24;
  int local_20;
  
  iVar1 = *param_2;
  iVar2 = param_2[1];
  iVar3 = *(int *)(param_1 + 0x3c);
  uVar4 = *(undefined4 *)(param_1 + 0x40);
  if (iVar3 != 1) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
    if (*(int *)(param_1 + 0x60) != 0) {
      _CGContextSetLineWidth(*(int *)(param_1 + 0x60),0x3f800000);
    }
  }
  FUN_0009f51a(param_1,param_3);
  local_24 = iVar1 + 1;
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x10) + iVar1;
  *(int *)(param_1 + 0x38) = iVar2 + *(int *)(param_1 + 0x14);
  local_20 = iVar2;
  FUN_000a0cea(param_1,&local_24);
  FUN_0009f51a(param_1,uVar4);
  if (iVar3 != *(int *)(param_1 + 0x3c)) {
    *(int *)(param_1 + 0x3c) = iVar3;
    if (*(int *)(param_1 + 0x60) != 0) {
      _CGContextSetLineWidth(*(int *)(param_1 + 0x60),(float)iVar3);
    }
  }
  return;
}

