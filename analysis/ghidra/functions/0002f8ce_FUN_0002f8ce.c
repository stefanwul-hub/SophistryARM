/* 0002f8ce FUN_0002f8ce */

void FUN_0002f8ce(int param_1,undefined4 param_2,int *param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_14;
  
  if ((*(int *)(param_1 + 0x10) != 0) && (param_3 != (int *)0x0)) {
    if (param_4 < 0) {
      param_4 = 0;
    }
    iVar7 = *(int *)(param_1 + 0xc) + -1;
    if (param_4 <= iVar7) {
      iVar7 = param_4;
    }
    (**(code **)(*param_3 + 0x8c))(param_3,*(undefined4 *)(param_5 + 0x10),0);
    iVar3 = iVar7 * 0x24;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 4 + iVar3) = param_2;
    *(undefined4 *)(iVar3 + 0xc + *(int *)(param_1 + 0x10)) = *(undefined4 *)(param_5 + 8);
    *(undefined4 *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10)) = *(undefined4 *)(param_5 + 0xc);
    *(undefined4 *)(iVar3 + 0x14 + *(int *)(param_1 + 0x10)) = *(undefined4 *)(param_5 + 0x10);
    iVar6 = *(int *)(param_1 + 0x10);
    uVar4 = FUN_0002e1c0(param_1 + 4);
    *(undefined4 *)(iVar3 + iVar6 + 0x1c) = uVar4;
    piVar1 = *(int **)(param_1 + 0x10);
    piVar5 = piVar1;
    if (piVar1 != (int *)0x0) {
      local_14 = piVar1[iVar7 * 9 + 7] + 1;
      if (0 < *(int *)(param_1 + 0xc)) {
        iVar6 = 0;
        do {
          iVar2 = local_14;
          if ((((iVar7 != iVar6) && (*piVar5 == 1)) && (piVar1[iVar7 * 9 + 1] == piVar5[1])) &&
             ((piVar1[iVar7 * 9 + 5] == piVar5[5] && (iVar2 = piVar5[7], local_14 <= piVar5[7])))) {
            iVar2 = local_14;
          }
          local_14 = iVar2;
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 9;
        } while (iVar6 != *(int *)(param_1 + 0xc));
      }
      piVar5 = (int *)(uint)(0x1e < piVar1[iVar7 * 9 + 7] - local_14);
    }
    *(char *)(piVar1 + iVar7 * 9 + 6) = (char)piVar5;
    FUN_0002f468(param_1,iVar7,1,param_3);
    *(int **)(iVar3 + 8 + *(int *)(param_1 + 0x10)) = param_3;
  }
  return;
}

