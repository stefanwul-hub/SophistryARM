/* 0000eab8 Instrument_c_vslot_46 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_46(int *param_1,int param_2)

{
  undefined *local_44;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  (**(code **)(*param_1 + 0x34))(param_1);
  local_40 = *(undefined1 *)(param_2 + 4);
  local_3c = *(undefined4 *)(param_2 + 8);
  local_38 = *(undefined4 *)(param_2 + 0xc);
  local_44 = PTR_DAT_00103814 + 8;
  local_34 = *(undefined4 *)(param_2 + 0x10);
  local_30 = PTR_DAT_00103814 + 8;
  local_2c = local_40;
  local_28 = local_3c;
  local_24 = local_38;
  local_20 = local_34;
  (**(code **)(*param_1 + 0x94))(param_1,&local_30,&local_44);
  return;
}

