/* 00001ce0 CControlPl_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CControlPl_vslot_7(int *param_1,undefined4 param_2)

{
  float *pfVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  uint local_38;
  char local_31;
  int local_24;
  int local_20;
  
  if ((char)param_1[0x2b] != '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x2b) = 1;
  (**(code **)(*(int *)param_1[0x25] + 8))((int *)param_1[0x25],param_2,param_1);
  if (0 < param_1[0x29]) {
    iVar5 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)(iVar4 + param_1[0x24] + 8) = *(undefined4 *)(iVar4 + param_1[0x24] + 0xc);
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar5 < param_1[0x29]);
  }
  local_38 = FUN_0009cba2(param_2);
  if (*(char *)((int)param_1 + 0x77) == '\0') {
    local_31 = '\0';
  }
  else {
    local_31 = FUN_0009cc16(param_2);
  }
  local_24 = 0;
  local_20 = 0;
  (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_24);
  param_1[0x27] = local_24;
  param_1[0x28] = local_20;
  iVar4 = param_1[0x24];
  iVar5 = *(int *)(iVar4 + 0xc);
  *(int *)(iVar4 + 4) = iVar5;
  *(int *)(iVar4 + 8) = iVar5;
  param_1[0x1e] = iVar5;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  if (*(char *)((int)param_1 + 0x6e) == '\0') {
    iVar4 = param_1[0x10];
    (**(code **)(*(int *)param_1[10] + 0x13c))((int *)param_1[10],param_1);
    (**(code **)(*(int *)param_1[10] + 300))((int *)param_1[10],iVar4);
  }
  if (*(char *)((int)param_1 + 0x6e) == '\0') {
    if ((local_38 & 0x10) == 0) {
      if (local_31 == '\0') {
        if ((local_38 & 0x20) == 0) {
          while ((local_38 & 5) != 0) {
            lVar6 = (longdouble)(**(code **)(*param_1 + 0x124))(param_1,&local_24,local_38 >> 3 & 1)
            ;
            fVar7 = (float)lVar6;
            if (*(char *)((int)param_1 + 0x73) != '\0') {
              fVar7 = 1.0 - fVar7;
            }
            *(float *)(param_1[0x24] + 4) = fVar7;
            fVar7 = *(float *)(param_1[0x24] + 4);
            if ((0.0 <= fVar7) || (NAN(fVar7))) {
              fVar8 = 1.0;
              if (fVar7 <= 1.0) {
                fVar8 = fVar7;
              }
            }
            else {
              fVar8 = 0.0;
            }
            *(float *)(param_1[0x24] + 4) = fVar8;
            fVar7 = *(float *)(param_1[0x24] + 4);
            pfVar1 = (float *)(param_1[0x24] + 8);
            if ((((fVar7 != *pfVar1) || (NAN(fVar7) || NAN(*pfVar1))) ||
                (*(char *)((int)param_1 + 0x6d) != '\0')) || ((char)param_1[0x1b] != '\0')) {
              (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1)
              ;
            }
            (**(code **)(*param_1 + 0xac))(param_1);
            iVar4 = 0;
            do {
              if (((*(char *)((int)param_1 + 0x6d) == '\0') && ((char)param_1[0x1b] == '\0')) ||
                 (iVar5 = FUN_0009cba2(param_2), iVar5 == 0)) break;
              FUN_0002e340(param_1 + 0x23,0x28);
              iVar4 = iVar4 + 1;
            } while (iVar4 != 5);
            local_38 = FUN_0009cba2(param_2);
            (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_24);
          }
        }
        else {
          while ((local_38 & 5) != 0) {
            bVar2 = local_20 < (param_1[3] + param_1[5]) / 2;
            *(bool *)((int)param_1 + 0x6d) = bVar2;
            *(bool *)(param_1 + 0x1b) = !bVar2;
            (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
            iVar4 = 0;
            local_38 = FUN_0009cba2(param_2);
            while( true ) {
              if ((local_38 & 5) != 0) {
                FUN_0002e340(param_1 + 0x23,0x28);
                (**(code **)(*param_1 + 0xac))(param_1);
              }
              iVar4 = iVar4 + 1;
              if (iVar4 == 5) break;
              local_38 = FUN_0009cba2(param_2);
            }
          }
        }
        goto LAB_00001de2;
      }
      (**(code **)(*param_1 + 0x11c))(param_1);
    }
    else {
      *(undefined4 *)(param_1[0x24] + 4) = *(undefined4 *)(param_1[0x24] + 0x14);
    }
LAB_0000206f:
    (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
    cVar3 = *(char *)((int)param_1 + 0x6e);
  }
  else {
    if (*(char *)((int)param_1 + 0x6f) == '\0') {
      cVar3 = (**(code **)(*param_1 + 0x128))(param_1,&local_24);
      if (cVar3 != '\0') goto LAB_0000206f;
    }
    else {
      while ((local_38 & 5) != 0) {
        (**(code **)(*param_1 + 0x128))(param_1,&local_24);
        (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
        (**(code **)(*param_1 + 0xac))(param_1);
        local_38 = FUN_0009cba2(param_2);
        (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_24);
      }
    }
LAB_00001de2:
    cVar3 = *(char *)((int)param_1 + 0x6e);
  }
  if (cVar3 == '\0') {
    (**(code **)(*(int *)param_1[10] + 0x130))((int *)param_1[10],param_1[0x10]);
  }
  *(undefined1 *)(param_1 + 0x2b) = 0;
  return;
}

