/* 000141b4 Modulator_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Modulator_c_vslot_33(int *param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  undefined *local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_1c = PTR_DAT_00103808 + 8;
  local_18 = *(undefined1 *)(param_3 + 4);
  local_14 = *(undefined4 *)(param_3 + 8);
  local_10 = *(undefined4 *)(param_3 + 0xc);
  (**(code **)(*param_1 + 0x80))(param_1,param_2,&local_1c,param_4);
  return;
}

