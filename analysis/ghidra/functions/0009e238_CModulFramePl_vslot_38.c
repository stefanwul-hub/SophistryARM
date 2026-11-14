/* 0009e238 CModulFramePl_vslot_38 */

void CModulFramePl_vslot_38(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_34;
  int local_30;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar3 = param_3[2];
  local_24 = param_1[2] + *param_3;
  local_1c = param_1[2] + iVar3;
  iVar2 = param_1[3] + param_3[1];
  local_18 = param_1[3] + param_3[3];
  local_20 = iVar2;
  if (*(char *)((int)param_1 + 0x32) == '\0') {
    if (param_1[0xb] != 0) {
      local_14 = 0;
      local_10 = 0;
      (**(code **)(*(int *)param_1[0xb] + 0x8c))((int *)param_1[0xb],&local_14);
      iVar2 = *(int *)(param_2 + 8);
      iVar3 = *(int *)(param_2 + 0xc);
      local_30 = *(int *)(param_2 + 0x10);
      local_34 = *(int *)(param_2 + 0x14);
      *(int *)(param_2 + 8) = iVar2 + local_14;
      *(int *)(param_2 + 0xc) = local_10 + iVar3;
      *(int *)(param_2 + 0x10) = local_14 + local_30;
      *(int *)(param_2 + 0x14) = local_10 + local_34;
    }
    (**(code **)(*param_1 + 0x14))(param_1,param_2,&local_24);
    if (param_1[0xb] != 0) {
      *(int *)(param_2 + 8) = iVar2;
      *(int *)(param_2 + 0xc) = iVar3;
      *(int *)(param_2 + 0x10) = local_30;
      *(int *)(param_2 + 0x14) = local_34;
      return;
    }
  }
  else {
    piVar1 = (int *)param_1[0xb];
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)param_1[10];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x14))(piVar1,param_2,&local_24);
        return;
      }
    }
    else {
      (**(code **)(*piVar1 + 0x98))(piVar1,param_2,&local_24);
    }
  }
  return;
}

