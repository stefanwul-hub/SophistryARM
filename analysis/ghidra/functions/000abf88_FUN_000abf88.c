/* 000abf88 FUN_000abf88 */

void FUN_000abf88(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 local_10;
  
  piVar6 = param_1 + 2;
  iVar4 = param_1[2];
  iVar2 = param_1[3];
  if ((uint)(iVar2 - iVar4 >> 2) < param_2) {
    FUN_000c6d9a(piVar6,param_2);
    puVar3 = (undefined4 *)param_1[3];
    while (uVar5 = (int)puVar3 - *piVar6 >> 2, uVar5 < param_2) {
      local_10 = (*(code *)**(undefined4 **)*param_1)((undefined4 *)*param_1,param_1[1],uVar5);
      puVar3 = (undefined4 *)param_1[3];
      if (puVar3 == (undefined4 *)param_1[4]) {
        FUN_000c6c44(piVar6,puVar3,&local_10);
        puVar3 = (undefined4 *)param_1[3];
      }
      else {
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = local_10;
          puVar3 = (undefined4 *)param_1[3];
        }
        puVar3 = puVar3 + 1;
        param_1[3] = puVar3;
      }
    }
  }
  else {
    while (param_2 < (uint)(iVar2 - iVar4 >> 2)) {
      while( true ) {
        piVar1 = *(int **)(iVar2 + -4);
        iVar2 = iVar2 + -4;
        param_1[3] = iVar2;
        if (piVar1 == (int *)0x0) break;
        (**(code **)(*piVar1 + 4))(piVar1);
        iVar2 = param_1[3];
        iVar4 = *piVar6;
        if ((uint)(iVar2 - iVar4 >> 2) <= param_2) {
          return;
        }
      }
    }
  }
  return;
}

