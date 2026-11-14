/* 0008cea6 FUN_0008cea6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008cea6(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  float local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined **local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined **local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar4 = *(int *)(param_1 + 0x124);
  if ((iVar4 != 0) && (*(char *)(iVar4 + 0x8c) != '\0')) {
    piVar2 = (int *)(iVar4 + 0x4d8);
    piVar3 = (int *)(iVar4 + 0x388);
    iVar4 = 0;
    do {
      if ((*piVar2 == param_2) && (*piVar3 == param_3)) {
        iVar4 = iVar4 + 1;
        if (iVar4 < 0x80) {
          iVar5 = iVar4 * 0x4d0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          local_98 = 0xffffffff;
          local_94 = 0x7f;
          local_90 = 0;
          local_8c = 1.0;
          local_88 = 0;
          local_84 = 0;
          local_80 = 0;
          do {
            if (((*(int *)(param_1 + 0x120) != 0) && (-1 < iVar4)) &&
               (*(int *)(param_1 + 0x124) != 0)) {
              iVar1 = *(int *)(param_1 + 0x124) + iVar5;
              local_88 = *(undefined4 *)(iVar1 + 0x404);
              local_8c = *(float *)(iVar1 + 0x474);
              local_a4 = *(undefined4 *)(iVar1 + 0x628);
              local_a0 = *(undefined4 *)(iVar1 + 0x5b8);
              local_9c = *(undefined4 *)(iVar1 + 0x548);
              local_98 = *(undefined4 *)(iVar1 + 0x4d8);
              local_94 = 0x7f - *(int *)(iVar1 + 0x708);
              local_90 = *(undefined4 *)(iVar1 + 0x698);
              local_84 = *(undefined4 *)(iVar1 + 0x388);
              local_80 = *(undefined4 *)(iVar1 + 0x318);
            }
            local_74 = &PTR_CCAss_c_vslot_0_000f2f08;
            local_6c = local_84;
            local_68 = local_88;
            local_64 = local_8c;
            local_60 = local_90;
            local_5c = local_94;
            local_58 = local_98;
            local_54 = local_9c;
            local_50 = local_a0;
            local_4c = local_a4;
            local_70 = local_80;
            FUN_0008bcda(param_1,iVar4 + -1,&local_74);
            local_74 = &PTR_CCAss_c_vslot_0_000f2f08;
            iVar4 = iVar4 + 1;
            iVar5 = iVar5 + 0x4d0;
          } while (iVar4 != 0x80);
        }
        local_48 = &PTR_CCAss_c_vslot_0_000f2f08;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        local_38 = 0x3f800000;
        local_34 = 0;
        local_30 = 0x7f;
        local_2c = 0xffffffff;
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        FUN_0008bcda(param_1,0x7f,&local_48);
        return;
      }
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 0x134;
      piVar3 = piVar3 + 0x134;
    } while (iVar4 != 0x80);
  }
  return;
}

