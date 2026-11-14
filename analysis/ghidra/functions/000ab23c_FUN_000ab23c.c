/* 000ab23c FUN_000ab23c */

void FUN_000ab23c(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  
  if (*param_2 != 0) {
    *(undefined1 *)(param_1 + 0x7c) = 1;
    *(undefined4 *)(param_1 + 0x78) = 1;
    *(int *)(param_1 + 0x88) = *param_2;
    *(int *)(param_1 + 0x8c) = param_2[1];
    *(int *)(param_1 + 0x90) = param_2[2];
    *(undefined4 *)(param_1 + 0x94) = 0;
    FUN_000ab9ac(param_1,0);
    local_10 = 4;
    iVar1 = _AudioUnitGetProperty(*param_2,5,0,0xe,param_1 + 0x94,&local_10);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    uVar2 = _GetComponentInstanceStorage(*param_2);
    *(undefined4 *)(param_1 + 0x98) = uVar2;
    *(undefined1 *)(param_1 + 0x7c) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  FUN_000ae198(param_1 + 0x5c);
  return;
}

