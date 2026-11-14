/* 0006ff0a FUN_0006ff0a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x000700fb) */
/* WARNING: Removing unreachable block (ram,0x0006ffce) */
/* WARNING: Removing unreachable block (ram,0x000700f4) */
/* WARNING: Removing unreachable block (ram,0x0006ffe7) */

void FUN_0006ff0a(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int local_50;
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
  
  if (*(int *)(param_1 + 0x1d4) != 0) {
    if (0 < *(int *)(param_1 + 0x78c)) {
      local_50 = param_1;
      iVar2 = 0;
      do {
        for (iVar1 = *(int *)(local_50 + 0x698) + *(int *)(param_1 + 0x310) * 0xc; 0x7f < iVar1;
            iVar1 = iVar1 + -0xc) {
        }
        for (; (local_3c = iVar1, iVar1 < 0 && (local_3c = iVar1 + 0xc, local_3c < 0));
            iVar1 = iVar1 + 0x18) {
        }
        local_40 = 0;
        local_44 = PTR_DAT_00103814 + 8;
        if (local_3c < 0) {
          local_3c = 0;
        }
        else if (0x7f < local_3c) {
          local_3c = 0x7f;
        }
        local_38 = 0;
        local_34 = 0;
        local_2c = 0;
        local_30 = PTR_DAT_00103814 + 8;
        local_28 = local_3c;
        local_24 = local_38;
        local_20 = local_34;
        (**(code **)(**(int **)(param_1 + 0x1d4) + 0x98))(*(int **)(param_1 + 0x1d4),&local_30);
        NoteC_c_vslot_0(&local_30);
        NoteC_c_vslot_0(&local_44);
        iVar2 = iVar2 + 1;
        local_50 = local_50 + 4;
      } while (iVar2 < *(int *)(param_1 + 0x78c));
    }
    *(undefined4 *)(param_1 + 0x78c) = 0;
  }
  iVar1 = 0;
  iVar2 = param_1;
  do {
    *(undefined1 *)(iVar2 + 0x318) = 0xff;
    *(undefined1 *)(iVar2 + 0x319) = 0xff;
    *(undefined4 *)(iVar2 + 0x31c) = 0xffffffff;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x1c;
  } while (iVar1 != 0x20);
  iVar1 = 0x30;
  iVar2 = param_1;
  do {
    *(undefined4 *)(iVar2 + 0x698) = 0xffffffff;
    iVar2 = iVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0x758) = 0;
  if (param_2 != '\0') {
    *(undefined4 *)(param_1 + 0x794) = 0;
  }
  *(undefined1 *)(param_1 + 0x75c) = 0xff;
  *(undefined4 *)(param_1 + 0x778) = 0xffffffff;
  return;
}

