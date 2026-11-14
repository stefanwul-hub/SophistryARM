/* 00071468 FUN_00071468 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00071468(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  float fVar8;
  undefined *local_1fc;
  undefined1 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined *local_bc;
  undefined1 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined *local_a8;
  undefined1 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined *local_94;
  undefined1 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined *local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined1 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
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
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  piVar3 = *(int **)(param_1 + 0x1d4);
  if (piVar3 != (int *)0x0) {
    if (*(int *)(param_1 + 0x314) == 0) {
      local_b8 = *(undefined1 *)(param_3 + 4);
      local_b4 = *(undefined4 *)(param_3 + 8);
      local_b0 = *(undefined4 *)(param_3 + 0xc);
      local_bc = PTR_DAT_00103814 + 8;
      local_ac = *(undefined4 *)(param_3 + 0x10);
      local_a4 = *(undefined1 *)(param_2 + 4);
      local_a0 = *(undefined4 *)(param_2 + 8);
      local_9c = *(undefined4 *)(param_2 + 0xc);
      local_a8 = PTR_DAT_00103814 + 8;
      local_98 = *(undefined4 *)(param_2 + 0x10);
      (**(code **)(*piVar3 + 0x94))(piVar3,&local_a8,&local_bc);
      NoteC_c_vslot_0(&local_a8);
      NoteC_c_vslot_0(&local_bc);
      return;
    }
    if (*(int *)(param_1 + 0x314) == 1) {
      local_90 = *(undefined1 *)(param_3 + 4);
      local_8c = *(undefined4 *)(param_3 + 8);
      local_88 = *(undefined4 *)(param_3 + 0xc);
      local_94 = PTR_DAT_00103814 + 8;
      local_84 = *(undefined4 *)(param_3 + 0x10);
      local_7c = *(undefined1 *)(param_2 + 4);
      local_78 = *(undefined4 *)(param_2 + 8);
      local_74 = *(undefined4 *)(param_2 + 0xc);
      local_80 = PTR_DAT_00103814 + 8;
      local_70 = *(undefined4 *)(param_2 + 0x10);
      (**(code **)(*piVar3 + 0x94))(piVar3,&local_80,&local_94);
      NoteC_c_vslot_0(&local_80);
      NoteC_c_vslot_0(&local_94);
    }
    puVar6 = PTR_DAT_00103814;
    local_68 = *(undefined1 *)(param_3 + 4);
    local_64 = *(undefined4 *)(param_3 + 8);
    local_60 = *(undefined4 *)(param_3 + 0xc);
    local_6c = PTR_DAT_00103814 + 8;
    local_5c = *(undefined4 *)(param_3 + 0x10);
    local_54 = *(undefined1 *)(param_2 + 4);
    local_50 = *(undefined4 *)(param_2 + 8);
    local_4c = *(undefined4 *)(param_2 + 0xc);
    local_58 = PTR_DAT_00103814 + 8;
    local_48 = *(undefined4 *)(param_2 + 0x10);
    if (*(int *)(param_1 + 0x758) < 0x20) {
      *(char *)(*(int *)(param_1 + 0x758) * 0x1c + 0x318 + param_1) = (char)local_50;
      *(char *)(*(int *)(param_1 + 0x758) * 0x1c + 0x319 + param_1) = (char)local_4c;
      iVar5 = *(int *)(param_1 + 0x758) * 0x1c + 800 + param_1;
      *(undefined1 *)(iVar5 + 4) = local_68;
      *(undefined4 *)(iVar5 + 8) = local_64;
      *(undefined4 *)(iVar5 + 0xc) = local_60;
      *(undefined4 *)(iVar5 + 0x10) = local_5c;
      *(undefined4 *)(*(int *)(param_1 + 0x758) * 0x1c + 0x31c + param_1) =
           *(undefined4 *)(param_1 + 0x780);
      *(int *)(param_1 + 0x780) = *(int *)(param_1 + 0x780) + 1;
      iVar5 = *(int *)(param_1 + 0x758);
      *(int *)(param_1 + 0x758) = iVar5 + 1;
      if ((((*(int *)(param_1 + 0x314) == 9) && (1 < iVar5 + 1)) && (0 < *(int *)(param_1 + 0x778)))
         && (*(int *)(param_1 + 0x778) < *(int *)(param_1 + 0x1e4))) {
        bVar2 = *(byte *)(*(int *)(param_1 + 0x794) + 0x28c + param_1);
        if (((bVar2 != 0) && (-1 < (char)bVar2)) && (*(int *)(param_1 + 0x1d4) != 0)) {
          fVar8 = *(float *)(*(int *)(param_1 + 0x124) + 0x31c) * 0.01;
          local_1fc = puVar6 + 8;
          local_1f4 = 0xffffffff;
          local_1f0 = 0xffffffff;
          local_1ec = 0xffffffff;
          local_1f8 = 1;
          iVar1 = iVar5 * 0x1c + 0x310 + param_1;
          for (iVar7 = (int)*(char *)(iVar1 + 8) + *(int *)(param_1 + 0x310) * 0xc; 0x7f < iVar7;
              iVar7 = iVar7 + -0xc) {
          }
          for (; iVar7 < 0; iVar7 = iVar7 + 0xc) {
          }
          NoteC_c_vslot_3(&local_1fc,iVar7,
                          (int)((float)bVar2 * (1.0 - fVar8) +
                               fVar8 * (float)(int)*(char *)(iVar1 + 9)),0);
          iVar7 = iVar5 * 0x1c + 800 + param_1;
          local_40 = *(undefined1 *)(iVar7 + 4);
          local_3c = *(undefined4 *)(iVar7 + 8);
          local_38 = *(undefined4 *)(iVar7 + 0xc);
          local_44 = PTR_DAT_00103814 + 8;
          local_34 = *(undefined4 *)(iVar7 + 0x10);
          local_2c = local_1f8;
          local_28 = local_1f4;
          local_24 = local_1f0;
          local_30 = PTR_DAT_00103814 + 8;
          local_20 = local_1ec;
          (**(code **)(**(int **)(param_1 + 0x1d4) + 0x94))
                    (*(int **)(param_1 + 0x1d4),&local_30,&local_44);
          NoteC_c_vslot_0(&local_30);
          NoteC_c_vslot_0(&local_44);
          iVar7 = *(int *)(param_1 + 0x78c);
          *(int *)(param_1 + 0x698 + iVar7 * 4) = (int)*(char *)(iVar5 * 0x1c + 0x318 + param_1);
          *(int *)(param_1 + 0x78c) = iVar7 + 1;
          NoteC_c_vslot_0(&local_1fc);
        }
      }
      FUN_000707ac(param_1);
      iVar5 = *(int *)(param_1 + 0x758);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x758);
    }
    if ((iVar5 == 1) && (*(char *)(param_1 + 0x75c) == -1)) {
      *(undefined1 *)(param_1 + 0x8a0) = 1;
      *(undefined4 *)(param_1 + 0x778) = 0;
      *(undefined4 *)(param_1 + 0x788) = 0;
      if (*(char *)(param_1 + 0x89b) != '\0') {
        *(undefined4 *)(param_1 + 0x794) = 0;
      }
      *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x318);
      *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x319);
      *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x31c);
      *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(param_1 + 0x324);
      *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(param_1 + 0x328);
      *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(param_1 + 0x32c);
      *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(param_1 + 0x330);
      uVar4 = *(undefined4 *)(param_1 + 0x794);
      FUN_00010aee(*(int *)(param_1 + 0x124) + 0x460,&local_1fc);
      local_1fc = (undefined *)CONCAT31(local_1fc._1_3_,(char)uVar4 + '\x01');
      FUN_00010e34(*(int *)(param_1 + 0x124) + 0x460,&local_1fc);
      piVar3 = *(int **)(param_1 + 0x1d8);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x358))(piVar3);
      }
      *(undefined4 *)(param_1 + 0x790) = 0;
      iVar5 = *(int *)(param_1 + 0x314);
      if (iVar5 - 6U < 2) {
        *(undefined4 *)(param_1 + 0x790) = 1;
      }
      *(undefined4 *)(param_1 + 0x310) = 0;
      if (((iVar5 == 3) || (iVar5 == 6)) || (iVar5 == 7)) {
        *(int *)(param_1 + 0x310) = *(int *)(param_1 + 0x30c) + -1;
      }
    }
    NoteC_c_vslot_0(&local_58);
    NoteC_c_vslot_0(&local_6c);
  }
  return;
}

