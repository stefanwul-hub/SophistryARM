/* 0000e364 Instrument_c_vslot_21 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_21(int *param_1,byte *param_2,char param_3)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  undefined *local_58;
  undefined1 local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined *local_44;
  undefined1 local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined *local_30;
  undefined1 local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
  piVar2 = (int *)param_1[1];
  if (piVar2 == (int *)0x0) {
    return;
  }
  if ((char)param_1[0x6d7] == '\0') {
    return;
  }
  uVar7 = *param_2 & 0xf0;
  uVar4 = *param_2 & 0xf;
  if ((uVar7 != 0x90) && (uVar7 != 0x80)) {
    if ((*(char *)((int)param_1 + 0xec2) == '\0') || (uVar7 != 0xa0)) {
      if (uVar7 == 0xc0) {
        FUN_0001fff6(piVar2,0x4d,param_1[0x69],param_2[1] & 0x7f,0,0);
      }
      else if ((*(char *)((int)param_1 + 0xec2) == '\0') || (uVar7 != 0xd0)) {
        if ((*(char *)((int)param_1 + 0xec1) == '\0') || (uVar7 != 0xe0)) {
          if (uVar7 == 0xb0) {
            bVar1 = param_2[1];
            if (bVar1 == 0) {
              return;
            }
            if (bVar1 != 0x20) {
              if (0x7a < bVar1) {
                (**(code **)(*param_1 + 0xa8))(param_1,uVar4);
                return;
              }
              FUN_00023018(piVar2,param_2);
              (**(code **)(*param_1 + 0x5c))(param_1,uVar4,param_2[1],param_2[2]);
              return;
            }
            FUN_0001fff6(piVar2,0x4e,param_1[0x69],param_2[2] & 0x7f,0,0);
            return;
          }
          if (uVar7 == 0xf0) {
            FUN_000257cc(piVar2,param_2);
          }
        }
        else {
          param_1[0x6b6] =
               (int)((float)((param_2[1] & 0x7f) + (param_2[2] & 0x7f) * 0x80) * 0.00012207776 - 1.0
                    );
        }
      }
      else {
        (**(code **)(*param_1 + 100))(param_1,(float)(param_2[1] & 0x7f) * 0.007874016);
      }
    }
    else {
      bVar1 = param_2[2];
      iVar6 = FUN_0002edda(piVar2 + 0xe33,param_1[0x69],param_2[1] & 0x7f,uVar4);
      if (-1 < iVar6) {
        piVar2 = *(int **)(*(int *)(param_1[1] + 0x3b0c) + iVar6 * 4);
        (**(code **)(*piVar2 + 0x38))(piVar2,(float)(bVar1 & 0x7f) * 0.007874016);
      }
    }
    goto LAB_0000e4b9;
  }
  puVar5 = PTR_DAT_00103808 + 8;
  local_58 = PTR_DAT_00103814 + 8;
  local_50 = param_2[1] & 0x7f;
  local_4c = param_2[2] & 0x7f;
  if ((uVar7 == 0x80) || ((param_2[2] & 0x7f) == 0)) {
    local_54 = 1;
    local_48 = uVar4;
    (**(code **)(*param_1 + 0xb4))(param_1,&local_58);
  }
  else {
    if (param_3 != '\0') {
      local_40 = 1;
      local_44 = local_58;
      local_3c = local_50;
      local_38 = local_4c;
      local_34 = uVar4;
      cVar3 = (**(code **)(*piVar2 + 0x340))(piVar2,param_1[0x69],&local_44);
      local_44 = puVar5;
      if (cVar3 == '\0') goto LAB_0000e4a5;
    }
    local_2c = 1;
    local_30 = PTR_DAT_00103814 + 8;
    local_28 = local_50;
    local_24 = local_4c;
    local_20 = uVar4;
    (**(code **)(*param_1 + 0xb8))(param_1,&local_30);
  }
LAB_0000e4a5:
  if (uVar7 == 0xb0) {
    return;
  }
LAB_0000e4b9:
  *(undefined1 *)(param_1 + 0x6d5) = 1;
  return;
}

