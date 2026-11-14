/* 0000eea0 Instrument_c_vslot_38 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_38(int param_1,int param_2)

{
  char cVar1;
  undefined *local_44;
  undefined1 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_40 = *(undefined1 *)(param_2 + 4);
  local_38 = *(undefined4 *)(param_2 + 0xc);
  local_34 = *(undefined4 *)(param_2 + 0x10);
  for (local_3c = *(int *)(param_2 + 8) + *(int *)(param_1 + 0xec4); 0x78 < local_3c;
      local_3c = local_3c + -0xc) {
  }
  if (local_3c < 0) {
    do {
      local_3c = local_3c + 0xc;
    } while (local_3c < 0);
    cVar1 = *(char *)(param_1 + 0xed0);
  }
  else {
    cVar1 = *(char *)(param_1 + 0xed0);
  }
  if (cVar1 != '\0') {
    local_44 = PTR_DAT_00103814 + 8;
    FUN_0000ec54(param_1,&local_44);
    return;
  }
  local_30 = PTR_DAT_00103814 + 8;
  local_2c = local_40;
  local_28 = local_3c;
  local_24 = local_38;
  local_20 = local_34;
  (**(code **)(**(int **)(param_1 + 4) + 0x38c))
            (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 0x1a4),&local_30);
  return;
}

