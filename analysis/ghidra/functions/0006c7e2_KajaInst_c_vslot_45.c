/* 0006c7e2 KajaInst_c_vslot_45 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void KajaInst_c_vslot_45(int *param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *local_70;
  undefined1 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined *local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined *local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined *local_34;
  undefined1 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d [13];
  
  puVar2 = PTR_DAT_00103808 + 8;
  local_70 = PTR_DAT_00103814 + 8;
  local_68 = 0xffffffff;
  local_64 = 0xffffffff;
  local_60 = 0xffffffff;
  local_6c = 1;
  local_1d[0] = 1;
  local_38 = *(int *)(param_2 + 0x10);
  if (*(char *)(local_38 + 0x1b4 + (int)param_1) != '\0') {
    local_58 = *(undefined1 *)(param_2 + 4);
    local_54 = *(undefined4 *)(param_2 + 8);
    local_50 = *(undefined4 *)(param_2 + 0xc);
    local_5c = local_70;
    local_4c = local_38;
    cVar1 = (**(code **)(*param_1 + 0xa4))(param_1,&local_5c);
    if (cVar1 != '\0') {
      return;
    }
    local_38 = *(int *)(param_2 + 0x10);
    local_5c = puVar2;
  }
  while( true ) {
    local_44 = *(undefined1 *)(param_2 + 4);
    local_40 = *(undefined4 *)(param_2 + 8);
    local_3c = *(undefined4 *)(param_2 + 0xc);
    local_48 = PTR_DAT_00103814 + 8;
    cVar1 = ChordMem_c_vslot_58(param_1 + 0x902,local_1d,&local_48,&local_70);
    local_34 = PTR_DAT_00103814 + 8;
    puVar2 = PTR_DAT_00103808 + 8;
    if (cVar1 == '\0') break;
    local_30 = local_6c;
    local_2c = local_68;
    local_28 = local_64;
    local_24 = local_60;
    local_48 = puVar2;
    FUN_00071b70(param_1 + 0x6d9,&local_34);
    local_38 = *(int *)(param_2 + 0x10);
    local_34 = puVar2;
  }
  return;
}

