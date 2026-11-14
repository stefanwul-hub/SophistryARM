/* 000a0958 CModulFramePl_vslot_54 */

void CModulFramePl_vslot_54(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    if (*(char *)(param_1 + 0x32) == '\0') {
      FUN_0009e6ec(param_2,*(undefined4 *)(param_1 + 0x4c));
      FUN_0009fcae(param_2,param_3);
    }
  }
  else {
    local_1c = -*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x50);
    local_14 = -*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x58);
    local_18 = -*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x54);
    local_10 = -*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x5c);
    local_2c = local_1c;
    if (local_1c <= *param_3) {
      local_2c = *param_3;
    }
    local_28 = local_18;
    if (local_18 <= param_3[1]) {
      local_28 = param_3[1];
    }
    iVar3 = local_14;
    if (param_3[2] <= local_14) {
      iVar3 = param_3[2];
    }
    iVar2 = local_10;
    if (param_3[3] <= local_10) {
      iVar2 = param_3[3];
    }
    local_20 = local_28;
    if (local_28 <= iVar2) {
      local_20 = iVar2;
    }
    local_24 = local_2c;
    if (local_2c <= iVar3) {
      local_24 = iVar3;
    }
    FUN_000a08c2(param_2,&local_2c);
    piVar1 = *(int **)(param_1 + 0x34);
    local_30 = piVar1[4];
    local_34 = piVar1[3];
    local_3c = 0;
    local_38 = 0;
    if (*(char *)(param_1 + 0x32) == '\0') {
      (**(code **)(*piVar1 + 0x10))(piVar1,param_2,&local_3c,param_1 + 0x50);
    }
    else {
      (**(code **)(*piVar1 + 0x14))(piVar1,param_2,&local_3c,param_1 + 0x50);
    }
    FUN_000a08c2(param_2,&local_1c);
  }
  return;
}

