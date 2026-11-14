/* 00094786 FUN_00094786 */

undefined4 FUN_00094786(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_10;
  
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(int *)(param_1 + 0x18) = param_2;
  piVar2 = *(int **)(param_1 + 4);
  if ((((piVar2 == (int *)0x0) || (*(int *)(param_1 + 8) == 0)) ||
      (*(int *)(param_1 + 0xc) < *(int *)(param_1 + 0x10) + 1)) ||
     (local_10 = 0, *(int *)(param_1 + 0x10) < 1)) {
LAB_000947a5:
    uVar3 = 0xffffffff;
  }
  else {
    if (param_2 != *piVar2) {
      iVar4 = 4;
      do {
        local_10 = local_10 + 1;
        *(int *)(param_1 + 0x14) = local_10;
        if (*(int *)(param_1 + 0x10) <= local_10) goto LAB_000947a5;
        piVar1 = (int *)(iVar4 + (int)piVar2);
        iVar4 = iVar4 + 4;
      } while (*piVar1 != *(int *)(param_1 + 0x18));
    }
    *(int *)(param_1 + 0x14) = local_10 + 1;
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + -4 + (local_10 + 1) * 4);
  }
  return uVar3;
}

