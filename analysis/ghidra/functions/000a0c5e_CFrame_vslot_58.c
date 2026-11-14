/* 000a0c5e CFrame_vslot_58 */

int CFrame_vslot_58(int *param_1)

{
  int iVar1;
  int *piVar2;
  int local_14;
  int local_10;
  
  iVar1 = param_1[0x1a];
  if (iVar1 == 0) {
    if (param_1[10] != 0) {
      local_14 = 0;
      local_10 = 0;
      (**(code **)(*(int *)param_1[10] + 0x134))((int *)param_1[10],&local_14);
      (**(code **)(*param_1 + 0x88))(param_1,&local_14);
      piVar2 = (int *)param_1[0x10];
      if (piVar2 != (int *)0x0) {
        while ((((iVar1 = *piVar2, iVar1 == 0 || (local_14 < *(int *)(iVar1 + 0x18))) ||
                (*(int *)(iVar1 + 0x20) < local_14)) ||
               ((local_10 < *(int *)(iVar1 + 0x1c) || (*(int *)(iVar1 + 0x24) < local_10))))) {
          piVar2 = (int *)piVar2[2];
          if (piVar2 == (int *)0x0) {
            return 0;
          }
        }
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

