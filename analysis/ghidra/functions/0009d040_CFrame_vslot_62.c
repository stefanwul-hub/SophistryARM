/* 0009d040 CFrame_vslot_62 */

undefined4 CFrame_vslot_62(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  if ((char)param_1[0x26] != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
    if ((cVar1 != '\0') && (param_1[0x19] != 0)) {
      piVar2 = (int *)(**(code **)(*(int *)param_1[0x18] + 8))((int *)param_1[0x18]);
      (**(code **)(*piVar2 + 0x244))(piVar2,param_1[0x27]);
      param_1[0x19] = 0;
      return 1;
    }
  }
  return 0;
}

