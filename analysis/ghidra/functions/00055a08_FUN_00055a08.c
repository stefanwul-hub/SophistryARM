/* 00055a08 FUN_00055a08 */

void FUN_00055a08(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined4 uVar1;
  int iVar2;
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
  
  if ((*(int *)(param_1 + 0x4c) != 0) && (param_2 != (int *)0x0)) {
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (iVar2 != 0) {
      local_20 = param_5 + param_7;
      local_2c = param_4;
      local_28 = param_5;
      local_24 = param_4 + param_6;
      local_1c = param_4;
      local_18 = param_5;
      uVar1 = *(undefined4 *)(param_1 + 0x34);
      local_14 = local_24;
      local_10 = local_20;
      piVar3 = (int *)operator_new(0xd8);
      FUN_00005f56(piVar3,&local_1c,param_1 + 0x20,param_3,iVar2,4,uVar1,0);
      if (piVar3 != (int *)0x0) {
        FUN_0001d532(*(undefined4 *)(param_1 + 0x4c),param_3,local_16c,0x13f);
        (**(code **)(*piVar3 + 0x130))(piVar3,local_16c);
        (**(code **)(*piVar3 + 0x58))(piVar3,0);
        FUN_000266ca(param_1,piVar3,param_3,param_2);
      }
    }
  }
  return;
}

