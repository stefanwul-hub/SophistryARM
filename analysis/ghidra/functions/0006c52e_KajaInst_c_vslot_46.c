/* 0006c52e KajaInst_c_vslot_46 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 KajaInst_c_vslot_46(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined *puVar4;
  int local_90;
  undefined *local_8c;
  undefined1 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined *local_78;
  undefined1 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined *local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined *local_50;
  undefined1 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined1 local_24 [7];
  undefined1 local_1d [13];
  
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0001ab48(*(int *)(param_1 + 4),local_24,&local_28);
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x3b28);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x25e0);
    }
    else {
      uVar2 = *(uint *)(iVar1 + 0x54);
      if ((uVar2 & 0x400) != 0) {
        Envelope_c_vslot_41(CControlPl_vslot_75 + param_1,(float)*(double *)(iVar1 + 0x20));
        uVar2 = *(uint *)(iVar1 + 0x54);
      }
      if (((uVar2 & 0x200) != 0) && ((uVar2 & 2) != 0)) {
        FUN_0006fca8(CControlPl_vslot_75 + param_1,*(int *)(param_1 + 0x1b60) + local_28);
      }
      iVar1 = *(int *)(param_1 + 0x25e0);
    }
    if (iVar1 == 1) {
      local_38 = *(undefined1 *)(param_2 + 4);
      local_34 = *(undefined4 *)(param_2 + 8);
      local_30 = *(undefined4 *)(param_2 + 0xc);
      local_3c = PTR_DAT_00103814 + 8;
      local_2c = *(undefined4 *)(param_2 + 0x10);
      ChordMem_c_vslot_56(param_1 + 0x2408,&local_3c);
      local_3c = PTR_DAT_00103808 + 8;
    }
    local_90 = param_1 + 0x2408;
    local_78 = PTR_DAT_00103814 + 8;
    local_70 = 0xffffffff;
    local_6c = 0xffffffff;
    local_68 = 0xffffffff;
    local_74 = 1;
    local_1d[0] = 1;
    while( true ) {
      local_88 = *(undefined1 *)(param_2 + 4);
      local_84 = *(undefined4 *)(param_2 + 8);
      local_80 = *(undefined4 *)(param_2 + 0xc);
      local_8c = PTR_DAT_00103814 + 8;
      local_7c = *(undefined4 *)(param_2 + 0x10);
      cVar3 = ChordMem_c_vslot_57(local_90,local_1d,&local_8c,&local_78);
      local_64 = PTR_DAT_00103814 + 8;
      puVar4 = PTR_DAT_00103808 + 8;
      if (cVar3 == '\0') break;
      local_60 = *(undefined1 *)(param_2 + 4);
      local_5c = *(undefined4 *)(param_2 + 8);
      local_58 = *(undefined4 *)(param_2 + 0xc);
      local_54 = *(undefined4 *)(param_2 + 0x10);
      local_4c = local_74;
      local_48 = local_70;
      local_44 = local_6c;
      local_40 = local_68;
      local_8c = puVar4;
      local_50 = local_64;
      FUN_00071468(CControlPl_vslot_75 + param_1,&local_50,&local_64);
      local_64 = puVar4;
      local_50 = puVar4;
    }
  }
  return 0xffffffff;
}

