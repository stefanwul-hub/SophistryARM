/* 00098f70 CMenuFileList_vslot_7 */

void CMenuFileList_vslot_7(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  char local_10c [256];
  
  if (((*(char *)((int)param_1 + 0x31) != '\0') && (param_1[10] != 0)) && (param_2 != 0)) {
    uVar2 = param_4;
    if (param_4 == 0xffffffff) {
      uVar2 = FUN_0009cba2(param_2);
    }
    param_1[0x31] = uVar2;
    piVar1 = (int *)param_1[0xf];
    if ((((piVar1 == (int *)0x0) || ((param_4 & 0x78) == 0)) ||
        (iVar3 = (**(code **)(*piVar1 + 4))(piVar1,param_2,param_1,param_4), iVar3 == 0)) &&
       ((*(byte *)(param_1 + 0x31) & 0x45) != 0)) {
      if (param_1[0x30] != 0) {
        if (param_1[0x2f] < 0) {
          local_10c[0] = '\0';
        }
        else {
          _strcpy(local_10c,*(char **)(param_1[0x29] + param_1[0x2f] * 4));
        }
        FUN_00098ac0(param_1,param_2,local_10c,param_1[0x30]);
      }
      (**(code **)(*param_1 + 0xe0))(param_1);
      (**(code **)(*param_1 + 0x4c))(param_1,param_2);
    }
  }
  return;
}

