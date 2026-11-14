/* 0009edb0 CModulFramePl_vslot_58 */

int CModulFramePl_vslot_58(int *param_1)

{
  int *piVar1;
  int iVar2;
  int local_14;
  int local_10;
  
  if (param_1[10] != 0) {
    local_14 = 0;
    local_10 = 0;
    (**(code **)(*(int *)param_1[10] + 0x134))((int *)param_1[10],&local_14);
    (**(code **)(*param_1 + 0x88))(param_1,&local_14);
    for (piVar1 = (int *)param_1[0x10]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      iVar2 = *piVar1;
      if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) <= local_14)) &&
          (local_14 <= *(int *)(iVar2 + 0x20))) &&
         ((*(int *)(iVar2 + 0x1c) <= local_10 && (local_10 <= *(int *)(iVar2 + 0x24))))) {
        return iVar2;
      }
    }
  }
  return 0;
}

