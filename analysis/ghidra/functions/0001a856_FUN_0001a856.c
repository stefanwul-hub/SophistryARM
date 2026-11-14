/* 0001a856 FUN_0001a856 */

void FUN_0001a856(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4,int param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_3 != (int *)0x0) && (0 < param_5)) &&
      (iVar3 = *(int *)(param_1 + 0x3b88), -1 < iVar3)) && (iVar3 < 0xa0)) {
    pvVar1 = _malloc(param_5 * 4 + 4);
    *(void **)(iVar3 * 0x1c + 0x511c + param_1) = pvVar1;
    iVar3 = *(int *)(param_1 + 0x3b88);
    if (*(int *)(iVar3 * 0x1c + 0x511c + param_1) != 0) {
      iVar4 = 0;
      while( true ) {
        *(undefined4 *)(*(int *)(iVar3 * 0x1c + 0x511c + param_1) + iVar4 * 4) = 0;
        iVar4 = iVar4 + 1;
        if (param_5 == iVar4) break;
        iVar3 = *(int *)(param_1 + 0x3b88);
      }
      *(int *)(*(int *)(param_1 + 0x3b88) * 0x1c + 0x5118 + param_1) = param_3[1];
      **(undefined4 **)(*(int *)(param_1 + 0x3b88) * 0x1c + 0x511c + param_1) = param_3;
      *(undefined4 *)(*(int *)(param_1 + 0x3b88) * 0x1c + 0x5120 + param_1) = 0;
      iVar3 = *(int *)(param_1 + 0x3b88);
      uVar2 = (**(code **)(*param_3 + 100))(param_3);
      *(undefined4 *)(iVar3 * 0x1c + 0x5124 + param_1) = uVar2;
      *(undefined4 *)(*(int *)(param_1 + 0x3b88) * 0x1c + 0x5128 + param_1) = param_4;
      *(int *)(*(int *)(param_1 + 0x3b88) * 0x1c + 0x512c + param_1) = param_5;
      *param_2 = *(undefined4 *)(param_1 + 0x3b88);
      *(int *)(param_1 + 0x3b88) = *(int *)(param_1 + 0x3b88) + 1;
      if (param_5 == 1) {
        FUN_0001a686();
        return;
      }
    }
  }
  return;
}

