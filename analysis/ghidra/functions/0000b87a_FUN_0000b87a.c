/* 0000b87a FUN_0000b87a */

void FUN_0000b87a(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9,undefined4 param_10,int param_11)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  void *pvVar9;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((param_4 != 0) && (param_3 != 0)) {
    if (param_11 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
      *(undefined4 *)(param_1 + 8) = param_2;
      *(int *)(param_1 + 0x48) = param_3;
      *(int *)(param_1 + 0x4c) = param_4;
      *(int *)(param_1 + 0x44) = param_11;
      *(undefined1 *)(param_1 + 4) = 1;
      FUN_0001ce0e(param_4,param_2,param_1 + 0x10);
    }
    *(undefined4 *)(param_1 + 0xc) = 10;
    local_1c = param_5;
    local_18 = param_6;
    local_14 = param_5 + param_7;
    local_10 = param_6 + param_8;
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    uVar2 = *(undefined4 *)(param_1 + 0x14);
    uVar3 = *(undefined4 *)(param_1 + 0x18);
    uVar4 = *(undefined4 *)(param_1 + 0x1c);
    uVar5 = *(undefined4 *)(param_1 + 0x20);
    uVar6 = *(undefined4 *)(param_1 + 0x24);
    uVar7 = *(undefined4 *)(param_1 + 0x28);
    pvVar9 = operator_new(0xfc);
    FUN_000077e2(pvVar9,&local_1c,param_1,param_2,param_10,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7
                );
    FUN_0000b6b6(param_1,pvVar9);
    piVar8 = *(int **)(param_1 + 0x34);
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 0x13c))(piVar8,4);
      (**(code **)(**(int **)(param_1 + 0x34) + 0x140))
                (*(int **)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x60));
      (**(code **)(**(int **)(param_1 + 0x34) + 0x138))(*(int **)(param_1 + 0x34),param_9);
      (**(code **)(**(int **)(param_1 + 0x34) + 0x144))(*(int **)(param_1 + 0x34),1);
    }
  }
  return;
}

