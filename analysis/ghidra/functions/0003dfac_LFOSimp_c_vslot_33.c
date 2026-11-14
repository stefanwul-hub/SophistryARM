/* 0003dfac LFOSimp_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LFOSimp_c_vslot_33(int param_1,undefined4 param_2,int param_3,char param_4,undefined1 param_5)

{
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  FUN_0003de56(param_1,param_2,&local_2c,param_4,param_5);
  if (param_4 == '\0') {
    **(undefined4 **)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x794);
    **(undefined4 **)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x798);
    **(undefined4 **)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x79c);
  }
  return;
}

