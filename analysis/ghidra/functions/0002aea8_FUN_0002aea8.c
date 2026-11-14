/* 0002aea8 FUN_0002aea8 */

void FUN_0002aea8(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_88;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c [24];
  
  iVar4 = FUN_00012888(param_1[0x30e],param_1[0x50]);
  if (iVar4 == 0) {
    return;
  }
  if (param_6 < 1) {
LAB_0002b12d:
    local_a8 = 0;
  }
  else {
    iVar5 = 0;
    do {
      local_6c[iVar5] = 0;
      iVar5 = iVar5 + 1;
    } while (param_6 != iVar5);
    if (param_6 < 1) goto LAB_0002b12d;
    local_a8 = 0;
    do {
      iVar5 = iVar4 + param_4 * 0x70;
      local_74 = 0;
      bVar2 = false;
      piVar6 = local_6c;
      do {
        iVar7 = *(int *)(iVar5 + 8);
        if ((param_5 <= iVar7) && (iVar7 < param_7 + param_5)) {
          iVar1 = *piVar6;
          iVar8 = param_7 + 1;
          if (local_6c[iVar7 - param_5] + 1 <= param_7 + 1) {
            iVar8 = local_6c[iVar7 - param_5] + 1;
          }
          *piVar6 = iVar8;
          bVar2 = (bool)(bVar2 | iVar1 != iVar8);
        }
        iVar7 = *piVar6;
        if (*piVar6 <= local_a8) {
          iVar7 = local_a8;
        }
        local_74 = local_74 + 1;
        piVar6 = piVar6 + 1;
        iVar5 = iVar5 + 0x70;
        local_a8 = iVar7;
      } while (param_6 != local_74);
    } while (bVar2);
    if (iVar7 < 0) {
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      goto LAB_0002aff7;
    }
  }
  local_88 = local_a8;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  do {
    if (0 < param_6) {
      local_78 = param_2 * 0x70;
      local_70 = 0;
      local_7c = 0;
      iVar5 = iVar4 + local_78;
      do {
        iVar7 = *(int *)(iVar5 + 8 + local_7c);
        iVar1 = *(int *)(iVar4 + param_4 * 0x70 + 8 + local_7c);
        if (((-1 < iVar7) && (-1 < iVar1)) && (local_88 == local_6c[local_70])) {
          if (*(char *)(iVar1 + 0x3c0 + (int)param_1) == '\0') {
            iVar8 = FUN_00012888(param_1[0x30e],param_1[0x50]);
            if ((iVar8 != 0) &&
               (*(char *)(*(int *)(iVar8 + 8 + local_78) + 0x4c0 + (int)param_1) != '\0')) {
              iVar8 = iVar8 + param_4 * 0x70;
              cVar3 = '\x01';
              local_80 = 0;
              do {
                if ((local_70 != local_80) && (*(int *)(iVar8 + 8) == param_5 + local_70)) {
                  cVar3 = FUN_0002a7fa(param_1,local_80,param_2,param_4,param_6,param_5,1);
                }
                local_80 = local_80 + 1;
                iVar8 = iVar8 + 0x70;
              } while (param_6 != local_80);
              if (cVar3 != '\0') {
                if (*(char *)(iVar1 + 0x340 + (int)param_1) == '\0') {
                  param_1[local_a4 + 0x148] = param_1[iVar7 + 0x100];
                  iVar7 = (**(code **)(*param_1 + 0x34))(param_1,local_70);
                  param_1[local_a4 + 0x161] = iVar7;
                  param_1[local_a4 + 0x17a] = param_1[iVar1 + 0x90];
                  local_a4 = local_a4 + 1;
                }
                else {
                  param_1[local_a0 + 0x193] = param_1[iVar7 + 0x100];
                  iVar7 = (**(code **)(*param_1 + 0x34))(param_1,local_70);
                  param_1[local_a0 + 0x1ac] = iVar7;
                  param_1[local_a0 + 0x1c5] = param_1[iVar1 + 0x90];
                  local_a0 = local_a0 + 1;
                }
                goto LAB_0002b1f8;
              }
            }
            if (*(char *)(iVar1 + 0x340 + (int)param_1) == '\0') {
              param_1[local_9c + 0x1de] = param_1[iVar7 + 0x100];
              iVar7 = (**(code **)(*param_1 + 0x34))(param_1,local_70);
              param_1[local_9c + 0x1f7] = iVar7;
              param_1[local_9c + 0x210] = param_1[iVar1 + 0x90];
              local_9c = local_9c + 1;
            }
            else {
              param_1[local_98 + 0x229] = param_1[iVar7 + 0x100];
              iVar7 = (**(code **)(*param_1 + 0x34))(param_1,local_70);
              param_1[local_98 + 0x242] = iVar7;
              param_1[local_98 + 0x25b] = param_1[iVar1 + 0x90];
              local_98 = local_98 + 1;
            }
          }
          else if (*(char *)(iVar1 + 0x340 + (int)param_1) == '\0') {
            param_1[local_94 + 0x274] = param_1[iVar7 + 0x100];
            iVar7 = (**(code **)(*param_1 + 0x34))(param_1,local_70);
            param_1[local_94 + 0x28d] = iVar7;
            param_1[local_94 + 0x2a6] = param_1[iVar1 + 0x90];
            local_94 = local_94 + 1;
          }
          else {
            param_1[local_90 + 0x2bf] = param_1[iVar7 + 0x100];
            iVar7 = (**(code **)(*param_1 + 0x34))(param_1,local_70);
            param_1[local_90 + 0x2d8] = iVar7;
            param_1[local_90 + 0x2f1] = param_1[iVar1 + 0x90];
            local_90 = local_90 + 1;
          }
        }
LAB_0002b1f8:
        local_70 = local_70 + 1;
        local_7c = local_7c + 0x70;
        local_78 = local_78 + 0x70;
      } while (param_6 != local_70);
    }
    local_88 = local_88 + -1;
  } while (local_88 != -1);
LAB_0002aff7:
  if (local_a0 <= param_6) {
    piVar6 = param_1 + local_a0 + 0x193;
    do {
      *piVar6 = 0;
      piVar6[0x19] = 0;
      piVar6[0x32] = 0;
      local_a0 = local_a0 + 1;
      piVar6 = piVar6 + 1;
    } while (local_a0 <= param_6);
  }
  if (local_a4 <= param_6) {
    piVar6 = param_1 + local_a4 + 0x148;
    do {
      *piVar6 = 0;
      piVar6[0x19] = 0;
      piVar6[0x32] = 0;
      local_a4 = local_a4 + 1;
      piVar6 = piVar6 + 1;
    } while (local_a4 <= param_6);
  }
  if (local_98 <= param_6) {
    piVar6 = param_1 + local_98 + 0x229;
    do {
      *piVar6 = 0;
      piVar6[0x19] = 0;
      piVar6[0x32] = 0;
      local_98 = local_98 + 1;
      piVar6 = piVar6 + 1;
    } while (local_98 <= param_6);
  }
  if (local_9c <= param_6) {
    piVar6 = param_1 + local_9c + 0x1de;
    do {
      *piVar6 = 0;
      piVar6[0x19] = 0;
      piVar6[0x32] = 0;
      local_9c = local_9c + 1;
      piVar6 = piVar6 + 1;
    } while (local_9c <= param_6);
  }
  if (local_90 <= param_6) {
    piVar6 = param_1 + local_90 + 0x2bf;
    do {
      *piVar6 = 0;
      piVar6[0x19] = 0;
      piVar6[0x32] = 0;
      local_90 = local_90 + 1;
      piVar6 = piVar6 + 1;
    } while (local_90 <= param_6);
  }
  if (local_94 <= param_6) {
    param_1 = param_1 + local_94 + 0x274;
    do {
      *param_1 = 0;
      param_1[0x19] = 0;
      param_1[0x32] = 0;
      local_94 = local_94 + 1;
      param_1 = param_1 + 1;
    } while (local_94 <= param_6);
  }
  return;
}

