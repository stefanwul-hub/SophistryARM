/* 0008ae2a CStepSeqPl_vslot_7 */

/* WARNING: Removing unreachable block (ram,0x0008b35b) */

void CStepSeqPl_vslot_7(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  int local_44;
  byte local_3e;
  byte local_3d;
  int local_2c;
  int local_20;
  int local_14;
  int local_10;
  
  FUN_00001bd4(param_1);
  uVar2 = FUN_0009cba2(param_2);
  local_14 = 0;
  local_10 = 0;
  (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_14);
  iVar6 = param_1[2];
  iVar3 = (param_1[4] - iVar6) / param_1[0x2f];
  iVar9 = param_1[0x30];
  iVar4 = (param_1[5] - param_1[3]) / iVar9;
  local_3d = *(byte *)((int)param_1 + 0xcd);
  local_3e = *(byte *)(param_1 + 0x33);
  if (*(char *)((int)param_1 + 0xcf) != '\0') {
    if (*(char *)((int)param_1 + 0xce) == '\0') {
      local_2c = 0;
    }
    else {
      local_2c = iVar4 / 2;
    }
    iVar5 = (local_14 - iVar6) / iVar3;
    local_44 = (local_10 - param_1[3]) / iVar4 + iVar5 * iVar9;
    if (local_3e != 0) {
      if (local_3d == 0) {
        local_3e = 1;
        local_3d = 0;
        goto LAB_0008af78;
      }
      local_3e = local_14 - (iVar3 * iVar5 + iVar6) < (iVar3 - local_2c) / 2 + local_2c;
    }
    local_3d = local_3e ^ 1;
  }
LAB_0008af78:
  iVar6 = (param_1[5] - param_1[3]) / iVar9;
  iVar6 = (local_44 % iVar9) * iVar6 + param_1[3] + iVar6 / 2;
  iVar9 = local_44 * 2;
  uVar7 = (int)*(char *)(param_1[0x21] + 3 + iVar9) + 0x100U & 0x800000ff;
  if ((int)uVar7 < 0) {
    uVar7 = (uVar7 - 1 | 0xffffff00) + 1;
  }
  if ((uVar2 & 0x10) == 0) {
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 5) != 0) {
        pcVar8 = (char *)((int)param_1 + 0x1d3);
        do {
          iVar3 = (uVar7 - 1) + (iVar6 - local_10) / 2;
          _strcpy(pcVar8,(char *)(param_1 + 0x34));
          if (local_44 < 0) {
            iVar4 = 0;
            if (-1 < iVar3) goto LAB_0008b225;
LAB_0008b377:
            iVar5 = 0;
          }
          else {
            iVar4 = 0xfe;
            if (local_44 < 0x80) {
              iVar4 = iVar9;
            }
            if (iVar3 < 0) goto LAB_0008b377;
LAB_0008b225:
            iVar5 = ~-(uint)(local_3e == 0) + 0x80;
            if (iVar3 <= iVar5) {
              iVar5 = iVar3;
            }
          }
          *(char *)((int)param_1 + iVar4 + (local_3d != 0) + 0x1d5) = (char)iVar5 + '\x01';
          param_1[0x1f] = (int)pcVar8;
          iVar3 = -1;
          pcVar10 = pcVar8;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          if (iVar3 == -0x104) {
            (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
          }
          (**(code **)(*param_1 + 0xac))(param_1);
          iVar3 = 5;
          do {
            if (((*(char *)((int)param_1 + 0x6d) == '\0') && ((char)param_1[0x1b] == '\0')) ||
               (iVar4 = FUN_0009cba2(param_2), iVar4 == 0)) break;
            FUN_00001c28(param_1,0x28);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          uVar2 = FUN_0009cba2(param_2);
          (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_14);
        } while ((uVar2 & 5) != 0);
      }
    }
    else {
      while ((uVar2 & 5) != 0) {
        iVar3 = (uVar7 - 2) + (uint)(local_10 <= iVar6) * 2;
        pcVar8 = (char *)((int)param_1 + 0x1d3);
        _strcpy(pcVar8,(char *)(param_1 + 0x34));
        if (local_44 < 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 0xfe;
          if (local_44 < 0x80) {
            iVar4 = iVar9;
          }
        }
        iVar5 = ~-(uint)(local_3e == 0) + 0x80;
        if (iVar3 < 0) {
          iVar5 = 0;
        }
        else if (iVar3 <= iVar5) {
          iVar5 = iVar3;
        }
        *(char *)((int)param_1 + iVar4 + (local_3d != 0) + 0x1d5) = (char)iVar5 + '\x01';
        param_1[0x1f] = (int)pcVar8;
        iVar3 = -1;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        if (iVar3 == -0x104) {
          (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
        }
        (**(code **)(*param_1 + 0xac))(param_1);
        iVar3 = 0;
        uVar2 = FUN_0009cba2(param_2);
        while( true ) {
          if ((uVar2 & 5) != 0) {
            FUN_00001c28(param_1,0x28);
            (**(code **)(*param_1 + 0xac))(param_1);
          }
          iVar3 = iVar3 + 1;
          if (iVar3 == 5) break;
          uVar2 = FUN_0009cba2(param_2);
        }
      }
    }
  }
  else {
    iVar6 = (-(uint)(local_3e == 0) & 0x28) + 0x3c;
    pcVar8 = (char *)((int)param_1 + 0x1d3);
    _strcpy(pcVar8,(char *)(param_1 + 0x34));
    if (local_44 < 0) {
      local_20 = 0;
    }
    else {
      local_20 = 0xfe;
      if (local_44 < 0x80) {
        local_20 = iVar9;
      }
    }
    iVar9 = ~-(uint)(local_3e == 0) + 0x80;
    if (iVar6 <= iVar9) {
      iVar9 = iVar6;
    }
    *(char *)((int)param_1 + local_20 + (local_3d != 0) + 0x1d5) = (char)iVar9 + '\x01';
    param_1[0x1f] = (int)pcVar8;
    iVar6 = -1;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    if (iVar6 == -0x104) {
      (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
    }
    (**(code **)(*param_1 + 0xac))(param_1);
  }
  return;
}

