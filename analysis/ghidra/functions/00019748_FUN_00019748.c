/* 00019748 FUN_00019748 */

void FUN_00019748(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_24;
  int local_10;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar6 = *(int *)(param_1 + 0xcfb0) + -1;
  if (iVar6 < param_2) {
    param_2 = iVar6;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar6 = *(int *)(param_1 + 0x9a4c) + -1;
  if (param_3 <= iVar6) {
    iVar6 = param_3;
  }
  piVar4 = *(int **)(*(int *)(param_1 + 0xcea0) + iVar6 * 4);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))(piVar4);
  }
  if (*(int *)(param_1 + 0x3b88) < 3) {
    local_24 = 0;
LAB_00019801:
    pvVar2 = operator_new(0x10);
    FUN_0002df20(pvVar2,local_24,0);
    *(void **)(iVar6 * 4 + *(int *)(param_1 + 0xcea0)) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      local_10 = 0;
      FUN_0002e0b2(pvVar2,0,&local_10);
      if ((((local_10 != 0) && (2 < *(int *)(param_1 + 0x3b88))) &&
          (iVar6 = (local_24 & 0xfffffffc) + local_10, local_10 - iVar6 < -3)) &&
         (piVar4 = *(int **)(param_1 + 0x5168), piVar4 != (int *)0x0)) {
        iVar5 = 2;
        iVar7 = param_1;
        do {
          uVar3 = (**(code **)(*piVar4 + 0xc))(piVar4,local_10,param_2);
          *(undefined4 *)(local_10 + 8) = *(undefined4 *)(iVar7 + 0x5160);
          local_10 = (uVar3 & 0xfffffffc) + local_10;
          iVar5 = iVar5 + 1;
          if (*(int *)(param_1 + 0x3b88) <= iVar5) {
            return;
          }
          if (-4 < local_10 - iVar6) {
            return;
          }
          piVar4 = *(int **)(iVar7 + 0x5184);
          iVar7 = iVar7 + 0x1c;
        } while (piVar4 != (int *)0x0);
      }
    }
  }
  else {
    piVar4 = *(int **)(param_1 + 0x5168);
    if (piVar4 != (int *)0x0) {
      iVar5 = 2;
      local_24 = 0;
      iVar7 = param_1;
      do {
        iVar1 = (**(code **)(*piVar4 + 8))(piVar4,param_2);
        local_24 = local_24 + iVar1;
        iVar5 = iVar5 + 1;
        if (*(int *)(param_1 + 0x3b88) <= iVar5) goto LAB_00019801;
        piVar4 = *(int **)(iVar7 + 0x5184);
        iVar7 = iVar7 + 0x1c;
      } while (piVar4 != (int *)0x0);
    }
  }
  return;
}

