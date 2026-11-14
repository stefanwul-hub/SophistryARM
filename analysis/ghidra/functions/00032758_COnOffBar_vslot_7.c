/* 00032758 COnOffBar_vslot_7 */

void COnOffBar_vslot_7(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00001bd4(param_1);
  *(undefined1 *)(param_1 + 0x6c) = 0;
  *(undefined1 *)(param_1 + 0x6d) = 0;
  FUN_00001ca6(param_1,*(undefined4 *)(param_1 + 0x40));
  iVar1 = (*param_3 - *(int *)(param_1 + 8)) / *(int *)(param_1 + 0xb8);
  iVar2 = *(int *)(param_1 + 0xb4) + -1;
  if (iVar1 < 0) {
    iVar2 = 0;
  }
  else if (iVar1 <= iVar2) {
    iVar2 = iVar1;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x84) + *(int *)(param_1 + 0xb4)) = 0;
  _strcpy(*(char **)(param_1 + 0xbc),*(char **)(param_1 + 0x84));
  *(char *)(iVar2 + *(int *)(param_1 + 0xbc)) =
       (*(char *)(iVar2 + *(int *)(param_1 + 0x84)) == '0') + '0';
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0xbc);
  (**(code **)**(undefined4 **)(param_1 + 0x94))(*(undefined4 **)(param_1 + 0x94),param_2,param_1);
  FUN_00001c10();
  return;
}

