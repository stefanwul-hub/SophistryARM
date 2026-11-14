/* 0008a182 CStepSeqPl_vslot_12 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CStepSeqPl_vslot_12(int *param_1,undefined4 param_2,int *param_3,float param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int local_3c;
  byte local_36;
  byte local_35;
  int local_28;
  int local_20;
  
  iVar7 = param_1[2];
  iVar2 = (param_1[4] - iVar7) / param_1[0x2f];
  iVar3 = (param_1[5] - param_1[3]) / param_1[0x30];
  local_35 = *(byte *)((int)param_1 + 0xcd);
  local_36 = *(byte *)(param_1 + 0x33);
  if (*(char *)((int)param_1 + 0xcf) != '\0') {
    if (*(char *)((int)param_1 + 0xce) == '\0') {
      local_28 = 0;
    }
    else {
      local_28 = iVar3 / 2;
    }
    iVar4 = (*param_3 - iVar7) / iVar2;
    local_3c = param_1[0x30] * iVar4 + (param_3[1] - param_1[3]) / iVar3;
    if (local_36 != 0) {
      if (local_35 == 0) {
        local_36 = 1;
        local_35 = 0;
        goto LAB_0008a272;
      }
      local_36 = *param_3 - (iVar4 * iVar2 + iVar7) < (iVar2 - local_28) / 2 + local_28;
    }
    local_35 = local_36 ^ 1;
  }
LAB_0008a272:
  uVar5 = (int)*(char *)(param_1[0x21] + 3 + local_3c * 2) + 0x100U & 0x800000ff;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xffffff00) + 1;
  }
  if (param_4 <= 0.0) {
    uVar5 = uVar5 - 2;
  }
  pcVar8 = (char *)((int)param_1 + 0x1d3);
  _strcpy(pcVar8,(char *)(param_1 + 0x34));
  if (local_3c < 0) {
    local_20 = 0;
  }
  else {
    local_20 = 0xfe;
    if (local_3c < 0x80) {
      local_20 = local_3c * 2;
    }
  }
  uVar6 = ~-(uint)(local_36 == 0) + 0x80;
  if ((int)uVar5 < 0) {
    uVar6 = 0;
  }
  else if ((int)uVar5 <= (int)uVar6) {
    uVar6 = uVar5;
  }
  *(char *)((int)param_1 + local_20 + (local_35 != 0) + 0x1d5) = (char)uVar6 + '\x01';
  param_1[0x1f] = (int)pcVar8;
  iVar7 = -1;
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  if (iVar7 == -0x104) {
    (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
    (**(code **)(*param_1 + 0xac))(param_1);
    return 1;
  }
  (**(code **)(*param_1 + 0xac))(param_1);
  return 1;
}

