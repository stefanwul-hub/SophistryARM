/* 000513b2 Kaja_c_vslot_235 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x00051429) */
/* WARNING: Removing unreachable block (ram,0x0005148f) */

void Kaja_c_vslot_235(int *param_1,undefined4 param_2,int param_3)

{
  int local_3c;
  int local_38;
  undefined *local_30;
  undefined1 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  local_38 = *(int *)(param_3 + 0xc);
  local_28 = *(int *)(param_3 + 8);
  if (local_28 < 0) {
    local_3c = 0;
    local_28 = local_3c;
  }
  else if (0x7f < local_28) {
    local_28 = 0x7f;
  }
  if (local_38 < 0) {
    local_38 = 0;
  }
  else if (0x7f < local_38) {
    local_38 = 0x7f;
  }
  local_20 = 0;
  local_2c = 0;
  local_24 = local_38;
  local_30 = PTR_DAT_00103814 + 8;
  (**(code **)(*param_1 + 0x288))(param_1,0,&local_30,1);
  return;
}

