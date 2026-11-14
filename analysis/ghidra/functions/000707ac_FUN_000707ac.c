/* 000707ac FUN_000707ac */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000707ac(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int local_44;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_30 = PTR_DAT_00103814 + 8;
  local_28 = 0xffffffff;
  local_24 = 0xffffffff;
  local_20 = 0xffffffff;
  local_2c = 1;
  iVar6 = *(int *)(param_1 + 0x758);
  do {
    bVar5 = false;
    iVar7 = 0;
    local_44 = param_1;
    while (iVar7 < iVar6 + -1) {
      if (*(char *)(local_44 + 0x334) < *(char *)(local_44 + 0x318)) {
        iVar6 = iVar7 * 0x1c + 0x310 + param_1;
        uVar2 = *(undefined1 *)(iVar6 + 8);
        uVar3 = *(undefined1 *)(iVar6 + 9);
        uVar4 = *(undefined4 *)(iVar6 + 0xc);
        local_2c = *(undefined1 *)(iVar6 + 0x14);
        local_28 = *(undefined4 *)(iVar6 + 0x18);
        local_24 = *(undefined4 *)(iVar6 + 0x1c);
        local_20 = *(undefined4 *)(iVar6 + 0x20);
        iVar1 = (iVar7 + 1) * 0x1c + 0x310 + param_1;
        *(undefined1 *)(iVar6 + 8) = *(undefined1 *)(iVar1 + 8);
        *(undefined1 *)(iVar6 + 9) = *(undefined1 *)(iVar1 + 9);
        *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
        *(undefined1 *)(iVar6 + 0x14) = *(undefined1 *)(iVar1 + 0x14);
        *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
        *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
        *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
        *(undefined1 *)(iVar1 + 8) = uVar2;
        *(undefined1 *)(iVar1 + 9) = uVar3;
        *(undefined4 *)(iVar1 + 0xc) = uVar4;
        *(undefined1 *)(iVar1 + 0x14) = local_2c;
        *(undefined4 *)(iVar1 + 0x18) = local_28;
        *(undefined4 *)(iVar1 + 0x1c) = local_24;
        *(undefined4 *)(iVar1 + 0x20) = local_20;
        bVar5 = true;
        iVar6 = *(int *)(param_1 + 0x758);
      }
      local_44 = local_44 + 0x1c;
      iVar7 = iVar7 + 1;
    }
  } while (bVar5);
  NoteC_c_vslot_0(&local_30);
  return;
}

