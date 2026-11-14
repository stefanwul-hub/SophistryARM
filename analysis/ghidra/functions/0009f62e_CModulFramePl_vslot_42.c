/* 0009f62e CModulFramePl_vslot_42 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CModulFramePl_vslot_42(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  if (param_1[0x11] == 0) {
    cVar3 = (**(code **)(*param_1 + 0x50))(param_1);
    if (cVar3 != '\0') {
      local_20 = param_1[5] - param_1[3];
      local_24 = param_1[4] - param_1[2];
      local_2c = 0;
      local_28 = 0;
      (**(code **)(*param_1 + 0x98))(param_1,param_2,&local_2c);
      (**(code **)(*param_1 + 0x54))(param_1,0);
      return;
    }
  }
  else if (param_1[0x11] == 1) {
    if ((char)param_1[0xc] == '\0') {
      local_2c = 0;
      local_24 = param_1[4] - param_1[2];
      local_28 = -param_1[3] + param_1[3];
      local_20 = -param_1[3] + param_1[5];
      for (piVar1 = (int *)param_1[0xf]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
        piVar2 = (int *)*piVar1;
        cVar3 = (**(code **)(*piVar2 + 0x50))(piVar2);
        if ((cVar3 != '\0') &&
           (cVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,&local_2c), cVar3 != '\0')) {
          iVar4 = (**(code **)(*piVar2 + 0x94))
                            (piVar2,param_1,PTR_s_kMsgCheckIfViewContainer_000e20a4);
          if (iVar4 == 0) {
            local_3c = local_2c;
            if (local_2c <= piVar2[2]) {
              local_3c = piVar2[2];
            }
            local_38 = local_28;
            if (local_28 <= piVar2[3]) {
              local_38 = piVar2[3];
            }
            iVar4 = local_24;
            if (piVar2[4] <= local_24) {
              iVar4 = piVar2[4];
            }
            iVar5 = local_20;
            if (piVar2[5] <= local_20) {
              iVar5 = piVar2[5];
            }
            local_30 = local_38;
            if (local_38 <= iVar5) {
              local_30 = iVar5;
            }
            local_34 = local_3c;
            if (local_3c <= iVar4) {
              local_34 = iVar4;
            }
            (**(code **)(*piVar2 + 0x98))(piVar2,param_2,&local_3c);
          }
          else {
            (**(code **)(*piVar2 + 0xa8))(piVar2,param_2);
          }
        }
      }
    }
    else {
      local_20 = param_1[5] - param_1[3];
      local_24 = param_1[4] - param_1[2];
      local_2c = 0;
      local_28 = 0;
      (**(code **)(*param_1 + 0x98))(param_1,param_2,&local_2c);
    }
    (**(code **)(*param_1 + 0x54))(param_1,0);
    return;
  }
  return;
}

