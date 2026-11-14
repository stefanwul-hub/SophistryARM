/* 0000b2b0 FUN_0000b2b0 */

void FUN_0000b2b0(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined1 local_16c [320];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (((*(int *)(param_1 + 0x4c) != 0) && (*(int *)(param_1 + 0x44) != 0)) &&
     (*(int *)(param_1 + 0x48) != 0)) {
    iVar1 = param_5 / 2 + param_3;
    local_2c = param_2 - param_4 / 2;
    local_28 = param_3 - param_5 / 2;
    local_24 = param_4 / 2 + param_2;
    local_20 = iVar1;
    FUN_0001d532(*(int *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),local_16c,0x18);
    uVar2 = (**(code **)(**(int **)(param_1 + 0x44) + 0x24))(*(int **)(param_1 + 0x44));
    local_1c = local_2c;
    local_18 = local_28;
    local_14 = local_24;
    local_10 = iVar1;
    piVar3 = (int *)operator_new(0xd8);
    FUN_00005f56(piVar3,&local_1c,param_1,0,uVar2,4,param_6,1);
    *(int **)(param_1 + 0x3c) = piVar3;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x130))(piVar3,local_16c);
      (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(*(int **)(param_1 + 0x3c),0);
      (**(code **)(**(int **)(param_1 + 0x44) + 0xac))
                (*(int **)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x3c));
    }
  }
  return;
}

