/* 00011190 FUN_00011190 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00011190(int param_1,char *param_2,short param_3)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  double dVar6;
  size_t sVar7;
  undefined8 in_stack_fffffe5c;
  undefined4 uVar8;
  char *local_18c;
  int local_180;
  undefined4 local_170;
  undefined4 local_16c;
  undefined2 uStack_168;
  char local_30 [32];
  
  uVar8 = (undefined4)((ulonglong)in_stack_fffffe5c >> 0x20);
  if (*(int *)(param_1 + 0x54) < 0) {
    return;
  }
  local_170 = 0x6f727245;
  local_16c = CONCAT13(local_16c._3_1_,0x2172);
  switch(*(undefined4 *)(param_1 + 4)) {
  default:
    cVar3 = FUN_0002d6ea(param_1 + 0x68,1);
    uVar2 = local_170;
    if ((cVar3 != '\0') && (uVar2 = 0x6f6f2d, *(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x44)))
    {
      uVar2 = local_170;
    }
    local_170 = uVar2;
    cVar3 = FUN_0002d6ea(param_1 + 0x68,2);
    if ((cVar3 != '\0') && (*(int *)(param_1 + 0x5c) == *(int *)(param_1 + 0x48))) {
      local_170 = CONCAT13(local_170._3_1_,0x6f6f);
      break;
    }
    iVar5 = *(int *)(param_1 + 0x54);
    if (iVar5 != 0) {
      if ((iVar5 == 2) && (**(char **)(param_1 + 0x40) == '%')) {
        _sprintf((char *)&local_170,"%ld",*(undefined4 *)(param_1 + 0x5c));
      }
      else {
        iVar1 = *(int *)(param_1 + 100);
        if (iVar1 == 0) {
          local_180 = 0;
        }
        else {
          local_180 = *(int *)(param_1 + 0x5c) / iVar1;
          if (*(int *)(param_1 + 0x5c) % iVar1 < 0) {
            _sprintf(local_30,"-%%ld.%%0%dld",iVar5);
            _sprintf((char *)&local_170,local_30,-local_180);
            if (0 < *(int *)(param_1 + 0x58)) {
              *(undefined1 *)((int)&local_170 + *(int *)(param_1 + 0x58) + 1) = 0;
            }
            break;
          }
        }
        _sprintf(local_30,"%%ld.%%0%dld",iVar5);
        _sprintf((char *)&local_170,local_30,local_180);
        if (0 < *(int *)(param_1 + 0x58)) {
          *(undefined1 *)((int)&local_170 + *(int *)(param_1 + 0x58)) = 0;
        }
      }
      break;
    }
    dVar6 = (double)CONCAT44(uVar8,*(undefined4 *)(param_1 + 0x5c));
    pcVar4 = "%ld";
    goto code_r0x00011388;
  case 2:
    if (*(int *)(param_1 + 0x54) < 1) {
      return;
    }
    if (*(int *)(param_1 + 0x30) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x5c) < *(int *)(param_1 + 0x44)) {
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x44);
    }
    if (*(int *)(param_1 + 0x48) < *(int *)(param_1 + 0x5c)) {
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x48);
    }
    cVar3 = FUN_0002d6ea(param_1 + 0x68,1);
    uVar8 = local_170;
    if ((cVar3 != '\0') && (uVar8 = 0x6f6f2d, *(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x44)))
    {
      uVar8 = local_170;
    }
    local_170 = uVar8;
    cVar3 = FUN_0002d6ea(param_1 + 0x68,2);
    if (cVar3 == '\0') {
      iVar5 = *(int *)(param_1 + 0x5c);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x5c);
      if (iVar5 == *(int *)(param_1 + 0x48)) {
        local_170 = CONCAT13(local_170._3_1_,0x6f6f);
        break;
      }
    }
    sVar7 = *(size_t *)(param_1 + 0x54);
    pcVar4 = (char *)(sVar7 * (iVar5 - *(int *)(param_1 + 0x44)) + *(int *)(param_1 + 0x30));
    goto code_r0x00011434;
  case 3:
    if (*(int *)(param_1 + 0x5c) == 0x10) {
      local_170 = 0x6c6c61;
      break;
    }
    dVar6 = (double)CONCAT44(uVar8,*(int *)(param_1 + 0x5c) + 1);
    pcVar4 = "%02d";
    goto code_r0x00011388;
  case 4:
    FUN_000104be(param_1,&local_170);
    break;
  case 5:
    FUN_000107ac(param_1,&local_170);
    break;
  case 6:
    if (1 < *(uint *)(param_1 + 0x5c)) {
      return;
    }
    sVar7 = *(size_t *)(param_1 + 0x54);
    if ((int)sVar7 < 1) {
      return;
    }
    if (*(int *)(param_1 + 0x30) == 0) {
      return;
    }
    pcVar4 = (char *)(*(int *)(param_1 + 0x30) + *(uint *)(param_1 + 0x5c) * sVar7);
code_r0x00011434:
    _strncpy((char *)&local_170,pcVar4,sVar7);
    *(undefined1 *)((int)&local_170 + *(int *)(param_1 + 0x54)) = 0;
    break;
  case 7:
    FUN_00011082(param_1,&local_170);
    break;
  case 9:
    if (*(int *)(param_1 + 8) < 0) {
      dVar6 = (double)((float)*(int *)(param_1 + 0x5c) * -0.01);
      pcVar4 = "L %0.2f";
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        local_170 = 0x203c2020;
        local_16c = 0x203e2043;
        uStack_168 = 0x20;
        break;
      }
      dVar6 = (double)((float)*(int *)(param_1 + 0x5c) * 0.01);
      pcVar4 = "  %0.2f R";
    }
code_r0x00011388:
    _sprintf((char *)&local_170,pcVar4,dVar6);
  }
  local_18c = (char *)&local_170;
  _strncpy(param_2,local_18c,(int)param_3 - 1);
  param_2[param_3 + -1] = '\0';
  return;
}

