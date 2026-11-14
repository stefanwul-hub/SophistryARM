/* 00071b70 FUN_00071b70 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00071b70(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined *local_58;
  undefined1 local_54;
  undefined4 local_50;
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
  
  piVar2 = *(int **)(param_1 + 0x1d4);
  if (piVar2 != (int *)0x0) {
    if (*(int *)(param_1 + 0x314) == 0) {
      local_54 = *(undefined1 *)(param_2 + 4);
      local_50 = *(undefined4 *)(param_2 + 8);
      local_4c = *(undefined4 *)(param_2 + 0xc);
      local_58 = PTR_DAT_00103814 + 8;
      local_48 = *(undefined4 *)(param_2 + 0x10);
      (**(code **)(*piVar2 + 0x98))(piVar2,&local_58);
      NoteC_c_vslot_0(&local_58);
      return;
    }
    if (*(int *)(param_1 + 0x314) == 1) {
      local_40 = *(undefined1 *)(param_2 + 4);
      local_3c = *(undefined4 *)(param_2 + 8);
      local_38 = *(undefined4 *)(param_2 + 0xc);
      local_44 = PTR_DAT_00103814 + 8;
      local_34 = *(undefined4 *)(param_2 + 0x10);
      (**(code **)(*piVar2 + 0x98))(piVar2,&local_44);
      NoteC_c_vslot_0(&local_44);
    }
    local_2c = *(undefined1 *)(param_2 + 4);
    local_28 = *(int *)(param_2 + 8);
    local_24 = *(undefined4 *)(param_2 + 0xc);
    local_30 = PTR_DAT_00103814 + 8;
    local_20 = *(undefined4 *)(param_2 + 0x10);
    iVar3 = 0;
    iVar4 = param_1;
    do {
      if (*(char *)(iVar4 + 0x318) == local_28) {
        *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + -1;
        if (iVar3 < 0x1f) {
          do {
            iVar4 = iVar3 + 1;
            iVar3 = iVar3 * 0x1c + 0x310 + param_1;
            iVar1 = iVar4 * 0x1c + 0x310 + param_1;
            *(undefined1 *)(iVar3 + 8) = *(undefined1 *)(iVar1 + 8);
            *(undefined1 *)(iVar3 + 9) = *(undefined1 *)(iVar1 + 9);
            *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
            *(undefined1 *)(iVar3 + 0x14) = *(undefined1 *)(iVar1 + 0x14);
            *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
            *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
            *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
            iVar3 = iVar4;
          } while (iVar4 != 0x1f);
          *(undefined1 *)(param_1 + 0x67c) = 0xff;
          *(undefined1 *)(param_1 + 0x67d) = 0xff;
          *(undefined4 *)(param_1 + 0x680) = 0xffffffff;
          NoteC_c_vslot_0(&local_30);
          return;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar3 != 0x20);
    *(undefined1 *)(param_1 + 0x67c) = 0xff;
    *(undefined1 *)(param_1 + 0x67d) = 0xff;
    *(undefined4 *)(param_1 + 0x680) = 0xffffffff;
    NoteC_c_vslot_0(&local_30);
  }
  return;
}

