/* 0009496a CKeyboard2_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CKeyboard2_vslot_7(int *param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined *local_44;
  undefined1 local_40;
  int local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined1 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  if ((param_2 != 0) && (param_1[300] != 0)) {
    FUN_00001bd4(param_1);
    *(undefined1 *)(param_1 + 0x1b) = 0;
    *(undefined1 *)((int)param_1 + 0x6d) = 0;
    local_34 = PTR_DAT_00103808 + 8;
    local_30 = 0;
    local_2c = -1;
    local_28 = 0xffffffff;
    local_44 = PTR_DAT_00103808 + 8;
    local_40 = 0;
    local_3c = -1;
    local_38 = 0xffffffff;
    do {
      local_24 = 0;
      local_20 = 0;
      (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_24);
      iVar7 = local_24 - param_1[2];
      iVar6 = local_20 - param_1[3];
      uVar4 = FUN_0009cba2(param_2);
      if ((local_24 < param_1[2]) || (param_1[4] < local_24)) {
        bVar2 = false;
        if ((uVar4 & 1) == 0) goto LAB_00094b7d;
LAB_00094a63:
        if (((bVar2) &&
            (cVar3 = (**(code **)(*param_1 + 0x144))(param_1,iVar7,iVar6,&local_34), cVar3 != '\0'))
           && (local_2c != local_3c)) {
          pcVar1 = *(code **)(*(int *)param_1[300] + 0x32c);
          uVar5 = FUN_00001afe(param_1,0);
          (*pcVar1)(param_1[300],0x3d,uVar5,0,&local_34);
          if (-1 < local_3c) {
            local_38 = 0;
            pcVar1 = *(code **)(*(int *)param_1[300] + 0x32c);
            uVar5 = FUN_00001afe(param_1,0);
            (*pcVar1)(param_1[300],0x3d,uVar5,0,&local_44);
          }
          local_40 = local_30;
          local_3c = local_2c;
          local_38 = local_28;
          bVar2 = true;
        }
        else {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
        if ((uVar4 & 1) != 0) goto LAB_00094a63;
LAB_00094b7d:
        if (local_3c < 0) {
          return;
        }
        local_38 = 0;
        pcVar1 = *(code **)(*(int *)param_1[300] + 0x32c);
        uVar5 = FUN_00001afe(param_1,0);
        (*pcVar1)(param_1[300],0x3d,uVar5,0,&local_44);
        bVar2 = false;
      }
      (**(code **)(*param_1 + 0xac))(param_1);
    } while (bVar2);
  }
  return;
}

