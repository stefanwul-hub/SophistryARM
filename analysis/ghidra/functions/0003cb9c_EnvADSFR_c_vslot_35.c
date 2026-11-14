/* 0003cb9c EnvADSFR_c_vslot_35 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvADSFR_c_vslot_35(int param_1,undefined4 param_2,int param_3)

{
  undefined *local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_1c = PTR_DAT_00103808 + 8;
  local_18 = *(undefined1 *)(param_3 + 4);
  local_14 = *(undefined4 *)(param_3 + 8);
  local_10 = *(undefined4 *)(param_3 + 0xc);
  Envelope_c_vslot_35(param_1,param_2,&local_1c);
  local_1c = PTR_DAT_00103808 + 8;
  if (*(char *)(param_1 + 0x1e0) != '\0') {
    **(undefined4 **)(param_1 + 0x1dc) = 0x7ffffbff;
    return;
  }
  *(bool *)(param_1 + 900) = *(int *)(param_1 + 0x1f0) < 2;
  FUN_0003c484(param_1,3);
  return;
}

