/* 000a0abe CFrame_vslot_42 */

void CFrame_vslot_42(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  cVar2 = (**(code **)(*param_1 + 0x150))(param_1);
  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_1 + 0x158))(param_1), cVar2 == '\0')) {
    if ((char)param_1[0xc] == '\0') {
      local_1c = *(int *)(param_2 + 0x50) + -*(int *)(param_2 + 0x10);
      local_14 = -*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x58);
      local_18 = -*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x54);
      local_10 = -*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x5c);
      piVar5 = (int *)param_1[0x1a];
      if ((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar2 != '\0'))
      {
        (**(code **)(*(int *)param_1[0x1a] + 0xa8))((int *)param_1[0x1a],param_2);
      }
      piVar5 = (int *)param_1[0xf];
      if (piVar5 != (int *)0x0) {
        do {
          piVar1 = (int *)*piVar5;
          local_2c = local_1c;
          if (local_1c <= piVar1[2]) {
            local_2c = piVar1[2];
          }
          local_28 = local_18;
          if (local_18 <= piVar1[3]) {
            local_28 = piVar1[3];
          }
          iVar3 = local_14;
          if (piVar1[4] <= local_14) {
            iVar3 = piVar1[4];
          }
          iVar4 = local_10;
          if (piVar1[5] <= local_10) {
            iVar4 = piVar1[5];
          }
          local_20 = local_28;
          if (local_28 <= iVar4) {
            local_20 = iVar4;
          }
          local_24 = local_2c;
          if (local_2c <= iVar3) {
            local_24 = iVar3;
          }
          FUN_000a08c2(param_2,&local_2c);
          (**(code **)(*piVar1 + 0xa8))(piVar1,param_2);
          piVar5 = (int *)piVar5[1];
        } while (piVar5 != (int *)0x0);
      }
      FUN_000a08c2(param_2,&local_1c);
      return;
    }
    (**(code **)(*param_1 + 0x10))(param_1,param_2);
    (**(code **)(*param_1 + 0x54))(param_1,0);
  }
  return;
}

