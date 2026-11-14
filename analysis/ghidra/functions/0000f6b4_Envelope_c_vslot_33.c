/* 0000f6b4 Envelope_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_33(int param_1,undefined4 param_2,int param_3,undefined1 param_4,char param_5)

{
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  Modulator_c_vslot_33(param_1,param_2,&local_2c,param_4,param_5);
  if (param_5 == '\0') {
    *(undefined4 *)(param_1 + 0x37c) = 0;
    *(undefined4 *)(param_1 + 0x380) = 0;
  }
  return;
}

