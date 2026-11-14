/* 0009f490 CFrame_vslot_85 */

void CFrame_vslot_85(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  piVar2 = *(int **)(param_1 + 0x3c);
  if (piVar2 != (int *)0x0) {
    do {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x78))(piVar1,&local_1c);
        if ((((local_1c <= param_2[2]) && (*param_2 <= local_14)) && (local_18 <= param_2[3])) &&
           (param_2[1] <= local_10)) {
          (**(code **)(*piVar1 + 0x54))(piVar1,1);
        }
      }
      piVar2 = (int *)piVar2[1];
    } while (piVar2 != (int *)0x0);
  }
  return;
}

