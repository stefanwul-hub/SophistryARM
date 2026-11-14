/* 000050da LPAUView_vslot_10 */

undefined4 LPAUView_vslot_10(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10 [2];
  
  iVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + 0xec) + 0x31c))
                    (*(int *)(param_1 + 0x54) + 0xec);
  piVar1 = *(int **)(param_1 + 0x54);
  local_10[0] = iVar3 * piVar1[0xf0a] + param_2;
  cVar2 = (**(code **)(*piVar1 + 0x134))(piVar1,local_10);
  if (cVar2 != '\0') {
    local_18 = 0;
    local_14 = 0;
    local_20 = *(undefined4 *)(param_1 + 0x10);
    local_1c = local_10[0];
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))
                (*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 4),&local_20,1,0);
    }
    return 1;
  }
  return 0;
}

