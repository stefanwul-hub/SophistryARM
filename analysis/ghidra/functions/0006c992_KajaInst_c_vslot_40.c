/* 0006c992 KajaInst_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void KajaInst_c_vslot_40(int param_1)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  int local_84;
  int local_80;
  undefined *local_70;
  undefined1 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined *local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined1 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d [13];
  
  if (*(int *)(param_1 + 0x1ac) != 0) {
    local_70 = PTR_DAT_00103814 + 8;
    local_68 = 0xffffffff;
    local_64 = 0xffffffff;
    local_60 = 0xffffffff;
    local_6c = 1;
    if (0 < *(int *)(param_1 + 0x1a8)) {
      local_84 = 0;
      local_80 = 0;
      local_5c = local_70;
      do {
        iVar3 = local_80 + *(int *)(param_1 + 0x1ac);
        local_58 = *(undefined1 *)(iVar3 + 4);
        local_54 = *(undefined4 *)(iVar3 + 8);
        local_50 = *(undefined4 *)(iVar3 + 0xc);
        local_4c = *(undefined4 *)(iVar3 + 0x10);
        local_1d[0] = 1;
        puVar4 = PTR_DAT_00103814;
        while( true ) {
          local_44 = local_58;
          local_40 = local_54;
          local_3c = local_50;
          local_48 = puVar4 + 8;
          local_38 = local_4c;
          cVar2 = ChordMem_c_vslot_58(param_1 + 0x2408,local_1d,&local_48,&local_70);
          puVar4 = PTR_DAT_00103814;
          puVar1 = PTR_DAT_00103808 + 8;
          if (cVar2 == '\0') break;
          local_30 = local_6c;
          local_2c = local_68;
          local_28 = local_64;
          local_24 = local_60;
          local_48 = puVar1;
          local_34 = PTR_DAT_00103814 + 8;
          FUN_00071b70(CControlPl_vslot_75 + param_1,&local_34);
          local_34 = puVar1;
        }
        local_84 = local_84 + 1;
        local_80 = local_80 + 0x14;
      } while (local_84 < *(int *)(param_1 + 0x1a8));
    }
    *(undefined4 *)(param_1 + 0x1a8) = 0;
  }
  return;
}

