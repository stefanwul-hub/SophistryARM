/* 00080022 Pan51_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Pan51_c_vslot_32(int param_1,undefined4 param_2,int param_3,char param_4)

{
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  VariatorTone_c_vslot_32(param_1,param_2,&local_2c,param_4);
  if ((*(int *)(param_1 + 0x124) != 0) && (param_4 == '\0')) {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    *(undefined4 *)(param_1 + 0x200) = 0;
  }
  return;
}

