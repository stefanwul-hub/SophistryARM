/* 0000d032 Instrument_c_vslot_42 */

void Instrument_c_vslot_42(int *param_1,int param_2)

{
  int iVar1;
  
  FUN_00024cf6(param_1[1],param_1[0x69]);
  if (param_2 < 0x10) {
    if (*(char *)(param_2 + 0x1b4 + (int)param_1) != '\0') {
      (**(code **)(*param_1 + 0xa0))(param_1,param_2);
    }
    *(undefined1 *)(param_2 + 0x1b4 + (int)param_1) = 0;
    return;
  }
  iVar1 = 0;
  do {
    (**(code **)(*param_1 + 0xa8))(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x10);
  return;
}

