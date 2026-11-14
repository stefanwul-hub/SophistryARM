/* 00031984 GloFil_c_vslot_3 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void GloFil_c_vslot_3(int param_1)

{
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  Envelope_c_vslot_17(param_1 + 0x1e0,0,2,"Triang");
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = 0;
  local_24 = 0x3c;
  local_20 = 100;
  LFOSimp_c_vslot_33(param_1 + 0x1e0,*(undefined4 *)(param_1 + 0x128),&local_2c,0,0);
  *(undefined8 *)(param_1 + 0x9a0) = 0;
  *(undefined8 *)(param_1 + 0x9a8) = 0;
  *(undefined8 *)(param_1 + 0x9c8) = 0;
  *(undefined8 *)(param_1 + 0x9c0) = 0;
  *(undefined8 *)(param_1 + 0x9b8) = 0;
  *(undefined8 *)(param_1 + 0x9b0) = 0;
  *(undefined8 *)(param_1 + 0x9e8) = 0;
  *(undefined8 *)(param_1 + 0x9e0) = 0;
  *(undefined8 *)(param_1 + 0x9d8) = 0;
  *(undefined8 *)(param_1 + 0x9d0) = 0;
  return;
}

