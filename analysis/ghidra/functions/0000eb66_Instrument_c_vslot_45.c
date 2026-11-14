/* 0000eb66 Instrument_c_vslot_45 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_45(int *param_1,int param_2)

{
  char cVar1;
  undefined *local_44;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(param_2 + 0x10);
  if (*(char *)(local_20 + 0x1b4 + (int)param_1) != '\0') {
    local_40 = *(undefined1 *)(param_2 + 4);
    local_3c = *(undefined4 *)(param_2 + 8);
    local_38 = *(undefined4 *)(param_2 + 0xc);
    local_44 = PTR_DAT_00103814 + 8;
    local_34 = local_20;
    cVar1 = (**(code **)(*param_1 + 0xa4))(param_1,&local_44);
    local_44 = PTR_DAT_00103808 + 8;
    if (cVar1 != '\0') {
      return;
    }
    local_20 = *(int *)(param_2 + 0x10);
  }
  local_2c = *(undefined1 *)(param_2 + 4);
  local_28 = *(undefined4 *)(param_2 + 8);
  local_24 = *(undefined4 *)(param_2 + 0xc);
  local_30 = PTR_DAT_00103814 + 8;
  (**(code **)(*param_1 + 0x98))(param_1,&local_30);
  return;
}

