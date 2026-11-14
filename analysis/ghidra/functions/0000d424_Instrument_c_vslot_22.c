/* 0000d424 Instrument_c_vslot_22 */

void Instrument_c_vslot_22(int *param_1,int param_2,char param_3)

{
  if ((*(char *)(param_2 + 0x1b4 + (int)param_1) != '\0') && (param_3 == '\0')) {
    (**(code **)(*param_1 + 0xa0))(param_1,param_2);
    *(undefined1 *)(param_2 + 0x1b4 + (int)param_1) = 0;
    return;
  }
  *(char *)(param_2 + 0x1b4 + (int)param_1) = param_3;
  return;
}

