/* 00006a9c CMenuWithSub_vslot_12 */

undefined4 CMenuWithSub_vslot_12(int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_30;
  
  if (param_4 <= 0.0) {
    iVar2 = param_1[0x36b];
  }
  else {
    iVar2 = param_1[0x36b] + 1;
    param_1[0x36b] = iVar2;
  }
  if (param_4 < 0.0) {
    iVar2 = iVar2 + -1;
    param_1[0x36b] = iVar2;
  }
  if (iVar2 < param_1[0x3d]) {
    param_1[0x36b] = param_1[0x3d];
    (**(code **)(*param_1 + 0xe0))(param_1);
    if (param_1[100] == 0) goto LAB_00006c07;
LAB_00006b14:
    iVar2 = 0x1f;
LAB_00006b19:
    iVar3 = param_1[iVar2 + 0x45];
  }
  else {
    if (param_1[0x3e] < iVar2) {
      iVar2 = param_1[0x3e];
    }
    param_1[0x36b] = iVar2;
    (**(code **)(*param_1 + 0xe0))(param_1);
    if (param_1[100] != 0) goto LAB_00006b14;
LAB_00006c07:
    iVar2 = 0x1f;
    piVar4 = param_1;
    do {
      iVar2 = iVar2 + -1;
      if (piVar4[99] != 0) goto LAB_00006b19;
      piVar4 = piVar4 + -1;
    } while (iVar2 != 0);
    iVar3 = param_1[0x45];
    if (iVar3 == 0) {
      (*(code *)**(undefined4 **)param_1[0xf])((undefined4 *)param_1[0xf],param_2,param_1);
      goto LAB_00006bb8;
    }
  }
  iVar1 = param_1[0x36b];
  iVar5 = iVar2;
  if ((iVar1 < *(int *)(iVar3 + 0xe4)) && (0 < iVar2)) {
    piVar4 = param_1 + iVar2 + 0x45;
    local_30 = 0;
    do {
      iVar5 = iVar5 + -1;
      if (*(int *)(piVar4[-1] + 0xe4) <= iVar1) break;
      local_30 = local_30 + 1;
      piVar4 = piVar4 + -1;
    } while (iVar2 != local_30);
  }
  piVar4 = (int *)param_1[iVar5 + 0x45];
  (**(code **)(*piVar4 + 0x13c))(piVar4,iVar1 - piVar4[0x39],1);
  (*(code *)**(undefined4 **)param_1[0xf])((undefined4 *)param_1[0xf],param_2,param_1[iVar5 + 0x45])
  ;
LAB_00006bb8:
  (**(code **)(*param_1 + 0xac))(param_1);
  (**(code **)(*param_1 + 0xe4))(param_1);
  return 1;
}

