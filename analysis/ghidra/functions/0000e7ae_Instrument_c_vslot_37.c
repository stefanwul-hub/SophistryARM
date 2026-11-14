/* 0000e7ae Instrument_c_vslot_37 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 Instrument_c_vslot_37(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_88;
  undefined *local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined1 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined1 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined *local_44;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  *(undefined1 *)(param_1 + 0x150) = 1;
  local_68 = *(undefined1 *)(param_2 + 4);
  iVar2 = *(int *)(param_2 + 8);
  local_60 = *(undefined4 *)(param_2 + 0xc);
  local_5c = *(undefined4 *)(param_2 + 0x10);
  for (local_64 = iVar2 + *(int *)(param_1 + 0xec4); 0x78 < local_64; local_64 = local_64 + -0xc) {
  }
  if (local_64 < 0) {
    do {
      local_64 = local_64 + 0xc;
    } while (local_64 < 0);
    cVar1 = *(char *)(param_1 + 0x1c8);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x1c8);
  }
  if (cVar1 != '\0') {
    local_7c = *(undefined1 *)(param_3 + 4);
    local_78 = *(undefined4 *)(param_3 + 8);
    local_74 = *(undefined4 *)(param_3 + 0xc);
    local_80 = PTR_DAT_00103814 + 8;
    local_70 = *(undefined4 *)(param_3 + 0x10);
    local_6c = local_80;
    (**(code **)(**(int **)(param_1 + 4) + 0x390))
              (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 0x1a4),&local_6c,&local_80);
    *(uint *)(param_1 + 0xebc) = *(uint *)(param_1 + 0xebc) ^ 0x80000000;
    return 0xffffffff;
  }
  local_88 = local_60;
  if (*(char *)(param_1 + 0xed0) != '\0') {
    if (*(char *)(param_1 + 0x158) != '\0') {
      iVar5 = 0;
      iVar3 = param_1;
      do {
        if (-1 < *(int *)(iVar3 + 0xed4)) {
          local_88 = *(undefined4 *)(param_1 + 0x10e0 + iVar5 * 0x14);
          break;
        }
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar5 != 0x80);
      local_58 = PTR_DAT_00103808 + 8;
      local_54 = local_68;
      local_50 = iVar2;
      local_4c = local_60;
      local_48 = local_5c;
    }
    uVar4 = FUN_0002e1c0(param_1 + 8);
    *(undefined4 *)(param_1 + 0xed4 + iVar2 * 4) = uVar4;
    iVar2 = param_1 + 0x10d4 + *(int *)(param_2 + 8) * 0x14;
    *(undefined1 *)(iVar2 + 4) = local_68;
    *(int *)(iVar2 + 8) = local_64;
    *(undefined4 *)(iVar2 + 0xc) = local_88;
    *(undefined4 *)(iVar2 + 0x10) = local_5c;
  }
  local_40 = *(undefined1 *)(param_3 + 4);
  local_3c = *(undefined4 *)(param_3 + 8);
  local_38 = *(undefined4 *)(param_3 + 0xc);
  local_44 = PTR_DAT_00103814 + 8;
  local_34 = *(undefined4 *)(param_3 + 0x10);
  local_24 = local_88;
  local_30 = local_44;
  local_2c = local_68;
  local_28 = local_64;
  local_20 = local_5c;
  uVar4 = (**(code **)(**(int **)(param_1 + 4) + 0x388))
                    (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 0x1a4),&local_30,&local_44);
  *(uint *)(param_1 + 0xebc) = *(uint *)(param_1 + 0xebc) ^ 0x80000000;
  return uVar4;
}

