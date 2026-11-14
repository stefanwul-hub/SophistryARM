/* 000a4654 CFrame_vslot_5 */

void CFrame_vslot_5(int param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (*(char *)(param_1 + 0x88) == '\0') {
    cVar1 = *(char *)(param_1 + 0x70);
  }
  else {
    if (*(char *)(param_1 + 0x70) == '\0') {
      return;
    }
    cVar1 = *(char *)(param_1 + 0x70);
  }
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x70) = 0;
  }
  if (param_2 == (int *)0x0) {
    piVar2 = *(int **)(param_1 + 0x94);
    if (piVar2 == (int *)0x0) {
      uVar3 = *(undefined4 *)(param_1 + 100);
      param_2 = (int *)operator_new(0x68);
      FUN_000a171a(param_2,param_1,0,uVar3);
      bVar4 = true;
    }
    else {
      (**(code **)(*piVar2 + 0xc))(piVar2);
      param_2 = *(int **)(param_1 + 0x94);
      bVar4 = true;
    }
  }
  else {
    bVar4 = false;
  }
  local_1c = -param_2[4] + param_2[0x14];
  local_14 = -param_2[4] + param_2[0x16];
  local_18 = -param_2[5] + param_2[0x15];
  local_10 = -param_2[5] + param_2[0x17];
  local_2c = *param_3;
  if (*param_3 < local_1c) {
    local_2c = local_1c;
  }
  local_28 = local_18;
  if (local_18 <= param_3[1]) {
    local_28 = param_3[1];
  }
  iVar5 = local_14;
  if (param_3[2] <= local_14) {
    iVar5 = param_3[2];
  }
  iVar6 = param_3[3];
  if (local_10 < param_3[3]) {
    iVar6 = local_10;
  }
  local_20 = local_28;
  if (local_28 <= iVar6) {
    local_20 = iVar6;
  }
  local_24 = local_2c;
  if (local_2c <= iVar5) {
    local_24 = iVar5;
  }
  FUN_000a08c2(param_2,&local_2c);
  if ((param_3[2] != *param_3 && -1 < param_3[2] - *param_3) &&
     (param_3[3] != param_3[1] && -1 < param_3[3] - param_3[1])) {
    CViewContainer_vslot_5(param_1,param_2,param_3);
  }
  FUN_000a08c2(param_2,&local_1c);
  if (bVar4) {
    (**(code **)(*param_2 + 8))(param_2);
    return;
  }
  return;
}

