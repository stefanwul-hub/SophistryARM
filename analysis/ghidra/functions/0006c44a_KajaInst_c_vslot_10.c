/* 0006c44a KajaInst_c_vslot_10 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void KajaInst_c_vslot_10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                        undefined1 param_5)

{
  undefined *local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  Instrument_c_vslot_10(param_1,param_2,param_3,param_4,param_5);
  *(undefined4 *)(param_1 + 0x1d3c) = param_2;
  local_3c = PTR_DAT_00103808 + 8;
  local_38 = 0;
  local_34 = 0x3c;
  local_30 = 100;
  Envelope_c_vslot_32(CControlPl_vslot_75 + param_1,*(undefined4 *)(param_1 + 0x1a4),&local_3c,0);
  local_3c = PTR_DAT_00103808 + 8;
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = 0;
  local_24 = 0x3c;
  local_20 = 100;
  Envelope_c_vslot_32(param_1 + 0x2408,*(undefined4 *)(param_1 + 0x1a4),&local_2c,0);
  return;
}

