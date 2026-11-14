/* 0009de6e CView_vslot_4 */

void CView_vslot_4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  piVar1 = (int *)param_1[0xd];
  if (piVar1 != (int *)0x0) {
    if (*(char *)((int)param_1 + 0x32) == '\0') {
      pcVar3 = *(code **)(*piVar1 + 0x10);
      local_14 = 0;
      local_10 = 0;
      puVar2 = &local_14;
    }
    else {
      pcVar3 = *(code **)(*piVar1 + 0x14);
      local_1c = 0;
      local_18 = 0;
      puVar2 = &local_1c;
    }
    (*pcVar3)(piVar1,param_2,param_1 + 2,puVar2);
  }
  (**(code **)(*param_1 + 0x54))(param_1,0);
  return;
}

