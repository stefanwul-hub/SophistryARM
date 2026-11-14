/* 0001cf16 Synth_vslot_219 */

void Synth_vslot_219(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *local_50;
  int local_30;
  int local_18;
  int *local_14;
  int local_10;
  
  if ((param_1[0xeda] < 0) || (local_10 = 0, param_1[0x33ec] < 1)) {
    local_30 = param_2;
  }
  else {
    local_30 = param_2;
    local_10 = 0;
    iVar5 = param_1[0xee0];
    iVar4 = param_1[0xeda];
    do {
      if (local_30 == iVar4) {
        local_30 = iVar5;
      }
      local_10 = local_10 + 1;
      iVar4 = iVar4 + param_1[0xedb];
      iVar5 = iVar5 + param_1[0xee1];
    } while (local_10 < param_1[0x33ec]);
  }
  FUN_0001cb52(param_1,local_30,&local_14,&local_18,&local_10);
  if (local_18 != -1) {
    if (local_14 == (int *)0x0) {
      return;
    }
    (**(code **)(*local_14 + 0x44))(local_14,local_10,local_18,param_3);
    bVar2 = true;
    while ((((param_1[0x22af] != 0 && (-1 < param_2)) && (param_2 < param_1[0x2692])) &&
           (piVar3 = (int *)(param_1[0x22af] + param_2 * 0x20), param_2 == *piVar3))) {
      if (bVar2) {
        if (0 < param_1[0xee2]) {
          local_50 = param_1;
          iVar5 = 0;
          do {
            if (((int *)local_50[0x1447] != (int *)0x0) && (piVar3[5] == *(int *)local_50[0x1447]))
            goto LAB_0001d192;
            iVar5 = iVar5 + 1;
            local_50 = local_50 + 7;
          } while (param_1[0xee2] != iVar5);
        }
        iVar5 = -1;
LAB_0001d192:
        param_1[0x2699] = iVar5;
        param_1[0x269a] = 0;
      }
      else {
        iVar5 = param_1[0x2699];
      }
      if ((iVar5 < 0) || (iVar4 = param_1[0x269a], param_1[iVar5 * 7 + 0x144b] <= iVar4)) break;
      iVar1 = param_1[iVar5 * 7 + 0x1447];
      while( true ) {
        if ((iVar1 == 0) || (piVar3 = *(int **)(iVar1 + iVar4 * 4), piVar3 == (int *)0x0))
        goto LAB_0001cfd2;
        iVar1 = piVar3[0x4a];
        iVar4 = iVar4 + 1;
        param_1[0x269a] = iVar4;
        if (local_10 == iVar1) break;
        if (param_1[iVar5 * 7 + 0x144b] <= iVar4) goto LAB_0001cfd2;
        iVar1 = param_1[iVar5 * 7 + 0x1447];
      }
      if (local_10 != iVar1) break;
      (**(code **)(*piVar3 + 0x7c))(piVar3,local_18);
      bVar2 = false;
    }
LAB_0001cfd2:
    (**(code **)(*param_1 + 0x364))(param_1,local_10,local_14,local_18);
    (**(code **)(*param_1 + 0x34c))(param_1,param_2,1);
    (**(code **)(*param_1 + 700))(param_1);
    if (local_30 != param_2) {
      (**(code **)(*param_1 + 0x34c))(param_1,local_30,1);
    }
    (**(code **)(*param_1 + 0x354))(param_1,1);
  }
  (**(code **)(*param_1 + 0x308))(param_1,param_1[0xee0]);
  return;
}

